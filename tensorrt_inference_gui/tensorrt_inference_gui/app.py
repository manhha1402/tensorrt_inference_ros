import rclpy
from nicegui import app,  ui_run, ui
import rclpy.client 

import threading
from pathlib import Path
from rclpy.executors import ExternalShutdownException, MultiThreadedExecutor
from tensorrt_inference_gui.config_panel import ConfigPanelNode
from tensorrt_inference_gui.camera_panel import ImageReceiverNode


def main() -> None:
    # NOTE: This function is defined as the ROS entry point in setup.py, but it's empty to enable NiceGUI auto-reloading
    pass
def ros_main() -> None:
    rclpy.init(args=None)
    config_panel = ConfigPanelNode()
    camera_panel = ImageReceiverNode()
    executor = MultiThreadedExecutor()
    executor.add_node(config_panel)
    executor.add_node(camera_panel)
    try:
        executor.spin()
    except ExternalShutdownException:
        pass
    finally:
        executor.shutdown()
        config_panel.destroy_node()
        camera_panel.destroy_node()
#Starting the ros node in a thread managed by nicegui. It will be restarted with "on_startup" after a reload.
#It has to be in a thread, since NiceGUI wants the main thread for itself.
app.on_startup(lambda: threading.Thread(target=ros_main).start())

ui_run.APP_IMPORT_STRING = f'{__name__}:app'  # ROS2 uses a non-standard module name, so we need to specify it here

# Prepare the arguments for ui.run()
uvicorn_args = {
    'uvicorn_reload_dirs': str(Path(__file__).parent.resolve()),
    # 'favicon': '/images/favicon.ico',
    'port': 3000,
    'show': False, # Disable auto-opening the browser
    'title': 'TensorRT Inference GUI'
}
ui.run(**uvicorn_args)

