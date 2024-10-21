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
// Member `user_ids`
// Member `timestamp`
#include "rosidl_runtime_c/string_functions.h"
// Member `rec_scores`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `cropped_faces`
#include "sensor_msgs/msg/image.h"
// Member `cropped_faces`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"

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

size_t tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__size_function__FaceRecognition__user_ids(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__get_const_function__FaceRecognition__user_ids(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__get_function__FaceRecognition__user_ids(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__fetch_function__FaceRecognition__user_ids(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__get_const_function__FaceRecognition__user_ids(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__assign_function__FaceRecognition__user_ids(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__get_function__FaceRecognition__user_ids(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__resize_function__FaceRecognition__user_ids(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__size_function__FaceRecognition__rec_scores(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__get_const_function__FaceRecognition__rec_scores(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__get_function__FaceRecognition__rec_scores(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__fetch_function__FaceRecognition__rec_scores(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__get_const_function__FaceRecognition__rec_scores(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__assign_function__FaceRecognition__rec_scores(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__get_function__FaceRecognition__rec_scores(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__resize_function__FaceRecognition__rec_scores(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__size_function__FaceRecognition__cropped_faces(
  const void * untyped_member)
{
  const sensor_msgs__msg__Image__Sequence * member =
    (const sensor_msgs__msg__Image__Sequence *)(untyped_member);
  return member->size;
}

const void * tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__get_const_function__FaceRecognition__cropped_faces(
  const void * untyped_member, size_t index)
{
  const sensor_msgs__msg__Image__Sequence * member =
    (const sensor_msgs__msg__Image__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__get_function__FaceRecognition__cropped_faces(
  void * untyped_member, size_t index)
{
  sensor_msgs__msg__Image__Sequence * member =
    (sensor_msgs__msg__Image__Sequence *)(untyped_member);
  return &member->data[index];
}

void tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__fetch_function__FaceRecognition__cropped_faces(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const sensor_msgs__msg__Image * item =
    ((const sensor_msgs__msg__Image *)
    tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__get_const_function__FaceRecognition__cropped_faces(untyped_member, index));
  sensor_msgs__msg__Image * value =
    (sensor_msgs__msg__Image *)(untyped_value);
  *value = *item;
}

void tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__assign_function__FaceRecognition__cropped_faces(
  void * untyped_member, size_t index, const void * untyped_value)
{
  sensor_msgs__msg__Image * item =
    ((sensor_msgs__msg__Image *)
    tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__get_function__FaceRecognition__cropped_faces(untyped_member, index));
  const sensor_msgs__msg__Image * value =
    (const sensor_msgs__msg__Image *)(untyped_value);
  *item = *value;
}

bool tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__resize_function__FaceRecognition__cropped_faces(
  void * untyped_member, size_t size)
{
  sensor_msgs__msg__Image__Sequence * member =
    (sensor_msgs__msg__Image__Sequence *)(untyped_member);
  sensor_msgs__msg__Image__Sequence__fini(member);
  return sensor_msgs__msg__Image__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__FaceRecognition_message_member_array[5] = {
  {
    "user_ids",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensorrt_infer_msgs__msg__FaceRecognition, user_ids),  // bytes offset in struct
    NULL,  // default value
    tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__size_function__FaceRecognition__user_ids,  // size() function pointer
    tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__get_const_function__FaceRecognition__user_ids,  // get_const(index) function pointer
    tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__get_function__FaceRecognition__user_ids,  // get(index) function pointer
    tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__fetch_function__FaceRecognition__user_ids,  // fetch(index, &value) function pointer
    tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__assign_function__FaceRecognition__user_ids,  // assign(index, value) function pointer
    tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__resize_function__FaceRecognition__user_ids  // resize(index) function pointer
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
    "rec_scores",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensorrt_infer_msgs__msg__FaceRecognition, rec_scores),  // bytes offset in struct
    NULL,  // default value
    tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__size_function__FaceRecognition__rec_scores,  // size() function pointer
    tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__get_const_function__FaceRecognition__rec_scores,  // get_const(index) function pointer
    tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__get_function__FaceRecognition__rec_scores,  // get(index) function pointer
    tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__fetch_function__FaceRecognition__rec_scores,  // fetch(index, &value) function pointer
    tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__assign_function__FaceRecognition__rec_scores,  // assign(index, value) function pointer
    tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__resize_function__FaceRecognition__rec_scores  // resize(index) function pointer
  },
  {
    "cropped_faces",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensorrt_infer_msgs__msg__FaceRecognition, cropped_faces),  // bytes offset in struct
    NULL,  // default value
    tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__size_function__FaceRecognition__cropped_faces,  // size() function pointer
    tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__get_const_function__FaceRecognition__cropped_faces,  // get_const(index) function pointer
    tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__get_function__FaceRecognition__cropped_faces,  // get(index) function pointer
    tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__fetch_function__FaceRecognition__cropped_faces,  // fetch(index, &value) function pointer
    tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__assign_function__FaceRecognition__cropped_faces,  // assign(index, value) function pointer
    tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__resize_function__FaceRecognition__cropped_faces  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__FaceRecognition_message_members = {
  "tensorrt_infer_msgs__msg",  // message namespace
  "FaceRecognition",  // message name
  5,  // number of fields
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
  tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__FaceRecognition_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  if (!tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__FaceRecognition_message_type_support_handle.typesupport_identifier) {
    tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__FaceRecognition_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tensorrt_infer_msgs__msg__FaceRecognition__rosidl_typesupport_introspection_c__FaceRecognition_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
