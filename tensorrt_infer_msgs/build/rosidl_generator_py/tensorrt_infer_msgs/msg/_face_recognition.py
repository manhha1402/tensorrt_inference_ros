# generated from rosidl_generator_py/resource/_idl.py.em
# with input from tensorrt_infer_msgs:msg/FaceRecognition.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'rec_scores'
import array  # noqa: E402, I100

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

            from sensor_msgs.msg import Image
            if Image.__class__._TYPE_SUPPORT is None:
                Image.__class__.__import_type_support__()

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
        '_user_ids',
        '_camera_id',
        '_timestamp',
        '_rec_scores',
        '_cropped_faces',
    ]

    _fields_and_field_types = {
        'user_ids': 'sequence<string>',
        'camera_id': 'uint16',
        'timestamp': 'string',
        'rec_scores': 'sequence<double>',
        'cropped_faces': 'sequence<sensor_msgs/Image>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'Image')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.user_ids = kwargs.get('user_ids', [])
        self.camera_id = kwargs.get('camera_id', int())
        self.timestamp = kwargs.get('timestamp', str())
        self.rec_scores = array.array('d', kwargs.get('rec_scores', []))
        self.cropped_faces = kwargs.get('cropped_faces', [])

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
        if self.user_ids != other.user_ids:
            return False
        if self.camera_id != other.camera_id:
            return False
        if self.timestamp != other.timestamp:
            return False
        if self.rec_scores != other.rec_scores:
            return False
        if self.cropped_faces != other.cropped_faces:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def user_ids(self):
        """Message field 'user_ids'."""
        return self._user_ids

    @user_ids.setter
    def user_ids(self, value):
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'user_ids' field must be a set or sequence and each value of type 'str'"
        self._user_ids = value

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
    def rec_scores(self):
        """Message field 'rec_scores'."""
        return self._rec_scores

    @rec_scores.setter
    def rec_scores(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'rec_scores' array.array() must have the type code of 'd'"
            self._rec_scores = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'rec_scores' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._rec_scores = array.array('d', value)

    @builtins.property
    def cropped_faces(self):
        """Message field 'cropped_faces'."""
        return self._cropped_faces

    @cropped_faces.setter
    def cropped_faces(self, value):
        if __debug__:
            from sensor_msgs.msg import Image
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Image) for v in value) and
                 True), \
                "The 'cropped_faces' field must be a set or sequence and each value of type 'Image'"
        self._cropped_faces = value
