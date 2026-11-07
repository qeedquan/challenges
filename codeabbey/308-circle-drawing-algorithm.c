/*

Supposing that you have already solved Line Drawing Algorithm let's think about evolving it to draw circles, or rather arcs. Our school math reminds that the function for semicircle is simple enough:

Y = sqrt(R^2 - X^2)    for X in [-R .. +R]
But again, thinking of the times when computer CPUs were not able to extract square roots that easily - moreover some processors lacked even multiplication and division!

So this problem also should be programmed either in Asm-4004 or BASIC (with Assembly it should be more close to reality due to lack of arithmetics besides addition and shifts - which is enough for this task).

Problem statement
Draw an arc of 45 degrees, given center point and radius, starting from the point at the same row with the center, to the left of it. Input data contain X0, Y0, X1, Y1 where the first two are coordinates of the center and the second two are coordinates of the starting point, Y1 = Y0, X0 < X1. The arc should be drawn in direction of increasing Y - at each step Y is incremented by 1 and X either remains unchanged, or is decremented by 1, whichever gives better approximation (prefer unchanged if both variants are equally good). The arc ends at some point X2, Y2 satisfying property X2 - X0 = Y2 - Y0.

For example, suppose center is at 0, 0 and radius is 7 (so X1 = 7 too);

- - - - - - - X -
- - - - - - - X -
- - - - - - - X -
- - - - - - X - -
- - - - - - X - -
- - - - - X - - -
- - - - - - - - -
This is't looking much like circle, but it's only 1/8 of it! You'll be provided with "graphical display" where your answer is plotted, so you can plot other octants by "reflecting" corresponding points, e.g:

- - - - - - - X -
- - - - - - - X -
- - - - - - - X -
- - - - - - X - -
- - - - - - X - -
- - - - - X - - -
- - - X X - - - -
X X X - - - - - -
- - - - - - - - -
Just make sure extra poinst are not submitted with the answer.

Input and answer format are exactly the same as in preceding task - here is an example:

input (for Asm-4004):
0 0 0 0 0 7 0 0 0 0 0 0 0 0 0 0

input (for BASIC):
0 0 7 0

answer:
070007010702060306040505

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

// https://www.geeksforgeeks.org/dsa/mid-point-circle-drawing-algorithm/
void
circle(int x0, int y0, int x1, int y1, char *buf)
{
	int p, r, x, y;

	*buf = '\0';
	if (y0 != y1)
		return;

	r = x1 - x0;
	x = r;
	y = 0;
	p = 1 - r;

	if (r > 0)
		buf += sprintf(buf, "%02d%02d", x0 + x, y0 + y);

	while (x > y) {
		y += 1;
		if (p <= 0)
			p += (2 * y) + 1;
		else {
			x -= 1;
			p += (2 * y) - (2 * x) + 1;
		}
		if (x < y)
			break;

		buf += sprintf(buf, "%02d%02d", x0 + x, y0 + y);
	}
}

void
test(int x0, int y0, int x1, int y1, const char *res)
{
	char buf[128];

	circle(x0, y0, x1, y1, buf);
	puts(buf);
	assert(!strcmp(buf, res));
}

int
main()
{
	test(0, 0, 7, 0, "070007010702060306040505");
	return 0;
}
