#pragma once
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "realsense2_camera_msgs/msg/rgbd.hpp"
#include <tensorrt_inference/yolov8.h>
#include <neura_scan_utils/conversions.hpp>
#include <neura_scan_utils/dynamic_params.hpp>
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
    };
    class DetectionNode : public rclcpp::Node
    {
    public:
        DetectionNode();
        bool initModel(const std::string &model_name);

    private:
        void detect_callback(const realsense2_camera_msgs::msg::RGBD::ConstSharedPtr &rgbd_msg);
        rclcpp::Subscription<realsense2_camera_msgs::msg::RGBD>::SharedPtr rgbd_sub_;
        rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr res_pub_;

        tensorrt_inference::YoloV8Config yolo_config_;
        std::shared_ptr<tensorrt_inference::YoloV8> yolo8_;
        Params params_;
        std::shared_ptr<neura_scan_utils::Parameters> dynamic_params_;

    private:
        void initParameters();
    };

}