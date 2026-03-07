/*

Given a positive integer n, return the number of the integers in the range [0, n] whose binary representations do not contain consecutive ones.

Example 1:

Input: n = 5
Output: 5
Explanation:
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule.

Example 2:

Input: n = 1
Output: 2

Example 3:

Input: n = 2
Output: 3

Constraints:

    1 <= n <= 10^9

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

typedef long long vlong;

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define bit(n) (1LL << (n))

vlong
findbf(vlong n)
{
	vlong b, c, i, p;

loop:
	for (c = i = 0; i <= n; i++) {
		p = i;
		for (b = i >> 1; b > 0; b >>= 1) {
			if ((p & 1) && (b & 1))
				continue loop;
			p = b;
		}
		c += 1;
	}
	return c;
}

vlong
fib(vlong n)
{
	vlong a, b, c, i;

	if (n < 1)
		return 0;

	a = b = 1;
	for (i = 0; i < n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return a;
}

vlong
find(vlong n)
{
	static const vlong maxbits = (CHAR_BIT * sizeof(n));

	vlong i, r, p;

	if (n < 0)
		return 0;

	r = p = 0;
	for (i = maxbits - 1; i >= 0; i--) {
		if (n & bit(i)) {
			r += fib(i + 1);
			if (p == 1) {
				r -= 1;
				break;
			}
			p = 1;
		} else
			p = 0;
	}
	return r + 1;
}

int
main()
{
	vlong i;

	assert(find(5) == 5);
	assert(find(1) == 2);
	assert(find(3) == 3);

	for (i = 0; i <= 10000; i++)
		assert(find(i) == findbf(i));

	return 0;
}
