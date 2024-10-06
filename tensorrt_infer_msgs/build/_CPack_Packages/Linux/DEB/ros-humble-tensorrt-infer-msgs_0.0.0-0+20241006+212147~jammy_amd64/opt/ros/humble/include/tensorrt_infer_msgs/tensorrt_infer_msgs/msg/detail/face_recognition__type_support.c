// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tensorrt_infer_msgs:msg/FaceRecognition.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tensorrt_infer_msgs/msg/detail/face_recognition__rosidl_typesupport_introspection_c.h"
#include "tensorrt_infer_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tensorrt_infer_msgs/msg/detail/face_recognition__functions.h"
#include "tensorrt_infer_msgs/msg/detail/face_recognition__struct.h"


// Include directives for member types
// Member `name`
// Member `timestamp`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__FaceRecognition_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tensorrt_infer_msgs__msg__FaceRecognition__init(message_memory);
}

void tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__FaceRecognition_fini_function(void * message_memory)
{
  tensorrt_infer_msgs__msg__FaceRecognition__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__FaceRecognition_message_member_array[4] = {
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensorrt_infer_msgs__msg__FaceRecognition, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "timestamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensorrt_infer_msgs__msg__FaceRecognition, timestamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rec_score",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensorrt_infer_msgs__msg__FaceRecognition, rec_score),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "camera_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensorrt_infer_msgs__msg__FaceRecognition, camera_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__FaceRecognition_message_members = {
  "tensorrt_infer_msgs__msg",  // message namespace
  "FaceRecognition",  // message name
  4,  // number of fields
  sizeof(tensorrt_infer_msgs__msg__FaceRecognition),
  tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__FaceRecognition_message_member_array,  // message members
  tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__FaceRecognition_init_function,  // function to initialize message memory (memory has to be allocated)
  tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__FaceRecognition_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__FaceRecognition_message_type_support_handle = {
  0,
  &tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__FaceRecognition_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tensorrt_infer_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tensorrt_infer_msgs, msg, FaceRecognition)() {
  if (!tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__FaceRecognition_message_type_support_handle.typesupport_identifier) {
    tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__FaceRecognition_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__FaceRecognition_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
