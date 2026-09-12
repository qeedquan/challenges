/*

Given 4 points on the 2D planes A, B, C, D, calculate the area of the intersection region of the triangles OAB and OCD, where O is the center of the plane, having coordinate (0, 0).

Algorithms that runs in constant time complexity (in terms of arithmetic operations) are encouraged, but not forced.

Rules
Each point is represented as two real numbers, denotes their X and Y coordinate.
Optionally, if your programming language (or some library of your programming language) has built-in Point type or equivalent, it is allowed to take Point object as input.
The input is given as 4 points, in the formats, including but not limited to:
A list of 8 coordinates.
A list of 4 points, each point can be represented in any convenient format.
Two lists of 2 points.
etc.
You cannot assume particular ordering of the points (counter-clockwise order or clockwise order)
You cannot assume that the point O is passed as input. In other word, program must not take and use extraneous input.
You cannot assume all the points are different. In other words, the triangles may be degenerate. You need to also handle that case (see test cases below)
The absolute or relative difference must be less than 10-3 for the sample test cases below.

Winning criteria
This is code-golf, the shortest answer in bytes win!

Sample test cases
Ax Ay Bx By Cx Cy Dx Dy area

5 1 1 3 -1 0 0 -1 0
5 1 1 3 -1 0 0 0 0
5 1 1 3 0 0 0 0 0
5 1 1 3 3 4 4 -3 4.50418
5 1 1 3 1 2 2 1 1.5
5 1 1 3 -2 5 4 -2 1.74829
5 1 1 3 -2 5 5 4 2.96154
5 1 1 3 3 5 5 4 1.88462
5 1 1 3 3 5 3 1 3.92308
5 1 1 3 3 5 4 -1 5.26619
5 1 1 3 5 1 4 -1 0
5 1 1 3 5 1 1 3 7
1 3 1 3 5 1 1 3 0
1 3 1 3 1 3 1 3 0
4 8 4 -1 -2 6 -2 -3 0

1.2 3.4 -0.3 4.2 5 7.6 -1.1 2.4 2.6210759326188535
3.1 0.6 0.1 7.2 5.2 0.7 0.9 8 9.018496993987977
If anyone want, here are the outputs for the first test case group in exact form:

0
0
0
46375/10296
3/2
1792/1025
77/26
49/26
51/13
23345/4433
0
7
0
0
0

Illustration image for test case 5 1 1 3 3 4 4 -3 (the area of the green quadrilateral is the expected output):

https://i.snipboard.io/FqhUSz.jpg

*/

#include <cassert>
#include <cmath>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

float area(Point2f A, Point2f B, Point2f C, Point2f D)
{
	auto O = Point2f(0, 0);
	vector<Point2f> P1 = { O, A, B };
	vector<Point2f> P2 = { O, C, D };
	vector<Point2f> PI;
	return intersectConvexConvex(P1, P2, PI, true);
}

void test(Point2f A, Point2f B, Point2f C, Point2f D, float expected)
{
	auto result = area(A, B, C, D);
	cout << result << endl;
	assert(fabsf(result - expected) < 1e-5);
}

int main()
{
	test(Point2f(5, 1), Point2f(1, 3), Point2f(-1, 0), Point2f(0, -1), 0);
	test(Point2f(5, 1), Point2f(1, 3), Point2f(-1, 0), Point2f(0, 0), 0);
	test(Point2f(5, 1), Point2f(1, 3), Point2f(0, 0), Point2f(0, 0), 0);
	test(Point2f(5, 1), Point2f(1, 3), Point2f(3, 4), Point2f(4, -3), 4.50418);
	test(Point2f(5, 1), Point2f(1, 3), Point2f(1, 2), Point2f(2, 1), 1.5);
	test(Point2f(5, 1), Point2f(1, 3), Point2f(-2, 5), Point2f(4, -2), 1.74829);
	test(Point2f(5, 1), Point2f(1, 3), Point2f(-2, 5), Point2f(5, 4), 2.96154);
	test(Point2f(5, 1), Point2f(1, 3), Point2f(3, 5), Point2f(5, 4), 1.88462);
	test(Point2f(5, 1), Point2f(1, 3), Point2f(3, 5), Point2f(3, 1), 3.92308);
	test(Point2f(5, 1), Point2f(1, 3), Point2f(3, 5), Point2f(4, -1), 5.26619);
	test(Point2f(5, 1), Point2f(1, 3), Point2f(5, 1), Point2f(4, -1), 0);
	test(Point2f(5, 1), Point2f(1, 3), Point2f(5, 1), Point2f(1, 3), 7);
	test(Point2f(1, 3), Point2f(1, 3), Point2f(5, 1), Point2f(1, 3), 0);
	test(Point2f(1, 3), Point2f(1, 3), Point2f(1, 3), Point2f(1, 3), 0);
	test(Point2f(4, 8), Point2f(4, -1), Point2f(-2, 6), Point2f(-2, -3), 0);
	test(Point2f(1.2, 3.4), Point2f(-0.3, 4.2), Point2f(5, 7.6), Point2f(-1.1, 2.4), 2.6210759326188535);
	test(Point2f(3.1, 0.6), Point2f(0.1, 7.2), Point2f(5.2, 0.7), Point2f(0.9, 8), 9.018496993987977);

	return 0;
}
