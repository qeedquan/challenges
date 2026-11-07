/*

Print the given three-digit number without the middle digit.

Input
One three-digit integer.

Output
Print the given three-digit number without the middle digit.

Examples

Input #1
198

Answer #1
18

*/

#include <assert.h>

int
solve(int n)
{
	return ((n / 100) * 10) + (n % 10);
}

int
main()
{
	assert(solve(198) == 18);

	return 0;
}
