/*

Three digit number n is given. Append to it the digit 3 from the left and from the right.

Input
One three digit positive integer n.

Output
Append to the number n the digit 3 from the left and from the right. Print the resulting number.

Examples
Input #1
345

Answer #1
33453

Input #2
800

Answer #2
38003

*/

#include <assert.h>

long
solve(long n)
{
	if (!(100 <= n && n <= 999))
		return -1;
	return 30000 + (n * 10) + 3;
}

int
main()
{
	assert(solve(345) == 33453);
	assert(solve(800) == 38003);

	return 0;
}
