/*

Six real numbers x1,y1,x2,y2,x3,y3

Given: the coordinates of the vertices of a triangle.

Find the perimeter and the area of the triangle.

Input
The only line contains six real numbers x1,y1,x2,y2,x3,y3, the coordinates of the triangle's vertices.
The absolute value of each number does not exceed 100.

Output
Print two real numbers: the perimeter and the area of the triangle, separated by a space.
Both values must be printed with 4 digits after the decimal point.

Examples

Input #1
3 2 7 6.5 10 1

Answer #1
19.3568 17.7500

*/

#include <cstdio>
#include <cmath>

void solve(double x1, double y1, double x2, double y2, double x3, double y3)
{
	auto a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	auto b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
	auto c = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
	auto p = (a + b + c) / 2;

	auto P = a + b + c;
	auto A = sqrt(p * (p - a) * (p - b) * (p - c));

	printf("%.4lf %.4lf\n", P, A);
}

int main()
{
	solve(3, 2, 7, 6.5, 10, 1);

	return 0;
}
