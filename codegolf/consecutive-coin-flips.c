/*

This is a cross-post of a problem I posted to anarchy golf: http://golf.shinh.org/p.rb?tails

Given two integers n and k (0≤k≤n), count the number of combinations of n coin tosses with at least k tails in a row.

For example, if n=3 and k=2, the answer is 3:

HHH ❌
HHT ❌
HTH ❌
HTT ✔️
THH ❌
THT ❌
TTH ✔️
TTT ✔️
For convenience sake, you do not need to handle the case where n=k=0.

Rules
The input must take in two integers n and k, and output the answer as a single integer
Inaccuracies due to integer overflow are acceptable, but floating point errors are prohibited
As usual for code-golf, the shortest code in bytes wins

Test Cases
 n,  k  ->  ans
---------------
 1,  0  ->  2
 1,  1  ->  1
 2,  0  ->  4
 2,  1  ->  3
 2,  2  ->  1
 3,  1  ->  7
 3,  2  ->  3
 3,  3  ->  1
 5,  2  ->  19
 6,  4  ->  8
 9,  2  ->  423
12,  0  ->  4096
13,  5  ->  1262
14,  8  ->  256
16,  7  ->  2811
More terms are listed under OEIS A109435.

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
kbonacci(uvlong n, uvlong k)
{
	uvlong i, r;

	if (k == 0 || n < k - 1)
		return 0;

	if (n == k - 1)
		return 1;

	r = 0;
	for (i = 1; i <= k; i++)
		r += kbonacci(n - i, k);
	return r;
}

// https://oeis.org/A109435
uvlong
coinflips(uvlong n, uvlong k)
{
	return (1ULL << n) - kbonacci(n + k, k);
}

int
main(void)
{
	assert(coinflips(1, 0) == 2);
	assert(coinflips(1, 1) == 1);
	assert(coinflips(2, 0) == 4);
	assert(coinflips(2, 1) == 3);
	assert(coinflips(2, 2) == 1);
	assert(coinflips(3, 1) == 7);
	assert(coinflips(3, 2) == 3);
	assert(coinflips(3, 3) == 1);
	assert(coinflips(5, 2) == 19);
	assert(coinflips(6, 4) == 8);
	assert(coinflips(9, 2) == 423);
	assert(coinflips(12, 0) == 4096);
	assert(coinflips(13, 5) == 1262);
	assert(coinflips(14, 8) == 256);
	assert(coinflips(16, 7) == 2811);

	return 0;
}
