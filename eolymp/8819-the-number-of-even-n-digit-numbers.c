/*

The program receives a natural number n as input. Your task is to output the count of even natural numbers that have exactly n digits.

Input
A natural number n.

Output
The count of even natural numbers with n digits.

Examples
Input #1
1

Answer #1
4

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

// https://oeis.org/A346629
uvlong
solve(uvlong n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 4;
	return 45 * pow(10, n - 2);
}

int
main()
{
	static const uvlong tab[] = {
		1,
		4,
		45,
		450,
		4500,
		45000,
		450000,
		4500000,
		45000000,
		450000000,
		4500000000,
		45000000000,
		450000000000,
		4500000000000,
		45000000000000,
		450000000000000,
		4500000000000000,
		45000000000000000,
		450000000000000000,
		4500000000000000000,
	};

	uvlong i;

	assert(solve(1) == 4);

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i) == tab[i]);

	return 0;
}
