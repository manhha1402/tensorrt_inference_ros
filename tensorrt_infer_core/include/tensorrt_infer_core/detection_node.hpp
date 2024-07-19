#pragma once
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "realsense2_camera_msgs/msg/rgbd.hpp"
#include <tensorrt_inference/yolov8.h>
#include <neura_scan_utils/conversions.hpp>
namespace tensorrt_infer_core
{
    class DetectionNode : public rclcpp::Node
    {
    public:
        DetectionNode();

    private:
        void detect_callback(const realsense2_camera_msgs::msg::RGBD::ConstSharedPtr &rgbd_msg);
        rclcpp::Subscription<realsense2_camera_msgs::msg::RGBD>::SharedPtr rgbd_sub_;
        rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr res_pub_;

        tensorrt_inference::YoloV8Config config_;
        std::shared_ptr<tensorrt_inference::YoloV8> yolo8_;
    };

}