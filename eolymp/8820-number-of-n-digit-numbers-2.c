/*

The program takes a natural number n as input.
Your task is to determine and output the count of n-digit natural numbers that consist solely of odd digits.

Input
A natural number n.

Output
The result of the calculation.

Examples
Input #1
1

Answer #1
5

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

// https://oeis.org/A000351
uvlong
solve(uvlong n)
{
	return pow(5, n);
}

int
main()
{
	static const uvlong tab[] = {
		1,
		5,
		25,
		125,
		625,
		3125,
		15625,
		78125,
		390625,
		1953125,
		9765625,
		48828125,
		244140625,
		1220703125,
		6103515625,
		30517578125,
		152587890625,
		762939453125,
		3814697265625,
		19073486328125,
		95367431640625,
		476837158203125,
		2384185791015625,
	};

	uvlong i;

	assert(solve(1) == 5);

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i) == tab[i]);

	return 0;
}
