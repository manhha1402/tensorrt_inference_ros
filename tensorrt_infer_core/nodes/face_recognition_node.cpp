
#include <tensorrt_infer_core/face_recognizer.hpp>
#include <rclcpp/rclcpp.hpp>

int main(int argc, char **argv)
{

    rclcpp::init(argc, argv);
    rclcpp::executors::MultiThreadedExecutor executor;
    auto detection_node = std::make_shared<tensorrt_infer_core::FaceRecognizer>();
    executor.add_node(detection_node);
    executor.spin();
    rclcpp::shutdown();

    return 0;
}
