/*

Find the coordinates of the intersection point of two different non-parallel lines.

Input
Six numbers are given: the coefficients A, B, and C for the normal equation of each of the two lines (first for the first line, then for the second line).
All input numbers are integers with absolute value not exceeding 10000.

Output
Print two numbers: the coordinates of the intersection point with an accuracy of 2 decimal places.

Examples

Input #1
1 1 -1 1 -1 0

Answer #1
0.50 0.50

*/

#include <cstdio>

void solve(int A1, int B1, int C1, int A2, int B2, int C2)
{
	C1 = -C1;
	C2 = -C2;

	int d = (A1 * B2) - (A2 * B1);
	int a = (C1 * B2) - (C2 * B1);
	int b = (A1 * C2) - (A2 * C1);

	if (d == 0)
		printf("0.00 0.00\n");
	else if (a == 0 && b != 0)
		printf("0.00 %.2lf\n", b * 1.0 / d);
	else if (b == 0 && a != 0)
		printf("%.2lf 0.00\n", a * 1.0 / d);
	else if (a == 0 && b == 0)
		printf("0.00 0.00\n");
	else
		printf("%.2lf %.2lf\n", a * 1.0 / d, b * 1.0 / d);
}

int main()
{
	solve(1, 1, -1, 1, -1, 0);
	return 0;
}
