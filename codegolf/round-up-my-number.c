/*

Given two positive integers a and b, return the smallest multiple of b that is greater than or equal to a.

Examples
Definitions: true = is a multiple of b, false = is not a multiple of b.

f(1,3) = 3 because 1 is false, 1+1 is false, but 1+1+1 is true. Therefore 3 is returned.

f(5,3) = 6 because 5 is false, but 5+1 is true. Therefore 6 is returned.

f(9,3) = 9 because 9 is already a multiple of 3.

f(12,5) = 15 because 12 is false, 12+1 is false, 12+2 is false, but 12+3 is true. Therefore 15 is returned.

Rules
Input/output can be given by any convenient method.
You can print it to STDOUT or return it as a function result.
Either a full program or a function are acceptable.
Any amount of extraneous whitespace is permitted, provided the characters line up appropriately.
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

*/

#include <assert.h>

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

int
roundup(int a, int b)
{
	return a + mod(-a, b);
}

int
main(void)
{
	assert(roundup(1, 3) == 3);
	assert(roundup(5, 3) == 6);
	assert(roundup(9, 3) == 9);
	assert(roundup(12, 5) == 15);

	return 0;
}
