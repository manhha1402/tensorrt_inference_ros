cmake_minimum_required(VERSION 3.5.2)
project(tensorrt_inference_ros)
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



################
# DEPENDENCIES #
################
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_auto REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(ament_index_cpp REQUIRED)

# dependencies
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
#find_package(tf2_geometry_msgs)
find_package(tf2_eigen)
set(dependencies
  rclcpp
  rclcpp_action
  ament_index_cpp
  tf2_eigen
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
set(CUDA_TOOLKIT_ROOT_DIR /usr/local/cuda)
find_package(CUDA REQUIRED)

# Mark executables and/or libraries for installation 
add_executable(tensorrt_inference_node nodes/tensorrt_inference_node.cpp)
target_link_libraries(tensorrt_inference_node ${OpenCV_LIBRARIES} ${CUDA_LIBRARIES})
target_include_directories(tensorrt_inference_node PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"   #find header files
    "$<INSTALL_INTERFACE:include/${PROJECT_NAME}>"
    ${CUDA_INCLUDE_DIRS}
    )   # to install header files

ament_target_dependencies(tensorrt_inference_node ${dependencies})



install(TARGETS tensorrt_inference_node
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)


ament_export_include_directories(include)
ament_export_libraries(${PROJECT_NAME})
ament_export_dependencies(${dependencies})
ament_package()

include(cmake/package_debian.cmake)

