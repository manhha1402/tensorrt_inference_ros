#pragma once
#include <tensorrt_inference/yolov8.h>

#include <filesystem>
#include <rcl_interfaces/msg/set_parameters_result.hpp>
#include <tensorrt_infer_core/conversions.hpp>
#include <tensorrt_infer_core/dynamic_params.hpp>

#include "rclcpp/rclcpp.hpp"
//#include "realsense2_camera_msgs/msg/rgbd.hpp"
#include <sensor_msgs/msg/image.hpp>
#include <std_msgs/msg/string.hpp>
namespace tensorrt_infer_core {
struct Params {
  Params() {}
  std::string model_name;
  std::filesystem::path model_path =
      std::filesystem::path(std::string(std::getenv("HOME"))) / "data" /
      "weights";
  std::vector<std::string> detected_class;
};
class DetectionNode : public rclcpp::Node {
public:
  DetectionNode(const rclcpp::NodeOptions &options = rclcpp::NodeOptions(),
                const std::string node_name = "detection_node");
  bool initModel(const std::string &model_name);

  // void detect_rgbd_callback(const
  // realsense2_camera_msgs::msg::RGBD::ConstSharedPtr & rgbd_msg);
  void
  detect_rgb_callback(const sensor_msgs::msg::Image::SharedPtr rgb_msg) const;
  void topic_callback(const std_msgs::msg::String::SharedPtr msg) const;

private:
  // rclcpp::Subscription<realsense2_camera_msgs::msg::RGBD>::SharedPtr
  // rgbd_sub_;
  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr rgb_sub_;
  std::shared_ptr<tensorrt_infer_core::Parameters> dynamic_params_;

  rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr res_pub_;

  tensorrt_inference::YoloV8Config yolo_config_;
  std::shared_ptr<tensorrt_inference::YoloV8> yolo8_;
  Params params_;

private:
  void initParameters();
};

} // namespace tensorrt_infer_core
