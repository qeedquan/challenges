/*

Objective
Given a three-dimensional vector:

v = [a b c]

Output the following matrix:

*v = [0 c -b]
     [-c 0 a]
     [b -a 0]

The unary prefix operator ⋆ is known as the Hodge star operator.

I/O Format
The numbers involved in the input are assumed to be floating-point real numbers. Otherwise flexible.

*/

#include <stdio.h>

void
hodgestar(int m[3][3], int v[3])
{
	int a, b, c;

	a = v[0];
	b = v[1];
	c = v[2];
	m[0][0] = 0;
	m[0][1] = c;
	m[0][2] = -b;
	m[1][0] = -c;
	m[1][1] = 0;
	m[1][2] = a;
	m[2][0] = b;
	m[2][1] = -a;
	m[2][2] = 0;
}

int
main()
{
	int v[3] = { 1, 2, 3 };
	int m[3][3];

	hodgestar(m, v);
	return 0;
}
