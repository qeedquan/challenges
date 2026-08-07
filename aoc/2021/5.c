/*

--- Day 5: Hydrothermal Venture ---
You come across a field of hydrothermal vents on the ocean floor! These vents constantly produce large, opaque clouds, so it would be best to avoid them if possible.

They tend to form in lines; the submarine helpfully produces a list of nearby lines of vents (your puzzle input) for you to review. For example:

0,9 -> 5,9
8,0 -> 0,8
9,4 -> 3,4
2,2 -> 2,1
7,0 -> 7,4
6,4 -> 2,0
0,9 -> 2,9
3,4 -> 1,4
0,0 -> 8,8
5,5 -> 8,2
Each line of vents is given as a line segment in the format x1,y1 -> x2,y2 where x1,y1 are the coordinates of one end the line segment and x2,y2 are the coordinates of the other end. These line segments include the points at both ends. In other words:

An entry like 1,1 -> 1,3 covers points 1,1, 1,2, and 1,3.
An entry like 9,7 -> 7,7 covers points 9,7, 8,7, and 7,7.
For now, only consider horizontal and vertical lines: lines where either x1 = x2 or y1 = y2.

So, the horizontal and vertical lines from the above list would produce the following diagram:

.......1..
..1....1..
..1....1..
.......1..
.112111211
..........
..........
..........
..........
222111....
In this diagram, the top left corner is 0,0 and the bottom right corner is 9,9. Each position is shown as the number of lines which cover that point or . if no line covers that point. The top-left pair of 1s, for example, comes from 2,2 -> 2,1; the very bottom row is formed by the overlapping lines 0,9 -> 5,9 and 0,9 -> 2,9.

To avoid the most dangerous areas, you need to determine the number of points where at least two lines overlap. In the above example, this is anywhere in the diagram with a 2 or larger - a total of 5 points.

Consider only horizontal and vertical lines. At how many points do at least two lines overlap?

--- Part Two ---
Unfortunately, considering only horizontal and vertical lines doesn't give you the full picture; you need to also consider diagonal lines.

Because of the limits of the hydrothermal vent mapping system, the lines in your list will only ever be horizontal, vertical, or a diagonal line at exactly 45 degrees. In other words:

An entry like 1,1 -> 3,3 covers points 1,1, 2,2, and 3,3.
An entry like 9,7 -> 7,9 covers points 9,7, 8,8, and 7,9.
Considering all lines from the above example would now produce the following diagram:

1.1....11.
.111...2..
..2.1.111.
...1.2.2..
.112313211
...1.2....
..1...1...
.1.....1..
1.......1.
222111....
You still need to determine the number of points where at least two lines overlap. In the above example, this is still anywhere in the diagram with a 2 or larger - now a total of 12 points.

Consider all of the lines. At how many points do at least two lines overlap?

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

enum {
	SIZE = 1000,
};

int
cmp(int a, int b)
{
	if (a > b)
		return -1;
	if (a == b)
		return 0;
	return 1;
}

void
inc(int grid[SIZE][SIZE], int x, int y)
{
	if (x < 0 || x >= SIZE || y < 0 || y >= SIZE)
		return;

	grid[y][x] += 1;
}

int
overlaps(int grid[SIZE][SIZE])
{
	int x, y, sum;

	sum = 0;
	for (y = 0; y < SIZE; y++) {
		for (x = 0; x < SIZE; x++) {
			if (grid[y][x] >= 2)
				sum += 1;
		}
	}
	return sum;
}

int
solve(const char *name, bool diagonal)
{
	int grid[SIZE][SIZE];
	int x0, y0;
	int x1, y1;
	int dx, dy;
	FILE *fp;

	fp = fopen(name, "rb");
	if (!fp) {
		printf("Failed to load file: %s\n", strerror(errno));
		exit(1);
	}

	memset(grid, 0, sizeof(grid));
	for (;;) {
		if (fscanf(fp, "%d,%d -> %d,%d\n", &x0, &y0, &x1, &y1) != 4)
			break;

		dx = cmp(x0, x1);
		dy = cmp(y0, y1);
		if (!diagonal && dx && dy)
			continue;

		inc(grid, x0, y0);
		while (x0 != x1 || y0 != y1) {
			x0 += dx;
			y0 += dy;
			inc(grid, x0, y0);
		}
	}
	fclose(fp);

	return overlaps(grid);
}

int
main()
{
	printf("%d\n", solve("5.txt", false));
	printf("%d\n", solve("5.txt", true));

	return 0;
}
