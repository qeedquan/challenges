/*

Given a positive integer n. Print the penultimate digit from the right (tens place) of the number n.

Input
One positive integer n (n>9).

Output
Print the tens digit of n.

Examples

Input #1
27

Answer #1
2

*/

#include <assert.h>

int
solve(int n)
{
	return (n / 10) % 10;
}

int
main()
{
	assert(solve(27) == 2);

	return 0;
}
