/*

Given a positive integer n, print its third digit from the right.

Input
The only line contains a positive integer n (100≤n≤10^9).

Output
Print the third digit of n from the right.

Examples

Input #1
1234567

Answer #1
5

*/

#include <assert.h>

long
solve(long n)
{
	return (n / 100) % 10;
}

int
main()
{
	assert(solve(1234567) == 5);

	return 0;
}
