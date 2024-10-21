// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from tensorrt_infer_msgs:msg/FaceRecognition.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "tensorrt_infer_msgs/msg/detail/face_recognition__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace tensorrt_infer_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void FaceRecognition_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) tensorrt_infer_msgs::msg::FaceRecognition(_init);
}

void FaceRecognition_fini_function(void * message_memory)
{
  auto typed_message = static_cast<tensorrt_infer_msgs::msg::FaceRecognition *>(message_memory);
  typed_message->~FaceRecognition();
}

size_t size_function__FaceRecognition__user_ids(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__FaceRecognition__user_ids(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__FaceRecognition__user_ids(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__FaceRecognition__user_ids(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__FaceRecognition__user_ids(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__FaceRecognition__user_ids(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__FaceRecognition__user_ids(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__FaceRecognition__user_ids(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

size_t size_function__FaceRecognition__rec_scores(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__FaceRecognition__rec_scores(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__FaceRecognition__rec_scores(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__FaceRecognition__rec_scores(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__FaceRecognition__rec_scores(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__FaceRecognition__rec_scores(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__FaceRecognition__rec_scores(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__FaceRecognition__rec_scores(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__FaceRecognition__cropped_faces(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  return member->size();
}

const void * get_const_function__FaceRecognition__cropped_faces(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  return &member[index];
}

void * get_function__FaceRecognition__cropped_faces(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  return &member[index];
}

void fetch_function__FaceRecognition__cropped_faces(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const sensor_msgs::msg::Image *>(
    get_const_function__FaceRecognition__cropped_faces(untyped_member, index));
  auto & value = *reinterpret_cast<sensor_msgs::msg::Image *>(untyped_value);
  value = item;
}

void assign_function__FaceRecognition__cropped_faces(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<sensor_msgs::msg::Image *>(
    get_function__FaceRecognition__cropped_faces(untyped_member, index));
  const auto & value = *reinterpret_cast<const sensor_msgs::msg::Image *>(untyped_value);
  item = value;
}

void resize_function__FaceRecognition__cropped_faces(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember FaceRecognition_message_member_array[5] = {
  {
    "user_ids",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensorrt_infer_msgs::msg::FaceRecognition, user_ids),  // bytes offset in struct
    nullptr,  // default value
    size_function__FaceRecognition__user_ids,  // size() function pointer
    get_const_function__FaceRecognition__user_ids,  // get_const(index) function pointer
    get_function__FaceRecognition__user_ids,  // get(index) function pointer
    fetch_function__FaceRecognition__user_ids,  // fetch(index, &value) function pointer
    assign_function__FaceRecognition__user_ids,  // assign(index, value) function pointer
    resize_function__FaceRecognition__user_ids  // resize(index) function pointer
  },
  {
    "camera_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensorrt_infer_msgs::msg::FaceRecognition, camera_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "timestamp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensorrt_infer_msgs::msg::FaceRecognition, timestamp),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "rec_scores",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensorrt_infer_msgs::msg::FaceRecognition, rec_scores),  // bytes offset in struct
    nullptr,  // default value
    size_function__FaceRecognition__rec_scores,  // size() function pointer
    get_const_function__FaceRecognition__rec_scores,  // get_const(index) function pointer
    get_function__FaceRecognition__rec_scores,  // get(index) function pointer
    fetch_function__FaceRecognition__rec_scores,  // fetch(index, &value) function pointer
    assign_function__FaceRecognition__rec_scores,  // assign(index, value) function pointer
    resize_function__FaceRecognition__rec_scores  // resize(index) function pointer
  },
  {
    "cropped_faces",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::Image>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensorrt_infer_msgs::msg::FaceRecognition, cropped_faces),  // bytes offset in struct
    nullptr,  // default value
    size_function__FaceRecognition__cropped_faces,  // size() function pointer
    get_const_function__FaceRecognition__cropped_faces,  // get_const(index) function pointer
    get_function__FaceRecognition__cropped_faces,  // get(index) function pointer
    fetch_function__FaceRecognition__cropped_faces,  // fetch(index, &value) function pointer
    assign_function__FaceRecognition__cropped_faces,  // assign(index, value) function pointer
    resize_function__FaceRecognition__cropped_faces  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers FaceRecognition_message_members = {
  "tensorrt_infer_msgs::msg",  // message namespace
  "FaceRecognition",  // message name
  5,  // number of fields
  sizeof(tensorrt_infer_msgs::msg::FaceRecognition),
  FaceRecognition_message_member_array,  // message members
  FaceRecognition_init_function,  // function to initialize message memory (memory has to be allocated)
  FaceRecognition_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t FaceRecognition_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &FaceRecognition_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace tensorrt_infer_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tensorrt_infer_msgs::msg::FaceRecognition>()
{
  return &::tensorrt_infer_msgs::msg::rosidl_typesupport_introspection_cpp::FaceRecognition_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tensorrt_infer_msgs, msg, FaceRecognition)() {
  return &::tensorrt_infer_msgs::msg::rosidl_typesupport_introspection_cpp::FaceRecognition_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
