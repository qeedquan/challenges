/*

A company is planning to interview 2n people.
Given the array costs where costs[i] = [aCosti, bCosti], the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.

Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.

Example 1:

Input: costs = [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation:
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.

Example 2:
Input: costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
Output: 1859

Example 3:
Input: costs = [[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
Output: 3086

Constraints:

2 * n == costs.length
2 <= costs.length <= 100
costs.length is even.
1 <= aCost[i], bCost[i] <= 1000

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	const int *x, *y;
	int dx, dy;

	x = a;
	y = b;
	dx = x[1] - x[0];
	dy = y[1] - y[0];
	if (dx > dy)
		return -1;
	if (dx == dy)
		return 0;
	return 1;
}

int
cost(int c[][2], size_t n)
{
	size_t i;
	int r;

	qsort(c, n, sizeof(*c), cmp);

	r = 0;
	for (i = 0; i < n / 2; i++)
		r += c[i][0] + c[n - i - 1][1];
	return r;
}

int
main()
{
	int c1[][2] = { { 10, 20 }, { 30, 200 }, { 400, 50 }, { 30, 20 } };
	int c2[][2] = { { 259, 770 }, { 448, 54 }, { 926, 667 }, { 184, 139 }, { 840, 118 }, { 577, 469 } };
	int c3[][2] = { { 515, 563 }, { 451, 713 }, { 537, 709 }, { 343, 819 }, { 855, 779 }, { 457, 60 }, { 650, 359 }, { 631, 42 } };

	assert(cost(c1, nelem(c1)) == 110);
	assert(cost(c2, nelem(c2)) == 1859);
	assert(cost(c3, nelem(c3)) == 3086);

	return 0;
}
