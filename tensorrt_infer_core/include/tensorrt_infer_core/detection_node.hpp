#pragma once
#include <tensorrt_inference/yolov8.h>

#include <rcl_interfaces/msg/set_parameters_result.hpp>
#include <tensorrt_infer_core/conversions.hpp>

#include "rclcpp/rclcpp.hpp"
#include "realsense2_camera_msgs/msg/rgbd.hpp"
#include "sensor_msgs/msg/image.hpp"
namespace tensorrt_infer_core
{
struct Params
{
  Params() {}
  std::string model_name;
  std::filesystem::path model_path =
    std::filesystem::path(std::string(std::getenv("HOME"))) / "data" / "weights";
  std::vector<std::string> detected_class;
};
class DetectionNode : public rclcpp::Node
{
public:
  DetectionNode();
  bool initModel(const std::string & model_name);

private:
  void detect_rgbd_callback(const realsense2_camera_msgs::msg::RGBD::ConstSharedPtr & rgbd_msg);
  void detect_rgb_callback(const sensor_msgs::msg::Image::ConstSharedPtr & rgb_msg);

  rclcpp::Subscription<realsense2_camera_msgs::msg::RGBD>::SharedPtr rgbd_sub_;
  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr rgb_sub_;

  rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr res_pub_;

  tensorrt_inference::YoloV8Config yolo_config_;
  std::shared_ptr<tensorrt_inference::YoloV8> yolo8_;
  Params params_;
  rcl_interfaces::msg::SetParametersResult parametersCallback(
    const std::vector<rclcpp::Parameter> & parameters);
  OnSetParametersCallbackHandle::SharedPtr callback_handle_;

private:
  void initParameters();
};

}  // namespace tensorrt_infer_core