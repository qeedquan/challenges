/*

A001057 is one way to represent an integer as a natural number. It lists them according to the following pattern:

0, 1, -1, 2, -2, 3, -3, 4, -4, ...
In this challenge, you'll take two distinct integers as input and return which is at a higher index in this enumeration.

Take -2 and 1 as an example: -2 comes after 1, so it would be returned.

You may also choose to instead return the smaller integer, or one of two consistent values (such as 0 or 1) to indicate which is higher or lower. Truthy/falsy values as output are not allowed.

Test cases:

 0   1       1
 1   0       1
 0  -1      -1
-1   0      -1
-1   1      -1
 1  -1      -1
 1  -2      -2
 1   2       2
-1  -2      -2
-1   2       2

*/

#include <assert.h>
#include <stdlib.h>

int
cmp(int a, int b)
{
	int xa, xb;

	xa = abs(a);
	xb = abs(b);
	if (xa > xb)
		return a;
	if (xa < xb)
		return b;
	return (a < b) ? a : b;
}

int
main(void)
{
	assert(cmp(0, 1) == 1);
	assert(cmp(1, 0) == 1);
	assert(cmp(0, -1) == -1);
	assert(cmp(-1, 0) == -1);
	assert(cmp(-1, 1) == -1);
	assert(cmp(1, -1) == -1);
	assert(cmp(1, -2) == -2);
	assert(cmp(1, 2) == 2);
	assert(cmp(-1, -2) == -2);
	assert(cmp(-1, 2) == 2);

	return 0;
}
