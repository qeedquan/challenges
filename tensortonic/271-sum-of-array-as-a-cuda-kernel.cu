/*

Implement a CUDA kernel that computes the scalar sum of a 1-D float vector input of length N:

result = Sum[i=0, N-1] input[i]

The result is a single float32 scalar written to the first slot of the device buffer result (a one-element buffer).
Because every element contributes to the same output, the kernel must accumulate across all N elements using a cross-thread reduction. Do not assume a single block covers N: the grid may span many blocks, and partial sums from different blocks must combine into result[0].

Examples
Input: input = [1, 2, 3, 4, 5]

Output: 15.0

Computed as 
1+2+3+4+5=15

Input: input = [-1, 2, -3, 4]

Output: 2.0

Computed as 
-1 + 2 + -3 + 4 = 2

Hint 1
A clean pattern is a per-block tree reduction in __shared__ memory: each thread loads its element into a register
(or 0 when i≥Ni≥N), writes the partial into shared memory, then participates in 
log^2(blockDim) log^2 (blockDim) pairwise merges under __syncthreads.

Hint 2
To merge across blocks, have thread 0 of each block call atomicAdd(result, block_sum). The launcher in the starter pre-zeros result, so accumulating into it directly is safe.

Hint 3
A pure-atomics alternative is to skip shared memory and have every thread atomicAdd(result, input[i]), but contention is much higher; prefer one atomic per block.

Requirements
Perform a cross-thread reduction; a single thread cannot read all of input
Write the final scalar into 
result[0]
result[0]
Do not assume one block covers N; combine partial sums from every block
The solve signature must not change
Constraints
1 ≤ N ≤ 10^7
1≤N≤10^7 input and result are device pointers
All values are 32-bit floats result refers to exactly one float slot

*/

#include <cstdio>
#include <cuda_runtime.h>

__global__ void sumArrayKernel(const float *__restrict__ input, float *__restrict__ result, int n)
{
	// Allocate shared memory for threads within this block
	extern __shared__ float sdata[];

	unsigned int tid = threadIdx.x;
	unsigned int idx = blockIdx.x * (blockDim.x * 2) + threadIdx.x;

	// 1. Load elements from global memory into shared memory
	// Each thread loads two elements and performs the first addition immediately
	float mySum = (idx < n) ? input[idx] : 0.0f;
	if (idx + blockDim.x < n)
	{
		mySum += input[idx + blockDim.x];
	}
	sdata[tid] = mySum;
	__syncthreads();

	// 2. Perform tree-based reduction in shared memory
	// Halve the active threads at each step to avoid warp divergence
	for (unsigned int s = blockDim.x / 2; s > 0; s >>= 1)
	{
		if (tid < s)
		{
			sdata[tid] += sdata[tid + s];
		}
		__syncthreads();
	}

	// 3. Thread 0 writes this block's partial sum to the global output
	if (tid == 0)
	{
		atomicAdd(result, sdata[0]);
	}
}

int main()
{
	int n = 1 << 20;
	size_t bytes = n * sizeof(float);

	float *h_input = new float[n];
	for (int i = 0; i < n; i++)
		h_input[i] = 1.0f;

	float *d_input, *d_result;
	cudaMalloc(&d_input, bytes);
	cudaMalloc(&d_result, sizeof(float));

	cudaMemcpy(d_input, h_input, bytes, cudaMemcpyHostToDevice);
	cudaMemset(d_result, 0, sizeof(float));

	int blockSize = 256;
	int gridSize = (n + (blockSize * 2 - 1)) / (blockSize * 2);
	size_t sharedMemSize = blockSize * sizeof(float);

	sumArrayKernel<<<gridSize, blockSize, sharedMemSize>>>(d_input, d_result, n);

	float h_result = 0.0f;
	cudaMemcpy(&h_result, d_result, sizeof(float), cudaMemcpyDeviceToHost);

	printf("Sum: %f\n", h_result); // Expected: 1048576.000000

	cudaFree(d_input);
	cudaFree(d_result);
	delete[] h_input;
	return 0;
}
