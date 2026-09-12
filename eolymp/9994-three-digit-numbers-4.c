/*

Determine the number of three-digit numbers where all the digits are even and their sum equals m.

Input
A natural number m, where 1≤m≤27.

Output
A single integer representing the solution to the problem.

Examples
Input #1
4

Answer #1
3

Input #2
3

Answer #2
0

*/

#include <assert.h>
#include <stdio.h>

int
solve(int m)
{
	int i, j, k, r;

	r = 0;
	for (i = 2; i <= 8; i += 2) {
		for (j = 0; j <= 8; j += 2) {
			for (k = 0; k <= 8; k += 2) {
				if (i + j + k == m)
					r += 1;
			}
		}
	}
	return r;
}

int
main()
{
	assert(solve(4) == 3);
	assert(solve(3) == 0);

	return 0;
}
