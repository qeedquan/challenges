/*

Given three integers N, K, M, identify the position (starting from 1) of the number that is neither the maximum nor the minimum among them.
If no such number exists, output 0.

−10^18 ≤ N,K,M ≤ 10^18

Input
The input consists of three numbers: N, K, and M, separated by spaces.

Output
Output a single line with the answer to the problem.

Examples
Input #1
3 7 6
Answer #1
3
Input #2
7 6 3
Answer #2
2
Input #3
7 3 7

*/

#include <assert.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
solve(int a, int b, int c)
{
	int m, n;

	if (a == b || b == c || a == c)
		return 0;

	m = max(a, max(b, c));
	n = min(a, min(b, c));

	if (a != m && a != n)
		return 1;
	if (b != m && b != n)
		return 2;
	if (c != m && c != n)
		return 3;
	return 0;
}

int
main()
{
	assert(solve(3, 7, 6) == 3);
	assert(solve(7, 6, 3) == 2);
	assert(solve(7, 3, 7) == 0);

	return 0;
}
