#include <tensorrt_infer_core/conversions.hpp>
namespace tensorrt_infer_core
{
void rosToOpenCV(const sensor_msgs::msg::Image & msg_image, cv::Mat & cv_image)
{
  cv_image.release();
  if (msg_image.encoding == "rgb8" || msg_image.encoding == "bgr8") {
    cv_image = cv::Mat(msg_image.height, msg_image.width, CV_8UC3);
  } else if (msg_image.encoding == "16UC1") {
    cv_image = cv::Mat(msg_image.height, msg_image.width, CV_16UC1);
  } else if (msg_image.encoding == "mono8") {
    cv_image = cv::Mat(msg_image.height, msg_image.width, CV_8UC1);
  } else if (msg_image.encoding == "8UC1") {
    cv_image = cv::Mat(msg_image.height, msg_image.width, CV_8UC1);
  } else if (msg_image.encoding == "32FC1") {
    cv_image = cv::Mat(msg_image.height, msg_image.width, CV_32FC1);
  } else {
    RCLCPP_ERROR(
      rclcpp::get_logger("rclcpp"), "[rosToOpenCV] Unsupported image format %s ",
      msg_image.encoding);
    return;
  }
  size_t size = msg_image.step * cv_image.rows;
  // assume image is continuous
  memcpy((char *)(&cv_image.data[0]), msg_image.data.data(), size);
  if (msg_image.encoding == "rgb8") {
    cv::cvtColor(cv_image, cv_image, cv::COLOR_BGR2RGB);
  }
  if (msg_image.encoding == "bgra8") {
    cv::cvtColor(cv_image, cv_image, cv::COLOR_BGRA2RGB);
  }
  if (msg_image.encoding == "rgba8") {
    cv::cvtColor(cv_image, cv_image, cv::COLOR_RGBA2RGB);
  }
}
cv::Mat rosToOpenCV(const sensor_msgs::msg::Image::SharedPtr & msg_image)
{
  cv::Mat image;
  rosToOpenCV(*msg_image, image);
  return image;
}

sensor_msgs::msg::Image::SharedPtr openCVToRos(const cv::Mat & cv_image)
{
  sensor_msgs::msg::Image::SharedPtr ptr = std::make_shared<sensor_msgs::msg::Image>();
  openCVToRos(cv_image, *ptr);
  return ptr;
}
void openCVToRos(const cv::Mat & cv_image, sensor_msgs::msg::Image & msg_image)
{
  if (cv_image.empty()) {
    return;
  }
  if (cv_image.channels() == 3 && cv_image.type() == CV_8UC3) {
    msg_image.encoding = "rgb8";
  } else if (cv_image.channels() == 1 && cv_image.type() == CV_16UC1) {
    msg_image.encoding = "mono16";
  } else {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "[openCVToRos] Unsupported image format.");
    return;
  }
  msg_image.width = cv_image.cols;
  msg_image.height = cv_image.rows;
  msg_image.step = cv_image.cols * cv_image.elemSize();
  size_t size = msg_image.step * cv_image.rows;
  msg_image.data.resize(size);
  msg_image.is_bigendian = (boost::endian::order::native == boost::endian::order::big);
  // assume image is continuous
  memcpy((char *)(&msg_image.data[0]), cv_image.data, size);
}

}  // namespace tensorrt_infer_core