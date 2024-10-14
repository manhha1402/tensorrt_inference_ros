#include <iostream>
#include <vector>
#include <cuda_runtime.h>
#include <cfloat>
#include <map>
#include "tensorrt_infer_core/similarity.hpp"
namespace tensorrt_infer_core
{
    // Custom atomicMax for doubles (since CUDA does not support atomicMax for doubles by default)
    __device__ double atomicMax_double(double *address, double val)
    {
        unsigned long long int *address_as_ull = (unsigned long long int *)address;
        unsigned long long int old = *address_as_ull, assumed;

        do
        {
            assumed = old;
            old = atomicCAS(address_as_ull, assumed, __double_as_longlong(max(val, __longlong_as_double(assumed))));
        } while (assumed != old);

        return __longlong_as_double(old);
    }
    // Custom atomicMin for double precision
    __device__ double atomicMin_double(double *address, double val)
    {
        unsigned long long int *address_as_ull = (unsigned long long int *)address;
        unsigned long long int old = *address_as_ull, assumed;

        do
        {
            assumed = old;
            old = atomicCAS(address_as_ull, assumed, __double_as_longlong(fmin(val, __longlong_as_double(assumed))));
        } while (assumed != old);

        return __longlong_as_double(old);
    }
    __global__ void compute_dot_products(const double *vectors, const double *target_vector, double *dot_products, int num_vectors, int vector_size)
    {
        int idx = blockIdx.x * blockDim.x + threadIdx.x;

        if (idx < num_vectors)
        {
            double dot_product = 0.0;
            for (int i = 0; i < vector_size; ++i)
            {
                dot_product += vectors[idx * vector_size + i] * target_vector[i];
            }
            dot_products[idx] = dot_product;
        }
    }
    // CUDA Kernel to find the maximum dot product and its index using atomic operations
    __global__ void find_max_with_index(double *results, double *max_val, int *max_idx, int num_vectors)
    {
        int idx = blockIdx.x * blockDim.x + threadIdx.x;

        // Initialize shared variables (maximum value and index)
        if (idx < num_vectors)
        {
            double result = results[idx];
            atomicMax_double(max_val, result);

            if (*max_val == result)
            {
                *max_idx = idx; // Update index if the current result is the new max
            }
        }
    }
    // CUDA Kernel to find the maximum dot product, its index, and its key using atomic operations
    __global__ void find_max_with_key(double *results, double *max_val, int *max_idx, int *max_key, const int *key_indices, int num_vectors)
    {
        int idx = blockIdx.x * blockDim.x + threadIdx.x;

        if (idx < num_vectors)
        {
            double result = results[idx];
            atomicMax_double(max_val, result);

            // If we find a new maximum, update the index and the key
            if (*max_val == result)
            {
                *max_idx = idx;
                *max_key = key_indices[idx];
            }
        }
    }

    // Kernel to compute the Euclidean distance and find the minimum

    // CUDA kernel to compute Euclidean distances
    __global__ void computeEuclideanDistance(const double *d_data, const double *d_target, double *d_distances, size_t vector_size, size_t num_vectors)
    {
        int idx = blockIdx.x * blockDim.x + threadIdx.x;
        if (idx < num_vectors)
        {
            double sum = 0.0;
            for (int i = 0; i < vector_size; i++)
            {
                double diff = d_data[idx * vector_size + i] - d_target[i];
                sum += diff * diff;
            }
            d_distances[idx] = sqrt(sum); // Store the Euclidean distance
        }
    }

    ///////////////////////////////
    std::tuple<double, std::string, int>
    findSimilaritywithName(
        const std::map<std::string, std::vector<std::vector<double>>> &data_map,
        const std::vector<double> &target_vector, const std::string &distance_metric)
    {

        if (distance_metric == "cosine")
        {
            int num_vectors = 0;
            int vector_size = target_vector.size();

            // Prepare a flattened version of the vectors and an array of corresponding keys
            std::vector<double> flat_vectors;
            std::vector<int> key_indices;  // Track which map key each vector belongs to
            std::vector<std::string> keys; // Map index to string key
            int key_counter = 0;

            for (const auto &entry : data_map)
            {
                keys.push_back(entry.first); // Keep track of the keys
                for (const auto &vec : entry.second)
                {
                    flat_vectors.insert(flat_vectors.end(), vec.begin(), vec.end());
                    key_indices.push_back(key_counter);
                    num_vectors++;
                }
                key_counter++;
            }

            // Allocate memory on the device (GPU)
            double *d_vectors, *d_target_vector, *d_results, *d_max_val;
            int *d_max_idx, *d_key_indices, *d_max_key;
            cudaMalloc(&d_vectors, num_vectors * vector_size * sizeof(double));
            cudaMalloc(&d_target_vector, vector_size * sizeof(double));
            cudaMalloc(&d_results, num_vectors * sizeof(double));
            cudaMalloc(&d_key_indices, num_vectors * sizeof(int));
            cudaMalloc(&d_max_val, sizeof(double));
            cudaMalloc(&d_max_idx, sizeof(int));
            cudaMalloc(&d_max_key, sizeof(int));

            // Copy data from host to device
            cudaMemcpy(d_vectors, flat_vectors.data(), num_vectors * vector_size * sizeof(double), cudaMemcpyHostToDevice);
            cudaMemcpy(d_target_vector, target_vector.data(), vector_size * sizeof(double), cudaMemcpyHostToDevice);
            cudaMemcpy(d_key_indices, key_indices.data(), num_vectors * sizeof(int), cudaMemcpyHostToDevice);

            // Initialize max_val on the device with a very small value
            double init_max = -DBL_MAX;
            cudaMemcpy(d_max_val, &init_max, sizeof(double), cudaMemcpyHostToDevice);

            // Set up block and grid sizes
            int block_size = 256;
            int grid_size = (num_vectors + block_size - 1) / block_size;

            // Launch kernel to compute dot products
            compute_dot_products<<<grid_size, block_size>>>(d_vectors, d_target_vector, d_results, num_vectors, vector_size);

            // Launch kernel to find the maximum dot product, its index, and key
            find_max_with_key<<<grid_size, block_size>>>(d_results, d_max_val, d_max_idx, d_max_key, d_key_indices, num_vectors);

            // Copy the result back to the host
            double max_similarity;
            int max_idx, max_key;
            cudaMemcpy(&max_similarity, d_max_val, sizeof(double), cudaMemcpyDeviceToHost);
            cudaMemcpy(&max_idx, d_max_idx, sizeof(int), cudaMemcpyDeviceToHost);
            cudaMemcpy(&max_key, d_max_key, sizeof(int), cudaMemcpyDeviceToHost);

            // Free the device memory
            cudaFree(d_vectors);
            cudaFree(d_target_vector);
            cudaFree(d_results);
            cudaFree(d_max_val);
            cudaFree(d_max_idx);
            cudaFree(d_key_indices);
            cudaFree(d_max_key);

            // Get the corresponding key and return the result
            std::string max_key_string = keys[max_key];
            return std::make_tuple(max_similarity, max_key_string, max_idx);
        }
        else if (distance_metric == "euclidean")
        {
            // Flatten the data_map into a 2D vector and collect the keys for each vector
            std::vector<std::string> keys;
            std::vector<double> flattened_data;
            size_t vector_size = target_vector.size();

            for (const auto &pair : data_map)
            {
                const std::string &key = pair.first;
                for (const auto &vec : pair.second)
                {
                    keys.push_back(key); // Repeat the key for each vector under that key
                    flattened_data.insert(flattened_data.end(), vec.begin(), vec.end());
                }
            }

            size_t num_vectors = flattened_data.size() / vector_size;

            // Allocate device memory for data, target vector, and distances
            double *d_data, *d_target, *d_distances;
            cudaMalloc(&d_data, flattened_data.size() * sizeof(double));
            cudaMalloc(&d_target, vector_size * sizeof(double));
            cudaMalloc(&d_distances, num_vectors * sizeof(double));

            // Copy data and target vector to device
            cudaMemcpy(d_data, flattened_data.data(), flattened_data.size() * sizeof(double), cudaMemcpyHostToDevice);
            cudaMemcpy(d_target, target_vector.data(), vector_size * sizeof(double), cudaMemcpyHostToDevice);

            // Launch kernel to compute distances
            int blockSize = 256;
            int numBlocks = (num_vectors + blockSize - 1) / blockSize;
            computeEuclideanDistance<<<numBlocks, blockSize>>>(d_data, d_target, d_distances, vector_size, num_vectors);

            // Copy distances back to host
            std::vector<double> distances(num_vectors);
            cudaMemcpy(distances.data(), d_distances, num_vectors * sizeof(double), cudaMemcpyDeviceToHost);

            // Find the index of the smallest distance
            int min_index = std::distance(distances.begin(), std::min_element(distances.begin(), distances.end()));
            double min_distance = distances[min_index];

            // Get the corresponding key for the closest vector
            std::string best_match_key = keys[min_index];

            // Clean up memory
            cudaFree(d_data);
            cudaFree(d_target);
            cudaFree(d_distances);

            // Return the result as a tuple (distance, key, index)
            return std::make_tuple(min_distance, best_match_key, min_index);
        }
    }
}
