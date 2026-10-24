/*

Being able to calculate area of triangle is quite important since many more complex tasks are often easily reduced to this (and we will use it too later).

One of the oldest known methods is Heron's Formula which takes as inputs the lengths of the triangle's sides.

In this problem you however is to write a program which uses X and Y coordinates of the triangle's vertices instead. So you can use either this formula somehow or find another one.

Input data will contain the number of triangles to process.
Next lines will contain 6 values each, in order X1 Y1 X2 Y2 X3 Y3, describing three vertices of a triangle.
Answer should give areas of triangles separated by space (precision about 1e-7 is expected).

Example:

data:
3
1 3 9 5 6 0
1 0 0 1 10000 10000
7886 5954 9953 2425 6250 2108

answer:
17 9999.5 6861563

*/

#include <iostream>
#include <Eigen/Dense>

using namespace std;

double solve(double x1, double y1, double x2, double y2, double x3, double y3)
{
	Eigen::Matrix3f A;
	A << x1, y1, 1,
		x2, y2, 1,
		x3, y3, 1;
	return 0.5 * A.determinant();
}

int main()
{
	cout << solve(1, 3, 9, 5, 6, 0) << endl;
	cout << solve(1, 0, 0, 1, 10000, 10000) << endl;
	cout << solve(7886, 5954, 9953, 2425, 6250, 2108) << endl;

	return 0;
}
