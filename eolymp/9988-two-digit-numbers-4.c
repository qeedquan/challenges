/*

Determine how many two-digit numbers exist where both digits are odd and their sum equals m.

Input
A natural number m, 0≤m≤20.

Output
A single integer representing the solution to the problem.

Examples

Input #1
2

Answer #1
1

Input #2
1

Answer #2
0

*/

#include <assert.h>

int
solve(int m)
{
	int i, j, r;

	r = 0;
	for (i = 1; i <= 9; i += 2) {
		for (j = 1; j <= 9; j += 2) {
			if (i + j == m)
				r += 1;
		}
	}
	return r;
}

int
main()
{
	assert(solve(2) == 1);
	assert(solve(1) == 0);
	return 0;
}
