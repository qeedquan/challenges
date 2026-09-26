/*

There seems not to be a contest for this one yet.

The task is simple. Add the first n numbers of the Fibonacci sequence that are even and output the result.

This is given by OEIS A099919, except that sequence is shifted by one, starting with fib(1) = 0 instead of fib(1) = 1.

This is code golf. Lowest byte count wins.

Examples
n sum
1 0
2 2
3 10
4 44
5 188
6 798
7 3382
8 14328
9 60696

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

// https://oeis.org/A099919
vlong
evenfibs(vlong n)
{
	static const double SQRT5 = 2.23606797749978969640917366873127623544061835961152;

	double a, b, c, d;

	if (n < 1)
		return 0;

	n -= 1;
	a = 5 - (3 * SQRT5);
	b = pow(2 - SQRT5, n);
	c = pow(2 + SQRT5, n);
	d = 5 + (3 * SQRT5);
	return ((a * b) + (c * d) - 10) / 20;
}

int
main(void)
{
	static const vlong tab[] = { 0, 2, 10, 44, 188, 798, 3382, 14328, 60696 };

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(evenfibs(i + 1) == tab[i]);

	return 0;
}
