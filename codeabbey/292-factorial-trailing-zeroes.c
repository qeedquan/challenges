/*

Very common exercise I've met on various IT-job interviews (both for programming and software testing positions) was about zeroes at the end of termial. Usually it sounds like "How many consequtive zeroes 100! has at the end".

This is surely too easy, moreover that some modern languages handle long numbers "out of the box". Let us make it bit harder.

Given some value N, please tell, how many such trailing zeroes at the end will have its termial N! if written in the non-decimal numeral system with the base B.

Input data will contain number of testcases in the first line.
Next lines will have N and B each.
Output should contain amount of trailing zeroes for every case.

Example:

input data:
3
10 10
659 385
6213 5054

answer:
2 64 172

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

typedef long long vlong;

vlong
min(vlong a, vlong b)
{
	return (a < b) ? a : b;
}

vlong
term(vlong x, vlong n)
{
	vlong e, p;

	e = 0;
	for (p = x; p <= n; p *= x)
		e += n / p;
	return e;
}

/*

To find the number of trailing zeros of N! in a base B, we need to determine how many times the base B cleanly divides N!.

1. Find the prime factorization of B

B = p1^k1 * p2^k2 ... pm*k^m

2. Count occurences of each prime in N!
https://en.wikipedia.org/wiki/Legendre%27s_formula

E(n, pi) = Legendre formula

3. Account for powers ki
E(n, pi) / ki

4. Trailing zeroes is then equal to:
min(floor(E(N, pi) / ki)) for all terms pi and ki

*/

vlong
solve(vlong n, vlong b)
{
	vlong k, p, t, z;

	if (n < 0 || b < 2)
		return 0;

	z = LLONG_MAX;
	t = b;
	for (p = 2; p * p <= t; p++) {
		if (t % p)
			continue;

		k = 0;
		while (!(t % p)) {
			k += 1;
			t /= p;
		}

		z = min(z, term(p, n) / k);
	}

	if (t > 1)
		z = min(z, term(t, n));

	if (z == LLONG_MAX)
		return 0;
	return z;
}

int
main()
{
	assert(solve(10, 10) == 2);
	assert(solve(659, 385) == 64);
	assert(solve(6213, 5054) == 172);

	return 0;
}
