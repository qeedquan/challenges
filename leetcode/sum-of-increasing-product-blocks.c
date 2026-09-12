/*

Description
You are given an integer n.

A sequence is formed as follows:

The 1st block contains 1.
The 2nd block contains 2 * 3.
The ith block is the product of the next i consecutive integers.
Let F(n) be the sum of the first n blocks.

Return an integer denoting F(n) modulo 10^9 + 7.

Example 1:

Input: n = 3

Output: 127

Explanation:

Block 1: 1
Block 2: 2 * 3 = 6
Block 3: 4 * 5 * 6 = 120
F(3) = 1 + 6 + 120 = 127

Example 2:

Input: n = 7

Output: 6997165

Explanation:

Block 1: 1
Block 2: 2 * 3 = 6
Block 3: 4 * 5 * 6 = 120
Block 4: 7 * 8 * 9 * 10 = 5040
Block 5: 11 * 12 * 13 * 14 * 15 = 360360
Block 6: 16 * 17 * 18 * 19 * 20 * 21 = 39070080
Block 7: 22 * 23 * 24 * 25 * 26 * 27 * 28 = 5967561600
F(7) = 6006997207 % (109 + 7) = 6997165

Constraints:

1 <= n <= 1000

*/

#include <stdio.h>
#include <assert.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

// https://oeis.org/A336502
vlong
sumblocks(vlong n)
{
	static const vlong mod = 1000000007;

	vlong i, j, k, r, x;

	r = 0;
	for (i = k = 1; i <= n; i++) {
		x = 1;
		for (j = k; j < k + i; j++)
			x = (x * j) % mod;
		r = (r + x) % mod;
		k += i;
	}
	return r;
}

int
main()
{
	static const vlong mod = 1000000007;
	static const vlong tab[] = {
		1,
		7,
		127,
		5167,
		365527,
		39435607,
		6006997207,
		1226103906007,
		322796982334807,
		106460296033918807,
	};

	size_t i;

	assert(sumblocks(3) == 127);
	assert(sumblocks(7) == 6997165);

	for (i = 0; i < nelem(tab); i++)
		assert(sumblocks(i + 1) == tab[i] % mod);

	return 0;
}
