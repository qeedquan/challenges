/*

Given a natural number N (8≤N≤1000000), which represents any integer sum of money not exceeding 1000000.
It is known that any integer sum of money greater than or equal to 7 units can be given only using bills with denominations of 2 and 5 units.
Determine the minimal number of bills of 2 and 5 units needed to make up the sum of N units.

Input
A single number N — the given sum.

Output
A single number — the required minimum number of bills.

Examples

Input #1
9

Answer #1
3

*/

#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef long long vlong;

// https://oeis.org/A194508 (semi-related)
vlong
solve(vlong n)
{
	vlong i, *p, r;

	if (n < 0 || n == 1 || n == 3)
		return -1;

	p = calloc(n + 1, sizeof(*p));
	if (!p)
		return -errno;

	p[0] = 0;
	p[1] = INT_MAX;
	p[2] = 1;
	p[3] = INT_MAX;
	p[4] = 2;
	p[5] = 1;
	p[6] = 3;
	p[7] = 2;
	for (i = 8; i <= n; i++)
		p[i] = min(p[i - 2], p[i - 5]) + 1;

	r = p[n];
	free(p);
	return r;
}

int
main()
{
	assert(solve(9) == 3);

	return 0;
}
