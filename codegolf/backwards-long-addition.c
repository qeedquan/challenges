/*

The standard long addition method:

The standard algorithm for adding multidigit numbers is to align the addends vertically and add the columns, starting from the ones column on the right. If a column exceeds ten, the extra digit is "carried" into the next column. (wikipedia)

A long addition example:

 145
+ 98
-----
 243
Backwards long addition is similar but you start adding from the leftmost column and carry to the next column (on it's right). If the last (ones) column produces a carry you write it behind the current sum in the next column. If there is no carry in the last column no extra column is needed.

 145
+ 98
-----
 1341
Explanation for the above example by columns, left to right: 1 = 1; 4+9 = 10(carried) + 3; 5+8+1(carry) = 10(carried) + 4; 1(carry) = 1

You should write a program or function which receives two positive integers as input and returns their sum using backwards long addition.

Input
Two positive integers.
Output
An integer, the sum of the two input numbers using backwards long addition.
There should be no leading zeros. (Consider 5+5=1 or 73+33=7.)

Examples
Format is Input => Output.

1 3 => 4
5 5 => 1
8 9 => 71
22 58 => 701
73 33 => 7
145 98 => 1341
999 1 => 9901
5729 7812 => 26411

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
rev(uvlong n)
{
	uvlong r;

	for (r = 0; n != 0; n /= 10)
		r = (r * 10) + (n % 10);
	return r;
}

uvlong
bladd(uvlong a, uvlong b)
{
	uvlong r;

	r = 0;
	while (a + b != 0) {
		r = (r * 10) + (a % 10) + (b % 10);
		a /= 10;
		b /= 10;
	}
	return rev(r);
}

int
main(void)
{
	assert(bladd(1, 3) == 4);
	assert(bladd(5, 5) == 1);
	assert(bladd(8, 9) == 71);
	assert(bladd(22, 58) == 701);
	assert(bladd(73, 33) == 7);
	assert(bladd(145, 98) == 1341);
	assert(bladd(999, 1) == 9901);
	assert(bladd(5729, 7812) == 26411);

	return 0;
}
