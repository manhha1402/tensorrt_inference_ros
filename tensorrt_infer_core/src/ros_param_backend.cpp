
#include "tensorrt_infer_core/ros_param_backend.hpp"

namespace tensorrt_infer_core
{
void ParametersBackend::add_on_set_parameters_callback(ros2_param_callback_type callback)
{
  _ros_callback = _node.add_on_set_parameters_callback(callback);
}

ParametersBackend::~ParametersBackend()
{
  if (_ros_callback) {
    _node.remove_on_set_parameters_callback(
      (rclcpp::node_interfaces::OnSetParametersCallbackHandle *)(_ros_callback.get()));
    _ros_callback.reset();
  }
}
}  // namespace tensorrt_infer_core