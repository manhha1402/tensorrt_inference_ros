from launch import LaunchDescription
from launch_ros.actions import Node
def generate_launch_description():
    return LaunchDescription([
        Node(
            package='tensorrt_infer_core',
            executable='tensorrt_inference_node',
            parameters=[
                {'my_str': 'Hello Cpp'},
                {'my_int': 12},
                {'my_double_array': [3.3, 4.4, 5.5]}
            ],
            output='screen',
            emulate_tty=True
        )
    ])