/*

Given a decimal integer n as input, output the smallest (in terms of absolute value) decimal integer m such that the absolute value of n-m is a binary integer (composed only of 1s and 0s).

n and m can be any integer, positive or negative.

Example
Let n = 702. The closest binary integer is 1000 = |702 - (-298)|, so m = -298.

Let n = -82. The closest binary integer in absolute value is 100 = |-82 - 18|, so m = 18.

Test Cases
Input n                Output m
0                      0
1                      0
4                      3
-4                     -3
6                      -4
15                     4
55                     44
56                     -44
-82                    18
702                    -298
-1000                  0

Scoring
This is code-golf, so the shortest answer in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*

@Arnauld

Starting with  k=0 and using the expression (k < 1) - k to update k after each iteration,
we recursively generate  k=0,1,−1,2,−2,3,−3,… (A001057) until the regular expression /[2-9]/ applied to n-k doesn't match anything.

*/

int
f(int n)
{
	int m, p, r;

	r = 1;
	for (m = 0; r; r ^= 1) {
		for (p = abs(n - m); p > 0; p /= 10) {
			if ((p % 10) >= 2) {
				r = 0;
				break;
			}
		}
		if (r == 0)
			m = -m + (m < 1);
	}
	return m;
}

int
main()
{
	assert(f(0) == 0);
	assert(f(1) == 0);
	assert(f(4) == 3);
	assert(f(-4) == -3);
	assert(f(6) == -4);
	assert(f(15) == 4);
	assert(f(55) == 44);
	assert(f(56) == -44);
	assert(f(-82) == 18);
	assert(f(702) == -298);
	assert(f(-1000) == 0);

	return 0;
}
