// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from tensorrt_infer_msgs:srv/DetectLicencePlate.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "tensorrt_infer_msgs/srv/detail/detect_licence_plate__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace tensorrt_infer_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void DetectLicencePlate_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) tensorrt_infer_msgs::srv::DetectLicencePlate_Request(_init);
}

void DetectLicencePlate_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<tensorrt_infer_msgs::srv::DetectLicencePlate_Request *>(message_memory);
  typed_message->~DetectLicencePlate_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DetectLicencePlate_Request_message_member_array[1] = {
  {
    "topic_name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensorrt_infer_msgs::srv::DetectLicencePlate_Request, topic_name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DetectLicencePlate_Request_message_members = {
  "tensorrt_infer_msgs::srv",  // message namespace
  "DetectLicencePlate_Request",  // message name
  1,  // number of fields
  sizeof(tensorrt_infer_msgs::srv::DetectLicencePlate_Request),
  DetectLicencePlate_Request_message_member_array,  // message members
  DetectLicencePlate_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  DetectLicencePlate_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DetectLicencePlate_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DetectLicencePlate_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace tensorrt_infer_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tensorrt_infer_msgs::srv::DetectLicencePlate_Request>()
{
  return &::tensorrt_infer_msgs::srv::rosidl_typesupport_introspection_cpp::DetectLicencePlate_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tensorrt_infer_msgs, srv, DetectLicencePlate_Request)() {
  return &::tensorrt_infer_msgs::srv::rosidl_typesupport_introspection_cpp::DetectLicencePlate_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "tensorrt_infer_msgs/srv/detail/detect_licence_plate__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace tensorrt_infer_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void DetectLicencePlate_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) tensorrt_infer_msgs::srv::DetectLicencePlate_Response(_init);
}

void DetectLicencePlate_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<tensorrt_infer_msgs::srv::DetectLicencePlate_Response *>(message_memory);
  typed_message->~DetectLicencePlate_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DetectLicencePlate_Response_message_member_array[3] = {
  {
    "plate_number",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensorrt_infer_msgs::srv::DetectLicencePlate_Response, plate_number),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "det_core",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensorrt_infer_msgs::srv::DetectLicencePlate_Response, det_core),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "rec_score",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensorrt_infer_msgs::srv::DetectLicencePlate_Response, rec_score),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DetectLicencePlate_Response_message_members = {
  "tensorrt_infer_msgs::srv",  // message namespace
  "DetectLicencePlate_Response",  // message name
  3,  // number of fields
  sizeof(tensorrt_infer_msgs::srv::DetectLicencePlate_Response),
  DetectLicencePlate_Response_message_member_array,  // message members
  DetectLicencePlate_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  DetectLicencePlate_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DetectLicencePlate_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DetectLicencePlate_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace tensorrt_infer_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tensorrt_infer_msgs::srv::DetectLicencePlate_Response>()
{
  return &::tensorrt_infer_msgs::srv::rosidl_typesupport_introspection_cpp::DetectLicencePlate_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tensorrt_infer_msgs, srv, DetectLicencePlate_Response)() {
  return &::tensorrt_infer_msgs::srv::rosidl_typesupport_introspection_cpp::DetectLicencePlate_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "tensorrt_infer_msgs/srv/detail/detect_licence_plate__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace tensorrt_infer_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers DetectLicencePlate_service_members = {
  "tensorrt_infer_msgs::srv",  // service namespace
  "DetectLicencePlate",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<tensorrt_infer_msgs::srv::DetectLicencePlate>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t DetectLicencePlate_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DetectLicencePlate_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace tensorrt_infer_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<tensorrt_infer_msgs::srv::DetectLicencePlate>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::tensorrt_infer_msgs::srv::rosidl_typesupport_introspection_cpp::DetectLicencePlate_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::tensorrt_infer_msgs::srv::DetectLicencePlate_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::tensorrt_infer_msgs::srv::DetectLicencePlate_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tensorrt_infer_msgs, srv, DetectLicencePlate)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<tensorrt_infer_msgs::srv::DetectLicencePlate>();
}

#ifdef __cplusplus
}
#endif
