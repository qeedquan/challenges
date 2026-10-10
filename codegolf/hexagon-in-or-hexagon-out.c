/*

There is a great story to tell about regular hexagons found for example in honeycombs. But this busy bee needs your help in telling him which point is inside or outside his honeypot. So, given a regular hexagon as pictured below, centered at the origin and with edge size l, determine if a set of coordinates (x,y) are inside, exactly on the edge or outside of my regular hexagon.

https://i.sstatic.net/bK746.png

Input, output and rules
The rules are:

Input and output methods follow the default rules.
Input consists of three integers: x,y,l.
x and y are of any convenient signed integer format. l is positive (never 0).
Your program must output/return a 1 if the point (x,y) is inside the regular hexagon, -1 if it's outside or 0 if it's exactly on the edge.
This is a code-golf, so shortest code wins. In case of a tie, the earliest post wins.
For output to stdout: leading/trailing spaces or newlines in the output are permitted.
Standard loopholes apply.
Test cases
Here are some test cases:

0,0,1        --> 1
0,1,1        --> -1
0,-1,1       --> -1
1,0,1        --> 0
-1,0,1       --> 0
-1,-1,1      --> -1
1,1,1        --> -1
-2,-3,4      --> 1
32,45,58     --> 1
99,97,155    --> -1
123,135,201  --> 1

*/

#include <assert.h>
#include <stdlib.h>
#include <math.h>

// Ported from @edc65 solution
int
inout(int x, int y, int l)
{
	bool b1, b2;
	double h;

	x = abs(x);
	y = abs(y);
	if (y == 0 && x == l)
		return 0;

	h = sqrt(3) * l;
	b1 = (2 * y) < h;
	b2 = ((x * 1.0) / l) + ((y * 1.0) / h) < 1;
	return (b1 && b2) ? 1 : -1;
}

int
main()
{
	assert(inout(0, 0, 1) == 1);
	assert(inout(0, 1, 1) == -1);
	assert(inout(0, -1, 1) == -1);
	assert(inout(1, 0, 1) == 0);
	assert(inout(-1, 0, 1) == 0);
	assert(inout(-1, -1, 1) == -1);
	assert(inout(1, 1, 1) == -1);
	assert(inout(-2, -3, 4) == 1);
	assert(inout(32, 45, 58) == 1);
	assert(inout(99, 97, 155) == -1);
	assert(inout(123, 135, 201) == 1);

	return 0;
}
