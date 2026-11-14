/*

You are given two integers x and y, each an integer from 0 through 9. You want to get from x to y by adding an integer z to x. Addition will be modulo 10, i.e., adding 1 to 9 results in 0; and adding a -1 to 0 results in 9.

Create a function f that, given the x and y defined above, returns the z such that its absolute value |z| is the smallest. If the answer is ambiguous, return the negative z.

Examples:

f(1,3) == 2
f(5,2) == -3
f(7,2) == -5
f(9,1) == 2
f(1,9) == -2

Code length limit: no more than 22 characters.

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

int
f(int x, int y)
{
	int z;

	for (z = 0; z < 10; z++) {
		if (mod(x - z, 10) == y)
			return -z;
		if (mod(x + z, 10) == y)
			return z;
	}
	return INT_MIN;
}

int
main()
{
	assert(f(1, 3) == 2);
	assert(f(5, 2) == -3);
	assert(f(7, 2) == -5);
	assert(f(9, 1) == 2);
	assert(f(1, 9) == -2);

	return 0;
}
