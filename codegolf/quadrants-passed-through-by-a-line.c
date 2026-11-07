/*

Task
Given a representation of a line, output the number of quadrants that that line passes through.

Valid Representations of a Line
You can represent a line as

Three signed integers A, B, and C which share no common factor and where A and B are not both zero, representing the line Ax + By = C,
Four signed integers X1, Y1, X2, and Y2, representing the line passing through the points (X1, Y1) and (X2, Y2), or
A data type that describes a line, if your language has one (it must support vertical lines).
You may not take input in any format that does not allow for a vertical line (e.g. slope-intercept form). If you choose to take integers as input, you can assume that they lie in the inclusive range [-127, 128].

Specifications
The output will always be 0, 2, or 3 (a line can never pass through all four quadrants, nor can it pass through only a single one).
A line on an axis is considered not to pass through any quadrants. A line through the origin is considered to only pass through 2 quadrants.
You do not have to return which quadrants are being passed through (though the test cases include them for clarity).
This is code-golf, so the shortest valid answer (measured in bytes) wins.
Test Cases
You will have to convert these to a suitable format before using them.

1x + 1y = 1   ->  3  (quadrants I, II, and IV)
-2x + 3y = 1  ->  3  (quadrants I, II, and III)
2x + -3y = 0  ->  2  (quadrants III and I)
1x + 1y = 0   ->  2  (quadrants II and IV)
3x + 0y = 6   ->  2  (quadrants I and IV)
-3x + 0y = 5  ->  2  (quadrants II and III)
0x + -8y = 4  ->  2  (quadrants III and IV)
0x + 1y = 0   ->  0  (lies on the x-axis)
1x + 0y = 0   ->  0  (lies on the y-axis)

*/

#include <assert.h>
#include <stdio.h>

int
sign(int x)
{
	if (x == 0)
		return 0;
	return 1;
}

/*

Ported from @Marcos solution

This was a little tricky at first for me to figure out a mathematical way to calculate this.
However there are only 8 possible configurations such that a != 0 & b != 0 & c != 0

0 0 0 = 0
a 0 0 = 0
0 b 0 = 0
0 0 c = 0
a 0 c = 2
0 b c = 2
a b 0 = 2
a b c = 3

I eventually came to the following function.

F(a,b,c) {
    var r = sign(a)+sign(b)+sign(c);
    if(r > 1)
        r;
    else
        return 0;
}

*/

int
quadrant(const char *s)
{
	int r, x, y, z;

	if (sscanf(s, "%dx + %dy = %d", &x, &y, &z) != 3)
		return -1;

	r = sign(x) + sign(y) + sign(z);
	return (r > 1) ? r : 0;
}

int
main()
{
	assert(quadrant("1x + 1y = 1") == 3);
	assert(quadrant("-2x + 3y = 1") == 3);
	assert(quadrant("2x + -3y = 0 ") == 2);
	assert(quadrant("1x + 1y = 0") == 2);
	assert(quadrant("3x + 0y = 6") == 2);
	assert(quadrant("-3x + 0y = 5") == 2);
	assert(quadrant("0x + -8y = 4 ") == 2);
	assert(quadrant("0x + 1y = 0") == 0);
	assert(quadrant("1x + 0y = 0") == 0);

	return 0;
}
