/*

Sum[i=1 to N] i^K

Given integers N and K, compute the value of the expression shown above modulo 1000000007.

Input
The first line contains a single integer T (1≤T≤10^5) — the number of test cases.

Each of the following T lines contains two integers N and K (1≤N≤10^9, 1≤K≤4).

Output
For each test case, output the value of the expression modulo 1000000007.

Examples

Input #1
5
5 1
4 2
1000000000 1
1000000000 2
1000000000 3

Answer #1
15
30
21
999999916
441

*/

#include <assert.h>
#include <stdio.h>

typedef long long vlong;

vlong
modexp(vlong x, vlong p, vlong m)
{
	vlong r;

	if (m == 0)
		return 0;

	x %= m;
	if (x == 0)
		return 0;

	for (r = 1; p > 0; p >>= 1) {
		if (p & 1)
			r = (r * x) % m;
		x = (x * x) % m;
	}
	return r;
}

vlong
solve(vlong n, vlong k)
{
	static const vlong mod = 1000000007;

	vlong i, r;

	r = 0;
	for (i = 1; i <= n; i++)
		r = (r + modexp(i, k, mod)) % mod;
	return r;
}

int
main()
{
	assert(solve(5, 1) == 15);
	assert(solve(4, 2) == 30);
	assert(solve(1000000000, 1) == 21);
	assert(solve(1000000000, 2) == 999999916);
	assert(solve(1000000000, 3) == 441);

	return 0;
}
