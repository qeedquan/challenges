/*

quintopia has posted here a challenge to compute multinomial coefficients (some of the text here is copied from there). There is a fun algorithm to compute multinomial coefficients mod 2.

Given a list of numbers, k1, k2, ... ,km, output the residue of the multinomial coefficient:

( k1 + ... km )
( k1, ..., km )  = (k1 + ... km)! / (k1! * ... km!)

reduced mod 2. The following algorithm does this efficiently: for each ki, compute the binary expansion of ki, that is, find aij such that each aij is either 1 or 0 and

k[i] = Sum[j=0, n] 2^j * a[i][j]

If there is any j such that arj = asj = 1 for r ≠ s, then the associated mod 2 multinomial coefficient is 0, otherwise the mod 2 multinomial coefficient is 1.

Task
Write a program or function which takes m numbers, k1, k2, ... ,km, and outputs or returns the corresponding multinomial coefficient. Your program may optionally take m as an additional argument if need be.

These numbers may be input in any format one likes, for instance grouped into lists or encoded in unary, or anything else, as long as the actual computation of the multinomial coefficient is performed by your code, and not the encoding process.

Output can be any truthy value if the multinomial coefficient is odd and any falsey value if the multinomial coefficient is even.

Built-ins designed to compute the multinomial coefficient are not allowed.

Standard loopholes apply.

Scoring
This is code golf: Shortest solution in bytes wins.

Examples:
To find the multinomial coefficient of 7, 16, and 1000, we binary expand each of them:

7    1   2   4   8   16  32  64  128 256 512
16   1   1   1   0    0   0   0    0   0   0
1000 0   0   0   1    0   1   1    1   1   1

Since no column has more than one 1, the multinomial coefficient is odd, and hence we should output something truthy.

To find the multinomial coefficient of 7, 16, and 76, we binary expand each of them:

   1  2  4  8 16 32 64
7  1  1  1  0  0  0  0
16 0  0  0  0  1  0  0
76 0  0  1  1  0  0  1

Since both 76 and 7 have a 4 in their binary expansion, the multinomial coefficient is even and so we output a falsey value.

Test cases:
Input: [2, 0, 1]
Output: Truthy

Input: [5,4,3,2,1]
Output: Falsey

Input: [1,2,4,8,16]
Output: Truthy

Input: [7,16,76]
Output: Falsey

Input: [7,16,1000]
Output: Truthy

Input: [545, 1044, 266, 2240]
Output: Truthy

Input: [1282, 2068, 137, 584]
Output: Falsey

Input: [274728976, 546308480, 67272744, 135004166, 16790592, 33636865]
Output: Truthy

Input: [134285315, 33849872, 553780288, 544928, 4202764, 345243648]
Output: Falsey

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

/*

@Leaky Nun
Test whether the sum is equal to the bitwise-or-sum (i.e. a+b+c == a|b|c).

*/

bool
mcp(uvlong *a, size_t n)
{
	uvlong x, y;
	size_t i;

	x = y = 0;
	for (i = 0; i < n; i++) {
		x += a[i];
		y |= a[i];
	}
	return x == y;
}

int
main(void)
{
	uvlong a1[] = {2, 0, 1};
	uvlong a2[] = {5, 4, 3, 2, 1};
	uvlong a3[] = {1, 2, 4, 8, 16};
	uvlong a4[] = {7, 16, 76};
	uvlong a5[] = {7, 16, 1000};
	uvlong a6[] = {545, 1044, 266, 2240};
	uvlong a7[] = {1282, 2068, 137, 584};
	uvlong a8[] = {274728976, 546308480, 67272744, 135004166, 16790592, 33636865};
	uvlong a9[] = {134285315, 33849872, 553780288, 544928, 4202764, 345243648};

	assert(mcp(a1, nelem(a1)) == true);
	assert(mcp(a2, nelem(a2)) == false);
	assert(mcp(a3, nelem(a3)) == true);
	assert(mcp(a4, nelem(a4)) == false);
	assert(mcp(a5, nelem(a5)) == true);
	assert(mcp(a6, nelem(a6)) == true);
	assert(mcp(a7, nelem(a7)) == false);
	assert(mcp(a8, nelem(a8)) == true);
	assert(mcp(a9, nelem(a9)) == false);

	return 0;
}
