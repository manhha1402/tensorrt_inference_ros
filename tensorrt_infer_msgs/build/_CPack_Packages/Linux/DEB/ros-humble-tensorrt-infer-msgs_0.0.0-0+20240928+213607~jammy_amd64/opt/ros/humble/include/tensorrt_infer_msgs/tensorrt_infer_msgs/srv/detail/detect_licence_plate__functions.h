// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from tensorrt_infer_msgs:srv/DetectLicencePlate.idl
// generated code does not contain a copyright notice

#ifndef TENSORRT_INFER_MSGS__SRV__DETAIL__DETECT_LICENCE_PLATE__FUNCTIONS_H_
#define TENSORRT_INFER_MSGS__SRV__DETAIL__DETECT_LICENCE_PLATE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "tensorrt_infer_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "tensorrt_infer_msgs/srv/detail/detect_licence_plate__struct.h"

/// Initialize srv/DetectLicencePlate message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * tensorrt_infer_msgs__srv__DetectLicencePlate_Request
 * )) before or use
 * tensorrt_infer_msgs__srv__DetectLicencePlate_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
bool
tensorrt_infer_msgs__srv__DetectLicencePlate_Request__init(tensorrt_infer_msgs__srv__DetectLicencePlate_Request * msg);

/// Finalize srv/DetectLicencePlate message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
void
tensorrt_infer_msgs__srv__DetectLicencePlate_Request__fini(tensorrt_infer_msgs__srv__DetectLicencePlate_Request * msg);

/// Create srv/DetectLicencePlate message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * tensorrt_infer_msgs__srv__DetectLicencePlate_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
tensorrt_infer_msgs__srv__DetectLicencePlate_Request *
tensorrt_infer_msgs__srv__DetectLicencePlate_Request__create();

/// Destroy srv/DetectLicencePlate message.
/**
 * It calls
 * tensorrt_infer_msgs__srv__DetectLicencePlate_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
void
tensorrt_infer_msgs__srv__DetectLicencePlate_Request__destroy(tensorrt_infer_msgs__srv__DetectLicencePlate_Request * msg);

/// Check for srv/DetectLicencePlate message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
bool
tensorrt_infer_msgs__srv__DetectLicencePlate_Request__are_equal(const tensorrt_infer_msgs__srv__DetectLicencePlate_Request * lhs, const tensorrt_infer_msgs__srv__DetectLicencePlate_Request * rhs);

/// Copy a srv/DetectLicencePlate message.
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
tensorrt_infer_msgs__srv__DetectLicencePlate_Request__copy(
  const tensorrt_infer_msgs__srv__DetectLicencePlate_Request * input,
  tensorrt_infer_msgs__srv__DetectLicencePlate_Request * output);

/// Initialize array of srv/DetectLicencePlate messages.
/**
 * It allocates the memory for the number of elements and calls
 * tensorrt_infer_msgs__srv__DetectLicencePlate_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
bool
tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence__init(tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence * array, size_t size);

/// Finalize array of srv/DetectLicencePlate messages.
/**
 * It calls
 * tensorrt_infer_msgs__srv__DetectLicencePlate_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
void
tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence__fini(tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence * array);

/// Create array of srv/DetectLicencePlate messages.
/**
 * It allocates the memory for the array and calls
 * tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence *
tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence__create(size_t size);

/// Destroy array of srv/DetectLicencePlate messages.
/**
 * It calls
 * tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
void
tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence__destroy(tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence * array);

/// Check for srv/DetectLicencePlate message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
bool
tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence__are_equal(const tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence * lhs, const tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence * rhs);

/// Copy an array of srv/DetectLicencePlate messages.
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
tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence__copy(
  const tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence * input,
  tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence * output);

/// Initialize srv/DetectLicencePlate message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * tensorrt_infer_msgs__srv__DetectLicencePlate_Response
 * )) before or use
 * tensorrt_infer_msgs__srv__DetectLicencePlate_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
bool
tensorrt_infer_msgs__srv__DetectLicencePlate_Response__init(tensorrt_infer_msgs__srv__DetectLicencePlate_Response * msg);

/// Finalize srv/DetectLicencePlate message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
void
tensorrt_infer_msgs__srv__DetectLicencePlate_Response__fini(tensorrt_infer_msgs__srv__DetectLicencePlate_Response * msg);

/// Create srv/DetectLicencePlate message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * tensorrt_infer_msgs__srv__DetectLicencePlate_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
tensorrt_infer_msgs__srv__DetectLicencePlate_Response *
tensorrt_infer_msgs__srv__DetectLicencePlate_Response__create();

/// Destroy srv/DetectLicencePlate message.
/**
 * It calls
 * tensorrt_infer_msgs__srv__DetectLicencePlate_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
void
tensorrt_infer_msgs__srv__DetectLicencePlate_Response__destroy(tensorrt_infer_msgs__srv__DetectLicencePlate_Response * msg);

/// Check for srv/DetectLicencePlate message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
bool
tensorrt_infer_msgs__srv__DetectLicencePlate_Response__are_equal(const tensorrt_infer_msgs__srv__DetectLicencePlate_Response * lhs, const tensorrt_infer_msgs__srv__DetectLicencePlate_Response * rhs);

/// Copy a srv/DetectLicencePlate message.
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
tensorrt_infer_msgs__srv__DetectLicencePlate_Response__copy(
  const tensorrt_infer_msgs__srv__DetectLicencePlate_Response * input,
  tensorrt_infer_msgs__srv__DetectLicencePlate_Response * output);

/// Initialize array of srv/DetectLicencePlate messages.
/**
 * It allocates the memory for the number of elements and calls
 * tensorrt_infer_msgs__srv__DetectLicencePlate_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
bool
tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence__init(tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence * array, size_t size);

/// Finalize array of srv/DetectLicencePlate messages.
/**
 * It calls
 * tensorrt_infer_msgs__srv__DetectLicencePlate_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
void
tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence__fini(tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence * array);

/// Create array of srv/DetectLicencePlate messages.
/**
 * It allocates the memory for the array and calls
 * tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence *
tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence__create(size_t size);

/// Destroy array of srv/DetectLicencePlate messages.
/**
 * It calls
 * tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
void
tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence__destroy(tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence * array);

/// Check for srv/DetectLicencePlate message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensorrt_infer_msgs
bool
tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence__are_equal(const tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence * lhs, const tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence * rhs);

/// Copy an array of srv/DetectLicencePlate messages.
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
tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence__copy(
  const tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence * input,
  tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TENSORRT_INFER_MSGS__SRV__DETAIL__DETECT_LICENCE_PLATE__FUNCTIONS_H_
