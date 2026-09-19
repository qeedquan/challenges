/*

Write a program or function that:

Takes as input a list or array of 128 numbers.

Sends that array to a GPU

Performs a calculation on the GPU to square each element of the array and then sum them

Gets the answer from the GPU, and returns or displays it

So your program will simply return the sum of the squares of its input array, but it will perform the calculation on a GPU.

The input numbers should be sent to the GPU in the form of signed or unsigned integer types or floats, of 32 or more bits in size.

You may make any assumptions you like about hardware, e.g. you may assume a CUDA or OpenCl capable card is present without checking for it.

This is code-golf. The smallest code (in bytes) will be considered the winner for each language.

*/

#include <stdio.h>

#define SIZE 128

__global__ void
sumofsquares(float *output, float *input, int length)
{
	float value;
	int i;

	value = 0;
	for (i = 0; i < length; i++)
		value += input[i] * input[i];
	*output = value;
}

int
main()
{
	float *input;
	float *output;
	float values[SIZE];
	float result;
	int status;
	int i;

	status = 0;
	input = output = NULL;
	if (cudaMalloc(&input, sizeof(*input) * SIZE) != cudaSuccess)
		goto error;

	if (cudaMalloc(&output, sizeof(*output)) != cudaSuccess)
		goto error;

	for (i = 0; i < SIZE; i++)
		values[i] = i;

	cudaMemcpy(input, values, sizeof(values), cudaMemcpyHostToDevice);

	sumofsquares<<<1, 1>>>(output, input, SIZE);
	cudaMemcpy(&result, output, sizeof(result), cudaMemcpyDeviceToHost);

	printf("%f\n", result);

	if (0) {
	error:
		status = 1;
	}

	cudaFree(input);
	cudaFree(output);
	return status;
}
