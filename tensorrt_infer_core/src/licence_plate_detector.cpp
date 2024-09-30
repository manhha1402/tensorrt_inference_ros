#include <yaml-cpp/yaml.h>

#include <memory>
#include <tensorrt_infer_core/licence_plate_detector.hpp>

using std::placeholders::_1;

namespace tensorrt_infer_core
{
    LicencePlateDetector::LicencePlateDetector(const rclcpp::NodeOptions &options,
                                               const std::string node_name)
        : Node(node_name, options)
    {
        // Declare parameters
        RCLCPP_INFO(get_logger(), "Creating licence plate detection");
        dynamic_params_ = std::make_shared<tensorrt_infer_core::Parameters>(*this);
        dynamic_params_->setParam<float>(
            "obj_thres", params_.obj_threshold, [this](const rclcpp::Parameter &parameter)
            { params_.obj_threshold = parameter.get_value<float>(); });

        dynamic_params_->setParam<float>(
            "nms_thres", params_.nms_threshold, [this](const rclcpp::Parameter &parameter)
            { params_.nms_threshold = parameter.get_value<float>(); });
        dynamic_params_->setParam<int>(
            "num_detect", params_.num_detect, [this](const rclcpp::Parameter &parameter)
            { params_.num_detect = parameter.get_value<int>(); });
        dynamic_params_->setParam<float>(
            "rec_score", rec_score_, [this](const rclcpp::Parameter &parameter)
            { rec_score_ = parameter.get_value<float>(); });
        dynamic_params_->setParam<std::string>(
            "camera_topic", camera_topic_, [this](const rclcpp::Parameter &parameter)
            { camera_topic_ = parameter.get_value<std::string>(); });

        bool ret = initModel();
        res_pub_ = create_publisher<sensor_msgs::msg::Image>("licence_plate_result", 10);
        // rgbd_sub_ = create_subscription<realsense2_camera_msgs::msg::RGBD>(
        //     "/camera/camera/rgbd", 10,
        //     std::bind(&LicencePlateDetector::detect_rgbd_callback, this, _1));

        // Create the image subscriber
        image_sub_ = this->create_subscription<sensor_msgs::msg::Image>(
            camera_topic_.c_str(), // Change this to your image topic
            10,
            [this](sensor_msgs::msg::Image::SharedPtr msg)
            {
                std::lock_guard<std::mutex> lock(image_mutex_);
                last_image_ = msg;
                image_received_ = true;
            });
        detect_lp_srv_ = create_service<tensorrt_infer_msgs::srv::DetectLicencePlate>(
            "detect_licene_plate", std::bind(&LicencePlateDetector::detectLicenePlateCallBack, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            rmw_qos_profile_services_default);
    }

    bool LicencePlateDetector::initModel()
    {

        detector_ = std::make_shared<tensorrt_inference::YoloV8>("plate_yolov8n_320_2024");
        const std::filesystem::path &model_dir =
            std::filesystem::path(std::getenv("HOME")) / "data" / "weights";
        const std::string model_name = "paddleocr";
        tensorrt_inference::Options options_det;
        tensorrt_inference::Options options_rec;

        options_rec.MIN_DIMS_ = {1, 3, 48, 10};
        options_rec.OPT_DIMS_ = {1, 3, 48, 320};
        options_rec.MAX_DIMS_ = {8, 3, 48, 2000};
        options_rec.engine_file_dir = (model_dir / model_name).string();
        options_det.engine_file_dir = (model_dir / model_name).string();

        ocr_ = std::make_shared<tensorrt_inference::PaddleOCR>(
            model_name, options_det, options_rec, model_dir);

        return true;
    }

    // void LicencePlateDetector::detect_rgbd_callback(
    //     const realsense2_camera_msgs::msg::RGBD::SharedPtr rgbd_msg) const
    // {
    //     cv::Mat rgb;
    //     tensorrt_infer_core::rosToOpenCV(rgbd_msg->rgb, rgb);
    //     if (rgb.empty() && detector_ == nullptr)
    //     {
    //         return;
    //     }
    //     // Run inference
    //     const auto objects = detector_->detect(rgb, params_);
    //     auto plates = tensorrt_inference::getCroppedObjects(rgb, objects, rgb.cols,
    //                                                         rgb.rows, false);
    //     std::vector<cv::cuda::GpuMat> img_list;
    //     for (size_t i = 0; i < plates.size(); i++)
    //     {
    //         auto rec_result = ocr_->runInference(rgb, plates[i]);
    //         plates[i].probability = rec_result.second;
    //         plates[i].label = rec_result.first;
    //     }
    //     // Remove all elements greater than rec_score_
    //     plates.erase(std::remove_if(plates.begin(), plates.end(), [&](const tensorrt_inference::CroppedObject &plate)
    //                                 { return plate.probability < rec_score_; }),
    //                  plates.end());
    //     // if (!plates.empty())
    //     //{
    //     cv::Mat img_result = ocr_->drawBBoxLabels(rgb, plates, 1);
    //     // Draw the bounding boxes on the image
    //     cv::cvtColor(img_result, img_result, cv::COLOR_RGB2BGR);
    //     res_pub_->publish(*tensorrt_infer_core::openCVToRos(img_result));
    //     //}
    // }
    void LicencePlateDetector::detectLicenePlateCallBack(const std::shared_ptr<rmw_request_id_t> request_header,
                                                         const std::shared_ptr<tensorrt_infer_msgs::srv::DetectLicencePlate::Request> req,
                                                         std::shared_ptr<tensorrt_infer_msgs::srv::DetectLicencePlate::Response> res)
    {
        // Create a subscriber to the image topic with a lambda function callback
        // Wait until an image is received
        std::unique_lock<std::mutex> lock(image_mutex_);
        if (!image_received_)
        {
            // Wait for an image to be received (this is a simple blocking wait)
            RCLCPP_INFO(this->get_logger(), "Waiting for an image message...");
            while (!image_received_)
            {
                if (!rclcpp::ok())
                {
                    return;
                }
                cv_.wait(lock);
            }
        }

        RCLCPP_INFO(get_logger(), "Image message received!");

        cv::Mat rgb;
        tensorrt_infer_core::rosToOpenCV(*last_image_, rgb);
        if (rgb.empty() && detector_ == nullptr)
        {
            return;
        }
        // Run inference
        const auto objects = detector_->detect(rgb, params_);
        auto plates = tensorrt_inference::getCroppedObjects(rgb, objects, rgb.cols,
                                                            rgb.rows, false);
        std::vector<cv::cuda::GpuMat> img_list;
        for (size_t i = 0; i < plates.size(); i++)
        {
            auto rec_result = ocr_->runInference(rgb, plates[i]);
            plates[i].rec_score = rec_result.second;
            plates[i].label = rec_result.first;
            std::cout << "label:" << plates[i].label << std::endl;
            std::cout << "det_score:" << plates[i].det_score << std::endl;
            std::cout << "rec_score:" << rec_result.second << std::endl;
        }
        // Remove all elements greater than rec_score_
        plates.erase(std::remove_if(plates.begin(), plates.end(), [&](const tensorrt_inference::CroppedObject &plate)
                                    { return plate.rec_score < rec_score_; }),
                     plates.end());
        // if (!plates.empty())
        //{
        cv::Mat img_result = ocr_->drawBBoxLabels(rgb, plates, 1);
        // Draw the bounding boxes on the image
        cv::cvtColor(img_result, img_result, cv::COLOR_RGB2BGR);
        res_pub_->publish(*tensorrt_infer_core::openCVToRos(img_result));
        auto max_prob = std::max_element(plates.begin(), plates.end(), [](const tensorrt_inference::CroppedObject &a, const tensorrt_inference::CroppedObject &b)
                                         { return a.det_score < b.det_score; });
        if (max_prob != plates.end())
        {
            std::cout << "label:" << max_prob->label << std::endl;
            std::cout << "max det_score:" << max_prob->det_score << std::endl;
            std::cout << "max rec_score:" << max_prob->rec_score << std::endl;
            res->det_core = max_prob->det_score;
            res->rec_score = max_prob->rec_score;
            res->plate_number = max_prob->label;
        }
        RCLCPP_INFO(get_logger(), "Done Service!");
    }
} // namespace tensorrt_infer_core
