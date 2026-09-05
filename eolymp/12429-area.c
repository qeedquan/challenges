/*

You are given n squares, each with a side length of m.
The squares are placed sequentially on a 2D plane such that they are all horizontally aligned.
For every square i (where 2≤i≤n), its leftmost edge passes exactly through the center of the (i−1)th square.
Calculate the total integer area occupied by the union of all n squares.

https://eolympusercontent.com/images/sh2olbamht58t8qrpd9go9i798

Input
The first line of each test case contains single integer t (1≤t≤10^4) — the number of test cases.

The only line of each test case contain two integers n,m (1≤n,m≤100) — the number of squares and the side length of each respectively.

Output
For each test case, Output the total area mod 1e4+7.

Examples

Input #1
5
10 9
9 10
3 3
2 1
4 2

Answer #1
445
500
18
1
10

Scoring
Subtask 1 (50 points) : No additional constraints

*/

#include <assert.h>

int
solve(int n, int m)
{
	return ((n + 1) * m * m) / 2;
}

int
main()
{
	assert(solve(10, 9) == 445);
	assert(solve(9, 10) == 500);
	assert(solve(3, 3) == 18);
	assert(solve(2, 1) == 1);
	assert(solve(4, 2) == 10);

	return 0;
}
