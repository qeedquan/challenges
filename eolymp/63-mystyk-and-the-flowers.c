/*

Smugastyk made a flowerbed shaped like a chessboard of size m×n, with a flower in each cell.
Sometimes, he takes Mytsyk for a walk through the flowerbed (yes, do not be surprised, they really are friends).
Mytsyk always starts his journey from the upper left corner and moves to the bottom right corner, collecting flowers along the way.
Each time, he chooses a new route, and at the end, Smugastyk gives him a piece of cheese as a reward.

Calculate the maximum number of pieces of cheese Mytsyk can get if, each time, he tries to collect as few flowers as possible.
On each route, Mytsyk must collect at least one flower.

Input
Two integers m and n (0<m,n≤2⋅10^9) are given in a single line.

Output
Print a single integer — the maximum number of pieces of cheese that Mytsyk can get.

Examples
Input #1
2 3

Answer #1
3

*/

#include <assert.h>

int
solve(int n, int m)
{
	return (n - 1) * (m - 1) + 1;
}

int
main()
{
	assert(solve(2, 3) == 3);

	return 0;
}
