/*

Find the remainder after dividing the last digit by the first digit in a given positive three-digit integer.

Input
A single positive three-digit integer n.

Output
Print the required remainder.

Examples

Input #1
198

Answer #1
0

*/

#include <assert.h>

int
solve(int n)
{
	return (n % 10) % (n / 100);
}

int
main()
{
	assert(solve(198) == 0);

	return 0;
}
