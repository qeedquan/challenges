/*

a is an integer and k is a natural number.
Output the number that contains only the last k bits of the number a (i.e., set all bits in a except for the last k bits to zero).

Input
The single line contains the numbers a and k (0≤a≤10^9).

Output
Output the number a after all bits except for the last k bits have been set to zero.

Examples

Input #1
5 1

Answer #1
1

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
solve(uvlong a, uvlong k)
{
	return a & ~(~0ULL << k);
}

int
main()
{
	assert(solve(5, 1) == 1);

	return 0;
}
