#pragma once
#include <tensorrt_inference/tensorrt_inference.h>
#include <filesystem>
#include <tensorrt_infer_core/conversions.hpp>
#include <tensorrt_infer_core/dynamic_params.hpp>
#include "rclcpp/rclcpp.hpp"
#include <realsense2_camera_msgs/msg/rgbd.hpp>
#include <std_msgs/msg/string.hpp>
#include <yaml-cpp/yaml.h>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <tensorrt_infer_msgs/msg/face_recognition.hpp>
namespace tensorrt_infer_core
{
    class FaceRecognitionNode : public rclcpp::Node
    {
    public:
        FaceRecognitionNode(const rclcpp::NodeOptions &options = rclcpp::NodeOptions(),
                            const std::string node_name = "face_recognition_node");
        void
        detect_rgbd_callback(const realsense2_camera_msgs::msg::RGBD::SharedPtr rgbd_msg) const;
        // void
        // detect_rgb_callback(const sensor_msgs::msg::Image::SharedPtr rgb_msg) const;

    private:
        rclcpp::Subscription<realsense2_camera_msgs::msg::RGBD>::SharedPtr rgbd_sub_;
        // rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr rgb_sub_;

        std::shared_ptr<tensorrt_infer_core::Parameters> dynamic_params_;

        rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr res_pub_;
        rclcpp::Publisher<tensorrt_infer_msgs::msg::FaceRecognition>::SharedPtr face_info_pub_;

        std::shared_ptr<tensorrt_inference::RetinaFace> detector_;
        std::shared_ptr<tensorrt_inference::FaceRecognition> recognizer_;

        tensorrt_inference::DetectionParams params_;
        std::string camera_topic_ = "/ros2_ipcamera/composition/image_raw";

    private:
        bool initModel();
        bool readFaceDatabase(const std::string &collection_id);
        Eigen::MatrixXd face_database_;
        /* data */
        std::string database_path_;
        std::string db_name_;

        mongocxx::client mongo_client_;
        mongocxx::instance mongo_instance_{};
    };

} // namespace tensorrt_infer_core
