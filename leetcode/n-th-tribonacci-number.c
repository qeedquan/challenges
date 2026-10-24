/*

The Tribonacci sequence Tn is defined as follows:

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
Example 2:

Input: n = 25
Output: 1389537


Constraints:

0 <= n <= 37
The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;

// https://oeis.org/A000073
uvlong
tribonacci(uvlong n)
{
	uvlong a, b, c, d;
	uvlong i;

	a = 0;
	b = 1;
	c = 1;
	for (i = 0; i < n; i++) {
		d = a + b + c;
		a = b;
		b = c;
		c = d;
	}
	return a;
}

int
main(void)
{
	uvlong i;

	assert(tribonacci(4) == 4);
	assert(tribonacci(25) == 1389537ULL);

	for (i = 0; i <= 37; i++)
		printf("%llu\n", tribonacci(i));

	return 0;
}
