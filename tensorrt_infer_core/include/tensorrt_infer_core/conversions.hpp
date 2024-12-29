#pragma once

// OpenCV
#include <opencv2/opencv.hpp>
#include <sensor_msgs/msg/camera_info.hpp>
#include <sensor_msgs/msg/image.hpp>
// Eigen
#include <Eigen/Dense>
#include <boost/endian/conversion.hpp>
#include <rclcpp/rclcpp.hpp>

// C++
#include <string>

namespace tensorrt_infer_core {
void rosToOpenCV(const sensor_msgs::msg::Image &msg_image, cv::Mat &cv_image);
cv::Mat rosToOpenCV(const sensor_msgs::msg::Image::SharedPtr &msg_image);
sensor_msgs::msg::Image::SharedPtr openCVToRos(const cv::Mat &cv_image);
void openCVToRos(const cv::Mat &cv_image, sensor_msgs::msg::Image &msg_image);
} // namespace tensorrt_infer_core