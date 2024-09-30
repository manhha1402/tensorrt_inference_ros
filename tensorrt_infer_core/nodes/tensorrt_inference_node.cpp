

#include <iostream>
#include <rclcpp/rclcpp.hpp>
#include <tensorrt_infer_core/detection_node.hpp>
int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::executors::MultiThreadedExecutor executor;
  auto detection_node = std::make_shared<tensorrt_infer_core::DetectionNode>();
  executor.add_node(detection_node);
  executor.spin();
  rclcpp::shutdown();

  return 0;
}
