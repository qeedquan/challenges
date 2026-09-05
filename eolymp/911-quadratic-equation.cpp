/*

Solve the quadratic equation a*x^2 + b*x + c=0, where a != 0.

Input
The input consists of one line containing three integers — the coefficients of the quadratic equation a, b, and c.
The absolute values of all coefficients do not exceed 100.

Output
Print on a single line:

No roots, if the equation has no roots;

One root: followed by the root, separated by a space, if the equation has one root;

Two roots: followed by the smaller root and the larger root, separated by a space, if the equation has two roots.

It is guaranteed that if solutions exist, all roots are integers.

Examples

Input #1
1 -5 6

Answer #1
Two roots: 2 3

Input #2
1 2 10

Answer #2
No roots

*/

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

void solve(int a, int b, int c)
{
	int d = (b * b) - (4 * a * c);
	if (d > 0)
	{
		double x1 = (-b - sqrt(d)) / (a * 2);
		double x2 = (-b + sqrt(d)) / (a * 2);
		if (x1 > x2)
			swap(x1, x2);
		printf("Two roots: %.0f %.0f\n", x1, x2);
	}
	else if (d == 0)
	{
		double x1 = -b / (2 * a);
		printf("One root: %.0f\n", x1);
	}
	else
		printf("No roots\n");
}

int main()
{
	solve(1, -5, 6);
	solve(1, 2, 10);

	return 0;
}
