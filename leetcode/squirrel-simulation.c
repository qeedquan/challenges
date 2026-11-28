/*

There's a tree, a squirrel, and several nuts. Positions are represented by the cells in a 2D grid.
Your goal is to find the minimal distance for the squirrel to collect all the nuts and put them under the tree one by one.
The squirrel can only take at most one nut at one time and can move in four directions - up, down, left and right, to the adjacent cell.
The distance is represented by the number of moves.

Example 1:

Input:

Height : 5
Width : 7
Tree position : [2,2]
Squirrel : [4,4]
Nuts : [[3,0], [2,5]]
Output: 12

Explanation:
https://assets.leetcode.com/uploads/2018/10/22/squirrel_simulation.png

Note:

All given positions won't overlap.
The squirrel can take at most one nut at one time.
The given positions of nuts have no order.
Height and width are positive integers. 3 <= height * width <= 10,000.
The given positions contain at least one nut, only one tree and one squirrel.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int x, y;
} Point;

int
max(int a, int b)
{
	return (a > b) ? a : b;
}

int
distance(Point a, Point b)
{
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int
minimize(int height, int width, Point tree, Point squirrel, Point *nuts, size_t numnuts)
{
	int total, maxdiff;
	int tree2nut, squ2nut;
	size_t i;

	total = 0;
	maxdiff = -(width + height);
	for (i = 0; i < numnuts; i++) {
		tree2nut = distance(nuts[i], tree);
		squ2nut = distance(nuts[i], squirrel);

		total += tree2nut * 2;
		maxdiff = max(maxdiff, tree2nut - squ2nut);
	}
	return total - maxdiff;
}

int
main(void)
{
	Point tree = {2, 2};
	Point squirrel = {4, 4};
	Point nuts[] = {{3, 0}, {2, 5}};

	assert(minimize(5, 7, tree, squirrel, nuts, nelem(nuts)) == 12);

	return 0;
}
