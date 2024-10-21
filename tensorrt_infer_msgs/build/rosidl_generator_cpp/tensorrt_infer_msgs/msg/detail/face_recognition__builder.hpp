// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tensorrt_infer_msgs:msg/FaceRecognition.idl
// generated code does not contain a copyright notice

#ifndef TENSORRT_INFER_MSGS__MSG__DETAIL__FACE_RECOGNITION__BUILDER_HPP_
#define TENSORRT_INFER_MSGS__MSG__DETAIL__FACE_RECOGNITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tensorrt_infer_msgs/msg/detail/face_recognition__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tensorrt_infer_msgs
{

namespace msg
{

namespace builder
{

class Init_FaceRecognition_cropped_faces
{
public:
  explicit Init_FaceRecognition_cropped_faces(::tensorrt_infer_msgs::msg::FaceRecognition & msg)
  : msg_(msg)
  {}
  ::tensorrt_infer_msgs::msg::FaceRecognition cropped_faces(::tensorrt_infer_msgs::msg::FaceRecognition::_cropped_faces_type arg)
  {
    msg_.cropped_faces = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tensorrt_infer_msgs::msg::FaceRecognition msg_;
};

class Init_FaceRecognition_rec_scores
{
public:
  explicit Init_FaceRecognition_rec_scores(::tensorrt_infer_msgs::msg::FaceRecognition & msg)
  : msg_(msg)
  {}
  Init_FaceRecognition_cropped_faces rec_scores(::tensorrt_infer_msgs::msg::FaceRecognition::_rec_scores_type arg)
  {
    msg_.rec_scores = std::move(arg);
    return Init_FaceRecognition_cropped_faces(msg_);
  }

private:
  ::tensorrt_infer_msgs::msg::FaceRecognition msg_;
};

class Init_FaceRecognition_timestamp
{
public:
  explicit Init_FaceRecognition_timestamp(::tensorrt_infer_msgs::msg::FaceRecognition & msg)
  : msg_(msg)
  {}
  Init_FaceRecognition_rec_scores timestamp(::tensorrt_infer_msgs::msg::FaceRecognition::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_FaceRecognition_rec_scores(msg_);
  }

private:
  ::tensorrt_infer_msgs::msg::FaceRecognition msg_;
};

class Init_FaceRecognition_camera_id
{
public:
  explicit Init_FaceRecognition_camera_id(::tensorrt_infer_msgs::msg::FaceRecognition & msg)
  : msg_(msg)
  {}
  Init_FaceRecognition_timestamp camera_id(::tensorrt_infer_msgs::msg::FaceRecognition::_camera_id_type arg)
  {
    msg_.camera_id = std::move(arg);
    return Init_FaceRecognition_timestamp(msg_);
  }

private:
  ::tensorrt_infer_msgs::msg::FaceRecognition msg_;
};

class Init_FaceRecognition_user_ids
{
public:
  Init_FaceRecognition_user_ids()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FaceRecognition_camera_id user_ids(::tensorrt_infer_msgs::msg::FaceRecognition::_user_ids_type arg)
  {
    msg_.user_ids = std::move(arg);
    return Init_FaceRecognition_camera_id(msg_);
  }

private:
  ::tensorrt_infer_msgs::msg::FaceRecognition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tensorrt_infer_msgs::msg::FaceRecognition>()
{
  return tensorrt_infer_msgs::msg::builder::Init_FaceRecognition_user_ids();
}

}  // namespace tensorrt_infer_msgs

#endif  // TENSORRT_INFER_MSGS__MSG__DETAIL__FACE_RECOGNITION__BUILDER_HPP_
