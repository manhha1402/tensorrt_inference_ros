#pragma once
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "message_filters/subscriber.h"
#include "message_filters/sync_policies/approximate_time.h"
#include "message_filters/synchronizer.h"

namespace tensorrt_infer_core
{
    class DetectionNode : public rclcpp::Node
    {
    public:
        DetectionNode();

    private:
        void detect_callback(const sensor_msgs::msg::Image::ConstSharedPtr &depth_msg, const sensor_msgs::msg::Image::ConstSharedPtr &color_msg);

        message_filters::Subscriber<sensor_msgs::msg::Image> depth_sub_;
        message_filters::Subscriber<sensor_msgs::msg::Image> color_sub_;
        typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::msg::Image, sensor_msgs::msg::Image> MySyncPolicy;
        typedef message_filters::Synchronizer<MySyncPolicy> Sync;
        std::shared_ptr<Sync> sync_;
    };

}