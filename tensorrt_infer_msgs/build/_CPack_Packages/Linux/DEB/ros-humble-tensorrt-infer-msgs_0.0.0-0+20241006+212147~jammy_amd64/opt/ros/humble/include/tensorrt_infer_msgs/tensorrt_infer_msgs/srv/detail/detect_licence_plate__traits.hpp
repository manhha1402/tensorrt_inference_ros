// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tensorrt_infer_msgs:srv/DetectLicencePlate.idl
// generated code does not contain a copyright notice

#ifndef TENSORRT_INFER_MSGS__SRV__DETAIL__DETECT_LICENCE_PLATE__TRAITS_HPP_
#define TENSORRT_INFER_MSGS__SRV__DETAIL__DETECT_LICENCE_PLATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tensorrt_infer_msgs/srv/detail/detect_licence_plate__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace tensorrt_infer_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const DetectLicencePlate_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: topic_name
  {
    out << "topic_name: ";
    rosidl_generator_traits::value_to_yaml(msg.topic_name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DetectLicencePlate_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: topic_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "topic_name: ";
    rosidl_generator_traits::value_to_yaml(msg.topic_name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DetectLicencePlate_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace tensorrt_infer_msgs

namespace rosidl_generator_traits
{

[[deprecated("use tensorrt_infer_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tensorrt_infer_msgs::srv::DetectLicencePlate_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  tensorrt_infer_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tensorrt_infer_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const tensorrt_infer_msgs::srv::DetectLicencePlate_Request & msg)
{
  return tensorrt_infer_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tensorrt_infer_msgs::srv::DetectLicencePlate_Request>()
{
  return "tensorrt_infer_msgs::srv::DetectLicencePlate_Request";
}

template<>
inline const char * name<tensorrt_infer_msgs::srv::DetectLicencePlate_Request>()
{
  return "tensorrt_infer_msgs/srv/DetectLicencePlate_Request";
}

template<>
struct has_fixed_size<tensorrt_infer_msgs::srv::DetectLicencePlate_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tensorrt_infer_msgs::srv::DetectLicencePlate_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tensorrt_infer_msgs::srv::DetectLicencePlate_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace tensorrt_infer_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const DetectLicencePlate_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: plate_number
  {
    out << "plate_number: ";
    rosidl_generator_traits::value_to_yaml(msg.plate_number, out);
    out << ", ";
  }

  // member: det_core
  {
    out << "det_core: ";
    rosidl_generator_traits::value_to_yaml(msg.det_core, out);
    out << ", ";
  }

  // member: rec_score
  {
    out << "rec_score: ";
    rosidl_generator_traits::value_to_yaml(msg.rec_score, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DetectLicencePlate_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: plate_number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "plate_number: ";
    rosidl_generator_traits::value_to_yaml(msg.plate_number, out);
    out << "\n";
  }

  // member: det_core
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "det_core: ";
    rosidl_generator_traits::value_to_yaml(msg.det_core, out);
    out << "\n";
  }

  // member: rec_score
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rec_score: ";
    rosidl_generator_traits::value_to_yaml(msg.rec_score, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DetectLicencePlate_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace tensorrt_infer_msgs

namespace rosidl_generator_traits
{

[[deprecated("use tensorrt_infer_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tensorrt_infer_msgs::srv::DetectLicencePlate_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  tensorrt_infer_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tensorrt_infer_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const tensorrt_infer_msgs::srv::DetectLicencePlate_Response & msg)
{
  return tensorrt_infer_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tensorrt_infer_msgs::srv::DetectLicencePlate_Response>()
{
  return "tensorrt_infer_msgs::srv::DetectLicencePlate_Response";
}

template<>
inline const char * name<tensorrt_infer_msgs::srv::DetectLicencePlate_Response>()
{
  return "tensorrt_infer_msgs/srv/DetectLicencePlate_Response";
}

template<>
struct has_fixed_size<tensorrt_infer_msgs::srv::DetectLicencePlate_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tensorrt_infer_msgs::srv::DetectLicencePlate_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tensorrt_infer_msgs::srv::DetectLicencePlate_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tensorrt_infer_msgs::srv::DetectLicencePlate>()
{
  return "tensorrt_infer_msgs::srv::DetectLicencePlate";
}

template<>
inline const char * name<tensorrt_infer_msgs::srv::DetectLicencePlate>()
{
  return "tensorrt_infer_msgs/srv/DetectLicencePlate";
}

template<>
struct has_fixed_size<tensorrt_infer_msgs::srv::DetectLicencePlate>
  : std::integral_constant<
    bool,
    has_fixed_size<tensorrt_infer_msgs::srv::DetectLicencePlate_Request>::value &&
    has_fixed_size<tensorrt_infer_msgs::srv::DetectLicencePlate_Response>::value
  >
{
};

template<>
struct has_bounded_size<tensorrt_infer_msgs::srv::DetectLicencePlate>
  : std::integral_constant<
    bool,
    has_bounded_size<tensorrt_infer_msgs::srv::DetectLicencePlate_Request>::value &&
    has_bounded_size<tensorrt_infer_msgs::srv::DetectLicencePlate_Response>::value
  >
{
};

template<>
struct is_service<tensorrt_infer_msgs::srv::DetectLicencePlate>
  : std::true_type
{
};

template<>
struct is_service_request<tensorrt_infer_msgs::srv::DetectLicencePlate_Request>
  : std::true_type
{
};

template<>
struct is_service_response<tensorrt_infer_msgs::srv::DetectLicencePlate_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TENSORRT_INFER_MSGS__SRV__DETAIL__DETECT_LICENCE_PLATE__TRAITS_HPP_
