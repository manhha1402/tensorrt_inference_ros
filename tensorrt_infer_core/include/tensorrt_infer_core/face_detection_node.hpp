#pragma once
#include <tensorrt_inference/retinaface.h>
#include <filesystem>
#include <rcl_interfaces/msg/set_parameters_result.hpp>
#include <tensorrt_infer_core/conversions.hpp>
#include <tensorrt_infer_core/dynamic_params.hpp>

#include "rclcpp/rclcpp.hpp"
#include <sensor_msgs/msg/image.hpp>
#include <std_msgs/msg/string.hpp>
#include <yaml-cpp/yaml.h>
namespace tensorrt_infer_core
{
    struct Params
    {
        Params() : model_name("FaceDetector"),
                   model_path(std::filesystem::path(std::string(std::getenv("HOME"))) / "data" / "weights")

        {
        }
        std::string model_name;
        std::filesystem::path model_path;
        std::vector<std::string> detected_class;
        tensorrt_inference::DetectionParams detect_params;
    };
    class FaceDetectionNode : public rclcpp::Node
    {
    public:
        FaceDetectionNode(const rclcpp::NodeOptions &options = rclcpp::NodeOptions(),
                          const std::string node_name = "face_detection_node");
        bool initModel(const std::string &model_name);
        void
        detect_rgb_callback(const sensor_msgs::msg::Image::SharedPtr rgb_msg) const;

    private:
        rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr rgb_sub_;
        std::shared_ptr<tensorrt_infer_core::Parameters> dynamic_params_;

        rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr res_pub_;

        std::shared_ptr<tensorrt_inference::YoloV8> yolo8_;
        Params params_;
    };

} // namespace tensorrt_infer_core
