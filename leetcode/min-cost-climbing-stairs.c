/*

You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.

Constraints:

2 <= cost.length <= 1000
0 <= cost[i] <= 999

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int
mincost(int *a, size_t n)
{
	int x, y, z;
	size_t i;

	if (n == 0)
		return 0;
	if (n == 1)
		return a[0];

	x = a[0];
	y = a[1];
	for (i = 2; i < n; i++) {
		z = min(x, y) + a[i];
		x = y;
		y = z;
	}
	return min(x, y);
}

int
main(void)
{
	int a1[] = {10, 15, 20};
	int a2[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
	int a3[] = {16, 19, 10, 12, 18};
	int a4[] = {2, 5, 3, 1, 7, 3, 4};

	assert(mincost(a1, nelem(a1)) == 15);
	assert(mincost(a2, nelem(a2)) == 6);
	assert(mincost(a3, nelem(a3)) == 31);
	assert(mincost(a4, nelem(a4)) == 9);

	return 0;
}
