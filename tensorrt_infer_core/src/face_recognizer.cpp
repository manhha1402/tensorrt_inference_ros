#include <memory>
#include <tensorrt_infer_core/face_recognizer.hpp>

using std::placeholders::_1;
namespace
{
  void normalize_vector(const std::vector<float> &vec, std::vector<double> &embedding)
  {
    // Step 1: Calculate the magnitude (L2 norm)
    float magnitude = 0.0f;
    for (const float &val : vec)
    {
      magnitude += val * val;
    }
    magnitude = std::sqrt(magnitude);

    // Step 2: Normalize each element by dividing by the magnitude
    if (magnitude > 0)
    {
      for (size_t i = 0; i < vec.size(); i++)
      {
        double norm = vec[i] / magnitude;
        embedding[i] = norm;
      }
    }
  }
} // namespace
namespace tensorrt_infer_core
{
  FaceRecognizer::FaceRecognizer(const rclcpp::NodeOptions &options, const std::string node_name)
      : Node(node_name, options)
  {
    // Declare parameters
    RCLCPP_INFO(get_logger(), "Creating tensorrt detection node");
    dynamic_params_ = std::make_shared<tensorrt_infer_core::Parameters>(*this);
    dynamic_params_->setParam<float>(
        "obj_thres", params_.obj_threshold, [this](const rclcpp::Parameter &parameter)
        { params_.obj_threshold = parameter.get_value<float>(); });
    dynamic_params_->setParam<float>(
        "nms_thres", params_.nms_threshold, [this](const rclcpp::Parameter &parameter)
        { params_.nms_threshold = parameter.get_value<float>(); });
    dynamic_params_->setParam<std::string>(
        "distance_metric", distance_metric_, [this](const rclcpp::Parameter &parameter)
        { distance_metric_ = parameter.get_value<std::string>(); });

    dynamic_params_->setParam<float>(
        "rec_cosine_thres", rec_cosine_thres_, [this](const rclcpp::Parameter &parameter)
        { rec_cosine_thres_ = parameter.get_value<float>(); });

    dynamic_params_->setParam<float>(
        "rec_l2_thres", rec_l2_thres_,
        [this](const rclcpp::Parameter &parameter)
        { rec_l2_thres_ = parameter.get_value<float>(); });

    dynamic_params_->setParam<int>(
        "num_detect", params_.num_detect, [this](const rclcpp::Parameter &parameter)
        { params_.num_detect = parameter.get_value<int>(); });
    dynamic_params_->setParam<std::string>(
        "rgbd_topic", camera_topic_, [this](const rclcpp::Parameter &parameter)
        {
          rgbd_topic_ = parameter.get_value<std::string>();
          // rgb_sub_ = this->create_subscription<sensor_msgs::msg::Image>(
          //   camera_topic_.c_str(), 10, std::bind(&FaceRecognizer::detect_rgb_callback, this, _1));
          rgbd_sub_ = this->create_subscription<realsense2_camera_msgs::msg::RGBD>(
              rgbd_topic_.c_str(), 10,
              std::bind(&FaceRecognizer::detect_rgbd_callback, this, _1)); });
    bool ret = initModel();

    face_info_srv_ = create_service<tensorrt_infer_msgs::srv::FaceDatabaseInfo>(
        "face_embeddings",
        std::bind(
            &FaceRecognizer::update_face_embeddings, this, std::placeholders::_1, std::placeholders::_2));
    res_pub_ = create_publisher<sensor_msgs::msg::Image>("face_recognition_image", 10);
    face_info_pub_ = create_publisher<tensorrt_infer_msgs::msg::FaceRecognition>("face_info", 10);
  }

  bool FaceRecognizer::initModel()
  {
    detector_ = std::make_shared<tensorrt_inference::RetinaFace>("facedetector");
    recognizer_ = std::make_shared<tensorrt_inference::FaceRecognition>("FaceNet_vggface2_optmized");
    mongodb_client_ptr_ = std::make_shared<MongoDBClient>();
    embeddings_map_ = mongodb_client_ptr_->getEmbeddings("FaceRecognition");
    rect_height_ = recognizer_->m_trtEngine->getInputInfo().begin()->second.dims.d[2];
    rec_width_ = recognizer_->m_trtEngine->getInputInfo().begin()->second.dims.d[3];

    return true;
  }

  void FaceRecognizer::detect_rgbd_callback(
      const realsense2_camera_msgs::msg::RGBD::SharedPtr rgbd_msg) const
  {
    cv::Mat rgb, depth;
    tensorrt_infer_core::rosToOpenCV(rgbd_msg->rgb, rgb);
    if (rgb.empty() && detector_ == nullptr)
    {
      return;
    }
    // Run inference
    const auto faces = detector_->detect(rgb, params_);
    auto cropped_faces =
        tensorrt_inference::getCroppedObjects(rgb, faces, rec_width_, rect_height_, false);
    tensorrt_infer_msgs::msg::FaceRecognition face_msg;
    // if embeddings_map_ is not empty, perform face recognition
    if (!embeddings_map_.empty())
    {
      for (size_t i = 0; i < cropped_faces.size(); i++)
      {
        std::unordered_map<std::string, std::vector<float>> feature_vectors;
        bool ret = recognizer_->doInference(cropped_faces[i].croped_object, feature_vectors);
        std::vector<double> embedding(feature_vectors.begin()->second.size());
        normalize_vector(feature_vectors.begin()->second, embedding);
        auto result = tensorrt_infer_core::findSimilaritywithName(embeddings_map_, embedding, distance_metric_);
        if (distance_metric_ == "cosine")
        {
          if (std::get<0>(result) > rec_cosine_thres_)
          {
            cropped_faces[i].label = std::get<1>(result);
            cropped_faces[i].rec_score = std::get<0>(result);
            sensor_msgs::msg::Image cropped_face_msg;
            face_msg.user_ids.push_back(cropped_faces[i].label);
            face_msg.rec_scores.push_back(cropped_faces[i].rec_score);
          }
        }
        else if (distance_metric_ == "euclidean")
        {
          if (std::get<0>(result) < rec_l2_thres_)
          {
            cropped_faces[i].label = std::get<1>(result);
            cropped_faces[i].rec_score = std::get<0>(result);
            face_msg.user_ids.push_back(cropped_faces[i].label);
            face_msg.rec_scores.push_back(cropped_faces[i].rec_score);
            sensor_msgs::msg::Image cropped_face_msg;
            tensorrt_infer_core::openCVToRos(cropped_faces[i].croped_object, cropped_face_msg);
            face_msg.cropped_faces.push_back(cropped_face_msg);
          }
        }
      }
    }
    auto now = std::chrono::system_clock::now();
    const std::time_t current_time = std::chrono::system_clock::to_time_t(now);
    face_msg.timestamp = std::ctime(&current_time);
    face_info_pub_->publish(face_msg);

    cv::Mat result = tensorrt_inference::drawBBoxLabels(rgb, cropped_faces, 2, true);
    // Draw the bounding boxes on the image
    cv::cvtColor(result, result, cv::COLOR_RGB2BGR);
    res_pub_->publish(*tensorrt_infer_core::openCVToRos(result));
  }

  void FaceRecognizer::detect_rgb_callback(const sensor_msgs::msg::Image::SharedPtr rgb_msg) const
  {
    cv::Mat rgb;
    tensorrt_infer_core::rosToOpenCV(*rgb_msg, rgb);
    if (rgb.empty() && detector_ == nullptr)
    {
      return;
    }
    // Run inference
    const auto faces = detector_->detect(rgb, params_);
    auto cropped_faces =
        tensorrt_inference::getCroppedObjects(rgb, faces, rec_width_, rect_height_, false);
    tensorrt_infer_msgs::msg::FaceRecognition face_msg;
    // if embeddings_map_ is not empty, perform face recognition
    if (!embeddings_map_.empty())
    {
      for (size_t i = 0; i < cropped_faces.size(); i++)
      {
        std::unordered_map<std::string, std::vector<float>> feature_vectors;
        bool ret = recognizer_->doInference(cropped_faces[i].croped_object, feature_vectors);
        std::vector<double> embedding(feature_vectors.begin()->second.size());
        normalize_vector(feature_vectors.begin()->second, embedding);
        auto result =
            tensorrt_infer_core::findSimilaritywithName(embeddings_map_, embedding, distance_metric_);

        if (distance_metric_ == "cosine")
        {
          if (std::get<0>(result) > rec_cosine_thres_)
          {
            cropped_faces[i].label = std::get<1>(result);
            cropped_faces[i].rec_score = std::get<0>(result);
            sensor_msgs::msg::Image cropped_face_msg;
            face_msg.user_ids.push_back(cropped_faces[i].label);
            face_msg.rec_scores.push_back(cropped_faces[i].rec_score);
          }
        }
        else if (distance_metric_ == "euclidean")
        {
          if (std::get<0>(result) < rec_l2_thres_)
          {
            cropped_faces[i].label = std::get<1>(result);
            cropped_faces[i].rec_score = std::get<0>(result);
            face_msg.user_ids.push_back(cropped_faces[i].label);
            face_msg.rec_scores.push_back(cropped_faces[i].rec_score);
            sensor_msgs::msg::Image cropped_face_msg;
            tensorrt_infer_core::openCVToRos(cropped_faces[i].croped_object, cropped_face_msg);
            face_msg.cropped_faces.push_back(cropped_face_msg);
          }
        }
      }
    }
    auto now = std::chrono::system_clock::now();
    const std::time_t current_time = std::chrono::system_clock::to_time_t(now);
    face_msg.timestamp = std::ctime(&current_time);
    face_info_pub_->publish(face_msg);

    cv::Mat result = tensorrt_inference::drawBBoxLabels(rgb, cropped_faces, 2, true);
    // Draw the bounding boxes on the image
    cv::cvtColor(result, result, cv::COLOR_RGB2BGR);
    res_pub_->publish(*tensorrt_infer_core::openCVToRos(result));
  }

  void FaceRecognizer::update_face_embeddings(
      const std::shared_ptr<tensorrt_infer_msgs::srv::FaceDatabaseInfo::Request> request,
      const std::shared_ptr<tensorrt_infer_msgs::srv::FaceDatabaseInfo::Response> response)
  {
    RCLCPP_INFO(get_logger(), "Update Face Embedding");
    embeddings_map_.clear();
    if (request->face_infos.empty())
    {
      RCLCPP_WARN(get_logger(), "Face Embedding is empty");
      response->success = false;
      return;
    }
    for (const auto &face_info : request->face_infos)
    {
      if (face_info.embeddings.empty())
        continue;
      std::vector<std::vector<double>> embeddings;
      for (const auto &embedding : face_info.embeddings)
      {
        embeddings.push_back(embedding.embedding);
      }
      embeddings_map_[face_info.name] = embeddings;
    }
    RCLCPP_INFO(get_logger(), "Face Embedding updated");
    response->success = true;
  }

} // namespace tensorrt_infer_core
