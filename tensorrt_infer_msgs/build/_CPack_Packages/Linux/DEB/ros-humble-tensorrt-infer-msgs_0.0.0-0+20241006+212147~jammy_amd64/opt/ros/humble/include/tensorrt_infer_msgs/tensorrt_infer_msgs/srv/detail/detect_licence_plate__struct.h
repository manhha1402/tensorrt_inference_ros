// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tensorrt_infer_msgs:srv/DetectLicencePlate.idl
// generated code does not contain a copyright notice

#ifndef TENSORRT_INFER_MSGS__SRV__DETAIL__DETECT_LICENCE_PLATE__STRUCT_H_
#define TENSORRT_INFER_MSGS__SRV__DETAIL__DETECT_LICENCE_PLATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'topic_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/DetectLicencePlate in the package tensorrt_infer_msgs.
typedef struct tensorrt_infer_msgs__srv__DetectLicencePlate_Request
{
  rosidl_runtime_c__String topic_name;
} tensorrt_infer_msgs__srv__DetectLicencePlate_Request;

// Struct for a sequence of tensorrt_infer_msgs__srv__DetectLicencePlate_Request.
typedef struct tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence
{
  tensorrt_infer_msgs__srv__DetectLicencePlate_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'plate_number'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/DetectLicencePlate in the package tensorrt_infer_msgs.
typedef struct tensorrt_infer_msgs__srv__DetectLicencePlate_Response
{
  rosidl_runtime_c__String plate_number;
  double det_core;
  double rec_score;
} tensorrt_infer_msgs__srv__DetectLicencePlate_Response;

// Struct for a sequence of tensorrt_infer_msgs__srv__DetectLicencePlate_Response.
typedef struct tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence
{
  tensorrt_infer_msgs__srv__DetectLicencePlate_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TENSORRT_INFER_MSGS__SRV__DETAIL__DETECT_LICENCE_PLATE__STRUCT_H_
