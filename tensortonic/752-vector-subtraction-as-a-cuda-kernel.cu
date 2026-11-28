/*

Implement element-wise subtraction of two vectors with a CUDA kernel.

C[i] = A[i] - B[i]

A is the first input vector, B is the vector subtracted from it, C is the output vector, N is their common length, and i is an integer index from zero through N minus one.

Subtract the second vector from the first at each index; reversing the operands changes the result.

The buffers are contiguous arrays of 32-bit floats in device memory. Write all N results into the preallocated C buffer; the solve function returns no value.

Examples
Input: A = [1,2,3,4], B = [5,6,7,8]

Output: [-4,-4,-4,-4]

Explanation: At every index, subtracting the second input value from the first gives negative four.

Input: A = [1.5,2.5,3.5], B = [0.5,0.5,0.5]

Output: [1,2,3]

Hint 1
Use blockIdx.x, blockDim.x, and threadIdx.x to identify a thread's global element index.

Hint 2
Check both operand order and whether the index lies inside the vector.

Requirements
Compute the specified operation independently at every valid index and store the result in C.
Leave input buffers unchanged and do not access memory outside the supplied buffers.
Preserve the supplied CUDA C++ function signatures and host launch wrapper.
Do not use external libraries.
Constraints
N is an integer from 1 through 10,000,000.
A, B, and C each contain N contiguous 32-bit floating-point elements in device memory.
Input values are finite and representable as 32-bit floats.

*/

#include <iostream>
#include <cstdio>
#include <cuda_runtime.h>

using namespace std;

__global__ void vector_sub(const float *A, const float *B, float *C, int N)
{
	int idx = blockIdx.x * blockDim.x + threadIdx.x;
	if (idx < N)
		C[idx] = A[idx] - B[idx];
}

extern "C" void solve(const float *A, const float *B, float *C, int N)
{
	int threads = 256;
	int blocks = (N + threads - 1) / threads;
	vector_sub<<<blocks, threads>>>(A, B, C, N);
	cudaDeviceSynchronize();
}

int main()
{
	float A1[4] = { 1, 2, 3, 4 };
	float B1[4] = { 5, 6, 7, 8 };
	float C1[4];

	float A2[3] = { 1.5, 2.5, 3.5 };
	float B2[3] = { 0.5, 0.5, 0.5 };
	float C2[3];

	solve(A1, B1, C1, size(A1));
	solve(A2, B2, C2, size(A2));

	printf("%f %f %f %f\n", C1[0], C1[1], C1[2], C1[3]);
	printf("%f %f %f\n", C2[0], C2[1], C2[2]);

	return 0;
}
