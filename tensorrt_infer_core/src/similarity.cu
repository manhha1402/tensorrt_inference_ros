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
    __device__ double atomicMin_double(double* address, double val) {
        unsigned long long int* address_as_ull = (unsigned long long int*) address;
        unsigned long long int old = *address_as_ull, assumed;

        do {
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
    __global__ void findClosestVector(const double* flattened_vectors, const double* target_vector,
                                    int num_vectors, const int* vector_lengths,
                                    const int* vector_offsets, double* min_distance,
                                    int* min_index, int target_size) {
        int idx = blockIdx.x * blockDim.x + threadIdx.x;

        if (idx < num_vectors) {
            int offset = vector_offsets[idx];
            int length = vector_lengths[idx];

            // Compute Euclidean distance
            double dist = 0.0;
            for (int i = 0; i < target_size && i < length; ++i) {
                double diff = target_vector[i] - flattened_vectors[offset + i];
                dist += diff * diff;
            }
            dist = sqrt(dist);

            // Use atomicMin to find the minimum distance
            atomicMin_double(min_distance, dist);
            
            if (dist == *min_distance) {
                atomicExch(min_index, idx);  // Store the index of the minimum
            }
        }
    }


///////////////////////////////
    std::tuple<double, std::string, int> findSimilaritywithName(
        const std::map<std::string, std::vector<std::vector<double>>> &data_map,
        const std::vector<double> &target_vector, const std::string &distance_metric)
    {

        if(distance_metric == "cosine")
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
        else if(distance_metric == "euclidean") {
            // Structure to hold the flattened map data on host
            struct FlattenedMap {
                std::vector<double> flattened_vectors;
                std::vector<int> vector_lengths;  // Length of each vector
                std::vector<int> vector_offsets;  // Offsets in the flattened array
                std::vector<std::string> keys;    // Corresponding keys
            };

            // Function to flatten the std::map
            //FlattenedMap flattenMap(const std::map<std::string, std::vector<std::vector<double>>>& my_map) {
                FlattenedMap flattened_data;
                int offset = 0;

                for (const auto& pair : data_map) {
                    flattened_data.keys.push_back(pair.first);
                    for (const auto& vec : pair.second) {
                        flattened_data.flattened_vectors.insert(flattened_data.flattened_vectors.end(), vec.begin(), vec.end());
                        flattened_data.vector_lengths.push_back(vec.size());
                        flattened_data.vector_offsets.push_back(offset);
                        offset += vec.size();
                    }
                }
        
            double* d_flattened_vectors;
            cudaMalloc(&d_flattened_vectors, flattened_data.flattened_vectors.size() * sizeof(double));
            cudaMemcpy(d_flattened_vectors, flattened_data.flattened_vectors.data(),
                    flattened_data.flattened_vectors.size() * sizeof(double), cudaMemcpyHostToDevice);

            double* d_target_vector;
            cudaMalloc(&d_target_vector, target_vector.size() * sizeof(double));
            cudaMemcpy(d_target_vector, target_vector.data(), target_vector.size() * sizeof(double), cudaMemcpyHostToDevice);

            int* d_vector_lengths;
            cudaMalloc(&d_vector_lengths, flattened_data.vector_lengths.size() * sizeof(int));
            cudaMemcpy(d_vector_lengths, flattened_data.vector_lengths.data(), flattened_data.vector_lengths.size() * sizeof(int), cudaMemcpyHostToDevice);

            int* d_vector_offsets;
            cudaMalloc(&d_vector_offsets, flattened_data.vector_offsets.size() * sizeof(int));
            cudaMemcpy(d_vector_offsets, flattened_data.vector_offsets.data(), flattened_data.vector_offsets.size() * sizeof(int), cudaMemcpyHostToDevice);

            // Allocate memory for results on the device
            double* d_min_distance;
            double host_min_distance = DBL_MAX;
            cudaMalloc(&d_min_distance, sizeof(double));
            cudaMemcpy(d_min_distance, &host_min_distance, sizeof(double), cudaMemcpyHostToDevice);

            int* d_min_index;
            cudaMalloc(&d_min_index, sizeof(int));
            int host_min_index = -1;
            cudaMemcpy(d_min_index, &host_min_index, sizeof(int), cudaMemcpyHostToDevice);

            // Launch the kernel
            int num_vectors = flattened_data.vector_offsets.size();
            int threads_per_block = 256;
            int blocks = (num_vectors + threads_per_block - 1) / threads_per_block;
            
            findClosestVector<<<blocks, threads_per_block>>>(d_flattened_vectors, d_target_vector,
                num_vectors, d_vector_lengths, d_vector_offsets, d_min_distance, d_min_index, target_vector.size());

            // Copy results back to host
            double min_distance;
            int min_index;
            cudaMemcpy(&min_distance, d_min_distance, sizeof(double), cudaMemcpyDeviceToHost);
            cudaMemcpy(&min_index, d_min_index, sizeof(int), cudaMemcpyDeviceToHost);

            // Free device memory
            cudaFree(d_flattened_vectors);
            cudaFree(d_target_vector);
            cudaFree(d_vector_lengths);
            cudaFree(d_vector_offsets);
            cudaFree(d_min_distance);
            cudaFree(d_min_index);

            // Get the key associated with the minimum index
            std::string best_key = flattened_data.keys[min_index];

            return std::make_tuple(min_distance, best_key, min_index);
        }
    }
}
