#include <iostream>
#include <vector>
#include <map>
namespace tensorrt_infer_core
{
    std::pair<double, int> findLargestSimilarity(const std::vector<std::vector<double>> &vectors, const std::vector<double> &target_vector);
    std::tuple<double, std::string, int> findSimilaritywithName(
        const std::map<std::string, std::vector<std::vector<double>>> &data_map,
        const std::vector<double> &target_vector);
}