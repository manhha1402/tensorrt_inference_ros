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
            "prob_thres", yolo_config_.prob_thres, [this](const rclcpp::Parameter &parameter)
            { yolo_config_.prob_thres = parameter.get_value<float>(); });

        dynamic_params_->setParam<float>(
            "nms_thres", yolo_config_.nms_thres, [this](const rclcpp::Parameter &parameter)
            { yolo_config_.nms_thres = parameter.get_value<float>(); });

        dynamic_params_->setParam<int>(
            "top_k", yolo_config_.top_k, [this](const rclcpp::Parameter &parameter)
            { yolo_config_.top_k = parameter.get_value<int>(); });

        dynamic_params_->setParam<int>(
            "seg_channels", yolo_config_.seg_channels, [this](const rclcpp::Parameter &parameter)
            { yolo_config_.seg_channels = parameter.get_value<int>(); });

        dynamic_params_->setParam<int>(
            "seg_w", yolo_config_.seg_w, [this](const rclcpp::Parameter &parameter)
            { yolo_config_.seg_w = parameter.get_value<int>(); });

        dynamic_params_->setParam<int>(
            "seg_h", yolo_config_.seg_h, [this](const rclcpp::Parameter &parameter)
            { yolo_config_.seg_h = parameter.get_value<int>(); });

        dynamic_params_->setParam<float>(
            "segmentation_thres", yolo_config_.segmentation_thres, [this](const rclcpp::Parameter &parameter)
            { yolo_config_.segmentation_thres = parameter.get_value<float>(); });

        dynamic_params_->setParam<int>(
            "num_kps", yolo_config_.num_kps, [this](const rclcpp::Parameter &parameter)
            { yolo_config_.num_kps = parameter.get_value<int>(); });

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
        res_pub_ = create_publisher<sensor_msgs::msg::Image>("yolo_image", 10);
        rgb_sub_ = this->create_subscription<sensor_msgs::msg::Image>(
            "/tapo1/color/image_raw", 10,
            std::bind(&DetectionNode::detect_rgb_callback, this, _1));
    }

    bool DetectionNode::initModel(const std::string &model_name)
    {
        // Load config file
        std::string model_config_file = (params_.model_path / model_name / (model_name + ".yaml")).string();
        YAML::Node config = YAML::LoadFile(model_config_file);
        if (config.size() > 0)
        {
            yolo_config_.class_names.clear();
            for (size_t i = 0; i < config.size(); i++)
            {
                yolo_config_.class_names.push_back(config[i].as<std::string>());
            }
        }
        // config_.classNames
        yolo8_ = std::make_shared<tensorrt_inference::YoloV8>(params_.model_path.string(), model_name, yolo_config_);
        return true;
    }

    void DetectionNode::detect_rgb_callback(
        const sensor_msgs::msg::Image::SharedPtr rgb_msg) const
    {
        cv::Mat rgb;
        tensorrt_infer_core::rosToOpenCV(*rgb_msg, rgb);
        if (rgb.empty() && yolo8_ == nullptr)
        {
            return;
        }
        // Run inference
        const auto objects = yolo8_->detectObjects(rgb);
        // Draw the bounding boxes on the image
        yolo8_->drawObjectLabels(rgb, objects, params_.detected_class);
        res_pub_->publish(*tensorrt_infer_core::openCVToRos(rgb));
    }

} // namespace tensorrt_infer_core
