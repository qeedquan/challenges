/*

n schoolchildren divide k apples evenly, the residue remains in the basket. How many apples remain in the basket?

Input
Two positive integers n and k not greater than 1500 — rarely are there more pupils in school, and where to find such a basket?

Output
Print the number of apples in the basket.

Examples

Input #1
3
14

Answer #1
2

Input #2
10
100

Answer #2
0

*/

#include <assert.h>

int
solve(int n, int k)
{
	if (n == 0)
		return 0;
	return k % n;
}

int
main()
{
	assert(solve(3, 14) == 2);
	assert(solve(10, 100) == 0);

	return 0;
}
