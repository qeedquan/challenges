/*

Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.

*/

#include <stdio.h>

typedef long long vlong;

vlong
d(vlong n)
{
	vlong i, r;

	if (n < 1)
		return 0;

	r = 0;
	for (i = 1; i < n; i++) {
		if (n % i == 0)
			r += i;
	}
	return r;
}

// https://oeis.org/A259180
int
amicable(vlong a)
{
	vlong b, c;

	b = d(a);
	c = d(b);
	return a != b && a == c;
}

vlong
solve(vlong n)
{
	vlong i, r;

	if (n < 1)
		return 0;

	if (n == 1)
		return 1;

	r = 0;
	for (i = 1; i < n; i++) {
		if (amicable(i))
			r += i;
	}
	return r;
}

int
main(void)
{
	printf("%lld\n", solve(10000));

	return 0;
}
