// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tensorrt_infer_msgs:msg/FaceRecognition.idl
// generated code does not contain a copyright notice
#include "tensorrt_infer_msgs/msg/detail/face_recognition__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
// Member `timestamp`
#include "rosidl_runtime_c/string_functions.h"

bool
tensorrt_infer_msgs__msg__FaceRecognition__init(tensorrt_infer_msgs__msg__FaceRecognition * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    tensorrt_infer_msgs__msg__FaceRecognition__fini(msg);
    return false;
  }
  // timestamp
  if (!rosidl_runtime_c__String__init(&msg->timestamp)) {
    tensorrt_infer_msgs__msg__FaceRecognition__fini(msg);
    return false;
  }
  // rec_score
  // camera_id
  return true;
}

void
tensorrt_infer_msgs__msg__FaceRecognition__fini(tensorrt_infer_msgs__msg__FaceRecognition * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // timestamp
  rosidl_runtime_c__String__fini(&msg->timestamp);
  // rec_score
  // camera_id
}

bool
tensorrt_infer_msgs__msg__FaceRecognition__are_equal(const tensorrt_infer_msgs__msg__FaceRecognition * lhs, const tensorrt_infer_msgs__msg__FaceRecognition * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // timestamp
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->timestamp), &(rhs->timestamp)))
  {
    return false;
  }
  // rec_score
  if (lhs->rec_score != rhs->rec_score) {
    return false;
  }
  // camera_id
  if (lhs->camera_id != rhs->camera_id) {
    return false;
  }
  return true;
}

bool
tensorrt_infer_msgs__msg__FaceRecognition__copy(
  const tensorrt_infer_msgs__msg__FaceRecognition * input,
  tensorrt_infer_msgs__msg__FaceRecognition * output)
{
  if (!input || !output) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // timestamp
  if (!rosidl_runtime_c__String__copy(
      &(input->timestamp), &(output->timestamp)))
  {
    return false;
  }
  // rec_score
  output->rec_score = input->rec_score;
  // camera_id
  output->camera_id = input->camera_id;
  return true;
}

tensorrt_infer_msgs__msg__FaceRecognition *
tensorrt_infer_msgs__msg__FaceRecognition__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensorrt_infer_msgs__msg__FaceRecognition * msg = (tensorrt_infer_msgs__msg__FaceRecognition *)allocator.allocate(sizeof(tensorrt_infer_msgs__msg__FaceRecognition), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tensorrt_infer_msgs__msg__FaceRecognition));
  bool success = tensorrt_infer_msgs__msg__FaceRecognition__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tensorrt_infer_msgs__msg__FaceRecognition__destroy(tensorrt_infer_msgs__msg__FaceRecognition * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tensorrt_infer_msgs__msg__FaceRecognition__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tensorrt_infer_msgs__msg__FaceRecognition__Sequence__init(tensorrt_infer_msgs__msg__FaceRecognition__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensorrt_infer_msgs__msg__FaceRecognition * data = NULL;

  if (size) {
    data = (tensorrt_infer_msgs__msg__FaceRecognition *)allocator.zero_allocate(size, sizeof(tensorrt_infer_msgs__msg__FaceRecognition), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tensorrt_infer_msgs__msg__FaceRecognition__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tensorrt_infer_msgs__msg__FaceRecognition__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
tensorrt_infer_msgs__msg__FaceRecognition__Sequence__fini(tensorrt_infer_msgs__msg__FaceRecognition__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tensorrt_infer_msgs__msg__FaceRecognition__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

tensorrt_infer_msgs__msg__FaceRecognition__Sequence *
tensorrt_infer_msgs__msg__FaceRecognition__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensorrt_infer_msgs__msg__FaceRecognition__Sequence * array = (tensorrt_infer_msgs__msg__FaceRecognition__Sequence *)allocator.allocate(sizeof(tensorrt_infer_msgs__msg__FaceRecognition__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tensorrt_infer_msgs__msg__FaceRecognition__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tensorrt_infer_msgs__msg__FaceRecognition__Sequence__destroy(tensorrt_infer_msgs__msg__FaceRecognition__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tensorrt_infer_msgs__msg__FaceRecognition__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tensorrt_infer_msgs__msg__FaceRecognition__Sequence__are_equal(const tensorrt_infer_msgs__msg__FaceRecognition__Sequence * lhs, const tensorrt_infer_msgs__msg__FaceRecognition__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tensorrt_infer_msgs__msg__FaceRecognition__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tensorrt_infer_msgs__msg__FaceRecognition__Sequence__copy(
  const tensorrt_infer_msgs__msg__FaceRecognition__Sequence * input,
  tensorrt_infer_msgs__msg__FaceRecognition__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tensorrt_infer_msgs__msg__FaceRecognition);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tensorrt_infer_msgs__msg__FaceRecognition * data =
      (tensorrt_infer_msgs__msg__FaceRecognition *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tensorrt_infer_msgs__msg__FaceRecognition__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tensorrt_infer_msgs__msg__FaceRecognition__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tensorrt_infer_msgs__msg__FaceRecognition__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
