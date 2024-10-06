#include <yaml-cpp/yaml.h>

#include <memory>
#include <tensorrt_infer_core/face_recognition_node.hpp>
using std::placeholders::_1;

namespace tensorrt_infer_core
{
    FaceRecognitionNode::FaceRecognitionNode(const rclcpp::NodeOptions &options,
                                             const std::string node_name)
        : Node(node_name, options)
    {
        // Declare parameters
        RCLCPP_INFO(get_logger(), "Creating tensorrt detection node");
        dynamic_params_ = std::make_shared<tensorrt_infer_core::Parameters>(*this);
        dynamic_params_->setParam<float>(
            "obj_thres", params_.obj_threshold, [this](const rclcpp::Parameter &parameter)
            { params_.obj_threshold = parameter.get_value<float>(); });

        dynamic_params_->setParam<float>(
            "nms_thres", params_.nms_threshold, [this](const rclcpp::Parameter &parameter)
            { params_.nms_threshold = parameter.get_value<float>(); });

        dynamic_params_->setParam<int>(
            "num_detect", params_.num_detect, [this](const rclcpp::Parameter &parameter)
            { params_.num_detect = parameter.get_value<int>(); });
        dynamic_params_->setParam<std::string>(
            "camera_topic", camera_topic_, [this](const rclcpp::Parameter &parameter)
            { camera_topic_ = parameter.get_value<std::string>(); });

        bool ret = initModel();
        res_pub_ = create_publisher<sensor_msgs::msg::Image>("face_recognition", 10);
        // rgbd_sub_ = this->create_subscription<realsense2_camera_msgs::msg::RGBD>(
        //     "/camera/camera/rgbd", 10,
        //     std::bind(&FaceRecognitionNode::detect_rgbd_callback, this, _1));

        rgb_sub_ = this->create_subscription<sensor_msgs::msg::Image>(
            camera_topic_.c_str(), 10,
            std::bind(&FaceRecognitionNode::detect_rgb_callback, this, _1));
    }

    bool FaceRecognitionNode::initModel()
    {

        detector_ = std::make_shared<tensorrt_inference::RetinaFace>("facedetector");
        recognizer_ = std::make_shared<tensorrt_inference::FaceRecognition>("FaceNet_vggface2_optmized");

        return true;
    }

    // void FaceRecognitionNode::detect_rgbd_callback(
    //     const realsense2_camera_msgs::msg::RGBD::SharedPtr rgbd_msg) const
    // {
    //     cv::Mat rgb;
    //     tensorrt_infer_core::rosToOpenCV(rgbd_msg->rgb, rgb);
    //     if (rgb.empty() && detector_ == nullptr)
    //     {
    //         return;
    //     }
    //     // Run inference
    //     const auto objects = detector_->detect(rgb, params_.detect_params, params_.detected_class);
    //     // Draw the bounding boxes on the image
    //     cv::Mat result = detector_->drawObjectLabels(rgb, objects, params_.detect_params);
    //     cv::cvtColor(result, result, cv::COLOR_RGB2BGR);
    //     res_pub_->publish(*tensorrt_infer_core::openCVToRos(result));
    // }

    void FaceRecognitionNode::detect_rgb_callback(
        const sensor_msgs::msg::Image::SharedPtr rgb_msg) const
    {
        cv::Mat rgb;
        tensorrt_infer_core::rosToOpenCV(*rgb_msg, rgb);
        if (rgb.empty() && detector_ == nullptr)
        {
            return;
        }
        // Run inference
        const auto objects = detector_->detect(rgb, params_);
        // Draw the bounding boxes on the image
        cv::Mat result = detector_->drawObjectLabels(rgb, objects, params_);
        cv::cvtColor(result, result, cv::COLOR_RGB2BGR);
        res_pub_->publish(*tensorrt_infer_core::openCVToRos(result));
    }

} // namespace tensorrt_infer_core
