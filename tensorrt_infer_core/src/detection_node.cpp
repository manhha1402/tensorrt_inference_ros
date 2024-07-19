#include <tensorrt_infer_core/detection_node.hpp>
#include <memory>
using std::placeholders::_1;

namespace tensorrt_infer_core
{
    DetectionNode::DetectionNode() : Node("detection_node")
    {

        const std::string home_dir = std::getenv("HOME");
        const std::string onnx_path = home_dir + "/data/weights/yolov8x-seg.onnx";
        yolo8_ = std::make_shared<tensorrt_inference::YoloV8>(onnx_path, config_);
        res_pub_ = create_publisher<sensor_msgs::msg::Image>("yolo_image", 10);
        rgbd_sub_ = create_subscription<realsense2_camera_msgs::msg::RGBD>(
            "/camera/camera/rgbd", 10, std::bind(&DetectionNode::detect_callback, this, _1));
    }

    void DetectionNode::detect_callback(const realsense2_camera_msgs::msg::RGBD::ConstSharedPtr &rgbd_msg)
    {
        cv::Mat rgb, depth;
        neura_scan_utils::conversions::rosToOpenCV(rgbd_msg->rgb, rgb);
        neura_scan_utils::conversions::rosToOpenCV(rgbd_msg->depth, depth);
        if (rgb.empty())
        {
            return;
        }
        // Run inference
        const auto objects = yolo8_->detectObjects(rgb);
        // Draw the bounding boxes on the image
        yolo8_->drawObjectLabels(rgb, objects);
        sensor_msgs::msg::Image::SharedPtr out_image_msg = neura_scan_utils::conversions::openCVToRos(rgb);
        res_pub_->publish(*out_image_msg);
    }

}
