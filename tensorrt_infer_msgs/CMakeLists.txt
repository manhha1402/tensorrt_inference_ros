cmake_minimum_required(VERSION 3.5)
project(tensorrt_infer_msgs)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()


# Default to release build
if(NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
endif()
message( STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}" )



find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

set(msg_files
  "msg/Embedding.msg"
  "msg/FaceInfo.msg"
  "msg/FaceRecognition.msg"
)

set(srv_files
  "srv/FaceDatabaseInfo.srv"
  "srv/DetectLicencePlate.srv"
)

rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
  ${srv_files}
  DEPENDENCIES rosidl_default_runtime std_msgs sensor_msgs
  ADD_LINTER_TESTS
)


ament_export_dependencies(rosidl_default_runtime sensor_msgs std_msgs)
ament_package()

include(cmake/package_debian.cmake)
