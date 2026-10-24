/*

Some positive integers n have the property that the sum floor[n + reverse(n)] consists entirely of odd (decimal) digits. For instance, 36 + 63 = 99 and 409 + 904 = 1313. We will call such number reversible; so 36, 63, 409$ and 904$ are reversible. Leading zeroes are not allowed in either n or reverse(n)

There are 120 reversible numbers below one-thousand.

How many reversible numbers are there below one-billion 10^9

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long ulong;

ulong
reverse(ulong n)
{
	ulong r;

	for (r = 0; n > 0; n /= 10)
		r = (r * 10) + (n % 10);
	return r;
}

int
odds(ulong n)
{
	if (n == 0)
		return 0;

	for (; n > 0; n /= 10) {
		if (!(n & 1))
			return 0;
	}
	return 1;
}

ulong
solve(ulong n)
{
	ulong f, i, r;

	f = 2;
	r = 0;
	for (i = 11; i < n; i += f) {
		if (odds(i + reverse(i)))
			r += f;
	}
	return r;
}

int
main(void)
{
	assert(solve(1000ULL) == 120);
	printf("%lu\n", solve(100000000UL));

	return 0;
}
