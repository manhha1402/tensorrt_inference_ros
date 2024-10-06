// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from tensorrt_infer_msgs:msg/FaceRecognition.idl
// generated code does not contain a copyright notice

#ifndef TENSORRT_INFER_MSGS__MSG__DETAIL__FACE_RECOGNITION__FUNCTIONS_H_
#define TENSORRT_INFER_MSGS__MSG__DETAIL__FACE_RECOGNITION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "tensorrt_infer_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "tensorrt_infer_msgs/msg/detail/face_recognition__struct.h"

/// Initialize msg/FaceRecognition message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * tensorrt_infer_msgs__msg__FaceRecognition
 * )) before or use
 * tensorrt_infer_msgs__msg__FaceRecognition__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
bool
tensorrt_infer_msgs__msg__FaceRecognition__init(tensorrt_infer_msgs__msg__FaceRecognition * msg);

/// Finalize msg/FaceRecognition message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
void
tensorrt_infer_msgs__msg__FaceRecognition__fini(tensorrt_infer_msgs__msg__FaceRecognition * msg);

/// Create msg/FaceRecognition message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * tensorrt_infer_msgs__msg__FaceRecognition__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
tensorrt_infer_msgs__msg__FaceRecognition *
tensorrt_infer_msgs__msg__FaceRecognition__create();

/// Destroy msg/FaceRecognition message.
/**
 * It calls
 * tensorrt_infer_msgs__msg__FaceRecognition__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
void
tensorrt_infer_msgs__msg__FaceRecognition__destroy(tensorrt_infer_msgs__msg__FaceRecognition * msg);

/// Check for msg/FaceRecognition message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
bool
tensorrt_infer_msgs__msg__FaceRecognition__are_equal(const tensorrt_infer_msgs__msg__FaceRecognition * lhs, const tensorrt_infer_msgs__msg__FaceRecognition * rhs);

/// Copy a msg/FaceRecognition message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
bool
tensorrt_infer_msgs__msg__FaceRecognition__copy(
  const tensorrt_infer_msgs__msg__FaceRecognition * input,
  tensorrt_infer_msgs__msg__FaceRecognition * output);

/// Initialize array of msg/FaceRecognition messages.
/**
 * It allocates the memory for the number of elements and calls
 * tensorrt_infer_msgs__msg__FaceRecognition__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
bool
tensorrt_infer_msgs__msg__FaceRecognition__Sequence__init(tensorrt_infer_msgs__msg__FaceRecognition__Sequence * array, size_t size);

/// Finalize array of msg/FaceRecognition messages.
/**
 * It calls
 * tensorrt_infer_msgs__msg__FaceRecognition__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
void
tensorrt_infer_msgs__msg__FaceRecognition__Sequence__fini(tensorrt_infer_msgs__msg__FaceRecognition__Sequence * array);

/// Create array of msg/FaceRecognition messages.
/**
 * It allocates the memory for the array and calls
 * tensorrt_infer_msgs__msg__FaceRecognition__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
tensorrt_infer_msgs__msg__FaceRecognition__Sequence *
tensorrt_infer_msgs__msg__FaceRecognition__Sequence__create(size_t size);

/// Destroy array of msg/FaceRecognition messages.
/**
 * It calls
 * tensorrt_infer_msgs__msg__FaceRecognition__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
void
tensorrt_infer_msgs__msg__FaceRecognition__Sequence__destroy(tensorrt_infer_msgs__msg__FaceRecognition__Sequence * array);

/// Check for msg/FaceRecognition message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
bool
tensorrt_infer_msgs__msg__FaceRecognition__Sequence__are_equal(const tensorrt_infer_msgs__msg__FaceRecognition__Sequence * lhs, const tensorrt_infer_msgs__msg__FaceRecognition__Sequence * rhs);

/// Copy an array of msg/FaceRecognition messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
bool
tensorrt_infer_msgs__msg__FaceRecognition__Sequence__copy(
  const tensorrt_infer_msgs__msg__FaceRecognition__Sequence * input,
  tensorrt_infer_msgs__msg__FaceRecognition__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TENSORRT_INFER_MSGS__MSG__DETAIL__FACE_RECOGNITION__FUNCTIONS_H_
