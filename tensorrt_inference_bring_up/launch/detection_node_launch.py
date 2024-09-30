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

    tensorrt_inference_node_raw_params = params['tensorrt_inference_node']['ros__parameters']
    license_plate_detector_node_raw_params = params['license_plate_detector_node']['ros__parameters']
    tensorrt_inference_node_params = dict()
    license_plate_detector_node_params = dict()

    for key, value in tensorrt_inference_node_raw_params.items():
        tensorrt_inference_node_params[key] = value['value'] 
    for key, value in license_plate_detector_node_raw_params.items():
        license_plate_detector_node_params[key] = value['value'] 
    print(3)

    tensorrt_inference_node = Node(
        package='tensorrt_infer_core',
        executable='tensorrt_inference_node',
        name='tensorrt_inference_node',
        namespace='tensorrt_infer_core',
        output='screen',
        parameters=[tensorrt_inference_node_params]
        )
    license_plate_detector_node = Node(
        package='tensorrt_infer_core',
        executable='license_plate_detector_node',
        name='license_plate_detector_node',
        namespace='tensorrt_infer_core',
        output='screen',
        parameters=[license_plate_detector_node_params]
        )
    ld = LaunchDescription()
    ld.add_action(SetEnvironmentVariable('RCUTILS_LOGGING_BUFFERED_STREAM', '1'))
    ld.add_action(SetEnvironmentVariable('RCUTILS_COLORIZED_OUTPUT', '1'))
    ld.add_action(SetEnvironmentVariable('RCUTILS_CONSOLE_OUTPUT_FORMAT', '[{severity}]: {message}'))
    ld.add_action(tensorrt_inference_node)
    ld.add_action(license_plate_detector_node)

    return ld
