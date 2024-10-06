# generated from rosidl_generator_py/resource/_idl.py.em
# with input from tensorrt_infer_msgs:msg/FaceRecognition.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FaceRecognition(type):
    """Metaclass of message 'FaceRecognition'."""

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
                'tensorrt_infer_msgs.msg.FaceRecognition')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__face_recognition
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__face_recognition
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__face_recognition
            cls._TYPE_SUPPORT = module.type_support_msg__msg__face_recognition
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__face_recognition

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FaceRecognition(metaclass=Metaclass_FaceRecognition):
    """Message class 'FaceRecognition'."""

    __slots__ = [
        '_name',
        '_timestamp',
        '_rec_score',
        '_camera_id',
    ]

    _fields_and_field_types = {
        'name': 'string',
        'timestamp': 'string',
        'rec_score': 'double',
        'camera_id': 'uint16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.name = kwargs.get('name', str())
        self.timestamp = kwargs.get('timestamp', str())
        self.rec_score = kwargs.get('rec_score', float())
        self.camera_id = kwargs.get('camera_id', int())

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
        if self.name != other.name:
            return False
        if self.timestamp != other.timestamp:
            return False
        if self.rec_score != other.rec_score:
            return False
        if self.camera_id != other.camera_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def name(self):
        """Message field 'name'."""
        return self._name

    @name.setter
    def name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'name' field must be of type 'str'"
        self._name = value

    @builtins.property
    def timestamp(self):
        """Message field 'timestamp'."""
        return self._timestamp

    @timestamp.setter
    def timestamp(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'timestamp' field must be of type 'str'"
        self._timestamp = value

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

    @builtins.property
    def camera_id(self):
        """Message field 'camera_id'."""
        return self._camera_id

    @camera_id.setter
    def camera_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'camera_id' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'camera_id' field must be an unsigned integer in [0, 65535]"
        self._camera_id = value
