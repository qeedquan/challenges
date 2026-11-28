/*

Challenge
Given an integer n, calculate the sum of all even numbers between 0 and n

Examples
n     output
-------------
100   2550
255   16256
1000  250500

Shortest code in bytes wins

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

// https://oeis.org/A110660
uvlong
promic(uvlong n)
{
	n /= 2;
	return n * (n + 1);
}

uvlong
promicbf(uvlong n)
{
	uvlong i, r;

	for (r = i = 0; i <= n; i += 2)
		r += i;
	return r;
}

int
main(void)
{
	static const uvlong tab[] = {0, 0, 2, 2, 6, 6, 12, 12, 20, 20, 30, 30, 42, 42, 56, 56, 72, 72, 90, 90, 110, 110, 132, 132, 156, 156, 182, 182, 210, 210, 240, 240, 272, 272, 306, 306, 342, 342, 380, 380, 420, 420, 462, 462, 506, 506, 552, 552, 600, 600, 650, 650, 702, 702, 756, 756, 812, 812};

	uvlong i;

	assert(promic(100) == 2550);
	assert(promic(255) == 16256);
	assert(promic(1000) == 250500);

	for (i = 0; i < nelem(tab); i++)
		assert(promic(i) == tab[i]);

	for (i = 0; i <= 100000; i++)
		assert(promic(i) == promicbf(i));

	return 0;
}
