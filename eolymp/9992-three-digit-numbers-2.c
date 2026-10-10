/*

Determine the sum of all three-digit numbers where each digit is odd and the sum of the digits equals m.

Input
A natural number m, where 1≤m≤27.

Output
A single integer representing the solution to the problem.

Examples

Input #1
3

Answer #1
111

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
	for (i = 1; i <= 9; i += 2) {
		for (j = 1; j <= 9; j += 2) {
			for (k = 1; k <= 9; k += 2) {
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
	assert(solve(3) == 111);
	assert(solve(4) == 0);
	return 0;
}
