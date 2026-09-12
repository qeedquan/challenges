/*

The problem:
Given a non-empty set of points in the Cartesian plane, find the smallest circle that encloses them all (Wikipedia link).

This problem is trivial if the number of points is three or less (if there's one point, the circle has a radius of zero; if there are two points, the line segment that joins the points is the diameter of the circle; if there are three (non-colinear) points, it's possible to get the equation of a circle that touches them all if they form a non-obtuse triangle, or a circle that touches only two points and encloses the third if the triangle is obtuse). So, for the sake of this challenge, the number of points should be greater than three.

The challenge:
Input: A list of 4 or more non-colinear points. The points should have X and Y coordinates; coordinates can be floats. To ease the challenge, no two points should share the same X coordinate.
For example: [(0,0), (2,1), (5,3), (-1,-1)]
Output: A tuple of values, (h,k,r), such that (x−h)2+(y−k)2=r2
 is the equation of the smallest circle that encloses all points.

Rules:
You can choose whatever input method suits your program.
Output should be printed to STDOUT or returned by a function.
"Normal", general-purpose, languages are preferred, but any esolang is acceptable.
You can assume that the points are not colinear.
This is code-golf, so the smallest program in bytes wins. The winner will be selected one week after the challenge is posted.
Please include the language you used and the length in bytes as header in the first line of your answer: # Language: n bytes

Test cases:
1:
Input: [(-8,0), (3,1), (-6.2,-8), (3,9.5)]
Output: [-1.6, 0.75, 9.89]
2:
Input: [(7.1,-6.9), (-7,-9), (5,10), (-9.5,-8)]
Output: [-1.73, 0.58, 11.58]
3:
Input: [(0,0), (1,2), (3,-4), (4,-5), (10,-10)]
Output: [5.5, -4, 7.5]
4:
Input: [(6,6), (-6,7), (-7,-6), (6,-8)]
Output: [0, -0.5, 9.60]

Happy golfing!!!

*/

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;

// Structure to represent a 2D point
struct Point
{
	double x, y;
};

// Structure to represent a 2D circle
struct Circle
{
	Point center;
	double radius;
};

// Return the euclidean distance between two points
double dist(const Point &a, const Point &b)
{
	return hypot(a.x - b.x, a.y - b.y);
}

// Check whether a point lies inside or on the boundaries of the circle
bool is_inside(const Circle &c, const Point &p)
{
	return dist(c.center, p) <= c.radius;
}

// Get a circle defined by 3 points
Point get_circle_center(double bx, double by, double cx, double cy)
{
	auto B = bx * bx + by * by;
	auto C = cx * cx + cy * cy;
	auto D = bx * cy - by * cx;
	return { (cy * B - by * C) / (2 * D),
			 (bx * C - cx * B) / (2 * D) };
}

// Return a unique circle that intersects three points
Circle circle_from(const Point &A, const Point &B, const Point &C)
{
	auto I = get_circle_center(B.x - A.x, B.y - A.y, C.x - A.x, C.y - A.y);
	I.x += A.x;
	I.y += A.y;
	return { I, dist(I, A) };
}

// Function to return the smallest circle that intersects 2 points
Circle circle_from(const Point &A, const Point &B)
{
	// Set the center to be the midpoint of A and B
	Point C = { (A.x + B.x) / 2.0, (A.y + B.y) / 2.0 };

	// Set the radius to be half the distance AB
	return { C, dist(A, B) / 2.0 };
}

// Check whether a circle encloses the given points
bool is_valid_circle(const Circle &c, const vector<Point> &P)
{
	for (const auto &p : P)
	{
		if (!is_inside(c, p))
			return false;
	}
	return true;
}

// Return the minimum enclosing circle for N <= 3
Circle min_circle_trivial(vector<Point> &P)
{
	assert(P.size() <= 3);
	if (P.empty())
		return { { 0, 0 }, 0 };
	else if (P.size() == 1)
		return { P[0], 0 };
	else if (P.size() == 2)
		return circle_from(P[0], P[1]);

	// Check if MEC can be determined by 2 points only
	for (auto i = 0; i < 3; i++)
	{
		for (auto j = i + 1; j < 3; j++)
		{
			Circle c = circle_from(P[i], P[j]);
			if (is_valid_circle(c, P))
				return c;
		}
	}
	return circle_from(P[0], P[1], P[2]);
}

// Takes a set of input points P and a set R points on the circle boundary.
// n represents the number of points in P that are not yet processed.
Circle welzl_decompose(vector<Point> &P, vector<Point> R, int n)
{
	// Base case when all points processed or |R| = 3
	if (n == 0 || R.size() == 3)
		return min_circle_trivial(R);

	// Pick a random point randomly
	auto i = rand() % n;
	auto p = P[i];

	// Put the picked point at the end of P since it's more efficient than deleting from the middle of the vector
	swap(P[i], P[n - 1]);

	// Get the MEC circle d from the set of points P - {p}
	auto d = welzl_decompose(P, R, n - 1);

	// If d contains p, return d
	if (is_inside(d, p))
		return d;

	// Otherwise, must be on the boundary of the MEC
	R.push_back(p);

	// Return the MEC for P - {p} and R U {p}
	return welzl_decompose(P, R, n - 1);
}

// https://www.geeksforgeeks.org/minimum-enclosing-circle-using-welzls-algorithm/
Circle welzl(const vector<Point> &P)
{
	auto Z = P;
	random_shuffle(Z.begin(), Z.end());
	return welzl_decompose(Z, {}, Z.size());
}

void test(const vector<Point> &P, const Circle &R)
{
	static const double eps = 1e-2;

	auto C = welzl(P);
	printf("[%.2f %.2f %.2f]\n", C.center.x, C.center.y, C.radius);
	assert(fabs(C.center.x - R.center.x) < eps);
	assert(fabs(C.center.y - R.center.y) < eps);
	assert(fabs(C.radius - R.radius) < eps);
}

int main()
{
	vector<Point> P1 = { { -8, 0 }, { 3, 1 }, { -6.2, -8 }, { 3, 9.5 } };
	Circle R1 = { { -1.6, 0.75 }, 9.89 };

	vector<Point> P2 = { { 7.1, -6.9 }, { -7, -9 }, { 5, 10 }, { -9.5, -8 } };
	Circle R2 = { { -1.73, 0.58 }, 11.58 };

	vector<Point> P3 = { { 0, 0 }, { 1, 2 }, { 3, -4 }, { 4, -5 }, { 10, -10 } };
	Circle R3 = { { 5.5, -4 }, 7.5 };

	vector<Point> P4 = { { 6, 6 }, { -6, 7 }, { -7, -6 }, { 6, -8 } };
	Circle R4 = { { 0, -0.5 }, 9.60 };

	srand(time(NULL));
	test(P1, R1);
	test(P2, R2);
	test(P3, R3);
	test(P4, R4);

	return 0;
}
