#include <yaml-cpp/yaml.h>

#include <memory>
#include <tensorrt_infer_core/detection_node.hpp>
using std::placeholders::_1;

namespace tensorrt_infer_core
{
    DetectionNode::DetectionNode(const rclcpp::NodeOptions &options,
                                 const std::string node_name)
        : Node(node_name, options)
    {
        // Declare parameters
        RCLCPP_INFO(get_logger(), "Creating tensorrt detection node");
        dynamic_params_ = std::make_shared<tensorrt_infer_core::Parameters>(*this);
        dynamic_params_->setParam<float>(
            "obj_thres", params_.detect_params.obj_threshold, [this](const rclcpp::Parameter &parameter)
            { params_.detect_params.obj_threshold = parameter.get_value<float>(); });

        dynamic_params_->setParam<float>(
            "nms_thres", params_.detect_params.nms_threshold, [this](const rclcpp::Parameter &parameter)
            { params_.detect_params.nms_threshold = parameter.get_value<float>(); });

        dynamic_params_->setParam<float>(
            "seg_thres", params_.detect_params.seg_threshold, [this](const rclcpp::Parameter &parameter)
            { params_.detect_params.seg_threshold = parameter.get_value<float>(); });

        dynamic_params_->setParam<float>(
            "kps_thresh", params_.detect_params.kps_threshold, [this](const rclcpp::Parameter &parameter)
            { params_.detect_params.kps_threshold = parameter.get_value<float>(); });

        dynamic_params_->setParam<int>(
            "num_detect", params_.detect_params.num_detect, [this](const rclcpp::Parameter &parameter)
            { params_.detect_params.num_detect = parameter.get_value<int>(); });

        dynamic_params_->setParam<std::vector<std::string>>(
            "detected_class", params_.detected_class, [this](const rclcpp::Parameter &parameter)
            { params_.detected_class = parameter.get_value<std::vector<std::string>>();
            if (params_.detected_class.size() == 1 && params_.detected_class[0].compare("all") == 0)
                {
                    params_.detected_class.clear();
                } });

        dynamic_params_->setParam<std::string>(
            "model_name", params_.model_name, [this](const rclcpp::Parameter &parameter)
            {
                params_.model_name = parameter.get_value<std::string>();
                bool ret = initModel(params_.model_name);
                // detect all classes again
                params_.detected_class.clear(); });
        bool ret = initModel(params_.model_name);
        res_pub_ = create_publisher<sensor_msgs::msg::Image>("tensorrt_result", 10);
        rgbd_sub_ = this->create_subscription<realsense2_camera_msgs::msg::RGBD>(
            "/camera/camera/rgbd", 10,
            std::bind(&DetectionNode::detect_rgbd_callback, this, _1));
    }

    bool DetectionNode::initModel(const std::string &model_name)
    {

        // config_.classNames
        if (model_name.find("yolov8") != std::string::npos)
        {
            detector_ = std::make_shared<tensorrt_inference::YoloV8>(model_name);
        }
        else if (model_name.find("yolov9") != std::string::npos)
        {
            detector_ = std::make_shared<tensorrt_inference::YoloV9>(model_name);
        }
        else if (model_name.find("face") != std::string::npos)
        {
            detector_ = std::make_shared<tensorrt_inference::RetinaFace>(model_name);
        }
        else if (model_name.find("plate_detection") != std::string::npos)
        {
            detector_ = std::make_shared<tensorrt_inference::YoloV8>(model_name);
        }
        else
        {
            std::cout << "unkown model" << std::endl;
            return false;
        }
        return true;
    }

    void DetectionNode::detect_rgbd_callback(
        const realsense2_camera_msgs::msg::RGBD::SharedPtr rgbd_msg) const
    {
        cv::Mat rgb;
        tensorrt_infer_core::rosToOpenCV(rgbd_msg->rgb, rgb);
        if (rgb.empty() && detector_ == nullptr)
        {
            return;
        }
        // Run inference
        const auto objects = detector_->detect(rgb, params_.detect_params, params_.detected_class);
        // Draw the bounding boxes on the image
        cv::Mat result = detector_->drawObjectLabels(rgb, objects, params_.detect_params);
        cv::cvtColor(result, result, cv::COLOR_RGB2BGR);
        res_pub_->publish(*tensorrt_infer_core::openCVToRos(result));
    }

} // namespace tensorrt_infer_core
