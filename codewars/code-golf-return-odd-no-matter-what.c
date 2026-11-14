/*

Given the integer n return odd numbers as they are, but subtract 1 from even numbers.

Note:

Your solution should be 36 or less characters long.

Examples
Input  = 2
Output = 1

Input  = 13
Output = 13

Input  = 46
Output = 45

*/

#include <assert.h>

int
odd(int n)
{
	return n - !(n & 1);
}

int
main()
{
	assert(odd(2) == 1);
	assert(odd(13) == 13);
	assert(odd(46) == 45);
	return 0;
}
