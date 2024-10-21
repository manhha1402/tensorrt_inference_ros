// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from tensorrt_infer_msgs:msg/FaceRecognition.idl
// generated code does not contain a copyright notice
#include "tensorrt_infer_msgs/msg/detail/face_recognition__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "tensorrt_infer_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "tensorrt_infer_msgs/msg/detail/face_recognition__struct.h"
#include "tensorrt_infer_msgs/msg/detail/face_recognition__functions.h"
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

#include "rosidl_runtime_c/primitives_sequence.h"  // rec_scores
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // rec_scores
#include "rosidl_runtime_c/string.h"  // timestamp, user_ids
#include "rosidl_runtime_c/string_functions.h"  // timestamp, user_ids
#include "sensor_msgs/msg/detail/image__functions.h"  // cropped_faces

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_tensorrt_infer_msgs
size_t get_serialized_size_sensor_msgs__msg__Image(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_tensorrt_infer_msgs
size_t max_serialized_size_sensor_msgs__msg__Image(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_tensorrt_infer_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image)();


using _FaceRecognition__ros_msg_type = tensorrt_infer_msgs__msg__FaceRecognition;

static bool _FaceRecognition__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _FaceRecognition__ros_msg_type * ros_message = static_cast<const _FaceRecognition__ros_msg_type *>(untyped_ros_message);
  // Field name: user_ids
  {
    size_t size = ros_message->user_ids.size;
    auto array_ptr = ros_message->user_ids.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__String * str = &array_ptr[i];
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
  }

  // Field name: camera_id
  {
    cdr << ros_message->camera_id;
  }

  // Field name: timestamp
  {
    const rosidl_runtime_c__String * str = &ros_message->timestamp;
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

  // Field name: rec_scores
  {
    size_t size = ros_message->rec_scores.size;
    auto array_ptr = ros_message->rec_scores.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: cropped_faces
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image
      )()->data);
    size_t size = ros_message->cropped_faces.size;
    auto array_ptr = ros_message->cropped_faces.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _FaceRecognition__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _FaceRecognition__ros_msg_type * ros_message = static_cast<_FaceRecognition__ros_msg_type *>(untyped_ros_message);
  // Field name: user_ids
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->user_ids.data) {
      rosidl_runtime_c__String__Sequence__fini(&ros_message->user_ids);
    }
    if (!rosidl_runtime_c__String__Sequence__init(&ros_message->user_ids, size)) {
      fprintf(stderr, "failed to create array for field 'user_ids'");
      return false;
    }
    auto array_ptr = ros_message->user_ids.data;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assign(
        &ros_i,
        tmp.c_str());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'user_ids'\n");
        return false;
      }
    }
  }

  // Field name: camera_id
  {
    cdr >> ros_message->camera_id;
  }

  // Field name: timestamp
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->timestamp.data) {
      rosidl_runtime_c__String__init(&ros_message->timestamp);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->timestamp,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'timestamp'\n");
      return false;
    }
  }

  // Field name: rec_scores
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->rec_scores.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->rec_scores);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->rec_scores, size)) {
      fprintf(stderr, "failed to create array for field 'rec_scores'");
      return false;
    }
    auto array_ptr = ros_message->rec_scores.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: cropped_faces
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->cropped_faces.data) {
      sensor_msgs__msg__Image__Sequence__fini(&ros_message->cropped_faces);
    }
    if (!sensor_msgs__msg__Image__Sequence__init(&ros_message->cropped_faces, size)) {
      fprintf(stderr, "failed to create array for field 'cropped_faces'");
      return false;
    }
    auto array_ptr = ros_message->cropped_faces.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tensorrt_infer_msgs
size_t get_serialized_size_tensorrt_infer_msgs__msg__FaceRecognition(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FaceRecognition__ros_msg_type * ros_message = static_cast<const _FaceRecognition__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name user_ids
  {
    size_t array_size = ros_message->user_ids.size;
    auto array_ptr = ros_message->user_ids.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }
  // field.name camera_id
  {
    size_t item_size = sizeof(ros_message->camera_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name timestamp
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->timestamp.size + 1);
  // field.name rec_scores
  {
    size_t array_size = ros_message->rec_scores.size;
    auto array_ptr = ros_message->rec_scores.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name cropped_faces
  {
    size_t array_size = ros_message->cropped_faces.size;
    auto array_ptr = ros_message->cropped_faces.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_sensor_msgs__msg__Image(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _FaceRecognition__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_tensorrt_infer_msgs__msg__FaceRecognition(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tensorrt_infer_msgs
size_t max_serialized_size_tensorrt_infer_msgs__msg__FaceRecognition(
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

  // member: user_ids
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: camera_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: timestamp
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
  // member: rec_scores
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: cropped_faces
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_sensor_msgs__msg__Image(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = tensorrt_infer_msgs__msg__FaceRecognition;
    is_plain =
      (
      offsetof(DataType, cropped_faces) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _FaceRecognition__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_tensorrt_infer_msgs__msg__FaceRecognition(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_FaceRecognition = {
  "tensorrt_infer_msgs::msg",
  "FaceRecognition",
  _FaceRecognition__cdr_serialize,
  _FaceRecognition__cdr_deserialize,
  _FaceRecognition__get_serialized_size,
  _FaceRecognition__max_serialized_size
};

static rosidl_message_type_support_t _FaceRecognition__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_FaceRecognition,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tensorrt_infer_msgs, msg, FaceRecognition)() {
  return &_FaceRecognition__type_support;
}

#if defined(__cplusplus)
}
#endif
