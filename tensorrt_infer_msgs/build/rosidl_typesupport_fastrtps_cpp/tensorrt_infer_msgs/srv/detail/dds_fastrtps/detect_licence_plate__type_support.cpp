// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from tensorrt_infer_msgs:srv/DetectLicencePlate.idl
// generated code does not contain a copyright notice
#include "tensorrt_infer_msgs/srv/detail/detect_licence_plate__rosidl_typesupport_fastrtps_cpp.hpp"
#include "tensorrt_infer_msgs/srv/detail/detect_licence_plate__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace tensorrt_infer_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tensorrt_infer_msgs
cdr_serialize(
  const tensorrt_infer_msgs::srv::DetectLicencePlate_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: topic_name
  cdr << ros_message.topic_name;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tensorrt_infer_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  tensorrt_infer_msgs::srv::DetectLicencePlate_Request & ros_message)
{
  // Member: topic_name
  cdr >> ros_message.topic_name;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tensorrt_infer_msgs
get_serialized_size(
  const tensorrt_infer_msgs::srv::DetectLicencePlate_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: topic_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.topic_name.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tensorrt_infer_msgs
max_serialized_size_DetectLicencePlate_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: topic_name
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = tensorrt_infer_msgs::srv::DetectLicencePlate_Request;
    is_plain =
      (
      offsetof(DataType, topic_name) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _DetectLicencePlate_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const tensorrt_infer_msgs::srv::DetectLicencePlate_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _DetectLicencePlate_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<tensorrt_infer_msgs::srv::DetectLicencePlate_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _DetectLicencePlate_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const tensorrt_infer_msgs::srv::DetectLicencePlate_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _DetectLicencePlate_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_DetectLicencePlate_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _DetectLicencePlate_Request__callbacks = {
  "tensorrt_infer_msgs::srv",
  "DetectLicencePlate_Request",
  _DetectLicencePlate_Request__cdr_serialize,
  _DetectLicencePlate_Request__cdr_deserialize,
  _DetectLicencePlate_Request__get_serialized_size,
  _DetectLicencePlate_Request__max_serialized_size
};

static rosidl_message_type_support_t _DetectLicencePlate_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_DetectLicencePlate_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace tensorrt_infer_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_tensorrt_infer_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<tensorrt_infer_msgs::srv::DetectLicencePlate_Request>()
{
  return &tensorrt_infer_msgs::srv::typesupport_fastrtps_cpp::_DetectLicencePlate_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tensorrt_infer_msgs, srv, DetectLicencePlate_Request)() {
  return &tensorrt_infer_msgs::srv::typesupport_fastrtps_cpp::_DetectLicencePlate_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace tensorrt_infer_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tensorrt_infer_msgs
cdr_serialize(
  const tensorrt_infer_msgs::srv::DetectLicencePlate_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: plate_number
  cdr << ros_message.plate_number;
  // Member: det_core
  cdr << ros_message.det_core;
  // Member: rec_score
  cdr << ros_message.rec_score;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tensorrt_infer_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  tensorrt_infer_msgs::srv::DetectLicencePlate_Response & ros_message)
{
  // Member: plate_number
  cdr >> ros_message.plate_number;

  // Member: det_core
  cdr >> ros_message.det_core;

  // Member: rec_score
  cdr >> ros_message.rec_score;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tensorrt_infer_msgs
get_serialized_size(
  const tensorrt_infer_msgs::srv::DetectLicencePlate_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: plate_number
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.plate_number.size() + 1);
  // Member: det_core
  {
    size_t item_size = sizeof(ros_message.det_core);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rec_score
  {
    size_t item_size = sizeof(ros_message.rec_score);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tensorrt_infer_msgs
max_serialized_size_DetectLicencePlate_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: plate_number
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: det_core
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: rec_score
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = tensorrt_infer_msgs::srv::DetectLicencePlate_Response;
    is_plain =
      (
      offsetof(DataType, rec_score) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _DetectLicencePlate_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const tensorrt_infer_msgs::srv::DetectLicencePlate_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _DetectLicencePlate_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<tensorrt_infer_msgs::srv::DetectLicencePlate_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _DetectLicencePlate_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const tensorrt_infer_msgs::srv::DetectLicencePlate_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _DetectLicencePlate_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_DetectLicencePlate_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _DetectLicencePlate_Response__callbacks = {
  "tensorrt_infer_msgs::srv",
  "DetectLicencePlate_Response",
  _DetectLicencePlate_Response__cdr_serialize,
  _DetectLicencePlate_Response__cdr_deserialize,
  _DetectLicencePlate_Response__get_serialized_size,
  _DetectLicencePlate_Response__max_serialized_size
};

static rosidl_message_type_support_t _DetectLicencePlate_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_DetectLicencePlate_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace tensorrt_infer_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_tensorrt_infer_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<tensorrt_infer_msgs::srv::DetectLicencePlate_Response>()
{
  return &tensorrt_infer_msgs::srv::typesupport_fastrtps_cpp::_DetectLicencePlate_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tensorrt_infer_msgs, srv, DetectLicencePlate_Response)() {
  return &tensorrt_infer_msgs::srv::typesupport_fastrtps_cpp::_DetectLicencePlate_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace tensorrt_infer_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _DetectLicencePlate__callbacks = {
  "tensorrt_infer_msgs::srv",
  "DetectLicencePlate",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tensorrt_infer_msgs, srv, DetectLicencePlate_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tensorrt_infer_msgs, srv, DetectLicencePlate_Response)(),
};

static rosidl_service_type_support_t _DetectLicencePlate__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_DetectLicencePlate__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace tensorrt_infer_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_tensorrt_infer_msgs
const rosidl_service_type_support_t *
get_service_type_support_handle<tensorrt_infer_msgs::srv::DetectLicencePlate>()
{
  return &tensorrt_infer_msgs::srv::typesupport_fastrtps_cpp::_DetectLicencePlate__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tensorrt_infer_msgs, srv, DetectLicencePlate)() {
  return &tensorrt_infer_msgs::srv::typesupport_fastrtps_cpp::_DetectLicencePlate__handle;
}

#ifdef __cplusplus
}
#endif
