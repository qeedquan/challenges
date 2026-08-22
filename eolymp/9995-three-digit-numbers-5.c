/*

Determine the sum of all three-digit numbers where the digits are in descending order and their sum equals m.

Input
A natural number m, where 1≤m≤27.

Output
A single integer representing the solution to the problem.

Examples

Input #1
3

Answer #1
210

Input #2
2

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
	for (i = 9; i >= 1; i--) {
		for (j = i - 1; j >= 0; j--) {
			for (k = j - 1; k >= 0; k--) {
				if (i + j + k == m)
					r += (i * 100) + (j * 10) + k;
			}
		}
	}
	return r;
}

int
main()
{
	assert(solve(3) == 210);
	assert(solve(2) == 0);

	return 0;
}
