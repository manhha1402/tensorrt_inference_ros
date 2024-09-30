// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from tensorrt_infer_msgs:srv/DetectLicencePlate.idl
// generated code does not contain a copyright notice
#include "tensorrt_infer_msgs/srv/detail/detect_licence_plate__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "tensorrt_infer_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "tensorrt_infer_msgs/srv/detail/detect_licence_plate__struct.h"
#include "tensorrt_infer_msgs/srv/detail/detect_licence_plate__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // topic_name
#include "rosidl_runtime_c/string_functions.h"  // topic_name

// forward declare type support functions


using _DetectLicencePlate_Request__ros_msg_type = tensorrt_infer_msgs__srv__DetectLicencePlate_Request;

static bool _DetectLicencePlate_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _DetectLicencePlate_Request__ros_msg_type * ros_message = static_cast<const _DetectLicencePlate_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: topic_name
  {
    const rosidl_runtime_c__String * str = &ros_message->topic_name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _DetectLicencePlate_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _DetectLicencePlate_Request__ros_msg_type * ros_message = static_cast<_DetectLicencePlate_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: topic_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->topic_name.data) {
      rosidl_runtime_c__String__init(&ros_message->topic_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->topic_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'topic_name'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tensorrt_infer_msgs
size_t get_serialized_size_tensorrt_infer_msgs__srv__DetectLicencePlate_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _DetectLicencePlate_Request__ros_msg_type * ros_message = static_cast<const _DetectLicencePlate_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name topic_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->topic_name.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _DetectLicencePlate_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_tensorrt_infer_msgs__srv__DetectLicencePlate_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tensorrt_infer_msgs
size_t max_serialized_size_tensorrt_infer_msgs__srv__DetectLicencePlate_Request(
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

  // member: topic_name
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
    using DataType = tensorrt_infer_msgs__srv__DetectLicencePlate_Request;
    is_plain =
      (
      offsetof(DataType, topic_name) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _DetectLicencePlate_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_tensorrt_infer_msgs__srv__DetectLicencePlate_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_DetectLicencePlate_Request = {
  "tensorrt_infer_msgs::srv",
  "DetectLicencePlate_Request",
  _DetectLicencePlate_Request__cdr_serialize,
  _DetectLicencePlate_Request__cdr_deserialize,
  _DetectLicencePlate_Request__get_serialized_size,
  _DetectLicencePlate_Request__max_serialized_size
};

static rosidl_message_type_support_t _DetectLicencePlate_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_DetectLicencePlate_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tensorrt_infer_msgs, srv, DetectLicencePlate_Request)() {
  return &_DetectLicencePlate_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "tensorrt_infer_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "tensorrt_infer_msgs/srv/detail/detect_licence_plate__struct.h"
// already included above
// #include "tensorrt_infer_msgs/srv/detail/detect_licence_plate__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "rosidl_runtime_c/string.h"  // plate_number
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // plate_number

// forward declare type support functions


using _DetectLicencePlate_Response__ros_msg_type = tensorrt_infer_msgs__srv__DetectLicencePlate_Response;

static bool _DetectLicencePlate_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _DetectLicencePlate_Response__ros_msg_type * ros_message = static_cast<const _DetectLicencePlate_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: plate_number
  {
    const rosidl_runtime_c__String * str = &ros_message->plate_number;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: det_core
  {
    cdr << ros_message->det_core;
  }

  // Field name: rec_score
  {
    cdr << ros_message->rec_score;
  }

  return true;
}

static bool _DetectLicencePlate_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _DetectLicencePlate_Response__ros_msg_type * ros_message = static_cast<_DetectLicencePlate_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: plate_number
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->plate_number.data) {
      rosidl_runtime_c__String__init(&ros_message->plate_number);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->plate_number,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'plate_number'\n");
      return false;
    }
  }

  // Field name: det_core
  {
    cdr >> ros_message->det_core;
  }

  // Field name: rec_score
  {
    cdr >> ros_message->rec_score;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tensorrt_infer_msgs
size_t get_serialized_size_tensorrt_infer_msgs__srv__DetectLicencePlate_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _DetectLicencePlate_Response__ros_msg_type * ros_message = static_cast<const _DetectLicencePlate_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name plate_number
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->plate_number.size + 1);
  // field.name det_core
  {
    size_t item_size = sizeof(ros_message->det_core);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rec_score
  {
    size_t item_size = sizeof(ros_message->rec_score);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _DetectLicencePlate_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_tensorrt_infer_msgs__srv__DetectLicencePlate_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tensorrt_infer_msgs
size_t max_serialized_size_tensorrt_infer_msgs__srv__DetectLicencePlate_Response(
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

  // member: plate_number
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
  // member: det_core
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: rec_score
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
    using DataType = tensorrt_infer_msgs__srv__DetectLicencePlate_Response;
    is_plain =
      (
      offsetof(DataType, rec_score) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _DetectLicencePlate_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_tensorrt_infer_msgs__srv__DetectLicencePlate_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_DetectLicencePlate_Response = {
  "tensorrt_infer_msgs::srv",
  "DetectLicencePlate_Response",
  _DetectLicencePlate_Response__cdr_serialize,
  _DetectLicencePlate_Response__cdr_deserialize,
  _DetectLicencePlate_Response__get_serialized_size,
  _DetectLicencePlate_Response__max_serialized_size
};

static rosidl_message_type_support_t _DetectLicencePlate_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_DetectLicencePlate_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tensorrt_infer_msgs, srv, DetectLicencePlate_Response)() {
  return &_DetectLicencePlate_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "tensorrt_infer_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "tensorrt_infer_msgs/srv/detect_licence_plate.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t DetectLicencePlate__callbacks = {
  "tensorrt_infer_msgs::srv",
  "DetectLicencePlate",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tensorrt_infer_msgs, srv, DetectLicencePlate_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tensorrt_infer_msgs, srv, DetectLicencePlate_Response)(),
};

static rosidl_service_type_support_t DetectLicencePlate__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &DetectLicencePlate__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tensorrt_infer_msgs, srv, DetectLicencePlate)() {
  return &DetectLicencePlate__handle;
}

#if defined(__cplusplus)
}
#endif
