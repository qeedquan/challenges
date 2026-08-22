/*

Triangular number is any amount of points that can fill an equilateral triangle.

Example: the number 6 is a triangular number because all sides of a triangle has the same amount of points.

http://puu.sh/nmoHB/4204fecf5d.png

Hint!
T(n) = n * (n + 1) / 2,
n - is the size of one side.
T(n) - is the triangular number.
Given a number T from interval [1..2147483646], find if it is triangular number or not.

Appreciate the feedback!

*/

#include <cstdio>
#include <cmath>

bool is_triangular(int n)
{
	if (n < 0)
		return false;

	int x = (-1 + sqrt(1 + (8 * n))) / 2;
	return (x * (x + 1)) / 2 == n;
}

int main()
{
	for (auto i = 0; i <= 1000; i++)
	{
		if (is_triangular(i))
			printf("%d\n", i);
	}
	return 0;
}
