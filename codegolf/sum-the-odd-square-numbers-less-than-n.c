/*

Write a program or function to output the sum of the odd square numbers (OEIS #A016754) less than an input n.

The first 44 numbers in the sequence are:

1, 9, 25, 49, 81, 121, 169, 225, 289, 361, 441, 529, 625, 729, 841, 961, 1089,
1225, 1369, 1521, 1681, 1849, 2025, 2209, 2401, 2601, 2809, 3025, 3249, 3481,
3721, 3969, 4225, 4489, 4761, 5041, 5329, 5625, 5929, 6241, 6561, 6889, 7225, 7569
The formula for the sequence is a(n) = ( 2n + 1 ) ^ 2.

Notes
Your program's behaviour may be undefined for n < 1 (that is, all valid inputs are >= 1.)
Test cases
1 => 0
2 => 1
9 => 1
10 => 10
9801 => 156849
9802 => 166650
10000 => 166650

*/

#include <assert.h>

typedef unsigned long long uvlong;

// https://oeis.org/A016754
uvlong
oddsquares(uvlong n)
{
	uvlong x;

	x = (2 * n) + 1;
	return x * x;
}

uvlong
seq(uvlong n)
{
	uvlong i, r, v;

	r = 0;
	i = 0;
	for (;;) {
		v = oddsquares(i);
		if (v >= n)
			break;
		r += v;
		i += 1;
	}
	return r;
}

int
main(void)
{
	assert(seq(1) == 0);
	assert(seq(2) == 1);
	assert(seq(9) == 1);
	assert(seq(10) == 10);
	assert(seq(9801) == 156849);
	assert(seq(9802) == 166650);
	assert(seq(10000) == 166650);

	return 0;
}
