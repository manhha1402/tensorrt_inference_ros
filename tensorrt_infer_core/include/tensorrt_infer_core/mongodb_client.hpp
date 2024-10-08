#pragma once
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

namespace tensorrt_infer_core
{
    class MongoDBClient
    {
    public:
        MongoDBClient(const std::string &url_path = "mongodb://localhost:27017/");

        bool init(const std::string &url_path);
        std::map<std::string, std::vector<std::vector<double>>> getEmbeddings(const std::string &db_name);

    private:
        mongocxx::client mongo_client_;
        mongocxx::instance mongo_instance_{};
    };

} // namespace tensorrt_infer_core
