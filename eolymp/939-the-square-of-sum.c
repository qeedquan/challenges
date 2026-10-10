/*

Find the square of the sum of the digits of a two-digit positive integer.

Input
One two-digit positive integer n.

Output
Print the square of the sum of the digits of the number n.

Examples

Input #1
23

Answer #1
25

*/

#include <assert.h>

int
solve(int n)
{
	int a, b;

	a = (n / 10) % 10;
	b = n % 10;
	return (a + b) * (a + b);
}

int
main()
{
	assert(solve(23) == 25);

	return 0;
}
