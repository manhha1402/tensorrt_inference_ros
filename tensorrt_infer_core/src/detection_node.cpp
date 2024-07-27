#include <yaml-cpp/yaml.h>

#include <memory>
#include <tensorrt_infer_core/detection_node.hpp>

namespace tensorrt_infer_core
{
DetectionNode::DetectionNode() : Node("tensorrt_inference_node")
{
  // Declare parameters
  RCLCPP_INFO(get_logger(), "Creating tensorrt detection node");
  declare_parameter("prob_thres", yolo_config_.prob_thres);
  declare_parameter("nms_thres", yolo_config_.prob_thres);
  declare_parameter("top_k", yolo_config_.top_k);
  declare_parameter("seg_channels", yolo_config_.seg_channels);
  declare_parameter("seg_w", yolo_config_.seg_w);
  declare_parameter("seg_h", yolo_config_.seg_h);
  declare_parameter("segmentation_thres", yolo_config_.segmentation_thres);
  declare_parameter("num_kps", yolo_config_.num_kps);
  declare_parameter("kps_thres", yolo_config_.kps_thres);
  declare_parameter("detected_class", params_.detected_class);
  declare_parameter("model_name", params_.model_name);
  initParameters();

  // Declare parameters
  RCLCPP_INFO(get_logger(), "Creating tensorrt detection node");
  // declare_parameter("prob_thres", yolo_config_.prob_thres);
  // declare_parameter("nms_thres", yolo_config_.nms_thres);
  // declare_parameter("top_k", yolo_config_.top_k);
  // declare_parameter("seg_channels", yolo_config_.seg_channels);
  // declare_parameter("seg_w", yolo_config_.seg_w);
  // declare_parameter("seg_h", yolo_config_.seg_h);
  // declare_parameter("segmentation_thres", yolo_config_.segmentation_thres);
  // declare_parameter("num_kps", yolo_config_.num_kps);
  // declare_parameter("kps_thres", yolo_config_.kps_thres);
  // declare_parameter("detected_class", params_.detected_class);
  // declare_parameter("model_name", params_.model_name);
  // initParameters();
  rcl_interfaces::msg::ParameterDescriptor crnt_descriptor;
  dynamic_params_ = std::make_shared<neura_scan_utils::Parameters>(*this);
  dynamic_params_->setParam<float>(
    "prob_thres", yolo_config_.prob_thres, [this](const rclcpp::Parameter & parameter) {
      yolo_config_.prob_thres = parameter.get_value<float>();
    });

  dynamic_params_->setParam<float>(
    "nms_thres", yolo_config_.nms_thres, [this](const rclcpp::Parameter & parameter) {
      yolo_config_.nms_thres = parameter.get_value<float>();
    });

  dynamic_params_->setParam<int>(
    "top_k", yolo_config_.top_k, [this](const rclcpp::Parameter & parameter) {
      yolo_config_.top_k = parameter.get_value<int>();
    });

  dynamic_params_->setParam<int>(
    "seg_channels", yolo_config_.seg_channels, [this](const rclcpp::Parameter & parameter) {
      yolo_config_.seg_channels = parameter.get_value<int>();
    });

  dynamic_params_->setParam<int>(
    "seg_w", yolo_config_.seg_w, [this](const rclcpp::Parameter & parameter) {
      yolo_config_.seg_w = parameter.get_value<int>();
    });

  dynamic_params_->setParam<int>(
    "seg_h", yolo_config_.seg_h, [this](const rclcpp::Parameter & parameter) {
      yolo_config_.seg_h = parameter.get_value<int>();
    });

  dynamic_params_->setParam<float>(
    "segmentation_thres", yolo_config_.segmentation_thres,
    [this](const rclcpp::Parameter & parameter) {
      yolo_config_.segmentation_thres = parameter.get_value<float>();
    });

  dynamic_params_->setParam<int>(
    "num_kps", yolo_config_.num_kps, [this](const rclcpp::Parameter & parameter) {
      yolo_config_.num_kps = parameter.get_value<int>();
    });

  dynamic_params_->setParam<std::vector<std::string>>(
    "detected_class", params_.detected_class, [this](const rclcpp::Parameter & parameter) {
      params_.detected_class = parameter.get_value<std::vector<std::string>>();
    });

  bool ret = initModel(params_.model_name);
  res_pub_ = create_publisher<sensor_msgs::msg::Image>("yolo_image", 10);
  rgbd_sub_ = create_subscription<realsense2_camera_msgs::msg::RGBD>(
    "/camera/camera/rgbd", 10,
    std::bind(&DetectionNode::detect_callback, this, std::placeholders::_1));
}
void DetectionNode::initParameters()
{
  // Declare parameters
  get_parameter_or("prob_thres", yolo_config_.prob_thres, yolo_config_.prob_thres);
  get_parameter_or("nms_thres", yolo_config_.nms_thres, yolo_config_.nms_thres);
  get_parameter_or("top_k", yolo_config_.top_k, yolo_config_.top_k);
  get_parameter_or("seg_channels", yolo_config_.seg_channels, yolo_config_.seg_channels);
  get_parameter_or("seg_w", yolo_config_.seg_w, yolo_config_.seg_w);
  get_parameter_or("seg_h", yolo_config_.seg_h, yolo_config_.seg_h);
  get_parameter_or(
    "segmentation_thres", yolo_config_.segmentation_thres, yolo_config_.segmentation_thres);
  get_parameter_or("num_kps", yolo_config_.num_kps, yolo_config_.num_kps);
  get_parameter_or("kps_thres", yolo_config_.kps_thres, yolo_config_.kps_thres);
  get_parameter_or("detected_class", params_.detected_class, params_.detected_class);
  get_parameter_or("model_name", params_.model_name, params_.model_name);

  if (params_.detected_class.size() == 1 && params_.detected_class[0].compare("all") == 0) {
    params_.detected_class.clear();
  }
  RCLCPP_INFO(get_logger(), "initParameters done!");
}
rcl_interfaces::msg::SetParametersResult DetectionNode::parametersCallback(
  const std::vector<rclcpp::Parameter> & parameters)
{
  RCLCPP_INFO(get_logger(), "parameters callback");
  rcl_interfaces::msg::SetParametersResult result;
  result.successful = false;
  result.reason = "";
  for (const auto & param : parameters) {
    if (param.get_name() == "detected_class") {
      if (param.get_type() == rclcpp::ParameterType::PARAMETER_STRING_ARRAY) {
        std::cout << "detected_class changed" << std::endl;
        if (param.as_string_array().size() == 1 && param.as_string_array()[0].compare("all") == 0) {
          params_.detected_class.clear();
        } else {
          n params_.detected_class = param.as_string_array();
        }
        result.successful = true;
      }
    }
    // rcl_interfaces::msg::SetParametersResult DetectionNode::parametersCallback(
    //     const std::vector<rclcpp::Parameter> &parameters)
    // {
    //     RCLCPP_INFO(get_logger(), "parameters callback");
    //     rcl_interfaces::msg::SetParametersResult result;
    //     result.successful = false;
    //     result.reason = "";
    //     for (const auto &param : parameters)
    //     {
    //         if (param.get_name() == "detected_class")
    //         {
    //             if (param.get_type() == rclcpp::ParameterType::PARAMETER_STRING_ARRAY)
    //             {
    //                 std::cout << "detected_class changed" << std::endl;
    //                 if (param.as_string_array().size() == 1 && param.as_string_array()[0].compare("all") == 0)
    //                 {
    //                     params_.detected_class.clear();
    //                 }
    //                 else
    //                 {
    //                     params_.detected_class = param.as_string_array();
    //                 }
    //                 result.successful = true;
    //             }
    //         }
    //         if (param.get_name() == "model_name")
    //         {
    //             if (param.get_type() == rclcpp::ParameterType::PARAMETER_STRING)
    //             {
    //                 std::cout << "model name changed, init model" << std::endl;
    //                 params_.model_name = param.as_string();
    //                 bool ret = initModel(params_.model_name);
    //                 // detect all classes again
    //                 params_.detected_class.clear();
    //                 result.successful = true;
    //             }
    //         }
    //         if (param.get_name() == "prob_thres")
    //         {
    //             if (param.get_type() == rclcpp::ParameterType::PARAMETER_DOUBLE)
    //             {
    //                 std::cout << "prob_thres changed" << std::endl;
    //                 yolo_config_.prob_thres = param.as_double();
    //                 result.successful = true;
    //             }
    //         }
    //     }

    //     return result;
    // }
    bool DetectionNode::initModel(const std::string & model_name)
    {
      // Load config file
      std::string model_config_file =
        (params_.model_path / model_name / (model_name + ".yaml")).string();
      YAML::Node config = YAML::LoadFile(model_config_file);
      if (config.size() > 0) {
        yolo_config_.class_names.clear();
        for (size_t i = 0; i < config.size(); i++) {
          yolo_config_.class_names.push_back(config[i].as<std::string>());
        }
      }
      // config_.classNames
      yolo8_ = std::make_shared<tensorrt_inference::YoloV8>(
        params_.model_path.string(), model_name, yolo_config_);
      return true;
    }
  }

  return result;
}
bool DetectionNode::initModel(const std::string & model_name)
{
  // Load config file
  std::string model_config_file =
    (params_.model_path / model_name / (model_name + ".yaml")).string();
  YAML::Node config = YAML::LoadFile(model_config_file);
  if (config.size() > 0) {
    yolo_config_.class_names.clear();
    for (size_t i = 0; i < config.size(); i++) {
      yolo_config_.class_names.push_back(config[i].as<std::string>());
    }
  }
  // config_.classNames
  yolo8_ = std::make_shared<tensorrt_inference::YoloV8>(
    params_.model_path.string(), model_name, yolo_config_);
  return true;
}

void DetectionNode::detect_rgbd_callback(
  const realsense2_camera_msgs::msg::RGBD::ConstSharedPtr & rgbd_msg)
{
  cv::Mat rgb, depth;
  tensorrt_infer_core::rosToOpenCV(rgbd_msg->rgb, rgb);
  tensorrt_infer_core::rosToOpenCV(rgbd_msg->depth, depth);
  if (rgb.empty() && yolo8_ == nullptr) {
    return;
  }
  // Run inference
  const auto objects = yolo8_->detectObjects(rgb);
  // Draw the bounding boxes on the image
  yolo8_->drawObjectLabels(rgb, objects, params_.detected_class);
  res_pub_->publish(*tensorrt_infer_core::openCVToRos(rgb));
}

void DetectionNode::detect_rgb_callback(const sensor_msgs::msg::Image::ConstSharedPtr & rgb_msg)
{
  cv::Mat rgb, depth;
  tensorrt_infer_core::rosToOpenCV(rgbd_msg->rgb, rgb);
  if (rgb.empty() && yolo8_ == nullptr) {
    return;
  }
  // Run inference
  const auto objects = yolo8_->detectObjects(rgb);
  // Draw the bounding boxes on the image
  yolo8_->drawObjectLabels(rgb, objects, params_.detected_class);
  res_pub_->publish(*tensorrt_infer_core::openCVToRos(rgb));
}

}  // namespace tensorrt_infer_core
