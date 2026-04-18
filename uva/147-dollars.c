/*

New Zealand currency consists of $100, $50, $20, $10, and $5 notes and $2, $1, 50c, 20c, 10c and 5c
coins. Write a program that will determine, for any given amount, in how many ways that amount may
be made up. Changing the order of listing does not increase the count. Thus 20c may be made up in
4 ways: 1×20c, 2×10c, 10c+2×5c, and 4×5c.

Input
Input will consist of a series of real numbers no greater than $300.00 each on a separate line. Each
amount will be valid, that is will be a multiple of 5c. The file will be terminated by a line containing
zero (0.00).

Output
Output will consist of a line for each of the amounts in the input, each line consisting of the amount
of money (with two decimal places and right justified in a field of width 6), followed by the number of
ways in which that amount may be made up, right justified in a field of width 17.

Sample Input
0.20
2.00
0.00

Sample Output
0.20 4
2.00 293

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

vlong
solve(double m)
{
	static const size_t coins[] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };

	size_t i, j, n;
	vlong *p, r;

	if (m < 0)
		return -EINVAL;

	n = round(m * 100);
	p = calloc(n + 1, sizeof(*p));
	if (!p)
		return -errno;

	p[0] = 1;
	for (i = 0; i < nelem(coins); i++) {
		for (j = coins[i]; j <= n; j++)
			p[j] += p[j - coins[i]];
	}
	r = p[n];

	free(p);
	return r;
}

int
main()
{
	assert(solve(0.20) == 4);
	assert(solve(2.00) == 293);

	return 0;
}
