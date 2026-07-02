/*

Find the original challenge here
https://codegolf.stackexchange.com/questions/120897/how-long-is-my-number

Challenge
Given an integer, Z in the range -2^31 < Z < 2^31, output the number of digits in that number (in base 10).

Rules
You must not use any string functions (in the case of overloading, you must not pass a string into functions which act as both string and integer functions). You are not allowed to store the number as a string.

All mathematical functions are allowed.

You may take input in any base, but the output must be the length of the number in base 10.

Do not count the minus sign for negative numbers. Number will never be a decimal.

Zero is effectively a leading zero, so it can have zero or one digit.

Examples
Input > Output

-45 > 2
1254 > 4
107638538 > 9
-20000 > 5
0 > 0 or 1
-18 > 2

Winning
Shortest code in bytes wins.

*/

#include <assert.h>
#include <stdlib.h>
#include <math.h>

typedef long long vlong;

vlong
diglen(vlong n)
{
	if (n == 0)
		return 1;
	return fmax(ceil(log10(llabs(n))), 0);
}

int
main()
{
	assert(diglen(-45) == 2);
	assert(diglen(1254) == 4);
	assert(diglen(107638538) == 9);
	assert(diglen(-20000) == 5);
	assert(diglen(0) == 1);
	assert(diglen(18) == 2);

	return 0;
}
