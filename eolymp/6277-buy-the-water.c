/*

The cost of a bottle of water (including the cost of the empty bottle) is 1 dollar 20 cents. The cost of the empty bottle is 20 cents.

How many bottles of water is it possible to drink for n dollars, if you can recycle bottles for cash and buy new bottles of water for this cash.

Input
Positive integer n (1≤n≤1000).

Output
Number of bottles of water that you can drink for n dollars.

Examples
Input #1
2

Answer #1
1

*/

#include <assert.h>
#include <stdio.h>

typedef long long vlong;

vlong
solve(vlong n)
{
	if (n < 1)
		return 0;
	return n - 1;
}

vlong
solvebf(vlong n)
{
	vlong c;

	n *= 100;
	for (c = 0; n >= 120; c++)
		n = (n - 120) + 20;
	return c;
}

int
main()
{
	vlong i;

	assert(solve(2) == 1);

	for (i = 0; i <= 100000; i++)
		assert(solve(i) == solvebf(i));

	return 0;
}
