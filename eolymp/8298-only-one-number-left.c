/*

Petryk Pyatochkin has decided to remove all odd numbers and numbers at odd positions from a sequence of natural numbers ranging from 1 to N.
He starts by eliminating all odd numbers, followed by numbers at odd positions, and continues this process until only one number is left.
What is this final number?

Input
A natural number N (2≤N≤2^63).

Output
The last remaining number.

Examples
Input #1
7

Answer #1
4

*/

#include <assert.h>
#include <stdio.h>
#include <stdbit.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

// https://oeis.org/A053644
uvlong
solve(uvlong n)
{
	if (n < 1)
		return 0;
	return 1ULL << (stdc_bit_width(n) - 1);
}

int
main()
{
	static const uvlong tab[] = {
		0, 1, 2, 2, 4, 4, 4, 4, 8, 8, 8, 8, 8, 8, 8, 8, 16, 16, 16, 16, 16, 16,
		16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 32, 32, 32, 32, 32, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64
	};

	uvlong i;

	assert(solve(1) == 1);
	assert(solve(2) == 2);
	assert(solve(7) == 4);

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i) == tab[i]);

	return 0;
}
