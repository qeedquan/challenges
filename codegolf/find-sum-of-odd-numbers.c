/*

Write a program to find the sum of all odd numbers between a given range [a,b]. Input consists of a single line containing two integers a and b separated by a space. 0 ≤ a,b ≤ 1,000,000,000,000. Your program should not take more than 10 secs.

Sample Inputs
1 5
4 8
1 8
0 5

Sample Outputs
9
12
16
9

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

// https://oeis.org/A008794 (without the first value)
vlong
sumodds(vlong n)
{
	if (n < 0)
		return 0;

	n = (n + 1) / 2;
	return n * n;
}

vlong
count(vlong a, vlong b)
{
	return sumodds(b) - sumodds(a - 1);
}

int
main(void)
{
	static const vlong tab[] = {0, 1, 1, 4, 4, 9, 9, 16, 16, 25, 25, 36, 36, 49, 49, 64, 64, 81, 81, 100, 100, 121, 121, 144, 144, 169, 169, 196, 196, 225, 225, 256, 256, 289, 289, 324, 324, 361, 361, 400, 400, 441, 441, 484, 484, 529, 529, 576, 576};

	size_t i;

	assert(count(1, 5) == 9);
	assert(count(4, 8) == 12);
	assert(count(1, 8) == 16);
	assert(count(0, 5) == 9);

	for (i = 0; i < nelem(tab); i++)
		assert(sumodds(i) == tab[i]);

	return 0;
}
