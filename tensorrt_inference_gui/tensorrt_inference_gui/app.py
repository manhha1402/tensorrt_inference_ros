#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from std_msgs.msg import String


class App(Node):

    def __init__(self):
        super().__init__("app")
        self.get_logger().info("Hello world from the Python node app")


def main(args=None):
    rclpy.init(args=args)

    app = App()

    try:
        rclpy.spin(app)
    except KeyboardInterrupt:
        pass

    app.destroy_node()
    rclpy.try_shutdown()


if __name__ == '__main__':
    main()
