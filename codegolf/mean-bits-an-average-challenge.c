/*

Given an integer N >= 1, output the mean number of bits in an integer from 0 to N - 1

Specification
The output can be calculated as the sum of the number of bits in the binary representation of each integer from 0 to N-1, divided by N.
The binary representation of an integer has no leading zeroes in this context, with the exception of zero, which is represented as 0 in binary.
The output should be accurate to at least 7 significant figures.

Example
N = 6

0: 0   : 1 bit
1: 1   : 1 bit
2: 10  : 2 bits
3: 11  : 2 bits
4: 100 : 3 bits
5: 101 : 3 bits
Mean number of bits = (1 + 1 + 2 + 2 + 3 + 3) / 6 = 2

Test cases
Input => output

1 => 1
2 => 1
3 => 1.3333333
4 => 1.5
5 => 1.8
6 => 2
7 => 2.1428571

Note that the sum (before dividing to find the mean) is a sequence on OEIS.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

// https://oeis.org/A083652
double
meanbits(unsigned n)
{
	unsigned b;
	double m;

	if (n == 0)
		return 0;

	b = ceil(log2(n));
	m = 2 + (n * b) - (1 << b);
	return m / n;
}

void
test(unsigned n, double r)
{
	double v;

	v = meanbits(n);
	printf("%f\n", v);
	assert(fabs(v - r) < 1e-7);
}

int
main(void)
{
	test(1, 1);
	test(2, 1);
	test(3, 1.3333333);
	test(4, 1.5);
	test(5, 1.8);
	test(6, 2);
	test(7, 2.1428571);

	return 0;
}
