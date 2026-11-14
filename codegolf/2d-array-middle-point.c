/*

Given dimensions of a 2D array, except 1xn, that results in an odd number of elements, find the midpoint index.

Example: Input is 3x5, representing the 2D array

[0,0] [0,1] [0,2] [0,3] [0,4]

[1,0] [1,1] [1,2] [1,3] [1,4]

[2,0] [2,1] [2,2] [2,3] [2,4]

The midpoint index is [1,2]

Input
3

5

Output
1 , 2

Rules
Standard code-golf rules, fewest bytes wins
Either full program or function is permitted
When input is either 1xn or the corresponding array would have an even number of elements, output must be [0,0]
nx1 should be treated like any other array

*/

#include <assert.h>
#include <stdio.h>

void
midpoint(int w, int h, int *x, int *y)
{
	*x = *y = 0;
	if (w > 1 && ((w * h) & 1)) {
		*x = w / 2;
		*y = h / 2;
	}
}

void
test(int w, int h, int rx, int ry)
{
	int x, y;

	midpoint(w, h, &x, &y);
	printf("%d %d\n", x, y);
	assert(x == rx);
	assert(y == ry);
}

int
main(void)
{
	test(3, 5, 1, 2);

	return 0;
}
