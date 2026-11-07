/*

Create a function that takes a number n (integer greater than zero) as an argument, and returns 2 if n is odd and 8 if n is even.

You can only use the following arithmetic operators: addition of numbers +, subtraction of numbers -, multiplication of number *, division of number /, and exponentiation **.

You are not allowed to use any other methods in this challenge (i.e. no if statements, comparison operators, etc).

Examples
f(1) ➞ 2

f(2) ➞ 8

f(3) ➞ 2

Notes
N/A

*/

#include <assert.h>

int
f(int n)
{
	int x;

	x = n & 1;
	return (2 * x) + (8 * !x);
}

int
main(void)
{
	assert(f(1) == 2);
	assert(f(2) == 8);
	assert(f(3) == 2);
	assert(f(4) == 8);
	assert(f(5) == 2);
	assert(f(6) == 8);
	assert(f(7) == 2);
	assert(f(8) == 8);

	return 0;
}
