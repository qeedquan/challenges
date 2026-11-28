/*

Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?

*/

#include <stdio.h>

typedef long long vlong;

#define min(a, b) (((a) < (b)) ? (a) : (b))

vlong
binomial(vlong n, vlong k)
{
	vlong i, c;

	if (k < 0 || k > n)
		return 0;
	if (k == 0 || k == n)
		return 1;

	k = min(k, n - k);
	c = 1;
	for (i = 0; i < k; i++)
		c = c * (n - i) / (i + 1);
	return c;
}

/*

https://www.mathblog.dk/project-euler-15/

The problem can be reformulated as an answer to the question:
In how many ways can we choose N out of 2N possible places if the order does not matter?

*/

vlong
paths(vlong n)
{
	return binomial(2 * n, n);
}

int
main(void)
{
	printf("%lld\n", paths(2));
	printf("%lld\n", paths(20));

	return 0;
}
