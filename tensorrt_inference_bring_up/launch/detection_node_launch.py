import os

from ament_index_python.packages import get_package_share_directory
from launch.actions import DeclareLaunchArgument, SetEnvironmentVariable
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
import yaml

def generate_launch_description():
    # Get the launch directory
    bringup_dir = get_package_share_directory('tensorrt_inference_bring_up')
    params_file = os.path.join(bringup_dir, 'params', 'tensorrt_infer_core_params.yaml')
    with open(params_file, 'r') as f:
        tensorrt_inference_node_params = yaml.safe_load(f)['tensorrt_inference_node']['ros__parameters']


    # Set env var to print messages to stdout immediately
    SetEnvironmentVariable('RCUTILS_LOGGING_BUFFERED_STREAM', '1')
    tensorrt_inference_node = Node(
        package='tensorrt_infer_core',
        executable='tensorrt_inference_node',
        name='tensorrt_inference_node',
        namespace='tensorrt_infer_core',
        output='screen',
        parameters=[tensorrt_inference_node_params]
        )
    
    ld = LaunchDescription()
    ld.add_action(tensorrt_inference_node)
    return ld
