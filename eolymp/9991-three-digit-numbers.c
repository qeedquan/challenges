/*

Determine the number of three-digit numbers where the digits are in strictly increasing order and their sum equals m.

Input
A natural number m, where 1≤m≤27.

Output
A single integer representing the solution to the problem.

Examples
Input #1
6

Answer #1
1

Input #2
4

Answer #2
0

*/

#include <assert.h>

int
solve(int m)
{
	int i, j, k, r;

	r = 0;
	for (i = 1; i <= 9; i++) {
		for (j = i + 1; j <= 9; j++) {
			for (k = j + 1; k <= 9; k++) {
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
	assert(solve(6) == 1);
	assert(solve(4) == 0);
	return 0;
}
