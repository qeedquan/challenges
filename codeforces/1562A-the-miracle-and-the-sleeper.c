/*

You are given two integers l and r, l≤r. Find the largest possible value of a mod b over all pairs (a,b) of integers for which r≥a≥b≥l.

As a reminder, a mod b is a remainder we get when dividing a by b. For example, 26 mod 8=2.

Input
Each test contains multiple test cases.

The first line contains one positive integer t (1≤t≤10^4), denoting the number of test cases. Description of the test cases follows.

The only line of each test case contains two integers l, r (1≤l≤r≤10^9).

Output
For every test case, output the largest possible value of a mod b over all pairs (a,b) of integers for which r≥a≥b≥l.

Example
input
4
1 1
999999999 1000000000
8 26
1 999999999

output
0
1
12
499999999

Note
In the first test case, the only allowed pair is (a,b)=(1,1), for which a mod b=1 mod 1=0.

In the second test case, the optimal choice is pair (a,b)=(1000000000,999999999), for which a mod b=1.

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
maxmod(uvlong l, uvlong r)
{
	if (l > r)
		return 0;
	if (r >= 2 * l)
		return (r - 1) / 2;
	return r - l;
}

uvlong
maxmodbf(uvlong l, uvlong r)
{
	uvlong a, b, v, x;

	x = 0;
	for (a = l; a <= r; a++) {
		for (b = l; b <= a; b++) {
			v = a % b;
			if (x < v)
				x = v;
		}
	}
	return x;
}

int
main(void)
{
	uvlong l, r;

	assert(maxmod(1, 1) == 0);
	assert(maxmod(999999999ULL, 1000000000ULL) == 1);
	assert(maxmod(8, 26) == 12);
	assert(maxmod(1, 999999999ULL) == 499999999ULL);

	for (l = 1; l <= 100; l++) {
		for (r = 1; r <= 100; r++) {
			assert(maxmod(l, r) == maxmodbf(l, r));
		}
	}

	return 0;
}
