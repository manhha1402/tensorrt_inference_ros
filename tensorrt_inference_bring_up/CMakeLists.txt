cmake_minimum_required (VERSION 3.8 FATAL_ERROR)
project(tensorrt_inference_bring_up)
include(cmake/project_version.cmake)

find_package(ament_cmake REQUIRED)


install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})
install(DIRECTORY rviz DESTINATION share/${PROJECT_NAME})
install(DIRECTORY params DESTINATION share/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

include(cmake/package_debian.cmake)
