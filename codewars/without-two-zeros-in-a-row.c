/*

You are given a positive integer n.

The task is to calculate how many binary numbers without leading zeros (such that their length is n and they do not contain two zeros in a row) there are. Note that zero itself ("0") meets the conditions (for n = 1).

For example, there are three eligible binary numbers of length 3:

101
110
111
100 is not suitable.

Remember that n may be fairly big (up to 10^4). Good luck!

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

vlong
fib(vlong n)
{
	vlong a, b, c, i;

	a = 1;
	b = 0;
	for (i = 2; i < n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return a;
}

vlong
zeros(vlong n)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	if (n == 1)
		return 2;
	return fib(n + 4);
}

int
main()
{
	assert(zeros(1) == 2);
	assert(zeros(2) == 2);
	assert(zeros(3) == 3);

	return 0;
}
