/*

The value of the Fenwick function of a number n is the largest power of two that divides n.

Given n, find its Fenwick function value.

It is recommended to solve this problem without using loops.

Input
The input contains one integer n (0<n≤2^31−1).

Output
Print the value of the Fenwick function for the number n.

Examples

Input #1
12

Answer #1
4

*/

#include <assert.h>
#include <stdio.h>
#include <stdbit.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned uint;

// https://oeis.org/A070939
uint
solve(uint n)
{
	return stdc_bit_width(n);
}

int
main()
{
	static const uint tab[] = {
		0, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5,
		5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7
	};

	uint i;

	assert(solve(12) == 4);

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i) == tab[i]);

	return 0;
}
