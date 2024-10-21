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

// Include directives for member types
// Member 'cropped_faces'
#include "sensor_msgs/msg/detail/image__traits.hpp"

namespace tensorrt_infer_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const FaceRecognition & msg,
  std::ostream & out)
{
  out << "{";
  // member: user_ids
  {
    if (msg.user_ids.size() == 0) {
      out << "user_ids: []";
    } else {
      out << "user_ids: [";
      size_t pending_items = msg.user_ids.size();
      for (auto item : msg.user_ids) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: camera_id
  {
    out << "camera_id: ";
    rosidl_generator_traits::value_to_yaml(msg.camera_id, out);
    out << ", ";
  }

  // member: timestamp
  {
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
    out << ", ";
  }

  // member: rec_scores
  {
    if (msg.rec_scores.size() == 0) {
      out << "rec_scores: []";
    } else {
      out << "rec_scores: [";
      size_t pending_items = msg.rec_scores.size();
      for (auto item : msg.rec_scores) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: cropped_faces
  {
    if (msg.cropped_faces.size() == 0) {
      out << "cropped_faces: []";
    } else {
      out << "cropped_faces: [";
      size_t pending_items = msg.cropped_faces.size();
      for (auto item : msg.cropped_faces) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FaceRecognition & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: user_ids
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.user_ids.size() == 0) {
      out << "user_ids: []\n";
    } else {
      out << "user_ids:\n";
      for (auto item : msg.user_ids) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
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

  // member: timestamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
    out << "\n";
  }

  // member: rec_scores
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.rec_scores.size() == 0) {
      out << "rec_scores: []\n";
    } else {
      out << "rec_scores:\n";
      for (auto item : msg.rec_scores) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: cropped_faces
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.cropped_faces.size() == 0) {
      out << "cropped_faces: []\n";
    } else {
      out << "cropped_faces:\n";
      for (auto item : msg.cropped_faces) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
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
