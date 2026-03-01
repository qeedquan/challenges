/*

Given a positive integer n: 0 < n < 1e6, remove the last digit until you're left with a number that is a multiple of three.

Return n if the input is already a multiple of three, and return null if no such number exists.

Examples

1      => null

25     => null

36     => 36

1244   => 12

952406 => 9

*/

#include <assert.h>

long
pmo3(long n)
{
	for (; n > 0; n /= 10) {
		if (!(n % 3))
			return n;
	}
	return -1;
}

int
main()
{
	assert(pmo3(1) == -1);
	assert(pmo3(25) == -1);
	assert(pmo3(36) == 36);
	assert(pmo3(1244) == 12);
	assert(pmo3(952406) == 9);

	return 0;
}
