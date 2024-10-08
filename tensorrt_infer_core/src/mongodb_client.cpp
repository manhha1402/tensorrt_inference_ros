#include "tensorrt_infer_core/mongodb_client.hpp"
namespace tensorrt_infer_core
{
    MongoDBClient::MongoDBClient(const std::string &url_path)
    {
        if (!init(url_path))
        {
            throw std::runtime_error("Mongo client can not be initialized");
        }
    }
    bool MongoDBClient::init(const std::string &url_path)
    {
        mongocxx::uri uri(url_path);
        try
        {
            mongo_client_ = mongocxx::client(uri);
        }
        catch (mongocxx::v_noabi::exception &error)
        {
            std::cerr << "Mongo client can not be initialized" << std::endl;
            return false;
        }
        return true;
    }
    std::map<std::string, std::vector<std::vector<double>>> MongoDBClient::getEmbeddings(const std::string &db_name)
    {
        mongocxx::database db = mongo_client_[db_name];
        std::map<std::string, std::vector<std::vector<double>>> embeddings_map;
        // Get all names
        std::vector<std::string> collection_names = db.list_collection_names();
        for (const auto &collection_name : collection_names)
        {
            mongocxx::collection collection = db[collection_name];
            auto cursor = collection.find({});
            // Retrieve the document
            std::vector<std::vector<double>> embeddings;
            for (const auto &doc : cursor)
            {
                // Extract and print the fields from the document
                // std::string name(doc["name"].get_utf8().value);
                // int id = doc["id"].get_int32();
                // std::string birth_day(doc["birth_day"].get_utf8().value);

                // For embeddings, we'll extract it as a list of floats
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
        return embeddings_map;
    }

} // namespace tensorrt_infer_core
