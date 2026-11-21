/*

You are trying to build a house, but unfortunately you currently have only four available walls with side lengths a, b, c, and d. You want your house to be as big as possible, so you would like to know the largest possible area of any quadrilateral you can construct with these four side lengths.

Input
The first line contains the integer T (1 ≤ T ≤ 2,000), the number of tests. Each test contains a single line with four real numbers: a, b, c, and d (0 < a, b, c, d < 1,000). Note that it will always be possible to form a valid quadrilateral with these lengths; that is, the sum of any three side lengths will be strictly larger than the other one.

Output
For each test case, print a single line containing the largest possible area. Your output will be accepted if it is within 0.01 of the official answer.

Example
Input:
2
1 2 1 2
0.5 0.5 0.5 0.5

Output:
2.00
0.25
For the first test case, it is optimal to construct a rectangle, and for the second, a square is optimal.

*/

#include <cmath>
#include <print>

using namespace std;

double solve(double a, double b, double c, double d)
{
	auto s = (a + b + c + d) / 2;
	return sqrt((s - a) * (s - b) * (s - c) * (s - d));
}

int main()
{
	println("{}", solve(1, 2, 1, 2));
	println("{}", solve(0.5, 0.5, 0.5, 0.5));

	return 0;
}
