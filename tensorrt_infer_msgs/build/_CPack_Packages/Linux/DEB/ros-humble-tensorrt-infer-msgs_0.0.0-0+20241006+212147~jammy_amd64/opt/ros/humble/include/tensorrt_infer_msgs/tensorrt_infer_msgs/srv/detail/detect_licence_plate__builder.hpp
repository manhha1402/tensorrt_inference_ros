// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tensorrt_infer_msgs:srv/DetectLicencePlate.idl
// generated code does not contain a copyright notice

#ifndef TENSORRT_INFER_MSGS__SRV__DETAIL__DETECT_LICENCE_PLATE__BUILDER_HPP_
#define TENSORRT_INFER_MSGS__SRV__DETAIL__DETECT_LICENCE_PLATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tensorrt_infer_msgs/srv/detail/detect_licence_plate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tensorrt_infer_msgs
{

namespace srv
{

namespace builder
{

class Init_DetectLicencePlate_Request_topic_name
{
public:
  Init_DetectLicencePlate_Request_topic_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tensorrt_infer_msgs::srv::DetectLicencePlate_Request topic_name(::tensorrt_infer_msgs::srv::DetectLicencePlate_Request::_topic_name_type arg)
  {
    msg_.topic_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tensorrt_infer_msgs::srv::DetectLicencePlate_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tensorrt_infer_msgs::srv::DetectLicencePlate_Request>()
{
  return tensorrt_infer_msgs::srv::builder::Init_DetectLicencePlate_Request_topic_name();
}

}  // namespace tensorrt_infer_msgs


namespace tensorrt_infer_msgs
{

namespace srv
{

namespace builder
{

class Init_DetectLicencePlate_Response_rec_score
{
public:
  explicit Init_DetectLicencePlate_Response_rec_score(::tensorrt_infer_msgs::srv::DetectLicencePlate_Response & msg)
  : msg_(msg)
  {}
  ::tensorrt_infer_msgs::srv::DetectLicencePlate_Response rec_score(::tensorrt_infer_msgs::srv::DetectLicencePlate_Response::_rec_score_type arg)
  {
    msg_.rec_score = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tensorrt_infer_msgs::srv::DetectLicencePlate_Response msg_;
};

class Init_DetectLicencePlate_Response_det_core
{
public:
  explicit Init_DetectLicencePlate_Response_det_core(::tensorrt_infer_msgs::srv::DetectLicencePlate_Response & msg)
  : msg_(msg)
  {}
  Init_DetectLicencePlate_Response_rec_score det_core(::tensorrt_infer_msgs::srv::DetectLicencePlate_Response::_det_core_type arg)
  {
    msg_.det_core = std::move(arg);
    return Init_DetectLicencePlate_Response_rec_score(msg_);
  }

private:
  ::tensorrt_infer_msgs::srv::DetectLicencePlate_Response msg_;
};

class Init_DetectLicencePlate_Response_plate_number
{
public:
  Init_DetectLicencePlate_Response_plate_number()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectLicencePlate_Response_det_core plate_number(::tensorrt_infer_msgs::srv::DetectLicencePlate_Response::_plate_number_type arg)
  {
    msg_.plate_number = std::move(arg);
    return Init_DetectLicencePlate_Response_det_core(msg_);
  }

private:
  ::tensorrt_infer_msgs::srv::DetectLicencePlate_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tensorrt_infer_msgs::srv::DetectLicencePlate_Response>()
{
  return tensorrt_infer_msgs::srv::builder::Init_DetectLicencePlate_Response_plate_number();
}

}  // namespace tensorrt_infer_msgs

#endif  // TENSORRT_INFER_MSGS__SRV__DETAIL__DETECT_LICENCE_PLATE__BUILDER_HPP_
