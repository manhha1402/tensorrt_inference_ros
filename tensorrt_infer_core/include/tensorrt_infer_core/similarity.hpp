#include <iostream>
#include <vector>
#include <thrust/device_vector.h>
#include <thrust/transform_reduce.h>
#include <thrust/functional.h>
#include <thrust/extrema.h>
// Function to calculate the smallest similarity using Thrust
double findSmallestSimilarity(const std::vector<std::vector<double>> &vectors, const std::vector<double> &target_vector);
std::pair<double, int> findLargestSimilarity(const std::vector<std::vector<double>> &vectors, const std::vector<double> &target_vector);