/*

Given n distinct objects, you want to take k of them. How many ways can you do it?

For example, say there are 4 items; you want to take 2 of them. You can do it 6 ways:

Take 1, 2
Take 1, 3
Take 1, 4
Take 2, 3
Take 2, 4
Take 3, 4
Input
Input starts with an integer T (≤ 2000), denoting the number of test cases.

Each test case contains two integers n (1 ≤ n≤ 106), k (0 ≤ k ≤ n).

Output
For each case, output the case number and the desired value. Since the result can be very large, you have to print the result modulo 1000003.

Sample
Input	Output
3
4 2
5 0
6 4

Case 1: 6
Case 2: 1
Case 3: 15

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef long long vlong;

vlong
modmul(vlong a, vlong b, vlong m)
{
	return ((a % m) * (b % m)) % m;
}

vlong
modexp(vlong a, vlong p, vlong m)
{
	vlong r, x;

	r = 1;
	x = a;
	while (p) {
		if (p & 1)
			r = (r * x) % m;
		x = (x * x) % m;
		p = p >> 1;
	}
	return r;
}

vlong *
facts(size_t m)
{
	vlong *f;
	size_t i;

	f = calloc(m + 1, sizeof(*f));
	if (!f)
		return NULL;

	f[0] = 1;
	for (i = 1; i < m; i++)
		f[i] = modmul(i, f[i - 1], m);
	return f;
}

vlong
solve(vlong *f, vlong m, vlong n, vlong k)
{
	vlong x, y, z;

	if (n < 1 || k < 0 || k > n)
		return 0;

	x = modmul(f[n - k], f[k], m);
	y = modexp(x, m - 2, m);
	z = modmul(f[n], y, m);
	return z;
}

int
main()
{
	vlong *f, m;

	m = 1000003;
	f = facts(m);
	assert(f);
	assert(solve(f, m, 4, 2) == 6);
	assert(solve(f, m, 5, 0) == 1);
	assert(solve(f, m, 6, 4) == 15);

	free(f);
	return 0;
}
