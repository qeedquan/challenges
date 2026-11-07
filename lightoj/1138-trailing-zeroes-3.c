/*

You task is to find minimal natural number N, so that N! contains exactly Q zeroes on the trail in decimal notation. As you know N! = 1 * 2 * ... * N. For example, 5! = 120, 120 contains one zero on the trail.

Input
Input starts with an integer T (≤ 10000), denoting the number of test cases.

Each case contains an integer Q (1 ≤ Q ≤ 10^8) in a line.

Output
For each case, print the case number and N. If no solution is found then print impossible.

Sample
Input	Output
3
1
2
5

Case 1: 5
Case 2: 10
Case 3: impossible

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

// https://oeis.org/A027868
vlong
lnzdf(vlong n)
{
	vlong i, z;

	z = 0;
	for (i = 5; i <= n; i *= 5)
		z += n / i;
	return z;
}

vlong
solve(vlong n)
{
	vlong lo, mid, hi;
	vlong r, z;

	r = -1;
	lo = 1;
	hi = LLONG_MAX;
	while (lo <= hi) {
		mid = lo + (hi - lo) / 2;

		z = lnzdf(mid);
		if (z > n)
			hi = mid - 1;
		else if (z < n)
			lo = mid + 1;
		else {
			r = mid;
			hi = mid - 1;
		}
	}
	return r;
}

int
main()
{
	static const vlong tab[] = {
		0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4,
		4, 4, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 10,
		10, 10, 10, 10, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 14, 14, 14,
		14, 14, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 18, 18, 18, 18, 18, 19
	};

	size_t i;

	assert(solve(1) == 5);
	assert(solve(2) == 10);
	assert(solve(3) == 15);
	assert(solve(4) == 20);
	assert(solve(5) == -1);

	for (i = 0; i < nelem(tab); i++)
		assert(lnzdf(i) == tab[i]);

	return 0;
}
