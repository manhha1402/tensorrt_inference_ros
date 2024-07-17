#include <tensorrt_infer_core/detection_node.hpp>
namespace tensorrt_infer_core
{
    DetectionNode::DetectionNode() : Node("image_sync_node")
    {
        // Create subscribers for depth and color topics
        depth_sub_.subscribe(this, "/camera/depth/image_raw");
        color_sub_.subscribe(this, "/camera/color/image_raw");

        // Synchronize the depth and color topics
        sync_.reset(new Sync(MySyncPolicy(10), depth_sub_, color_sub_));
        sync_->registerCallback(std::bind(&DetectionNode::detect_callback, this, std::placeholders::_1, std::placeholders::_2));
    }

    void DetectionNode::detect_callback(const sensor_msgs::msg::Image::ConstSharedPtr &depth_msg, const sensor_msgs::msg::Image::ConstSharedPtr &color_msg)
    {
        RCLCPP_INFO(this->get_logger(), "Synchronized depth and color messages received.");
        // Add your processing code here
        // Example: Print the timestamps
        RCLCPP_INFO(this->get_logger(), "Depth Timestamp: %d", depth_msg->header.stamp.sec);
        RCLCPP_INFO(this->get_logger(), "Color Timestamp: %d", color_msg->header.stamp.sec);
    }

}
