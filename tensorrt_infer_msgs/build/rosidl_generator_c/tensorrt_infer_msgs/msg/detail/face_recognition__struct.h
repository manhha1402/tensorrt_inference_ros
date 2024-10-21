// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tensorrt_infer_msgs:msg/FaceRecognition.idl
// generated code does not contain a copyright notice

#ifndef TENSORRT_INFER_MSGS__MSG__DETAIL__FACE_RECOGNITION__STRUCT_H_
#define TENSORRT_INFER_MSGS__MSG__DETAIL__FACE_RECOGNITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'user_ids'
// Member 'timestamp'
#include "rosidl_runtime_c/string.h"
// Member 'rec_scores'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'cropped_faces'
#include "sensor_msgs/msg/detail/image__struct.h"

/// Struct defined in msg/FaceRecognition in the package tensorrt_infer_msgs.
typedef struct tensorrt_infer_msgs__msg__FaceRecognition
{
  rosidl_runtime_c__String__Sequence user_ids;
  uint16_t camera_id;
  rosidl_runtime_c__String timestamp;
  rosidl_runtime_c__double__Sequence rec_scores;
  sensor_msgs__msg__Image__Sequence cropped_faces;
} tensorrt_infer_msgs__msg__FaceRecognition;

// Struct for a sequence of tensorrt_infer_msgs__msg__FaceRecognition.
typedef struct tensorrt_infer_msgs__msg__FaceRecognition__Sequence
{
  tensorrt_infer_msgs__msg__FaceRecognition * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tensorrt_infer_msgs__msg__FaceRecognition__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TENSORRT_INFER_MSGS__MSG__DETAIL__FACE_RECOGNITION__STRUCT_H_
