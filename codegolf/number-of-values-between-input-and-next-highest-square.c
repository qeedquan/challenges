/*

Given a positive square number as input. Output the number of values between the input and next highest square.

Example
Input: 1

Output: 2

Reason: The numbers 2 and 3 are between 1 and 4, the next highest square

Input: 4

Output: 4

Reason: The numbers 5, 6, 7, 8 are between 4 and 9

*/

#include <assert.h>
#include <math.h>

/*

@Martin Ender

The difference between n^2 and (n+1)^2 is always 2n+1 but we just want the values between them excluding both ends, which is 2n.

*/

int
values(int n)
{
	if (n < 1)
		return 0;
	return 2 * sqrt(n);
}

int
main()
{
	assert(values(1) == 2);
	assert(values(4) == 4);
	assert(values(9) == 6);
	assert(values(16) == 8);
	assert(values(25) == 10);
	assert(values(36) == 12);

	return 0;
}
