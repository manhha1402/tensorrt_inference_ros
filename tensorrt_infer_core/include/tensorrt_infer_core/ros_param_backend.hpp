
#pragma once
#include <rclcpp/rclcpp.hpp>

namespace tensorrt_infer_core
{
  class ParametersBackend
  {
  public:
    ParametersBackend(rclcpp::Node &node) : _node(node), _logger(node.get_logger()) {}
    ~ParametersBackend();

#if defined(RCLCPP_HAS_OnSetParametersCallbackType)
    using ros2_param_callback_type =
        rclcpp::node_interfaces::NodeParametersInterface::OnSetParametersCallbackType;
#else
    using ros2_param_callback_type =
        rclcpp::node_interfaces::NodeParametersInterface::OnParametersSetCallbackType;
#endif

    void add_on_set_parameters_callback(ros2_param_callback_type callback);

  private:
    rclcpp::Node &_node;
    rclcpp::Logger _logger;
    std::shared_ptr<void> _ros_callback;
  };
} // namespace tensorrt_infer_core