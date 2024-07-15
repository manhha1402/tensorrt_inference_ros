

#include <tensorrt_inference/yolov8.h>

#include <iostream>
#include <rclcpp/rclcpp.hpp>
int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  tensorrt_inference::YoloV8Config config;
  std::string onnxModelPath;
  std::string inputImage;

  // Create the YoloV8 engine
  //tensorrt_inference::YoloV8 yoloV8(onnxModelPath, config);

  return 0;
}
