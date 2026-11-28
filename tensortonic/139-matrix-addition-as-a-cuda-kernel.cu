/*

Add two float32 matrices elementwise on the GPU.

C[i, j] = A[i, j] + B[i, j]

Here, A and B are the input matrices, C is the output matrix, M is the number of rows, N is the number of columns, and i and j are valid row and column indices. All buffers use contiguous row-major storage, with each row's N values placed consecutively.

Write the result into the preallocated float32 device buffer C with shape (M, N), leaving A and B unchanged. The function returns no value.

Examples
Input: A = [[1, 2], [3, 4]], B = [[5, 6], [7, 8]], M = 2, N = 2

Output: [[6.0, 8.0], [10.0, 12.0]]

Explanation: Each output entry adds the two inputs at the same row and column.

Input: A = [[0, 1, 2], [3, 4, 5]], B = [[10, 10, 10], [20, 20, 20]], M = 2, N = 3

Output: [[10.0, 11.0, 12.0], [23.0, 24.0, 25.0]]

Hint 1
Use the x and y thread coordinates to distinguish columns from rows.

Hint 2
The row stride in either flat input buffer is N elements.

Hint 3
Check both coordinates before accessing a matrix element.

Requirements
Add matching entries from A and B using their row-major layout.
Write every output element without changing either input or accessing beyond the buffers.
Keep the supplied solve interface.
Constraints
M and N are each between 1 and 4,096.
A, B, and C are contiguous row-major device buffers with shape (M, N).
Input values are finite float32.

*/

#include <cstdio>
#include <cuda_runtime.h>

using namespace std;

__global__ void matrixAdd(const float *A, const float *B, float *C, int rows, int cols)
{
	int col = blockIdx.x * blockDim.x + threadIdx.x;
	int row = blockIdx.y * blockDim.y + threadIdx.y;

	if (row < rows && col < cols)
	{
		int idx = row * cols + col;
		C[idx] = A[idx] + B[idx];
	}
}

int main()
{
	const int rows = 512;
	const int cols = 512;
	const size_t bytes = static_cast<size_t>(rows) * cols * sizeof(float);

	float *h_A = new float[rows * cols];
	float *h_B = new float[rows * cols];
	float *h_C = new float[rows * cols];

	for (int i = 0; i < rows * cols; ++i)
	{
		h_A[i] = i;
		h_B[i] = i + 1;
	}

	float *d_A = nullptr, *d_B = nullptr, *d_C = nullptr;
	cudaMalloc(&d_A, bytes);
	cudaMalloc(&d_B, bytes);
	cudaMalloc(&d_C, bytes);

	cudaMemcpy(d_A, h_A, bytes, cudaMemcpyHostToDevice);
	cudaMemcpy(d_B, h_B, bytes, cudaMemcpyHostToDevice);

	dim3 threadsPerBlock(16, 16);
	dim3 numBlocks((cols + threadsPerBlock.x - 1) / threadsPerBlock.x,
				   (rows + threadsPerBlock.y - 1) / threadsPerBlock.y);

	matrixAdd<<<numBlocks, threadsPerBlock>>>(d_A, d_B, d_C, rows, cols);
	cudaDeviceSynchronize();

	cudaMemcpy(h_C, d_C, bytes, cudaMemcpyDeviceToHost);

	for (int i = 0; i < rows*cols; i++)
		printf("h_C[%d] = %.1f\n", i, h_C[i]);

	cudaFree(d_A);
	cudaFree(d_B);
	cudaFree(d_C);
	delete[] h_A;
	delete[] h_B;
	delete[] h_C;
	return 0;
}
