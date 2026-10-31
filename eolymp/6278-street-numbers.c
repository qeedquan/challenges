/*

As you may be aware, houses with even street numbers are typically situated on one side of the street,
while those with odd numbers are positioned on the opposite side.
Determine whether the houses numbered n and m are situated on the same side of the street.

Input
Two integers n and m (1≤n,m≤100).

Output
Print 1 if the houses with numbers n and m are located on the same side of the street, and 0 otherwise.

Examples

Input #1
1 2

Answer #1
0

*/

#include <assert.h>

int
solve(int a, int b)
{
	return (a & 1) == (b & 1);
}

int
main()
{
	assert(solve(1, 2) == 0);

	return 0;
}
