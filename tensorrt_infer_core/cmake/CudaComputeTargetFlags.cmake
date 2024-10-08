set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} --extended-lambda --expt-relaxed-constexpr --generate-line-info -lineinfo -Xcudafe --display_error_number -Xcudafe --diag_suppress=20011 -Xcudafe --diag_suppress=20014 -Xcudafe --diag_suppress=2977 -Xcudafe --diag_suppress=3057 -Xcudafe --diag_suppress=3059")
list(APPEND CUDA_NVCC_FLAGS --compiler-options;-fPIC;)

set(CMAKE_CUDA_COMPILE_FEATURES cuda_std_17)
set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS}
    --expt-relaxed-constexpr
    --expt-extended-lambda
    --default-stream per-thread
    --use_fast_math
    -Xcudafe "--diag_suppress=integer_sign_change"
    -Xcudafe "--diag_suppress=partial_override"
    -Xcudafe "--diag_suppress=virtual_function_decl_hidden")