import os

from ament_index_python.packages import get_package_share_directory
from launch.actions import SetEnvironmentVariable
from launch import LaunchDescription
from launch_ros.actions import Node
import yaml

def generate_launch_description():
    # Get the launch directory
    bringup_dir = get_package_share_directory('tensorrt_inference_bring_up')
    params_file = os.path.join(bringup_dir, 'params', 'tensorrt_infer_core_params.yaml')
    with open(params_file, 'r') as f:
        params =  yaml.safe_load(f)

    face_recognition_node_raw_params = params['face_recognition_node']['ros__parameters']
    face_recognition_node_params = dict()

    for key, value in face_recognition_node_raw_params.items():
        face_recognition_node_params[key] = value['value'] 


    face_recognition_node = Node(
        package='tensorrt_infer_core',
        executable='face_recognition_node',
        name='face_recognition_node',
        namespace='tensorrt_infer_core',
        output='screen',
        parameters=[face_recognition_node_params]
        )
  
    ld = LaunchDescription()
    ld.add_action(SetEnvironmentVariable('RCUTILS_LOGGING_BUFFERED_STREAM', '1'))
    ld.add_action(SetEnvironmentVariable('RCUTILS_COLORIZED_OUTPUT', '1'))
    ld.add_action(SetEnvironmentVariable('RCUTILS_CONSOLE_OUTPUT_FORMAT', '[{severity}]: {message}'))
    ld.add_action(face_recognition_node)

    return ld
