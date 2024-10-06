// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tensorrt_infer_msgs:srv/DetectLicencePlate.idl
// generated code does not contain a copyright notice
#include "tensorrt_infer_msgs/srv/detail/detect_licence_plate__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `topic_name`
#include "rosidl_runtime_c/string_functions.h"

bool
tensorrt_infer_msgs__srv__DetectLicencePlate_Request__init(tensorrt_infer_msgs__srv__DetectLicencePlate_Request * msg)
{
  if (!msg) {
    return false;
  }
  // topic_name
  if (!rosidl_runtime_c__String__init(&msg->topic_name)) {
    tensorrt_infer_msgs__srv__DetectLicencePlate_Request__fini(msg);
    return false;
  }
  return true;
}

void
tensorrt_infer_msgs__srv__DetectLicencePlate_Request__fini(tensorrt_infer_msgs__srv__DetectLicencePlate_Request * msg)
{
  if (!msg) {
    return;
  }
  // topic_name
  rosidl_runtime_c__String__fini(&msg->topic_name);
}

bool
tensorrt_infer_msgs__srv__DetectLicencePlate_Request__are_equal(const tensorrt_infer_msgs__srv__DetectLicencePlate_Request * lhs, const tensorrt_infer_msgs__srv__DetectLicencePlate_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // topic_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->topic_name), &(rhs->topic_name)))
  {
    return false;
  }
  return true;
}

bool
tensorrt_infer_msgs__srv__DetectLicencePlate_Request__copy(
  const tensorrt_infer_msgs__srv__DetectLicencePlate_Request * input,
  tensorrt_infer_msgs__srv__DetectLicencePlate_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // topic_name
  if (!rosidl_runtime_c__String__copy(
      &(input->topic_name), &(output->topic_name)))
  {
    return false;
  }
  return true;
}

tensorrt_infer_msgs__srv__DetectLicencePlate_Request *
tensorrt_infer_msgs__srv__DetectLicencePlate_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensorrt_infer_msgs__srv__DetectLicencePlate_Request * msg = (tensorrt_infer_msgs__srv__DetectLicencePlate_Request *)allocator.allocate(sizeof(tensorrt_infer_msgs__srv__DetectLicencePlate_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tensorrt_infer_msgs__srv__DetectLicencePlate_Request));
  bool success = tensorrt_infer_msgs__srv__DetectLicencePlate_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tensorrt_infer_msgs__srv__DetectLicencePlate_Request__destroy(tensorrt_infer_msgs__srv__DetectLicencePlate_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tensorrt_infer_msgs__srv__DetectLicencePlate_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence__init(tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensorrt_infer_msgs__srv__DetectLicencePlate_Request * data = NULL;

  if (size) {
    data = (tensorrt_infer_msgs__srv__DetectLicencePlate_Request *)allocator.zero_allocate(size, sizeof(tensorrt_infer_msgs__srv__DetectLicencePlate_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tensorrt_infer_msgs__srv__DetectLicencePlate_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tensorrt_infer_msgs__srv__DetectLicencePlate_Request__fini(&data[i - 1]);
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
tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence__fini(tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence * array)
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
      tensorrt_infer_msgs__srv__DetectLicencePlate_Request__fini(&array->data[i]);
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

tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence *
tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence * array = (tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence *)allocator.allocate(sizeof(tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence__destroy(tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence__are_equal(const tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence * lhs, const tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tensorrt_infer_msgs__srv__DetectLicencePlate_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence__copy(
  const tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence * input,
  tensorrt_infer_msgs__srv__DetectLicencePlate_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tensorrt_infer_msgs__srv__DetectLicencePlate_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tensorrt_infer_msgs__srv__DetectLicencePlate_Request * data =
      (tensorrt_infer_msgs__srv__DetectLicencePlate_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tensorrt_infer_msgs__srv__DetectLicencePlate_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tensorrt_infer_msgs__srv__DetectLicencePlate_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tensorrt_infer_msgs__srv__DetectLicencePlate_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `plate_number`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
tensorrt_infer_msgs__srv__DetectLicencePlate_Response__init(tensorrt_infer_msgs__srv__DetectLicencePlate_Response * msg)
{
  if (!msg) {
    return false;
  }
  // plate_number
  if (!rosidl_runtime_c__String__init(&msg->plate_number)) {
    tensorrt_infer_msgs__srv__DetectLicencePlate_Response__fini(msg);
    return false;
  }
  // det_core
  // rec_score
  return true;
}

void
tensorrt_infer_msgs__srv__DetectLicencePlate_Response__fini(tensorrt_infer_msgs__srv__DetectLicencePlate_Response * msg)
{
  if (!msg) {
    return;
  }
  // plate_number
  rosidl_runtime_c__String__fini(&msg->plate_number);
  // det_core
  // rec_score
}

bool
tensorrt_infer_msgs__srv__DetectLicencePlate_Response__are_equal(const tensorrt_infer_msgs__srv__DetectLicencePlate_Response * lhs, const tensorrt_infer_msgs__srv__DetectLicencePlate_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // plate_number
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->plate_number), &(rhs->plate_number)))
  {
    return false;
  }
  // det_core
  if (lhs->det_core != rhs->det_core) {
    return false;
  }
  // rec_score
  if (lhs->rec_score != rhs->rec_score) {
    return false;
  }
  return true;
}

bool
tensorrt_infer_msgs__srv__DetectLicencePlate_Response__copy(
  const tensorrt_infer_msgs__srv__DetectLicencePlate_Response * input,
  tensorrt_infer_msgs__srv__DetectLicencePlate_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // plate_number
  if (!rosidl_runtime_c__String__copy(
      &(input->plate_number), &(output->plate_number)))
  {
    return false;
  }
  // det_core
  output->det_core = input->det_core;
  // rec_score
  output->rec_score = input->rec_score;
  return true;
}

tensorrt_infer_msgs__srv__DetectLicencePlate_Response *
tensorrt_infer_msgs__srv__DetectLicencePlate_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensorrt_infer_msgs__srv__DetectLicencePlate_Response * msg = (tensorrt_infer_msgs__srv__DetectLicencePlate_Response *)allocator.allocate(sizeof(tensorrt_infer_msgs__srv__DetectLicencePlate_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tensorrt_infer_msgs__srv__DetectLicencePlate_Response));
  bool success = tensorrt_infer_msgs__srv__DetectLicencePlate_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tensorrt_infer_msgs__srv__DetectLicencePlate_Response__destroy(tensorrt_infer_msgs__srv__DetectLicencePlate_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tensorrt_infer_msgs__srv__DetectLicencePlate_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence__init(tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensorrt_infer_msgs__srv__DetectLicencePlate_Response * data = NULL;

  if (size) {
    data = (tensorrt_infer_msgs__srv__DetectLicencePlate_Response *)allocator.zero_allocate(size, sizeof(tensorrt_infer_msgs__srv__DetectLicencePlate_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tensorrt_infer_msgs__srv__DetectLicencePlate_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tensorrt_infer_msgs__srv__DetectLicencePlate_Response__fini(&data[i - 1]);
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
tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence__fini(tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence * array)
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
      tensorrt_infer_msgs__srv__DetectLicencePlate_Response__fini(&array->data[i]);
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

tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence *
tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence * array = (tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence *)allocator.allocate(sizeof(tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence__destroy(tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence__are_equal(const tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence * lhs, const tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tensorrt_infer_msgs__srv__DetectLicencePlate_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence__copy(
  const tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence * input,
  tensorrt_infer_msgs__srv__DetectLicencePlate_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tensorrt_infer_msgs__srv__DetectLicencePlate_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tensorrt_infer_msgs__srv__DetectLicencePlate_Response * data =
      (tensorrt_infer_msgs__srv__DetectLicencePlate_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tensorrt_infer_msgs__srv__DetectLicencePlate_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tensorrt_infer_msgs__srv__DetectLicencePlate_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tensorrt_infer_msgs__srv__DetectLicencePlate_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
