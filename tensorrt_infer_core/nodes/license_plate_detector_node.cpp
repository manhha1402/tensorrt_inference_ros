

#include <iostream>
#include <rclcpp/rclcpp.hpp>
#include <tensorrt_infer_core/licence_plate_detector.hpp>
int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::executors::MultiThreadedExecutor executor;
  auto license_plate_detector = std::make_shared<tensorrt_infer_core::LicencePlateDetector>();
  executor.add_node(license_plate_detector);
  executor.spin();
  rclcpp::shutdown();

  return 0;
}
