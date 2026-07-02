/*

Everyone knows the so-called Dirichlet principle, which is formulated as follows:

Suppose that a certain number of rabbits are placed in cells.
If the number of rabbits is greater than the number of cells, then there will be at least one cell containing more than one rabbit.

In this problem, we consider a more general case of this classical mathematical fact.
Suppose there are n cells and m rabbits, which are placed in these cells.
Calculate the maximum number of rabbits that is guaranteed to be in the same cell.

Input
One line contains two natural numbers n and m (1≤n,m≤10^9).

Output
Print the maximum number of rabbits that is guaranteed to be in the same cell.

Examples
Input #1
2 3

Answer #1
2

*/

#include <assert.h>

int
solve(int n, int m)
{
	return (m / n) + !!(m % n);
}

int
main()
{
	assert(solve(2, 3) == 2);

	return 0;
}
