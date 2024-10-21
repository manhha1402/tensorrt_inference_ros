
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

    // auto detector_ = std::make_shared<tensorrt_inference::RetinaFace>("facedetector");
    // auto recognizer_ = std::make_shared<tensorrt_inference::FaceRecognition>("FaceNet_vggface2_optmized");
    // auto mongodb_client_ptr_ = std::make_shared<tensorrt_infer_core::MongoDBClient>();
    // std::map<std::string, std::vector<std::vector<double>>> embeddings_map_ = mongodb_client_ptr_->getEmbeddings("FaceRecognition");
    // int rect_height_ = recognizer_->m_trtEngine->getInputInfo().begin()->second.dims.d[2];
    // int rec_width_ = recognizer_->m_trtEngine->getInputInfo().begin()->second.dims.d[3];

    // cv::Mat rgb = cv::imread("/home/neura_ai/data/test_images/david2.jpg");
    // // Run inference
    // tensorrt_inference::DetectionParams params_;
    // const auto faces = detector_->detect(rgb, params_);
    // auto cropped_faces =
    //     tensorrt_inference::getCroppedObjects(rgb, faces, rec_width_, rect_height_, false);
    // for (size_t i = 0; i < cropped_faces.size(); i++)
    // {
    //     std::unordered_map<std::string, std::vector<float>> feature_vectors;
    //     cv::cuda::GpuMat gpu_input(cropped_faces[i].croped_object);
    //     bool ret = recognizer_->doInference(gpu_input, feature_vectors);
    //     std::vector<double> embedding(feature_vectors.begin()->second.size());
    //     normalize(feature_vectors.begin()->second, embedding);
    //     auto result = tensorrt_infer_core::findSimilaritywithName(embeddings_map_, embedding, "euclidean");
    //     // if (std::get<0>(result) > 0.6)
    //     // {
    //     cropped_faces[i].label = std::get<1>(result);
    //     cropped_faces[i].rec_score = std::get<0>(result);
    //     std::cout << cropped_faces[i].label << std::endl;
    //     std::cout << cropped_faces[i].rec_score << std::endl;
    //     //}
    // }
    // cv::Mat result = tensorrt_inference::drawBBoxLabels(rgb, cropped_faces, 2, true);
    // cv::imwrite("result.png", result);
    return 0;
}
