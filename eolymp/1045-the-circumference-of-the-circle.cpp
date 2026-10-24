/*

Calculating the circumference of a circle is a simple task if you know its diameter. But what if you don't?

You are given the Cartesian coordinates of three non-collinear points on a plane.

Your task is to calculate the circumference of the circle passing through these three points.

Input
The input consists of several test cases.
Each test case consists of a single line containing six real numbers x1, y1, x2, y2, x3, y3 representing the coordinates of the three points.
It is guaranteed that the diameter of the circle defined by these three points does not exceed 1000000.

Output
For each test case, print on a separate line the circumference of the circle defined by these three points. Print the circumference with 2 decimal digits.

Examples
Input #1
0.0 -0.5 0.5 0.0 0.0 0.5
0.0 0.0 0.0 1.0 1.0 1.0
5.0 5.0 5.0 7.0 4.0 6.0
0.0 0.0 -1.0 7.0 7.0 7.0
50.0 50.0 50.0 70.0 40.0 60.0
0.0 0.0 10.0 0.0 20.0 1.0
0.0 -500000.0 500000.0 0.0 0.0 500000.0

Answer #1
3.14
4.44
6.28
31.42
62.83
632.24
3141592.65

*/

#include <cmath>
#include <numbers>
#include <print>

using namespace std;
using numbers::pi;

double solve(double x1, double y1, double x2, double y2, double x3, double y3)
{
	auto d1 = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	auto d2 = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
	auto d3 = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));

	auto p = (d1 + d2 + d3) / 2;
	auto c = sqrt(p * (p - d1) * (p - d2) * (p - d3));
	auto a = (d1 * d2 * d3) / (4 * c);

	return 2 * pi * a;
}

int main()
{
	println("{:.2f}", solve(0.0, -0.5, 0.5, 0.0, 0.0, 0.5));
	println("{:.2f}", solve(0.0, 0.0, 0.0, 1.0, 1.0, 1.0));
	println("{:.2f}", solve(5.0, 5.0, 5.0, 7.0, 4.0, 6.0));
	println("{:.2f}", solve(0.0, 0.0, -1.0, 7.0, 7.0, 7.0));
	println("{:.2f}", solve(50.0, 50.0, 50.0, 70.0, 40.0, 60.0));
	println("{:.2f}", solve(0.0, 0.0, 10.0, 0.0, 20.0, 1.0));
	println("{:.2f}", solve(0.0, -500000.0, 500000.0, 0.0, 0.0, 500000.0));

	return 0;
}
