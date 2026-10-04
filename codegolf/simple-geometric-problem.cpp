/*

This problem (see below) has been given as a High School Programming League code golf challenge. The shortest codes submitted during the contest were: 177 bytes in Ruby, 212 bytes in Python 2.5, 265 bytes in C. Can anyone make it shorter? Other programming languages are also allowed.

Problem formulation: Given 8 integers: -1000 < x1, y1, x2, y2, x3, y3, x4, y4 < 1000. Check what is the shape of the intersection of two axis-aligned rectangles: P1 = (x1, y1), (x1, y2), (x2, y2), (x2, y1) and P2 = (x3, y3), (x3, y4), (x4, y4), (x4, y3).

* If the rectangles do not intersect print *nothing*.
* If there is exactly one point in common print *point*.
* If the intersections of P1 and P2 is a line segment print *line*.
* If they have a rectangular area in common print *rectangle*. 
Input data specification: The first line contains the number of test cases t (1<=t<1000). Each of the following t lines contains 8 integers: x1, y1, x2, y2, x3, y3, x4, y4 (The area of both rectangles is greater than 0).

You can test your solution here.
https://www.spoj.com/HSPLARCH/problems/HS10RECT/

*/

#include <cassert>
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Rect make_rect(int x1, int y1, int x2, int y2)
{
	if (x1 > x2)
		swap(x1, x2);
	if (y1 > y2)
		swap(y1, y2);
	return Rect(x1, y1, x2 - x1 + 1, y2 - y1 + 1);
}

string classify(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	auto rect1 = make_rect(x1, y1, x2, y2);
	auto rect2 = make_rect(x3, y3, x4, y4);
	auto recti = rect1 & rect2;
	auto size = recti.size();
	
	if (size.width == 1 && size.height == 1)
		return "point";
	if ((size.width == 1 && size.height > 1) || (size.height == 1 && size.width > 1))
		return "line";
	if (size.width > 1 || size.height > 1)
		return "rectangle";
	return "nothing";
}

int main()
{
	assert(classify(1, 1, 2, 2, 2, 2, 3, 3) == "point");
	assert(classify(10, 1, 1, 10, 12, 9, 10, 12) == "line");
	assert(classify(2, 3, 10, 10, 1, 4, 0, 0) == "nothing");
	assert(classify(1, 20, 20, 1, 2, 10, 10, 2) == "rectangle");
	assert(classify(10, 20, 20, 10, 20, 30, 25, 1) == "line");

	return 0;
}
