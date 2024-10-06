// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tensorrt_infer_msgs:msg/FaceRecognition.idl
// generated code does not contain a copyright notice

#ifndef TENSORRT_INFER_MSGS__MSG__DETAIL__FACE_RECOGNITION__TRAITS_HPP_
#define TENSORRT_INFER_MSGS__MSG__DETAIL__FACE_RECOGNITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tensorrt_infer_msgs/msg/detail/face_recognition__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace tensorrt_infer_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const FaceRecognition & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: timestamp
  {
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
    out << ", ";
  }

  // member: rec_score
  {
    out << "rec_score: ";
    rosidl_generator_traits::value_to_yaml(msg.rec_score, out);
    out << ", ";
  }

  // member: camera_id
  {
    out << "camera_id: ";
    rosidl_generator_traits::value_to_yaml(msg.camera_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FaceRecognition & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: timestamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
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

  // member: camera_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "camera_id: ";
    rosidl_generator_traits::value_to_yaml(msg.camera_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FaceRecognition & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace tensorrt_infer_msgs

namespace rosidl_generator_traits
{

[[deprecated("use tensorrt_infer_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tensorrt_infer_msgs::msg::FaceRecognition & msg,
  std::ostream & out, size_t indentation = 0)
{
  tensorrt_infer_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tensorrt_infer_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const tensorrt_infer_msgs::msg::FaceRecognition & msg)
{
  return tensorrt_infer_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tensorrt_infer_msgs::msg::FaceRecognition>()
{
  return "tensorrt_infer_msgs::msg::FaceRecognition";
}

template<>
inline const char * name<tensorrt_infer_msgs::msg::FaceRecognition>()
{
  return "tensorrt_infer_msgs/msg/FaceRecognition";
}

template<>
struct has_fixed_size<tensorrt_infer_msgs::msg::FaceRecognition>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tensorrt_infer_msgs::msg::FaceRecognition>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tensorrt_infer_msgs::msg::FaceRecognition>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TENSORRT_INFER_MSGS__MSG__DETAIL__FACE_RECOGNITION__TRAITS_HPP_
