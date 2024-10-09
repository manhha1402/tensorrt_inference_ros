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
}
namespace tensorrt_infer_core
{
    FaceRecognizer::FaceRecognizer(const rclcpp::NodeOptions &options,
                                   const std::string node_name)
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
        dynamic_params_->setParam<float>(
            "rec_thres", rec_thres_, [this](const rclcpp::Parameter &parameter)
            { rec_thres_ = parameter.get_value<float>(); });

        dynamic_params_->setParam<int>(
            "num_detect", params_.num_detect, [this](const rclcpp::Parameter &parameter)
            { params_.num_detect = parameter.get_value<int>(); });
        dynamic_params_->setParam<std::string>(
            "camera_topic", camera_topic_, [this](const rclcpp::Parameter &parameter)
            { camera_topic_ = parameter.get_value<std::string>(); });
        bool ret = initModel();
        res_pub_ = create_publisher<sensor_msgs::msg::Image>("face_recognition_image", 10);
        face_info_pub_ = create_publisher<tensorrt_infer_msgs::msg::FaceRecognition>("face_info", 10);
        rgbd_sub_ = this->create_subscription<realsense2_camera_msgs::msg::RGBD>(
            "/camera/camera/rgbd", 10,
            std::bind(&FaceRecognizer::detect_rgbd_callback, this, _1));

        // rgb_sub_ = this->create_subscription<sensor_msgs::msg::Image>(
        //     camera_topic_.c_str(), 10,
        //     std::bind(&FaceRecognizer::detect_rgb_callback, this, _1));
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
        cv::Mat rgb;
        tensorrt_infer_core::rosToOpenCV(rgbd_msg->rgb, rgb);
        if (rgb.empty() && detector_ == nullptr)
        {
            return;
        }
        // Run inference
        const auto faces = detector_->detect(rgb, params_);
        auto cropped_faces =
            tensorrt_inference::getCroppedObjects(rgb, faces, rec_width_, rect_height_, false);

        for (size_t i = 0; i < cropped_faces.size(); i++)
        {
            std::unordered_map<std::string, std::vector<float>> feature_vectors;
            cv::cuda::GpuMat gpu_input(cropped_faces[i].croped_object);
            bool ret = recognizer_->doInference(gpu_input, feature_vectors);
            std::vector<double> embedding(feature_vectors.begin()->second.size());
            normalize_vector(feature_vectors.begin()->second, embedding);
            auto result = tensorrt_infer_core::findSimilaritywithName(embeddings_map_, embedding, "cosine");
            if (std::get<0>(result) > rec_thres_)
            {
                cropped_faces[i].label = std::get<1>(result);
                cropped_faces[i].rec_score = std::get<0>(result);
            }
        }
        cv::Mat result = tensorrt_inference::drawBBoxLabels(rgb, cropped_faces, 2, true);
        // Draw the bounding boxes on the image
        cv::cvtColor(result, result, cv::COLOR_RGB2BGR);
        res_pub_->publish(*tensorrt_infer_core::openCVToRos(result));
    }

    // void FaceRecognizer::detect_rgb_callback(
    //     const sensor_msgs::msg::Image::SharedPtr rgb_msg) const
    // {
    //     cv::Mat rgb;
    //     tensorrt_infer_core::rosToOpenCV(*rgb_msg, rgb);
    //     if (rgb.empty() && detector_ == nullptr)
    //     {
    //         return;
    //     }
    //     // Run inference
    //     const auto objects = detector_->detect(rgb, params_);
    //     // Draw the bounding boxes on the image
    //     cv::Mat result = detector_->drawObjectLabels(rgb, objects, params_);
    //     cv::cvtColor(result, result, cv::COLOR_RGB2BGR);
    //     res_pub_->publish(*tensorrt_infer_core::openCVToRos(result));
    // }

} // namespace tensorrt_infer_core
