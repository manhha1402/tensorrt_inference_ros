cmake_minimum_required(VERSION 3.5.2)
project(tensorrt_infer_core)
include(cmake/project_version.cmake)

# Save the command line compile commands in the build output
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

# Default to release build
if(NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
endif()
message( STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}" )
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})



################
# DEPENDENCIES #
################
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_auto REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(ament_index_cpp REQUIRED)

# dependencies
find_package(rclcpp REQUIRED)
find_package(message_filters REQUIRED)
find_package(sensor_msgs)
find_package(tensorrt_infer_msgs)
find_package(realsense2_camera_msgs)
find_package(tf2_eigen)

set(dependencies
  rclcpp
  sensor_msgs
  message_filters
  ament_index_cpp
  realsense2_camera_msgs
  tf2_eigen
  tensorrt_infer_msgs
)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

find_package(tensorrt_inference REQUIRED)

set(Eigen3_INCLUDE_DIRS /usr/include/eigen3)
find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED NO_MODULE PATHS /usr/local NO_DEFAULT_PATH)

include("${CMAKE_SOURCE_DIR}/cmake/find_cuda.cmake")
find_package(CUDA REQUIRED)
find_package(fmt REQUIRED)
find_package(yaml-cpp)

pkg_check_modules(LIBMONGOCXX  libmongocxx REQUIRED)
if (${LIBMONGOCXX_FOUND})
  message("found mongocxx")
else ()
  message(WARNING "not found mongocxx")
endif ()
include_directories("/usr/local/include/mongocxx/v_noabi")
include_directories("/usr/local/include/bsoncxx/v_noabi")

###Open3D############
#find_package(Open3D HINTS ${CMAKE_INSTALL_PREFIX}/lib/CMake)
cuda_add_library(similarity SHARED
  src/similarity.cu
)
set_target_properties(similarity PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

target_include_directories(similarity PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
  ${CUDA_INCLUDE_DIRS}
  PRIVATE ${CMAKE_CURRENT_BINARY_DIR}  # for private headers generated during build
  )
target_link_libraries(similarity ${CUDA_LIBRARIES} )
add_library(${PROJECT_NAME}_lib SHARED
    src/conversions.cpp
    src/dynamic_params.cpp
    src/ros_param_backend.cpp
    src/mongodb_client.cpp
    src/licence_plate_detector.cpp
    src/detection_node.cpp
    src/face_recognition_node.cpp
    )
if(NOT DEFINED ENV{ROS_DISTRO})
  message(FATAL_ERROR "ROS_DISTRO is not defined." )
endif()
if("$ENV{ROS_DISTRO}" STREQUAL "foxy")
  message(STATUS "Build for ROS2 Foxy")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DFOXY")
elseif("$ENV{ROS_DISTRO}" STREQUAL "humble")
  message(STATUS "Build for ROS2 Humble")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DHUMBLE")
endif()
target_include_directories(
  ${PROJECT_NAME}_lib PUBLIC 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
  ${CUDA_INCLUDE_DIRS}
  PRIVATE ${CMAKE_CURRENT_BINARY_DIR}  # for private headers generated during build
)
ament_target_dependencies(${PROJECT_NAME}_lib ${dependencies})
target_link_libraries(${PROJECT_NAME}_lib 
                      tensorrt_inference_lib
                      Eigen3::Eigen 
                      ${CUDA_LIBRARIES} 
                      ${OpenCV_LIBRARIES}
                      ${YAML_CPP_LIBRARIES} 
                      fmt
                      ${LIBMONGOCXX_LIBRARIES}
                      )

# Mark executables and/or libraries for installation 
add_executable(tensorrt_inference_node nodes/tensorrt_inference_node.cpp)
target_link_libraries(tensorrt_inference_node ${PROJECT_NAME}_lib similarity)
add_executable(license_plate_detector_node nodes/license_plate_detector_node.cpp)
target_link_libraries(license_plate_detector_node ${PROJECT_NAME}_lib)
###########
# INSTALL #
###########
# Install includes.
install(
  DIRECTORY include/
  DESTINATION include
)


# Install the library target.
install(
  TARGETS ${PROJECT_NAME}_lib
  EXPORT ${PROJECT_NAME}Targets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

install(TARGETS tensorrt_inference_node license_plate_detector_node
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)


ament_export_include_directories(include)
ament_export_libraries(${PROJECT_NAME})
ament_export_dependencies(${dependencies})
ament_package()

include(cmake/package_debian.cmake)

