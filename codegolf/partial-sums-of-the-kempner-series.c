/*

The Kempner series is a series that sums the inverse of all positive integers that don't contain a "9" in their base-10 representations (i.e., 1/1 + 1/2 +1/3 + .. + 1/8 + 1/10 + ...).

It can be shown that, unlike the Harmonic series, the Kempner series converges (to a value of about 22.92067661926415034816).

Your task is to find the partial sums of the Kempner series. These are the ways you can do it:

Take a number n, and return the sum of the inverse of the first n numbers that don't have a "9" in them, which is the nth partial sum of the series.
Take a number n, and return the first n partial sums of the series.
Don't take any input and output the partial sums infinitely.
You can choose if your input is 0-indexed or 1-indexed.

Your algorithm result's distance from the correct value may not be over 10^-4, for all possible values of n.
While your algorithm should work theoretically for all values for N, you may ignore inaccuracies coming from floating-point errors.

Test cases, in case of returning the n
th partial sum, 0-indexed:

0 -> 1.0
1 -> 1.5
9 -> 2.908766...
999 -> 6.8253...
Standard loopholes are disallowed.

This is code-golf, so the shortest answer in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

int
has9(int n)
{
	for (; n > 0; n /= 10) {
		if ((n % 10) == 9)
			return 1;
	}
	return 0;
}

double
kempner(int n)
{
	double r;
	int i, x;

	if (n < 0)
		return 0;

	r = 1;
	x = 2;
	for (i = 0; i < n; x++) {
		if (!has9(x)) {
			r += 1.0 / x;
			i += 1;
		}
	}
	return r;
}

void
test(int n, double r)
{
	double v;

	v = kempner(n);
	printf("%f\n", v);
	assert(fabs(v - r) < 1e-4);
}

int
main(void)
{
	test(0, 1);
	test(1, 1.5);
	test(9, 2.908766);
	test(999, 6.8253);

	return 0;
}
