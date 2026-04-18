/*

In Euclidean geometry, a regular polygon is a polygon that is equiangular (all angles are equal in
measure) and equilateral (all sides have the same length). Tara drew a regular convex polygon on a
paper plane. The polygon has N vertices. The lower side of the polygon is parallel to the X-axis. The
lower side is the side having minimum value of (ya + yb) among all sides of that polygon, where ya and
yb are the y coordinate of two different end points of a side. Unfortunately her friend Gudu lost the
paper. Tara only can remember the length of each side L and lower left point P0(x, y) of that polygon.
Help Tara to draw the polygon again.

Input
First line of the input contains a positive integer T (≤ 20) denoting the number of test cases. Each
of the following T lines contains four integers. N (2 < N ≤ 1000), L (0 < L ≤ 100), x (|x| ≤ 100), y
(|y| ≤ 100) as described before.

Output
For each case, print the case number in a single line first. Print N points of the polygon in next N
lines. Each point consists of two numbers rounded to six decimal places. Points should be ordered
by counter-clockwise starting from P0. Errors less than 10−4 will be ignored. Consecutive output set
should be separated by a blank line.
See sample output format.

Sample Input
2
4 5 0 0
5 5 0 0

Sample Output
Case #1:
0.000000 0.000000
5.000000 0.000000
5.000000 5.000000
0.000000 5.000000
Case #2:
0.000000 0.000000
5.000000 0.000000
6.545085 4.755283
2.500000 7.694209
-1.545085 4.755283

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

#define TAU (2 * M_PI)

void
draw(int N, int L, double x, double y)
{
	double t;
	int i;

	t = 0;
	for (i = 0; i < N; i++) {
		printf("%.6lf %.6lf\n", x, y);
		x += L * cos(t);
		y += L * sin(t);
		t += TAU / N;
	}
	printf("\n");
}

int
main()
{
	draw(4, 5, 0, 0);
	draw(5, 5, 0, 0);

	return 0;
}
