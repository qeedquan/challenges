#include <assert.h>
#include <stdio.h>

int
solvebf(int n)
{
	int i, r;

	r = 0;
	for (i = 1; i <= n; i++)
		r += i * (i + 2);
	return r;
}

/*

Sum[i=1, n] i * (i + 2)

This can be split up into:

Sum[i=1, n]i^2 + 2*Sum[i=1, n]i

Use the sum of squares formula and sum of natural numbers to get a closed-form formula

*/

int
solve(int n)
{
	if (n < 1)
		return 0;
	return n * (n + 1) * ((2 * n) + 7) / 6;
}

int
main()
{
	int i;

	printf("%d\n", solve(20));
	for (i = 0; i <= 100; i++)
		assert(solve(i) == solvebf(i));
	return 0;
}
