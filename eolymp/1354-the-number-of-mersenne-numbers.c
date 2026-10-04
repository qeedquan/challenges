/*

A Mersenne number is a number of the form 2^n-1, where n is a natural number.

Given an array of integers, count how many numbers in it are Mersenne numbers.

Input
The first line contains an integer k – the number of elements in the array.
The next line contains the numbers a1,a2,…,ak. (0<k<1000, 0≤ai<2^31).

Output
Output a single number – the number of Mersenne numbers in the given array.

Examples

Input #1
5
3 7 10 31 63

Answer #1
4

*/

#include <assert.h>
#include <stdbit.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

bool
mersenne(uvlong n)
{
	return stdc_bit_width(n) == stdc_count_ones(n);
}

size_t
solve(uvlong *a, size_t n)
{
	size_t c, i;

	for (c = i = 0; i < n; i++) {
		if (mersenne(a[i]))
			c += 1;
	}
	return c;
}

int
main()
{
	uvlong a1[] = { 3, 7, 10, 31, 63 };
	uvlong a2[] = { 0 };

	assert(solve(a1, nelem(a1)) == 4);
	assert(solve(a2, nelem(a2)) == 1);

	return 0;
}
