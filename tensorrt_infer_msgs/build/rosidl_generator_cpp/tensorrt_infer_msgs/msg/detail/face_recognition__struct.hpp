// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tensorrt_infer_msgs:msg/FaceRecognition.idl
// generated code does not contain a copyright notice

#ifndef TENSORRT_INFER_MSGS__MSG__DETAIL__FACE_RECOGNITION__STRUCT_HPP_
#define TENSORRT_INFER_MSGS__MSG__DETAIL__FACE_RECOGNITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'cropped_faces'
#include "sensor_msgs/msg/detail/image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tensorrt_infer_msgs__msg__FaceRecognition __attribute__((deprecated))
#else
# define DEPRECATED__tensorrt_infer_msgs__msg__FaceRecognition __declspec(deprecated)
#endif

namespace tensorrt_infer_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FaceRecognition_
{
  using Type = FaceRecognition_<ContainerAllocator>;

  explicit FaceRecognition_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->camera_id = 0;
      this->timestamp = "";
    }
  }

  explicit FaceRecognition_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->camera_id = 0;
      this->timestamp = "";
    }
  }

  // field types and members
  using _user_ids_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _user_ids_type user_ids;
  using _camera_id_type =
    uint16_t;
  _camera_id_type camera_id;
  using _timestamp_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _timestamp_type timestamp;
  using _rec_scores_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _rec_scores_type rec_scores;
  using _cropped_faces_type =
    std::vector<sensor_msgs::msg::Image_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sensor_msgs::msg::Image_<ContainerAllocator>>>;
  _cropped_faces_type cropped_faces;

  // setters for named parameter idiom
  Type & set__user_ids(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->user_ids = _arg;
    return *this;
  }
  Type & set__camera_id(
    const uint16_t & _arg)
  {
    this->camera_id = _arg;
    return *this;
  }
  Type & set__timestamp(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__rec_scores(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->rec_scores = _arg;
    return *this;
  }
  Type & set__cropped_faces(
    const std::vector<sensor_msgs::msg::Image_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sensor_msgs::msg::Image_<ContainerAllocator>>> & _arg)
  {
    this->cropped_faces = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tensorrt_infer_msgs::msg::FaceRecognition_<ContainerAllocator> *;
  using ConstRawPtr =
    const tensorrt_infer_msgs::msg::FaceRecognition_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tensorrt_infer_msgs::msg::FaceRecognition_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tensorrt_infer_msgs::msg::FaceRecognition_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tensorrt_infer_msgs::msg::FaceRecognition_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tensorrt_infer_msgs::msg::FaceRecognition_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tensorrt_infer_msgs::msg::FaceRecognition_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tensorrt_infer_msgs::msg::FaceRecognition_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tensorrt_infer_msgs::msg::FaceRecognition_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tensorrt_infer_msgs::msg::FaceRecognition_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tensorrt_infer_msgs__msg__FaceRecognition
    std::shared_ptr<tensorrt_infer_msgs::msg::FaceRecognition_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tensorrt_infer_msgs__msg__FaceRecognition
    std::shared_ptr<tensorrt_infer_msgs::msg::FaceRecognition_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FaceRecognition_ & other) const
  {
    if (this->user_ids != other.user_ids) {
      return false;
    }
    if (this->camera_id != other.camera_id) {
      return false;
    }
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->rec_scores != other.rec_scores) {
      return false;
    }
    if (this->cropped_faces != other.cropped_faces) {
      return false;
    }
    return true;
  }
  bool operator!=(const FaceRecognition_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FaceRecognition_

// alias to use template instance with default allocator
using FaceRecognition =
  tensorrt_infer_msgs::msg::FaceRecognition_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tensorrt_infer_msgs

#endif  // TENSORRT_INFER_MSGS__MSG__DETAIL__FACE_RECOGNITION__STRUCT_HPP_
