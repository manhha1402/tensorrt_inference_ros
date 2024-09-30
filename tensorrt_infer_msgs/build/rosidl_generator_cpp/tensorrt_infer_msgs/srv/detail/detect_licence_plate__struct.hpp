// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tensorrt_infer_msgs:srv/DetectLicencePlate.idl
// generated code does not contain a copyright notice

#ifndef TENSORRT_INFER_MSGS__SRV__DETAIL__DETECT_LICENCE_PLATE__STRUCT_HPP_
#define TENSORRT_INFER_MSGS__SRV__DETAIL__DETECT_LICENCE_PLATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__tensorrt_infer_msgs__srv__DetectLicencePlate_Request __attribute__((deprecated))
#else
# define DEPRECATED__tensorrt_infer_msgs__srv__DetectLicencePlate_Request __declspec(deprecated)
#endif

namespace tensorrt_infer_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DetectLicencePlate_Request_
{
  using Type = DetectLicencePlate_Request_<ContainerAllocator>;

  explicit DetectLicencePlate_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->topic_name = "";
    }
  }

  explicit DetectLicencePlate_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : topic_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->topic_name = "";
    }
  }

  // field types and members
  using _topic_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _topic_name_type topic_name;

  // setters for named parameter idiom
  Type & set__topic_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->topic_name = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tensorrt_infer_msgs::srv::DetectLicencePlate_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const tensorrt_infer_msgs::srv::DetectLicencePlate_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tensorrt_infer_msgs::srv::DetectLicencePlate_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tensorrt_infer_msgs::srv::DetectLicencePlate_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tensorrt_infer_msgs::srv::DetectLicencePlate_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tensorrt_infer_msgs::srv::DetectLicencePlate_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tensorrt_infer_msgs::srv::DetectLicencePlate_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tensorrt_infer_msgs::srv::DetectLicencePlate_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tensorrt_infer_msgs::srv::DetectLicencePlate_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tensorrt_infer_msgs::srv::DetectLicencePlate_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tensorrt_infer_msgs__srv__DetectLicencePlate_Request
    std::shared_ptr<tensorrt_infer_msgs::srv::DetectLicencePlate_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tensorrt_infer_msgs__srv__DetectLicencePlate_Request
    std::shared_ptr<tensorrt_infer_msgs::srv::DetectLicencePlate_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectLicencePlate_Request_ & other) const
  {
    if (this->topic_name != other.topic_name) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectLicencePlate_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectLicencePlate_Request_

// alias to use template instance with default allocator
using DetectLicencePlate_Request =
  tensorrt_infer_msgs::srv::DetectLicencePlate_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tensorrt_infer_msgs


#ifndef _WIN32
# define DEPRECATED__tensorrt_infer_msgs__srv__DetectLicencePlate_Response __attribute__((deprecated))
#else
# define DEPRECATED__tensorrt_infer_msgs__srv__DetectLicencePlate_Response __declspec(deprecated)
#endif

namespace tensorrt_infer_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DetectLicencePlate_Response_
{
  using Type = DetectLicencePlate_Response_<ContainerAllocator>;

  explicit DetectLicencePlate_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->plate_number = "";
      this->det_core = 0.0;
      this->rec_score = 0.0;
    }
  }

  explicit DetectLicencePlate_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : plate_number(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->plate_number = "";
      this->det_core = 0.0;
      this->rec_score = 0.0;
    }
  }

  // field types and members
  using _plate_number_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _plate_number_type plate_number;
  using _det_core_type =
    double;
  _det_core_type det_core;
  using _rec_score_type =
    double;
  _rec_score_type rec_score;

  // setters for named parameter idiom
  Type & set__plate_number(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->plate_number = _arg;
    return *this;
  }
  Type & set__det_core(
    const double & _arg)
  {
    this->det_core = _arg;
    return *this;
  }
  Type & set__rec_score(
    const double & _arg)
  {
    this->rec_score = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tensorrt_infer_msgs::srv::DetectLicencePlate_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const tensorrt_infer_msgs::srv::DetectLicencePlate_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tensorrt_infer_msgs::srv::DetectLicencePlate_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tensorrt_infer_msgs::srv::DetectLicencePlate_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tensorrt_infer_msgs::srv::DetectLicencePlate_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tensorrt_infer_msgs::srv::DetectLicencePlate_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tensorrt_infer_msgs::srv::DetectLicencePlate_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tensorrt_infer_msgs::srv::DetectLicencePlate_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tensorrt_infer_msgs::srv::DetectLicencePlate_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tensorrt_infer_msgs::srv::DetectLicencePlate_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tensorrt_infer_msgs__srv__DetectLicencePlate_Response
    std::shared_ptr<tensorrt_infer_msgs::srv::DetectLicencePlate_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tensorrt_infer_msgs__srv__DetectLicencePlate_Response
    std::shared_ptr<tensorrt_infer_msgs::srv::DetectLicencePlate_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectLicencePlate_Response_ & other) const
  {
    if (this->plate_number != other.plate_number) {
      return false;
    }
    if (this->det_core != other.det_core) {
      return false;
    }
    if (this->rec_score != other.rec_score) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectLicencePlate_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectLicencePlate_Response_

// alias to use template instance with default allocator
using DetectLicencePlate_Response =
  tensorrt_infer_msgs::srv::DetectLicencePlate_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tensorrt_infer_msgs

namespace tensorrt_infer_msgs
{

namespace srv
{

struct DetectLicencePlate
{
  using Request = tensorrt_infer_msgs::srv::DetectLicencePlate_Request;
  using Response = tensorrt_infer_msgs::srv::DetectLicencePlate_Response;
};

}  // namespace srv

}  // namespace tensorrt_infer_msgs

#endif  // TENSORRT_INFER_MSGS__SRV__DETAIL__DETECT_LICENCE_PLATE__STRUCT_HPP_
