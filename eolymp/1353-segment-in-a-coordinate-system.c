/*

Given a segment with endpoints x1, y1, x2, y2.
In which coordinate quadrants does the segment lie?

Input
One line contains four integers x1, y1, x2, y2 (−50 ≤ x1, y1, x2, y2 ≤50).

Output
Print in ascending order the numbers of the quadrants in which the segment lies.
Print each number on a new line, or 0 if the segment lies on the coordinate axis.

Examples
Input #1
1 1 -1 1
Answer #1
1
2

*/

#include <stdio.h>

#define bit(x) (1 << (x))

int
quadrant(int x, int y)
{
	if (x >= 0 && y >= 0)
		return 1;
	if (x < 0 && y >= 0)
		return 2;
	if (x < 0 && y < 0)
		return 3;
	return 4;
}

void
solve(int x1, int y1, int x2, int y2)
{
	int i, m;

	if ((x1 == 0 && x2 == 0) || (y1 == 0 && y2 == 0)) {
		puts("0");
		return;
	}

	m = bit(quadrant(x1, y1)) | bit(quadrant(x2, y2));
	for (i = 1; i <= 4; i++) {
		if (m & bit(i))
			printf("%d\n", i);
	}
	printf("\n");
}

int
main()
{
	solve(1, 1, -1, 1);
	solve(1, 1, 2, 2);
	solve(-4, -4, 3, 3);
	solve(0, 0, 1, 1);
	solve(-4, -4, -3, 3);
	solve(0, 0, 0, 3);

	return 0;
}
