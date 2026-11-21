/*

An employee of the technical control department liked to reject "domino tiles" that had equal values.
The factory producing K-dominoes was unaware of this, so it regularly received claims with amounts equal to the value of the purchased K-domino set.
The value of a K-domino set is equal to the number of domino tiles in the set bought by the customer.

To avoid being fired, the employee sometimes rejected not only his "favorite" domino tiles, but also a few additional ones,
but never more than half the number of guaranteed rejections.

Given the amount of a claim received by the factory, determine which K-domino set was bought by the customer.

Input
The only input is a single integer S (S≤2000000000) — the amount of the claim received by the factory.

Output
Print a single integer — the index K of the purchased K-domino set.

Examples

Input #1
21

Answer #1
6

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

typedef long long vlong;

// https://oeis.org/A002024
vlong
solve(vlong n)
{
	if (n < 1)
		return 0;
	return (sqrt(8 * n) + 1) / 2;
}

vlong
solvebf(vlong n)
{
	vlong i, s;

	if (n < 1)
		return 0;

	s = 0;
	for (i = 1; i < LLONG_MAX; i++) {
		s += i;
		if (s >= n)
			return i;
	}
	return -1;
}

int
main()
{
	vlong i;

	assert(solve(21) == 6);

	for (i = 0; i <= 1000000; i++)
		assert(solve(i) == solvebf(i));

	return 0;
}
