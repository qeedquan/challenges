/*

Given a decimal number k, find the smallest integer n such that the square root of n is within k of an integer. However, the distance should be nonzero - n cannot be a perfect square.

Given k, a decimal number or a fraction (whichever is easier for you), such that 0 < k < 1, output the smallest positive integer n such that the difference between the square root of n and the closest integer to the square root of n is less than or equal to k but nonzero.

If i is the closest integer to the square root of n, you are looking for the first n where 0 < |i - sqrt(n)| <= k.

Rules
You cannot use a language's insufficient implementation of non-integer numbers to trivialize the problem.
Otherwise, you can assume that k will not cause problems with, for example, floating point rounding.
Test Cases
.9         > 2
.5         > 2
.4         > 3
.3         > 3
.25        > 5
.2         > 8
.1         > 26
.05        > 101
.03        > 288
.01        > 2501
.005       > 10001
.003       > 27888
.001       > 250001
.0005      > 1000001
.0003      > 2778888
.0001      > 25000001
.0314159   > 255
.00314159  > 25599
.000314159 > 2534463

Comma separated test case inputs:

0.9, 0.5, 0.4, 0.3, 0.25, 0.2, 0.1, 0.05, 0.03, 0.01, 0.005, 0.003, 0.001, 0.0005, 0.0003, 0.0001, 0.0314159, 0.00314159, 0.000314159
This is code-golf, so shortest answer in bytes wins.

*/

#include <stdio.h>
#include <assert.h>
#include <math.h>

/*

@alephalpha

Explanation
The result must be of the form m^2 +- 1 for some m∈N.
Solving the inequations sqrt(m^2+1)-m <= k and m-sqrt(m^2-1) <= k,
we get m >= (1-k^2)/(2k) and m >= (1+k^2)/(2k) respectively.
So the result is min(ceil((1-k^2)/(2k))^2 + 1, ceil((1+k^2)/(2k))^2 - 1)

*/

long
sqdfi(double k)
{
	double x, y;

	x = ceil((1 - (k * k)) / (2 * k));
	y = ceil((1 + (k * k)) / (2 * k));
	x *= x;
	y *= y;
	return fmin(x + 1, y - 1);
}

int
main(void)
{
	assert(sqdfi(0.900000) == 2);
	assert(sqdfi(0.500000) == 2);
	assert(sqdfi(0.400000) == 3);
	assert(sqdfi(0.300000) == 3);
	assert(sqdfi(0.250000) == 5);
	assert(sqdfi(0.200000) == 8);
	assert(sqdfi(0.100000) == 26);
	assert(sqdfi(0.050000) == 101);
	assert(sqdfi(0.030000) == 288);
	assert(sqdfi(0.010000) == 2501);
	assert(sqdfi(0.005000) == 10001);
	assert(sqdfi(0.003000) == 27888);
	assert(sqdfi(0.001000) == 250001);
	assert(sqdfi(0.000500) == 1000001);
	assert(sqdfi(0.000300) == 2778888);
	assert(sqdfi(0.000100) == 25000001);
	assert(sqdfi(0.031416) == 255);
	assert(sqdfi(0.003142) == 25599);
	assert(sqdfi(0.000314159) == 2534463);

	return 0;
}
