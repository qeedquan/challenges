/*

Given a rational point P, return four integral points A, B, C, and D, such that the line segments AB and CD intersect only at P. To make it a bit more interesting, segment AB doesn't include A and B.

You can take input P as (a/b,c/d) or (a/b,c/b), and assume that b and d are the smallest possible positive integers for the value. a and c are also integers (not necessarily positive).

Shortest code wins.

Test cases (answers are not unique):

(1/2,1/2), aka. (1,1)/2 => (0,0)-(1,1);(0,1)-(1,0)
(1/2,-1/3), aka. (3,-2)/6 => (1,0)-(-2,-2);(0,0)-(6,-4)
(-5/2,5/4), aka. (-10,5)/4 => (0,0)-(-60,30);(-3,2)-(1,-4)
(1/2,0), aka. (1,0)/2 => (0,0)-(42,0);(0,1)-(1,-1)

*/

#include <stdio.h>

/*

@Neil

Output the lines (3a+b,0)-(5a+b-6ab-2b²,2c);(3a+b,1)-(5a+b-6ab-2b²,2c-2b+1)

*/

void
construct(int a, int c, int b, int p[8])
{
	p[0] = (3 * a) + b;
	p[1] = 0;
	p[2] = (5 * a) + b - (6 * a * b) - (2 * b * b);
	p[3] = 2 * c;

	p[4] = p[0];
	p[5] = 1;
	p[6] = p[2];
	p[7] = (2 * c) - (2 * b) + 1;
}

void
test(int a, int c, int b)
{
	int p[8];

	construct(a, c, b, p);
	printf("(%d,%d)-(%d,%d);(%d,%d)-(%d,%d)\n",
	       p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7]);
}

int
main(void)
{
	test(1, 1, 2);
	test(3, -2, 6);
	test(10, 5, 4);
	test(1, 0, 2);
	test(-2, 3, 2);
	test(-2, 1, 2);

	return 0;
}
