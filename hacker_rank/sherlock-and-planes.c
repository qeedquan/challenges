/*

Watson gives four 3-dimensional points to Sherlock and asks him if they all lie in the same plane. Your task here is to help Sherlock.

Input Format
First line contains T, the number of testcases.
Each test case consists of four lines. Each line contains three integers, denoting xi yi zi.

Output Format
For each test case, print YES or NO whether all four points lie in same plane or not, respectively.

Constraints
1 ≤ T ≤ 10^4
-10^3 ≤ xi,yi,zi ≤ 10^3

Sample Input

1
1 2 0
2 3 0
4 0 0
0 0 0

Sample Output

YES

Explanation

All points have zi = 0, hence they lie in the same plane, and output is YES

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	int x, y, z;
} Point;

Point
sub(Point a, Point b)
{
	return (Point){a.x - b.x, a.y - b.y, a.z - b.z};
}

int
det3x3(int m[3][3])
{
	int c00, c01, c02;

	c00 = m[1][1] * m[2][2] - m[1][2] * m[2][1];
	c01 = m[1][2] * m[2][0] - m[1][0] * m[2][2];
	c02 = m[1][0] * m[2][1] - m[1][1] * m[2][0];
	return (m[0][0] * c00) + (m[0][1] * c01) + (m[0][2] * c02);
}

// https://math.stackexchange.com/questions/1557144/how-to-prove-four-points-belong-to-the-same-plane
const char *
planar(Point p[4])
{
	Point a = sub(p[1], p[0]);
	Point b = sub(p[2], p[0]);
	Point c = sub(p[3], p[0]);
	int m[3][3] = {
	    {a.x, a.y, a.z},
	    {b.x, b.y, b.z},
	    {c.x, c.y, c.z},
	};
	return (det3x3(m) == 0) ? "YES" : "NO";
}

int
main(void)
{
	Point p1[] = {
	    {1, 2, 0},
	    {2, 3, 0},
	    {4, 0, 0},
	    {0, 0, 0},
	};
	Point p2[] = {
	    {1, 3, 4},
	    {5, 6, 1},
	    {3, 5, 100},
	    {49, 5, 6},
	};
	Point p3[] = {
	    {5, 5, 5},
	    {5, 5, 5},
	    {5, 5, 5},
	    {5, 5, 5},
	};

	assert(!strcmp(planar(p1), "YES"));
	assert(!strcmp(planar(p2), "NO"));
	assert(!strcmp(planar(p3), "YES"));

	return 0;
}
