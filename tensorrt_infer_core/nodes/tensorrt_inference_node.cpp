

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

// #include "rclcpp/rclcpp.hpp"
// #include "rcl_interfaces/msg/set_parameters_result.hpp"
// class TestParamsCallback : public rclcpp::Node
// {
// public:
//   rcl_interfaces::msg::SetParametersResult parametersCallback(
//       const std::vector<rclcpp::Parameter> &parameters)
//   {
//     rcl_interfaces::msg::SetParametersResult result;
//     result.successful = true;
//     result.reason = "success";
//     for (const auto &param : parameters)
//     {
//       RCLCPP_INFO(this->get_logger(), "%s", param.get_name().c_str());
//       RCLCPP_INFO(this->get_logger(), "%s", param.get_type_name().c_str());
//       RCLCPP_INFO(this->get_logger(), "%s", param.value_to_string().c_str());
//     }
//     // Here update class attributes, do some actions, etc.
//     return result;
//   }
//   TestParamsCallback() : Node("test_params_rclcpp")
//   {
//     this->declare_parameter("motor_device_port", "/dev/ttyUSB0");
//     this->declare_parameter("control_loop_frequency", 100);
//     this->declare_parameter("simulation_mode", false);
//     motor_device_port_ = this->get_parameter("motor_device_port").as_string();
//     control_loop_frequency_ = this->get_parameter("control_loop_frequency").as_int();
//     simulation_mode_ = this->get_parameter("simulation_mode").as_bool();
//     callback_handle_ = this->add_on_set_parameters_callback(
//         std::bind(&TestParamsCallback::parametersCallback, this, std::placeholders::_1));
//   }

// private:
//   std::string motor_device_port_;
//   int control_loop_frequency_;
//   bool simulation_mode_;
//   OnSetParametersCallbackHandle::SharedPtr callback_handle_;
// };
// int main(int argc, char **argv)
// {
//   rclcpp::init(argc, argv);
//   auto node = std::make_shared<TestParamsCallback>();
//   rclcpp::spin(node);
//   rclcpp::shutdown();
//   return 0;
// }