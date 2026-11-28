/*

If you already learned how to write program with a simple loop from Sum in Loop task, this new exercise will be just a simple modification.

Now we are given several pairs of values and we want to calculate sum for each pair.

Input data will contain the total count of pairs to process in the first line.
The following lines will contain pairs themselves - one pair at each line.
Answer should contain the results separated by spaces.

Example:

data:
3
100 8
15 245
1945 54

answer:
108 260 1999

*/

#include <stdio.h>
#include <immintrin.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

float
sumavx512(const float *restrict a, size_t n)
{
	__m512 x;
	__m512 v;
	float r;
	size_t i;

	v = _mm512_setzero_ps();
	for (i = 0; i + 16 <= n; i += 16) {
		x = _mm512_loadu_ps(&a[i]);
		v = _mm512_add_ps(v, x);
	}

	r = _mm512_reduce_add_ps(v);
	for (; i < n; i++)
		r += a[i];
	return r;
}

int
main(void)
{
	alignas(64) float a1[16] = { 100, 8 };
	alignas(64) float a2[16] = { 15, 245 };
	alignas(64) float a3[16] = { 1945, 54 };

	printf("%f\n", sumavx512(a1, nelem(a1)));
	printf("%f\n", sumavx512(a2, nelem(a2)));
	printf("%f\n", sumavx512(a3, nelem(a3)));
	
	return 0;
}
