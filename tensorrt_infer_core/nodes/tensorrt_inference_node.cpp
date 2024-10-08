

// #include <iostream>
// #include <rclcpp/rclcpp.hpp>
// #include <tensorrt_infer_core/detection_node.hpp>
// int main(int argc, char **argv)
// {
//   rclcpp::init(argc, argv);
//   rclcpp::executors::MultiThreadedExecutor executor;
//   auto detection_node = std::make_shared<tensorrt_infer_core::DetectionNode>();
//   executor.add_node(detection_node);
//   executor.spin();
//   rclcpp::shutdown();

//   return 0;
// }

#include <iostream>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/exception/operation_exception.hpp>
#include <mongocxx/stdx.hpp>
#include <bsoncxx/types.hpp>
#include <mongocxx/database.hpp>
#include <tensorrt_infer_core/similarity.hpp>
#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/generate.h>
#include <thrust/sort.h>
#include <thrust/copy.h>
#include <thrust/random.h>
int main(int argc, char **argv)
{
    std::string db_name = "FaceRecognition";
    std::string collection_name = "manhha";
    std::string database_path = "mongodb://localhost:27017/";
    mongocxx::uri uri(database_path);

    mongocxx::client mongo_client_;
    try
    {
        mongo_client_ = mongocxx::client(uri);
    }
    catch (mongocxx::v_noabi::exception &error)
    {
        std::cerr << "Mongo client can not be initialized" << std::endl;
        return 0;
    }

    mongocxx::instance mongo_instance_{};
    mongocxx::database db = mongo_client_[db_name];
    std::vector<std::string> collection_names = db.list_collection_names();
    std::map<std::string, std::vector<std::vector<double>>> embeddings_map;

    for (const auto &collection_name : collection_names)
    {
        mongocxx::collection collection = db[collection_name];
        auto cursor = collection.find({});
        std::vector<std::vector<double>> embeddings;

        for (const auto &doc : cursor)
        {
            // auto doc = maybe_result->view();
            // Extract and print the fields from the document
            std::string name(doc["name"].get_utf8().value);
            int id = doc["id"].get_int32();
            std::string birth_day(doc["birth_day"].get_utf8().value);
            // For embeddings, we'll extract it as a list of doubles
            auto embeddings_array = doc["embeddings"].get_array().value;
            for (auto &&embedding : embeddings_array)
            {
                std::vector<double> inner_vector;
                auto inner_array = embedding.get_array().value;
                for (const auto &elem : inner_array)
                {
                    if (elem.type() == bsoncxx::type::k_array)
                    {
                        inner_vector.push_back(elem.get_array().value[0].get_double());
                    }
                    else
                    {
                        std::cerr << "Unexpected type in inner embeddings array: " << std::endl;
                    }
                }
                embeddings.push_back(inner_vector); // Add the inner vector to the outer vector
            }
        }
        embeddings_map[collection_name] = embeddings;
    }

    std::vector<std::vector<double>> vectors;
    for (const auto &it : embeddings_map)
    {
        for (const auto &embedding : it.second)
        {
            vectors.push_back(embedding);
        }
    }
    std::cout << vectors.size() << std::endl;
    std::vector<double> rec_embed = embeddings_map[embeddings_map.begin()->first][1];
    std::cout << rec_embed.size() << std::endl;
    std::pair<double, int> result = findLargestSimilarity(vectors, rec_embed);

    std::cout << "Biggest similarity (dot product): " << result.first << std::endl;
    std::cout << "Index of vector with largest similarity: " << result.second << std::endl;

    return 0;
}
