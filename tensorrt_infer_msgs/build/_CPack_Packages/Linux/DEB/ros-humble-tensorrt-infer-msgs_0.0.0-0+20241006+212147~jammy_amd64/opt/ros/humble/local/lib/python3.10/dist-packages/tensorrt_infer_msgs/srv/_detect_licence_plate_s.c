// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from tensorrt_infer_msgs:srv/DetectLicencePlate.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "tensorrt_infer_msgs/srv/detail/detect_licence_plate__struct.h"
#include "tensorrt_infer_msgs/srv/detail/detect_licence_plate__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool tensorrt_infer_msgs__srv__detect_licence_plate__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[73];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("tensorrt_infer_msgs.srv._detect_licence_plate.DetectLicencePlate_Request", full_classname_dest, 72) == 0);
  }
  tensorrt_infer_msgs__srv__DetectLicencePlate_Request * ros_message = _ros_message;
  {  // topic_name
    PyObject * field = PyObject_GetAttrString(_pymsg, "topic_name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->topic_name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * tensorrt_infer_msgs__srv__detect_licence_plate__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of DetectLicencePlate_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("tensorrt_infer_msgs.srv._detect_licence_plate");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "DetectLicencePlate_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  tensorrt_infer_msgs__srv__DetectLicencePlate_Request * ros_message = (tensorrt_infer_msgs__srv__DetectLicencePlate_Request *)raw_ros_message;
  {  // topic_name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->topic_name.data,
      strlen(ros_message->topic_name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "topic_name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "tensorrt_infer_msgs/srv/detail/detect_licence_plate__struct.h"
// already included above
// #include "tensorrt_infer_msgs/srv/detail/detect_licence_plate__functions.h"

// already included above
// #include "rosidl_runtime_c/string.h"
// already included above
// #include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool tensorrt_infer_msgs__srv__detect_licence_plate__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[74];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("tensorrt_infer_msgs.srv._detect_licence_plate.DetectLicencePlate_Response", full_classname_dest, 73) == 0);
  }
  tensorrt_infer_msgs__srv__DetectLicencePlate_Response * ros_message = _ros_message;
  {  // plate_number
    PyObject * field = PyObject_GetAttrString(_pymsg, "plate_number");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->plate_number, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // det_core
    PyObject * field = PyObject_GetAttrString(_pymsg, "det_core");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->det_core = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rec_score
    PyObject * field = PyObject_GetAttrString(_pymsg, "rec_score");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rec_score = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * tensorrt_infer_msgs__srv__detect_licence_plate__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of DetectLicencePlate_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("tensorrt_infer_msgs.srv._detect_licence_plate");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "DetectLicencePlate_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  tensorrt_infer_msgs__srv__DetectLicencePlate_Response * ros_message = (tensorrt_infer_msgs__srv__DetectLicencePlate_Response *)raw_ros_message;
  {  // plate_number
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->plate_number.data,
      strlen(ros_message->plate_number.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "plate_number", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // det_core
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->det_core);
    {
      int rc = PyObject_SetAttrString(_pymessage, "det_core", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rec_score
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rec_score);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rec_score", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
