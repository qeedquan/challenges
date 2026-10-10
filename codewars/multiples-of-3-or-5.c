/*

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Finish the solution so that it returns the sum of all the multiples of 3 or 5 below the number passed in.

Additionally, if the number is negative, return 0.

Note: If the number is a multiple of both 3 and 5, only count it once.

Courtesy of projecteuler.net (Problem 1)

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

long
solvebf(long n)
{
	long i, r;

	r = 0;
	for (i = 3; i < n; i++) {
		if (!(i % 3) || !(i % 5))
			r += i;
	}
	return r;
}

long
an(long n, long d)
{
	return d * (n / d);
}

long
sn(long n, long d)
{
	return (an(n, d) * (an(n, d) + d)) / (2 * d);
}

// https://oeis.org/A126592
long
solve(long n)
{
	if (n < 1)
		return 0;

	n -= 1;
	return sn(n, 3) + sn(n, 5) - sn(n, 15);
}

int
main()
{
	static const long tab[] = {
		0, 0, 3, 3, 8, 14, 14, 14, 23, 33, 33, 45, 45, 45, 60, 60, 60,
		78, 78, 98, 119, 119, 119, 143, 168, 168, 195, 195, 195, 225,
		225, 225, 258, 258, 293, 329, 329, 329, 368, 408, 408, 450, 450,
		450, 495, 495, 495, 543, 543, 593, 644, 644, 644, 698, 753, 753,
		810, 810
	};
	size_t i;

	assert(solve(3) == 0);
	assert(solve(4) == 3);
	assert(solve(5) == 3);
	assert(solve(6) == 8);
	assert(solve(7) == 14);
	assert(solve(10) == 23);

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i + 2) == tab[i]);

	for (i = 0; i <= 10000; i++)
		assert(solve(i) == solvebf(i));

	return 0;
}
