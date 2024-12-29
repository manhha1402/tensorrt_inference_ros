

from rclpy.node import Node
import rclpy
from nicegui import ui
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from nicegui import app, Client, ui_run, ui
import base64
import cv2
class ImageReceiverNode(Node):
    def __init__(self) -> None:
        super().__init__('image_receiver_node')
            
        self.topic_map = {'color' :'/camera/camera/color/image_raw',
                         'depth' :'/camera/camera/aligned_depth_to_color/image_raw' ,
                         'plate' : '/tensorrt_infer_core/face_recognition_image' ,
                         'tensorrt' :'/tensorrt_infer_core/tensorrt_result'}
        #create two subscriptions for the two images
        self.color_sub = self.create_subscription(Image, self.topic_map['color'], self.color_callback, 10)
        self.depth_sub = self.create_subscription(Image, self.topic_map['depth'], self.depth_callback, 10)
        self.plate_sub = self.create_subscription(Image, self.topic_map['plate'], self.plate_callback, 10)
        self.tensorrt_sub = self.create_subscription(Image, self.topic_map['tensorrt'], self.tensorrt_callback, 10)
        self.topic = None
        #adding CV bridge for image processing
        self.cv_bridge = CvBridge()
        #this is where we add nicegui elements
        with Client.auto_index_client:
            #create a row with a width of 50%
            with ui.row().style('width: 40%;position: absolute; top: 100px; right: 50px;'):
                #create an empty interactive_image element
                self.sub_image = ui.interactive_image()
                #create a button to switch between the images, it calls the switch_image function
                ui.select(options= list(self.topic_map.values()),label="Select topic", on_change=lambda v: self.switch_image(topic = v.value)).bind_value(self.topic_map, 'color')

    def switch_image(self, topic: str) -> None:
        self.topic = topic
        return

    def color_callback(self, msg) -> None:
        if self.topic == "/camera/camera/color/image_raw":
            #convert the image to a cv::Mat
            image = self.cv_bridge.imgmsg_to_cv2(msg,desired_encoding= "bgr8" )
            #encode the image to base64
            base64_image = self.encode_image_to_base64(image)
            #set the image source to the base64 string to display it
            self.sub_image.set_source(f'data:image/png;base64,{base64_image}')
        return
    def depth_callback(self, msg) -> None:
        if self.topic == "/camera/camera/aligned_depth_to_color/image_raw":
            #convert the image to a cv::Mat
            image = self.cv_bridge.imgmsg_to_cv2(msg,desired_encoding= "16UC1" )
            #encode the image to base64
            base64_image = self.encode_image_to_base64(image)
            #set the image source to the base64 string to display it
            self.sub_image.set_source(f'data:image/png;base64,{base64_image}')
        return
    def plate_callback(self, msg) -> None:
        if self.topic == "/tensorrt_infer_core/face_recognition_image":
            #convert the image to a cv::Mat
            image = self.cv_bridge.imgmsg_to_cv2(msg,desired_encoding= "bgr8" )
            #encode the image to base64
            base64_image = self.encode_image_to_base64(image)
            #set the image source to the base64 string to display it
            self.sub_image.set_source(f'data:image/png;base64,{base64_image}')
        return
    def tensorrt_callback(self, msg) -> None:
        if self.topic == "/tensorrt_infer_core/tensorrt_result":
            #convert the image to a cv::Mat
            image = self.cv_bridge.imgmsg_to_cv2(msg,desired_encoding= "bgr8" )
            #encode the image to base64
            base64_image = self.encode_image_to_base64(image)
            #set the image source to the base64 string to display it
            self.sub_image.set_source(f'data:image/png;base64,{base64_image}')
        return
    def encode_image_to_base64(self, image) -> None:
        # Convert image to binary format
        _, image_data = cv2.imencode('.png', image)  
        # encode the binary image to base64
        base64_image = base64.b64encode(image_data).decode('utf-8')
        #return the base64 string
        return base64_image

