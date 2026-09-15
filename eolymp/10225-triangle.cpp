/*

Given three natural numbers A, B, and C (where 1≤A,B,C≤10000000), determine the type of triangle they can form, if any.

Your task is to output:

0 if a triangle with these sides cannot exist;

1 if the triangle is scalene;

2 if the triangle is isosceles;

3 if the triangle is equilateral.

Input
The input consists of three lines:

The first line contains the number A.

The second line contains the number B.

The third line contains the number C.

Output
Print the number corresponding to the type of triangle described above.

Examples

Input #1
5
5
5

Answer #1
3

*/

#include <cassert>
#include <algorithm>

using namespace std;

int solve(int a, int b, int c)
{
	if (a > b)
		swap(a, b);
	if (a > c)
		swap(a, c);
	if (b > c)
		swap(b, c);

	if (c >= a + b)
		return 0;
	if (a == b && b == c && a == c)
		return 3;
	if (a == b || b == c)
		return 2;
	return 1;
}

int main()
{
	assert(solve(5, 5, 5) == 3);

	return 0;
}
