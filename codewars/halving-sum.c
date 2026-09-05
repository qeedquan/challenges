/*

Task
Given a positive integer n, calculate the following sum:

n + n/2 + n/4 + n/8 + ...
All elements of the sum are the results of integer division.

Example
25  =>  25 + 12 + 6 + 3 + 1 = 47

*/

#include <assert.h>
#include <stdio.h>
#include <stdbit.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

unsigned
halvesumbf(unsigned n)
{
	unsigned r;

	for (r = 0; n; n /= 2)
		r += n;
	return r;
}

// https://oeis.org/A005187
unsigned
halvesum(unsigned n)
{
	return (n << 1) - stdc_count_ones(n);
}

int
main()
{
	static const unsigned tab[] = {
		0, 1, 3, 4, 7, 8, 10, 11, 15, 16, 18, 19, 22, 23, 25, 26, 31, 32, 34,
		35, 38, 39, 41, 42, 46, 47, 49, 50, 53, 54, 56, 57, 63, 64, 66, 67,
		70, 71, 73, 74, 78, 79, 81, 82, 85, 86, 88, 89, 94, 95, 97, 98, 101,
		102, 104, 105, 109, 110, 112, 113, 116, 117, 119, 120, 127, 128
	};

	unsigned i;

	for (i = 0; i < nelem(tab); i++) {
		assert(halvesum(i) == tab[i]);
		assert(halvesumbf(i) == tab[i]);
	}

	return 0;
}
