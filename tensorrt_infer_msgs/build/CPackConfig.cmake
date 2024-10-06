# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BUILD_SOURCE_DIRS "/home/neura_ai/neura/ros2_ws/src/tensorrt_inference_ros/tensorrt_infer_msgs;/home/neura_ai/neura/ros2_ws/src/tensorrt_inference_ros/tensorrt_infer_msgs/build")
set(CPACK_CMAKE_GENERATOR "Unix Makefiles")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "ros-humble-std-msgs")
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS "ON")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "/usr/share/cmake-3.30/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "tensorrt_infer_msgs built using CMake")
set(CPACK_GENERATOR "DEB")
set(CPACK_INNOSETUP_ARCHITECTURE "x64")
set(CPACK_INSTALL_CMAKE_PROJECTS "/home/neura_ai/neura/ros2_ws/src/tensorrt_inference_ros/tensorrt_infer_msgs/build;tensorrt_infer_msgs;ALL;/")
set(CPACK_INSTALL_PREFIX "/opt/ros/humble")
set(CPACK_MODULE_PATH "/opt/ros/humble/share/python_cmake_module/cmake/Modules;/opt/ros/humble/share/fastrtps_cmake_module/cmake/Modules")
set(CPACK_NSIS_DISPLAY_NAME "ros-humble-tensorrt-infer-msgs 0.0.0-0+20241006+212147~jammy")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
set(CPACK_NSIS_PACKAGE_NAME "ros-humble-tensorrt-infer-msgs 0.0.0-0+20241006+212147~jammy")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OBJCOPY_EXECUTABLE "/usr/bin/objcopy")
set(CPACK_OBJDUMP_EXECUTABLE "/usr/bin/objdump")
set(CPACK_OUTPUT_CONFIG_FILE "/home/neura_ai/neura/ros2_ws/src/tensorrt_inference_ros/tensorrt_infer_msgs/build/CPackConfig.cmake")
set(CPACK_PACKAGE_CONTACT "Manh Ha Hoang <manhha1402@gmail.com>")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "/usr/share/cmake-3.30/Templates/CPack.GenericDescription.txt")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "PathTech tensorrt_infer_msgs package")
set(CPACK_PACKAGE_FILE_NAME "ros-humble-tensorrt-infer-msgs_0.0.0-0+20241006+212147~jammy_amd64")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "ros-humble-tensorrt-infer-msgs 0.0.0-0+20241006+212147~jammy")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "ros-humble-tensorrt-infer-msgs 0.0.0-0+20241006+212147~jammy")
set(CPACK_PACKAGE_NAME "ros-humble-tensorrt-infer-msgs")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "PathTech, Hanoi, Vietnam")
set(CPACK_PACKAGE_VERSION "0.0.0-0+20241006+212147~jammy")
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "1")
set(CPACK_PACKAGE_VERSION_PATCH "1")
set(CPACK_READELF_EXECUTABLE "/usr/bin/readelf")
set(CPACK_RESOURCE_FILE_LICENSE "/usr/share/cmake-3.30/Templates/CPack.GenericLicense.txt")
set(CPACK_RESOURCE_FILE_README "/usr/share/cmake-3.30/Templates/CPack.GenericDescription.txt")
set(CPACK_RESOURCE_FILE_WELCOME "/usr/share/cmake-3.30/Templates/CPack.GenericWelcome.txt")
set(CPACK_SET_DESTDIR "true")
set(CPACK_SOURCE_GENERATOR "TBZ2;TGZ;TXZ;TZ")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/home/neura_ai/neura/ros2_ws/src/tensorrt_inference_ros/tensorrt_infer_msgs/build/CPackSourceConfig.cmake")
set(CPACK_SOURCE_RPM "OFF")
set(CPACK_SOURCE_TBZ2 "ON")
set(CPACK_SOURCE_TGZ "ON")
set(CPACK_SOURCE_TXZ "ON")
set(CPACK_SOURCE_TZ "ON")
set(CPACK_SOURCE_ZIP "OFF")
set(CPACK_SYSTEM_NAME "Linux")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "Linux")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/home/neura_ai/neura/ros2_ws/src/tensorrt_inference_ros/tensorrt_infer_msgs/build/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
