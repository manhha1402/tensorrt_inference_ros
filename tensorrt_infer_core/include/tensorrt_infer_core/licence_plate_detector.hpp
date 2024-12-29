#pragma once
#include <tensorrt_inference/tensorrt_inference.h>

#include <filesystem>
#include <rcl_interfaces/msg/set_parameters_result.hpp>
#include <tensorrt_infer_core/conversions.hpp>
#include <tensorrt_infer_core/dynamic_params.hpp>
#include "rclcpp/rclcpp.hpp"
#include <realsense2_camera_msgs/msg/rgbd.hpp>
#include <tensorrt_infer_msgs/srv/detect_licence_plate.hpp>
#include <std_msgs/msg/string.hpp>
#include <yaml-cpp/yaml.h>
namespace tensorrt_infer_core
{
    class LicencePlateDetector : public rclcpp::Node
    {
    public:
        LicencePlateDetector(const rclcpp::NodeOptions &options = rclcpp::NodeOptions(),
                             const std::string node_name = "licence_plate_detector");
        bool initModel();
        void
        detect_rgbd_callback(const realsense2_camera_msgs::msg::RGBD::SharedPtr rgbd_msg) const;

        void detectLicenePlateCallBack(const std::shared_ptr<rmw_request_id_t> request_header,
                                       const std::shared_ptr<tensorrt_infer_msgs::srv::DetectLicencePlate::Request> req,
                                       std::shared_ptr<tensorrt_infer_msgs::srv::DetectLicencePlate::Response> res);

    private:
        rclcpp::Subscription<realsense2_camera_msgs::msg::RGBD>::SharedPtr rgbd_sub_;
        std::shared_ptr<tensorrt_infer_core::Parameters> dynamic_params_;

        rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr res_pub_;
        rclcpp::Service<tensorrt_infer_msgs::srv::DetectLicencePlate>::SharedPtr detect_lp_srv_;

        rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_sub_;

        std::shared_ptr<tensorrt_inference::Detection> detector_;
        std::shared_ptr<tensorrt_inference::PaddleOCR> ocr_;
        tensorrt_inference::DetectionParams params_;
        float rec_score_ = 0.8;
        std::string camera_topic_ = "/camera/camera/color/image_raw";
        bool image_received_ = false;
        std::mutex image_mutex_;
        std::condition_variable cv_;
        sensor_msgs::msg::Image::SharedPtr last_image_;
    };

} // namespace tensorrt_infer_core
