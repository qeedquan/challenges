/*

Calculate the sum of all two-digit numbers where both digits are even and their sum equals m.

Input
A natural number m, 0≤m≤20.

Output
A single integer representing the solution to the problem.

Examples

Input #1
2

Answer #1
20

Input #2
1

Answer #2
0

*/

#include <assert.h>
#include <stdio.h>

int
solve(int m)
{
	int i, j, r;

	r = 0;
	for (i = 2; i <= 8; i += 2) {
		for (j = 0; j <= 8; j += 2) {
			if (i + j == m)
				r += (i * 10) + j;
		}
	}
	return r;
}

int
main()
{
	assert(solve(2) == 20);
	assert(solve(1) == 0);
	return 0;
}
