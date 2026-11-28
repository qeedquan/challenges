/*

Compute the dot product of two equal-length vectors:

dot(x, y) = Sum[i=1, n] x[i]*y[i]

Here, x[i] and y[i] are corresponding vector elements and n is their shared length.
Return the result as a Python float.

Examples
Input: x = [1, 2, 3], y = [4, 5, 6]

Output: 32.0

Explanation: The products 4, 10, and 18 sum to 32.

Input: x = [1, 0], y = [0, 1]

Output: 0.0

Input: x = [-1, 2], y = [3, -1]

Output: -5.0

Hint 1
Convert both vectors with np.asarray(..., dtype=float).

Hint 2
Use np.dot(x, y) and convert the NumPy scalar to float.

Requirements
Compute the dot product with NumPy
Return a Python float
Constraints
x and y are equal-length, nonempty one-dimensional numeric lists
Each vector contains at most 10^6 values
Use NumPy only

*/

#include <stdio.h>
#include <immintrin.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

float
dotavx512(const float *a, const float *b, size_t n)
{
	__m512 acc = _mm512_setzero_ps();
	size_t i = 0;
	for (; i + 16 <= n; i += 16) {
		__m512 va = _mm512_loadu_ps(a + i);
		__m512 vb = _mm512_loadu_ps(b + i);
		acc = _mm512_fmadd_ps(va, vb, acc);
	}
	if (i < n) {
		__mmask16 mask = (__mmask16)((1u << (n - i)) - 1u);
		__m512 va = _mm512_maskz_loadu_ps(mask, a + i);
		__m512 vb = _mm512_maskz_loadu_ps(mask, b + i);
		acc = _mm512_mask3_fmadd_ps(va, vb, acc, mask);
	}
	return _mm512_reduce_add_ps(acc);
}

int
main()
{
	alignas(64) float a1[] = { 1, 2, 3 };
	alignas(64) float b1[] = { 4, 5, 6 };

	alignas(64) float a2[] = { 1, 0 };
	alignas(64) float b2[] = { 0, 1 };

	alignas(64) float a3[] = { -1, 2 };
	alignas(64) float b3[] = { 3, -1 };

	printf("%f\n", dotavx512(a1, b1, nelem(a1)));
	printf("%f\n", dotavx512(a2, b2, nelem(a2)));
	printf("%f\n", dotavx512(a3, b3, nelem(a3)));

	return 0;
}
