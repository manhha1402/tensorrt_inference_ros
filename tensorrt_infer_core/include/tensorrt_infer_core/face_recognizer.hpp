#pragma once
#include <tensorrt_inference/tensorrt_inference.h>
#include <filesystem>
#include <tensorrt_infer_core/conversions.hpp>
#include <tensorrt_infer_core/dynamic_params.hpp>
#include <rclcpp/rclcpp.hpp>
#include <realsense2_camera_msgs/msg/rgbd.hpp>
#include <std_msgs/msg/string.hpp>
#include <yaml-cpp/yaml.h>
#include <tensorrt_infer_msgs/msg/face_recognition.hpp>
#include <tensorrt_infer_msgs/srv/face_database_info.hpp>
#include <tensorrt_infer_core/mongodb_client.hpp>
#include <tensorrt_infer_core/similarity.hpp>
namespace tensorrt_infer_core
{
    class FaceRecognizer : public rclcpp::Node
    {
    public:
        FaceRecognizer(const rclcpp::NodeOptions &options = rclcpp::NodeOptions(),
                       const std::string node_name = "face_recognition_node");
        void
        detect_rgbd_callback(const realsense2_camera_msgs::msg::RGBD::SharedPtr rgbd_msg) const;
        void
        detect_rgb_callback(const sensor_msgs::msg::Image::SharedPtr rgb_msg) const;

        void update_face_embeddings(
            const std::shared_ptr<tensorrt_infer_msgs::srv::FaceDatabaseInfo::Request> request,
            const std::shared_ptr<tensorrt_infer_msgs::srv::FaceDatabaseInfo::Response> response);

    private:
        rclcpp::Subscription<realsense2_camera_msgs::msg::RGBD>::SharedPtr rgbd_sub_;
        rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr rgb_sub_;
        // Get face embedding
        rclcpp::Service<tensorrt_infer_msgs::srv::FaceDatabaseInfo>::SharedPtr face_info_srv_;

        std::shared_ptr<tensorrt_infer_core::Parameters> dynamic_params_;
        rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr res_pub_;
        rclcpp::Publisher<tensorrt_infer_msgs::msg::FaceRecognition>::SharedPtr face_info_pub_;

        std::shared_ptr<tensorrt_inference::RetinaFace> detector_;
        std::shared_ptr<tensorrt_inference::FaceRecognition> recognizer_;

        tensorrt_inference::DetectionParams params_;
        float rec_cosine_thres_ = 0.7;
        float rec_l2_thres_ = 1.0;
        std::string distance_metric_ = "euclidean"; // euclidean
        std::string camera_topic_ = "/ros2_ipcamera/composition/image_raw";
        std::string rgbd_topic_ = "/camera/camera/rgbd";

    private:
        bool initModel();
        std::shared_ptr<MongoDBClient> mongodb_client_ptr_;
        std::map<std::string, std::vector<std::vector<double>>> embeddings_map_;
        int rec_width_;
        int rect_height_;
    };

} // namespace tensorrt_infer_core
