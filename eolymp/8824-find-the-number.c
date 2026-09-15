/*

Find the integer value of n, if its previous and next numbers are known.

Input
Two integers - the previous and the next number for n, given in any order in one line, space separated.
The numbers do not exceed 10^9 by absolute value.

Output
Print the value of n.

Examples

Input #1
6 8

Answer #1
7

Input #2
-16 -18

Answer #2
-17

*/

#include <assert.h>

int
solve(int a, int b)
{
	return a + (b - a) / 2;
}

int
main()
{
	assert(solve(6, 8) == 7);
	assert(solve(-16, -18) == -17);

	return 0;
}
