/*

While the binomial coefficient are the coefficients of (1 + x)^n, m-nomial coefficients are the coefficients of (1 + x + x^2 + ... + x^(m-1))^n.

For example, m(3,5,6) is the coefficient of x^6 in the expansion of (1+x+x^2)^5.

Write a program/function that takes 3 numbers as input and outputs the corresponding m-nomial coefficient.

Details
Input can be taken via any reasonable method.
Everything out of range is 0, for example m(2,0,-1)=m(2,5,6)=0
The first argument will be positive.
The second argument will not be negative.
All three arguments will be integers.
Testcases
Inputs:

[1,0,0]
[2,5,6]
[3,5,6]
[4,5,-1]
Outputs:

1
0
45
0

Scoring
This is code-golf. Shortest solution in bytes wins.

*/

#include <assert.h>
#include <stdio.h>

typedef long long vlong;

vlong
mnc(vlong m, vlong n, vlong k)
{
	vlong i, r;

	if (n < 0 || k < 0 || k > (m - 1) * n)
		return 0;

	if (n == 0 && k == 0)
		return 1;

	r = 0;
	for (i = 0; i < m; i++)
		r += mnc(m, n - 1, k - i);
	return r;
}

int
main(void)
{
	assert(mnc(1, 0, 0) == 1);
	assert(mnc(2, 5, 6) == 0);
	assert(mnc(3, 5, 6) == 45);
	assert(mnc(4, 5, -1) == 0);
	assert(mnc(10, 5, 15) == 3246);
	assert(mnc(12, 8, 5) == 792);
	assert(mnc(12, -8, 5) == 0);

	return 0;
}
