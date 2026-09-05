/*

Given two rectangles, which are possibly not in the orthogonal direction, find the area of their intersection.

https://i.stack.imgur.com/CmqsU.png

Input
You may take the rectangles as input in one of the following ways:

The coordinates of the four vertices of the rectangle. These coordinates are guaranteed to represent a rectangle.
The coordinates of the center of the rectangle, the width, the height, and the angle of rotation.
The coordinates of the center of the rectangle, half the width, half the height, and the angle of rotation.
The coordinates of the four vertices of the unrotated rectangle, and the angle of rotation. Since the unrotated rectangle is in the orthogonal direction, its coordinates can be represented by four numbers instead of eight. You may choose to rotate about either the center of the rectangle or the origin.
The angle can be either in degrees or radians. It can be either counterclockwise or clockwise.

You don't need to take the two rectangles in the same way.

Output
The area of the intersection of the two rectangles.

The output must be within a relative or absolute error of 10^-3 of the expected answer for the given test cases.

This means that, if the expected answer is x, and your answer is y, then y must satisfy |x-y| <= max(10^-3,10^-3x).

This is code-golf, so the shortest code in bytes wins.

Test cases
In the test cases, the rectangles will be given in the format [x, y, w, h, a], where (x, y) is the center of the rectangle, w is the width, h is the height, and a is the angle of rotation in radians.
The angle is measured counterclockwise from the positive x-axis.

[[0.0,0.0,1.0,1.0,0.0], [0.0,0.0,1.0,1.0,0.0]] -> 1.0
[[0.0,0.0,1.0,1.0,0.0], [0.0,0.0,1.0,1.0,0.785398]] -> 0.828427
[[-3.04363,2.24972,4.58546,9.13518,2.46245], [-3.2214,4.88133,9.71924,8.41894,-2.95077]] -> 31.9172
[[-0.121604,-0.968191,4.37972,3.76739,0.378918], [-2.64606,4.07074,5.22199,0.847033,-0.785007]] -> 0.0
[[-2.00903,-0.801126,9.90998,6.7441,-1.69896] ,[-2.6075,4.35779,4.29303,8.99664,-0.644758]] -> 14.5163
[[-3.29334,-1.24609,8.73904,3.86844,-2.90883], [-3.77132,-0.751654,1.14319,6.62548,0.806614]] -> 5.26269
[[3.74777,3.13039,1.94813,6.56605,1.53073], [1.20541,4.38287,5.16402,3.75463,-1.66412]] -> 4.89221
[[2.40846,1.71749,7.71957,0.416597,-2.4268], [-0.696347,-2.3767,5.75712,2.90767,3.05614]] -> 0.000584885
[[3.56139,-2.87304,8.19849,8.33166,1.00892], [3.03548,-2.46197,8.74573,7.43495,-2.88278]] -> 54.0515
[[3.49495,2.59436,8.45799,5.83319,0.365058], [3.02722,1.64742,1.14493,2.96577,-2.9405]] -> 3.3956

*/

#include <cassert>
#include <iostream>
#include <numbers>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace std::numbers;
using namespace cv;

#define rad2deg(x) (((x)*180) / pi)

double shoelace(const vector<Point2f> &vertices)
{
	auto length = vertices.size();
	if (length < 3)
		return 0;

	auto value = 0.0;
	for (auto i = 0u; i < length - 1; i++)
		value += (vertices[i + 1].x + vertices[i].x) * (vertices[i].y - vertices[i + 1].y);

	value += (vertices[0].x + vertices[length - 1].x) * (vertices[length - 1].y - vertices[0].y);

	return value * 0.5;
}

double area(RotatedRect rect0, RotatedRect rect1)
{
	vector<Point2f> vertices;
	rotatedRectangleIntersection(rect0, rect1, vertices);
	return fabs(shoelace(vertices));
}

void test(RotatedRect rect0, RotatedRect rect1, double result)
{
	auto value = area(rect0, rect1);
	cout << value << endl;
	assert(fabs(value - result) < 1e-3);
}

int main()
{
	test(RotatedRect(Point2f(0, 0), Size2f(1, 1), rad2deg(0)),
		 RotatedRect(Point2f(0, 0), Size2f(1, 1), rad2deg(0)),
		 1);

	test(RotatedRect(Point2f(0.0, 0.0), Size2f(1.0, 1.0), rad2deg(0.0)),
		 RotatedRect(Point2f(0.0, 0.0), Size2f(1.0, 1.0), rad2deg(0.785398)),
		 0.828427);

	test(RotatedRect(Point2f(-3.04363, 2.24972), Size2f(4.58546, 9.13518), rad2deg(2.46245)),
		 RotatedRect(Point2f(-3.2214, 4.88133), Size2f(9.71924, 8.41894), rad2deg(-2.95077)),
		 31.9172);

	test(RotatedRect(Point2f(-0.121604, -0.968191), Size2f(4.37972, 3.76739), rad2deg(0.378918)),
		 RotatedRect(Point2f(-2.64606, 4.07074), Size2f(5.22199, 0.847033), rad2deg(-0.785007)),
		 0.0);

	test(RotatedRect(Point2f(-2.00903, -0.801126), Size2f(9.90998, 6.7441), rad2deg(-1.69896)),
		 RotatedRect(Point2f(-2.6075, 4.35779), Size2f(4.29303, 8.99664), rad2deg(-0.644758)),
		 14.5163);

	test(RotatedRect(Point2f(-3.29334, -1.24609), Size2f(8.73904, 3.86844), rad2deg(-2.90883)),
		 RotatedRect(Point2f(-3.77132, -0.751654), Size2f(1.14319, 6.62548), rad2deg(0.806614)),
		 5.26269);

	test(RotatedRect(Point2f(3.74777, 3.13039), Size2f(1.94813, 6.56605), rad2deg(1.53073)),
		 RotatedRect(Point2f(1.20541, 4.38287), Size2f(5.16402, 3.75463), rad2deg(-1.66412)),
		 4.89221);

	test(RotatedRect(Point2f(2.40846, 1.71749), Size2f(7.71957, 0.416597), rad2deg(-2.4268)),
		 RotatedRect(Point2f(-0.696347, -2.3767), Size2f(5.75712, 2.90767), rad2deg(3.05614)),
		 0.000584885);

	test(RotatedRect(Point2f(3.56139, -2.87304), Size2f(8.19849, 8.33166), rad2deg(1.00892)),
		 RotatedRect(Point2f(3.03548, -2.46197), Size2f(8.74573, 7.43495), rad2deg(-2.88278)),
		 54.0515);

	test(RotatedRect(Point2f(3.49495, 2.59436), Size2f(8.45799, 5.83319), rad2deg(0.365058)),
		 RotatedRect(Point2f(3.02722, 1.64742), Size2f(1.14493, 2.96577), rad2deg(-2.9405)),
		 3.3956);

	return 0;
}
