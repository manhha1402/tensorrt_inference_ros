#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <cmath>
#include <string>
#include <limits>
#include <cuda_runtime.h>
#include <tensorrt_infer_core/similarity.hpp>

namespace
{
    // CUDA helper functions for cosine similarity calculation
    __device__ double dotProduct(const double *a, const double *b, int size)
    {
        double dot = 0.0;
        for (int i = 0; i < size; ++i)
        {
            dot += a[i] * b[i];
        }
        return dot;
    }

    __device__ double magnitude(const double *vec, int size)
    {
        double sum = 0.0;
        for (int i = 0; i < size; ++i)
        {
            sum += vec[i] * vec[i];
        }
        return sqrt(sum);
    }

    __global__ void computeCosineSimilarity(
        const double *target_vector,
        const double *data,
        int vector_size,
        int total_vectors,
        double *similarities)
    {
        int idx = blockIdx.x * blockDim.x + threadIdx.x;
        if (idx < total_vectors)
        {
            const double *current_vector = data + idx * vector_size;
            double dot = dotProduct(target_vector, current_vector, vector_size);
            double mag_target = magnitude(target_vector, vector_size);
            double mag_current = magnitude(current_vector, vector_size);
            similarities[idx] = dot / (mag_target * mag_current + 1e-10); // Avoid division by zero
        }
    }

    // Kernel for finding max similarity (parallel reduction)
    __global__ void findMaxSimilarity(
        const double *similarities,
        int total_vectors,
        double *max_similarity,
        int *max_index)
    {
        extern __shared__ double shared_data[]; // Shared memory for block reduction
        double *shared_similarities = shared_data;
        int *shared_indices = (int *)&shared_data[blockDim.x];

        int tid = threadIdx.x;
        int global_idx = blockIdx.x * blockDim.x + threadIdx.x;

        // Initialize shared memory with similarities and indices
        if (global_idx < total_vectors)
        {
            shared_similarities[tid] = similarities[global_idx];
            shared_indices[tid] = global_idx;
        }
        else
        {
            shared_similarities[tid] = -1e10; // Negative infinity for unused threads
            shared_indices[tid] = -1;
        }
        __syncthreads();

        // Block reduction to find max similarity and its index
        for (int s = blockDim.x / 2; s > 0; s >>= 1)
        {
            if (tid < s && shared_similarities[tid] < shared_similarities[tid + s])
            {
                shared_similarities[tid] = shared_similarities[tid + s];
                shared_indices[tid] = shared_indices[tid + s];
            }
            __syncthreads();
        }

        // Write block's maximum to global memory
        if (tid == 0)
        {
            max_similarity[blockIdx.x] = shared_similarities[0];
            max_index[blockIdx.x] = shared_indices[0];
        }
    }

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
}

namespace tensorrt_infer_core
{

    // Host function to find the best match using CUDA
    std::tuple<double, std::string, int> findSimilaritywithName(
        const std::map<std::string, std::vector<std::vector<double>>> &data_map,
        const std::vector<double> &target_vector, const std::string &distance_metric)
    {
        cudaError_t err;
        std::vector<std::string> keys;
        std::vector<double> flattened_data;
        if (distance_metric == "cosine")
        {

            // Step 1: Flatten the data_map into a contiguous array and track categories and indices
            std::vector<int> category_indices;
            int vector_size = target_vector.size();
            int total_vectors = 0;

            for (const auto &[key, vectors] : data_map)
            {
                keys.push_back(key);
                for (const auto &vec : vectors)
                {
                    flattened_data.insert(flattened_data.end(), vec.begin(), vec.end());
                    category_indices.push_back(keys.size() - 1);
                }
                total_vectors += vectors.size();
            }

            // Step 2: Allocate device memory
            double *d_target_vector, *d_data, *d_similarities;
            double *d_max_similarity; // For storing max similarity
            int *d_max_index;         // For storing max index

            cudaMalloc(&d_target_vector, vector_size * sizeof(double));
            cudaMalloc(&d_data, flattened_data.size() * sizeof(double));
            cudaMalloc(&d_similarities, total_vectors * sizeof(double));
            cudaMalloc(&d_max_similarity, sizeof(double) * total_vectors); // Temp max per block
            cudaMalloc(&d_max_index, sizeof(int) * total_vectors);         // Temp max indices

            // Step 3: Copy data to device
            cudaMemcpy(d_target_vector, target_vector.data(), vector_size * sizeof(double), cudaMemcpyHostToDevice);
            cudaMemcpy(d_data, flattened_data.data(), flattened_data.size() * sizeof(double), cudaMemcpyHostToDevice);

            // Step 4: Launch kernel to compute similarities
            int threadsPerBlock = 256;
            int blocksPerGrid = (total_vectors + threadsPerBlock - 1) / threadsPerBlock;
            computeCosineSimilarity<<<blocksPerGrid, threadsPerBlock>>>(
                d_target_vector, d_data, vector_size, total_vectors, d_similarities);
            // Wait for GPU to finish
            cudaDeviceSynchronize();
            // Check for kernel errors
            err = cudaGetLastError();
            if (err != cudaSuccess)
            {
                std::cerr << "CUDA kernel launch failed: " << cudaGetErrorString(err) << std::endl;
                return {0.0, "", -1};
            }

            // Step 5: Launch reduction kernel to find the maximum similarity
            size_t shared_memory_size = 2 * threadsPerBlock * sizeof(double); // For similarities and indices
            findMaxSimilarity<<<blocksPerGrid, threadsPerBlock, shared_memory_size>>>(
                d_similarities, total_vectors, d_max_similarity, d_max_index);
            // Wait for GPU to finish
            cudaDeviceSynchronize();
            // Check for kernel errors
            err = cudaGetLastError();
            if (err != cudaSuccess)
            {
                std::cerr << "CUDA kernel launch failed: " << cudaGetErrorString(err) << std::endl;
                return {0.0, "", -1};
            }
            // Step 6: Copy block results to host and find global max
            std::vector<double> block_max_similarity(blocksPerGrid);
            std::vector<int> block_max_index(blocksPerGrid);
            cudaMemcpy(block_max_similarity.data(), d_max_similarity, blocksPerGrid * sizeof(double), cudaMemcpyDeviceToHost);
            cudaMemcpy(block_max_index.data(), d_max_index, blocksPerGrid * sizeof(int), cudaMemcpyDeviceToHost);

            // Step 7: Find the global max similarity on the host
            double best_similarity = -1e10;
            int best_index = -1;
            for (int i = 0; i < blocksPerGrid; ++i)
            {
                if (block_max_similarity[i] > best_similarity)
                {
                    best_similarity = block_max_similarity[i];
                    best_index = block_max_index[i];
                }
            }

            // Step 8: Map best index back to category and local index
            int category_index = category_indices[best_index];
            std::string best_name = keys[category_index];
            int local_index = best_index;
            for (int i = 0; i < category_index; ++i)
            {
                local_index -= data_map.at(keys[i]).size();
            }

            // Step 9: Free device memory
            cudaFree(d_target_vector);
            cudaFree(d_data);
            cudaFree(d_similarities);
            cudaFree(d_max_similarity);
            cudaFree(d_max_index);

            // Step 10: Return the best match result
            return {best_similarity, best_name, local_index};
        }
        else
        {
            // Flatten the data_map into a 2D vector and collect the keys for each vector
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
            // Wait for GPU to finish
            cudaDeviceSynchronize();
            // Check for kernel errors
            err = cudaGetLastError();
            if (err != cudaSuccess)
            {
                std::cerr << "CUDA kernel launch failed: " << cudaGetErrorString(err) << std::endl;
                return {0.0, "", -1};
            }
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