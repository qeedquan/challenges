/*

Determine and output how many powers of two fall within the interval [a,b], excluding the number one, since 2^0=1 is not considered.

Input
Two natural numbers a and b provided on a single line, separated by a space (1≤a,b≤10^12).

Output
The solution to the problem.

Examples

Input #1
2 34

Answer #1
5

*/

#include <assert.h>
#include <stdio.h>
#include <stdbit.h>

typedef unsigned long long uvlong;

uvlong
ispow2(uvlong n)
{
	if (n > 0 && !(n & (n - 1)))
		return 1;
	return 0;
}

uvlong
bits(uvlong n)
{
	if (n < 1)
		return 0;
	return stdc_bit_width(n) - 1;
}

uvlong
solve(uvlong a, uvlong b)
{
	if (a >= 1)
		a -= 1;
	if (a > b)
		return 0;
	return bits(b) - bits(a);
}

uvlong
solvebf(uvlong a, uvlong b)
{
	uvlong c, i;

	c = 0;
	for (i = a; i <= b; i++) {
		if (i != 1 && ispow2(i))
			c += 1;
	}
	return c;
}

int
main()
{
	uvlong a, b;

	assert(solve(2, 34) == 5);

	for (a = 0; a <= 5000; a++) {
		for (b = 0; b <= 5000; b++)
			assert(solve(a, b) == solvebf(a, b));
	}
	return 0;
}
