# generated from rosidl_generator_py/resource/_idl.py.em
# with input from tensorrt_infer_msgs:srv/DetectLicencePlate.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DetectLicencePlate_Request(type):
    """Metaclass of message 'DetectLicencePlate_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('tensorrt_infer_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'tensorrt_infer_msgs.srv.DetectLicencePlate_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__detect_licence_plate__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__detect_licence_plate__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__detect_licence_plate__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__detect_licence_plate__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__detect_licence_plate__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DetectLicencePlate_Request(metaclass=Metaclass_DetectLicencePlate_Request):
    """Message class 'DetectLicencePlate_Request'."""

    __slots__ = [
        '_topic_name',
    ]

    _fields_and_field_types = {
        'topic_name': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.topic_name = kwargs.get('topic_name', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.topic_name != other.topic_name:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def topic_name(self):
        """Message field 'topic_name'."""
        return self._topic_name

    @topic_name.setter
    def topic_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'topic_name' field must be of type 'str'"
        self._topic_name = value


# Import statements for member types

# already imported above
# import builtins

import math  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_DetectLicencePlate_Response(type):
    """Metaclass of message 'DetectLicencePlate_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('tensorrt_infer_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'tensorrt_infer_msgs.srv.DetectLicencePlate_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__detect_licence_plate__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__detect_licence_plate__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__detect_licence_plate__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__detect_licence_plate__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__detect_licence_plate__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DetectLicencePlate_Response(metaclass=Metaclass_DetectLicencePlate_Response):
    """Message class 'DetectLicencePlate_Response'."""

    __slots__ = [
        '_plate_number',
        '_det_core',
        '_rec_score',
    ]

    _fields_and_field_types = {
        'plate_number': 'string',
        'det_core': 'double',
        'rec_score': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.plate_number = kwargs.get('plate_number', str())
        self.det_core = kwargs.get('det_core', float())
        self.rec_score = kwargs.get('rec_score', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.plate_number != other.plate_number:
            return False
        if self.det_core != other.det_core:
            return False
        if self.rec_score != other.rec_score:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def plate_number(self):
        """Message field 'plate_number'."""
        return self._plate_number

    @plate_number.setter
    def plate_number(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'plate_number' field must be of type 'str'"
        self._plate_number = value

    @builtins.property
    def det_core(self):
        """Message field 'det_core'."""
        return self._det_core

    @det_core.setter
    def det_core(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'det_core' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'det_core' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._det_core = value

    @builtins.property
    def rec_score(self):
        """Message field 'rec_score'."""
        return self._rec_score

    @rec_score.setter
    def rec_score(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rec_score' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'rec_score' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._rec_score = value


class Metaclass_DetectLicencePlate(type):
    """Metaclass of service 'DetectLicencePlate'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('tensorrt_infer_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'tensorrt_infer_msgs.srv.DetectLicencePlate')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__detect_licence_plate

            from tensorrt_infer_msgs.srv import _detect_licence_plate
            if _detect_licence_plate.Metaclass_DetectLicencePlate_Request._TYPE_SUPPORT is None:
                _detect_licence_plate.Metaclass_DetectLicencePlate_Request.__import_type_support__()
            if _detect_licence_plate.Metaclass_DetectLicencePlate_Response._TYPE_SUPPORT is None:
                _detect_licence_plate.Metaclass_DetectLicencePlate_Response.__import_type_support__()


class DetectLicencePlate(metaclass=Metaclass_DetectLicencePlate):
    from tensorrt_infer_msgs.srv._detect_licence_plate import DetectLicencePlate_Request as Request
    from tensorrt_infer_msgs.srv._detect_licence_plate import DetectLicencePlate_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
