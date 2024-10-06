// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tensorrt_infer_msgs:srv/DetectLicencePlate.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tensorrt_infer_msgs/srv/detail/detect_licence_plate__rosidl_typesupport_introspection_c.h"
#include "tensorrt_infer_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tensorrt_infer_msgs/srv/detail/detect_licence_plate__functions.h"
#include "tensorrt_infer_msgs/srv/detail/detect_licence_plate__struct.h"


// Include directives for member types
// Member `topic_name`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tensorrt_infer_msgs__srv__DetectLicencePlate_Request__rosidl_typesupport_introspection_c__DetectLicencePlate_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tensorrt_infer_msgs__srv__DetectLicencePlate_Request__init(message_memory);
}

void tensorrt_infer_msgs__srv__DetectLicencePlate_Request__rosidl_typesupport_introspection_c__DetectLicencePlate_Request_fini_function(void * message_memory)
{
  tensorrt_infer_msgs__srv__DetectLicencePlate_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tensorrt_infer_msgs__srv__DetectLicencePlate_Request__rosidl_typesupport_introspection_c__DetectLicencePlate_Request_message_member_array[1] = {
  {
    "topic_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensorrt_infer_msgs__srv__DetectLicencePlate_Request, topic_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tensorrt_infer_msgs__srv__DetectLicencePlate_Request__rosidl_typesupport_introspection_c__DetectLicencePlate_Request_message_members = {
  "tensorrt_infer_msgs__srv",  // message namespace
  "DetectLicencePlate_Request",  // message name
  1,  // number of fields
  sizeof(tensorrt_infer_msgs__srv__DetectLicencePlate_Request),
  tensorrt_infer_msgs__srv__DetectLicencePlate_Request__rosidl_typesupport_introspection_c__DetectLicencePlate_Request_message_member_array,  // message members
  tensorrt_infer_msgs__srv__DetectLicencePlate_Request__rosidl_typesupport_introspection_c__DetectLicencePlate_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  tensorrt_infer_msgs__srv__DetectLicencePlate_Request__rosidl_typesupport_introspection_c__DetectLicencePlate_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tensorrt_infer_msgs__srv__DetectLicencePlate_Request__rosidl_typesupport_introspection_c__DetectLicencePlate_Request_message_type_support_handle = {
  0,
  &tensorrt_infer_msgs__srv__DetectLicencePlate_Request__rosidl_typesupport_introspection_c__DetectLicencePlate_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tensorrt_infer_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tensorrt_infer_msgs, srv, DetectLicencePlate_Request)() {
  if (!tensorrt_infer_msgs__srv__DetectLicencePlate_Request__rosidl_typesupport_introspection_c__DetectLicencePlate_Request_message_type_support_handle.typesupport_identifier) {
    tensorrt_infer_msgs__srv__DetectLicencePlate_Request__rosidl_typesupport_introspection_c__DetectLicencePlate_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tensorrt_infer_msgs__srv__DetectLicencePlate_Request__rosidl_typesupport_introspection_c__DetectLicencePlate_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "tensorrt_infer_msgs/srv/detail/detect_licence_plate__rosidl_typesupport_introspection_c.h"
// already included above
// #include "tensorrt_infer_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "tensorrt_infer_msgs/srv/detail/detect_licence_plate__functions.h"
// already included above
// #include "tensorrt_infer_msgs/srv/detail/detect_licence_plate__struct.h"


// Include directives for member types
// Member `plate_number`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tensorrt_infer_msgs__srv__DetectLicencePlate_Response__rosidl_typesupport_introspection_c__DetectLicencePlate_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tensorrt_infer_msgs__srv__DetectLicencePlate_Response__init(message_memory);
}

void tensorrt_infer_msgs__srv__DetectLicencePlate_Response__rosidl_typesupport_introspection_c__DetectLicencePlate_Response_fini_function(void * message_memory)
{
  tensorrt_infer_msgs__srv__DetectLicencePlate_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tensorrt_infer_msgs__srv__DetectLicencePlate_Response__rosidl_typesupport_introspection_c__DetectLicencePlate_Response_message_member_array[3] = {
  {
    "plate_number",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensorrt_infer_msgs__srv__DetectLicencePlate_Response, plate_number),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "det_core",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensorrt_infer_msgs__srv__DetectLicencePlate_Response, det_core),  // bytes offset in struct
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
    offsetof(tensorrt_infer_msgs__srv__DetectLicencePlate_Response, rec_score),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tensorrt_infer_msgs__srv__DetectLicencePlate_Response__rosidl_typesupport_introspection_c__DetectLicencePlate_Response_message_members = {
  "tensorrt_infer_msgs__srv",  // message namespace
  "DetectLicencePlate_Response",  // message name
  3,  // number of fields
  sizeof(tensorrt_infer_msgs__srv__DetectLicencePlate_Response),
  tensorrt_infer_msgs__srv__DetectLicencePlate_Response__rosidl_typesupport_introspection_c__DetectLicencePlate_Response_message_member_array,  // message members
  tensorrt_infer_msgs__srv__DetectLicencePlate_Response__rosidl_typesupport_introspection_c__DetectLicencePlate_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  tensorrt_infer_msgs__srv__DetectLicencePlate_Response__rosidl_typesupport_introspection_c__DetectLicencePlate_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tensorrt_infer_msgs__srv__DetectLicencePlate_Response__rosidl_typesupport_introspection_c__DetectLicencePlate_Response_message_type_support_handle = {
  0,
  &tensorrt_infer_msgs__srv__DetectLicencePlate_Response__rosidl_typesupport_introspection_c__DetectLicencePlate_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tensorrt_infer_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tensorrt_infer_msgs, srv, DetectLicencePlate_Response)() {
  if (!tensorrt_infer_msgs__srv__DetectLicencePlate_Response__rosidl_typesupport_introspection_c__DetectLicencePlate_Response_message_type_support_handle.typesupport_identifier) {
    tensorrt_infer_msgs__srv__DetectLicencePlate_Response__rosidl_typesupport_introspection_c__DetectLicencePlate_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tensorrt_infer_msgs__srv__DetectLicencePlate_Response__rosidl_typesupport_introspection_c__DetectLicencePlate_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "tensorrt_infer_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "tensorrt_infer_msgs/srv/detail/detect_licence_plate__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers tensorrt_infer_msgs__srv__detail__detect_licence_plate__rosidl_typesupport_introspection_c__DetectLicencePlate_service_members = {
  "tensorrt_infer_msgs__srv",  // service namespace
  "DetectLicencePlate",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // tensorrt_infer_msgs__srv__detail__detect_licence_plate__rosidl_typesupport_introspection_c__DetectLicencePlate_Request_message_type_support_handle,
  NULL  // response message
  // tensorrt_infer_msgs__srv__detail__detect_licence_plate__rosidl_typesupport_introspection_c__DetectLicencePlate_Response_message_type_support_handle
};

static rosidl_service_type_support_t tensorrt_infer_msgs__srv__detail__detect_licence_plate__rosidl_typesupport_introspection_c__DetectLicencePlate_service_type_support_handle = {
  0,
  &tensorrt_infer_msgs__srv__detail__detect_licence_plate__rosidl_typesupport_introspection_c__DetectLicencePlate_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tensorrt_infer_msgs, srv, DetectLicencePlate_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tensorrt_infer_msgs, srv, DetectLicencePlate_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tensorrt_infer_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tensorrt_infer_msgs, srv, DetectLicencePlate)() {
  if (!tensorrt_infer_msgs__srv__detail__detect_licence_plate__rosidl_typesupport_introspection_c__DetectLicencePlate_service_type_support_handle.typesupport_identifier) {
    tensorrt_infer_msgs__srv__detail__detect_licence_plate__rosidl_typesupport_introspection_c__DetectLicencePlate_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)tensorrt_infer_msgs__srv__detail__detect_licence_plate__rosidl_typesupport_introspection_c__DetectLicencePlate_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tensorrt_infer_msgs, srv, DetectLicencePlate_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tensorrt_infer_msgs, srv, DetectLicencePlate_Response)()->data;
  }

  return &tensorrt_infer_msgs__srv__detail__detect_licence_plate__rosidl_typesupport_introspection_c__DetectLicencePlate_service_type_support_handle;
}
