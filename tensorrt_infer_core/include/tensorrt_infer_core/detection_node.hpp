#pragma once
#include <tensorrt_inference/tensorrt_inference.h>

#include <filesystem>
#include <rcl_interfaces/msg/set_parameters_result.hpp>
#include <tensorrt_infer_core/conversions.hpp>
#include <tensorrt_infer_core/dynamic_params.hpp>

#include "rclcpp/rclcpp.hpp"
#include <realsense2_camera_msgs/msg/rgbd.hpp>
#include <std_msgs/msg/string.hpp>
#include <yaml-cpp/yaml.h>
namespace tensorrt_infer_core
{
    struct Params
    {
        Params() : model_name("yolov8x-seg"),
                   model_path(std::filesystem::path(std::string(std::getenv("HOME"))) / "data" / "weights")

        {
        }
        std::string model_name;
        std::filesystem::path model_path;
        std::vector<std::string> detected_class;
        tensorrt_inference::DetectionParams detect_params;
    };
    class DetectionNode : public rclcpp::Node
    {
    public:
        DetectionNode(const rclcpp::NodeOptions &options = rclcpp::NodeOptions(),
                      const std::string node_name = "detection_node");
        bool initModel(const std::string &model_name);
        void
        detect_rgbd_callback(const realsense2_camera_msgs::msg::RGBD::SharedPtr rgbd_msg) const;

        void
        detect_rgb_callback(const sensor_msgs::msg::Image::SharedPtr rgb_msg) const;

    private:
        rclcpp::Subscription<realsense2_camera_msgs::msg::RGBD>::SharedPtr rgbd_sub_;
        rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr rgb_sub_;

        std::shared_ptr<tensorrt_infer_core::Parameters> dynamic_params_;

        rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr res_pub_;

        std::shared_ptr<tensorrt_inference::Detection> detector_;
        Params params_;
    };

} // namespace tensorrt_infer_core
