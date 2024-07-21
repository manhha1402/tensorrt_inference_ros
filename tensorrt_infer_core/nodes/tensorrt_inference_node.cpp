

#include <iostream>
#include <rclcpp/rclcpp.hpp>
#include <tensorrt_infer_core/detection_node.hpp>
int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<tensorrt_infer_core::DetectionNode>());
  rclcpp::shutdown();

  return 0;
}
