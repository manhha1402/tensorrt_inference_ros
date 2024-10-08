#include <yaml-cpp/yaml.h>

#include <memory>
#include <tensorrt_infer_core/face_recognition_node.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
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
        const std::string collection_id = "face";
        if (!readFaceDatabase(collection_id))
        {
            throw std::runtime_error("Initilization failed");
        }
        res_pub_ = create_publisher<sensor_msgs::msg::Image>("face_recognition_image", 10);
        face_info_pub_ = create_publisher<tensorrt_infer_msgs::msg::FaceRecognition>("face_info", 10);
        rgbd_sub_ = this->create_subscription<realsense2_camera_msgs::msg::RGBD>(
            "/camera/camera/rgbd", 10,
            std::bind(&FaceRecognitionNode::detect_rgbd_callback, this, _1));

        // rgb_sub_ = this->create_subscription<sensor_msgs::msg::Image>(
        //     camera_topic_.c_str(), 10,
        //     std::bind(&FaceRecognitionNode::detect_rgb_callback, this, _1));
    }

    bool FaceRecognitionNode::readFaceDatabase(const std::string &collection_id)
    {

        detector_ = std::make_shared<tensorrt_inference::RetinaFace>("facedetector");
        recognizer_ = std::make_shared<tensorrt_inference::FaceRecognition>("FaceNet_vggface2_optmized");
        mongocxx::database db = mongo_client_[db_name_];
        mongocxx::collection collection = db[collection_id];
        // get all documents in collection
        auto cursor_all = collection.find({});

        // build json string array with all documents
        std::string tools_array_str = "[";
        bool first_document = true;
        for (auto doc : cursor_all)
        {
            if (!first_document)
            {
                tools_array_str += ",";
            }
            // std::cout << bsoncxx::to_json(doc, bsoncxx::ExtendedJsonMode::k_relaxed) << std::endl;
            tools_array_str += std::string(bsoncxx::to_json(doc, bsoncxx::ExtendedJsonMode::k_relaxed));
            first_document = false;
        }
        tools_array_str += "]";
        return true;
    }

    void FaceRecognitionNode::detect_rgbd_callback(
        const realsense2_camera_msgs::msg::RGBD::SharedPtr rgbd_msg) const
    {
        cv::Mat rgb;
        tensorrt_infer_core::rosToOpenCV(rgbd_msg->rgb, rgb);
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

    // void FaceRecognitionNode::detect_rgb_callback(
    //     const sensor_msgs::msg::Image::SharedPtr rgb_msg) const
    // {
    //     cv::Mat rgb;
    //     tensorrt_infer_core::rosToOpenCV(*rgb_msg, rgb);
    //     if (rgb.empty() && detector_ == nullptr)
    //     {
    //         return;
    //     }
    //     // Run inference
    //     const auto objects = detector_->detect(rgb, params_);
    //     // Draw the bounding boxes on the image
    //     cv::Mat result = detector_->drawObjectLabels(rgb, objects, params_);
    //     cv::cvtColor(result, result, cv::COLOR_RGB2BGR);
    //     res_pub_->publish(*tensorrt_infer_core::openCVToRos(result));
    // }

} // namespace tensorrt_infer_core
