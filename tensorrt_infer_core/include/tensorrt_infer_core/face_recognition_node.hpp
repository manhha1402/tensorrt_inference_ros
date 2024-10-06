#pragma once
#include <tensorrt_inference/tensorrt_inference.h>
#include <filesystem>
#include <tensorrt_infer_core/conversions.hpp>
#include <tensorrt_infer_core/dynamic_params.hpp>
#include "rclcpp/rclcpp.hpp"
#include <realsense2_camera_msgs/msg/rgbd.hpp>
#include <std_msgs/msg/string.hpp>
#include <yaml-cpp/yaml.h>
namespace tensorrt_infer_core
{
    class FaceRecognitionNode : public rclcpp::Node
    {
    public:
        FaceRecognitionNode(const rclcpp::NodeOptions &options = rclcpp::NodeOptions(),
                            const std::string node_name = "face_recognition_node");
        bool initModel();
        // void
        // detect_rgbd_callback(const realsense2_camera_msgs::msg::RGBD::SharedPtr rgbd_msg) const;

        void
        detect_rgb_callback(const sensor_msgs::msg::Image::SharedPtr rgb_msg) const;

    private:
        // rclcpp::Subscription<realsense2_camera_msgs::msg::RGBD>::SharedPtr rgbd_sub_;
        rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr rgb_sub_;

        std::shared_ptr<tensorrt_infer_core::Parameters> dynamic_params_;

        rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr res_pub_;

        std::shared_ptr<tensorrt_inference::RetinaFace> detector_;
        std::shared_ptr<tensorrt_inference::FaceRecognition> recognizer_;

        tensorrt_inference::DetectionParams params_;
        std::string camera_topic_ = "/ros2_ipcamera/composition/image_raw";
    };

} // namespace tensorrt_infer_core
