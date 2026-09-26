/*

Divide the first quadrant (including the positive x-axis, the positive y-axis, and the origin) into 1x1 grids, with each grid labelled by the coordinates of its bottom-left corner, as demonstrated below:

https://i.stack.imgur.com/61W6S.png

Note that each grid contains its boundaries and its vertices. Using mathematical symbols, the grid labelled (m,n) would represent the square {(x,y) | m ≤ x ≤ m+1, n ≤ y ≤ n+1}.

Given a straight line in the form of ax+by+c=0 with integers a, b, and c, and a grid represented by (m,n), output whether the line passes through the grid, i.e. whether any point in the given grid is on the line.

a  b  c m n output
1  1  0 0 0 true
1  1  0 1 1 false
1  1  0 0 2 false
1  1 -3 0 1 true
1  1 -3 0 0 false
2 -1  0 1 1 true
2 -1  0 1 0 false
2 -1  0 0 2 true
2 -1  0 0 1 true
2 -1  0 1 2 true
2  0 -1 0 0 true
2  0 -1 0 1 true
2  0 -1 0 2 true
2  0 -1 1 0 false
2  0 -1 1 1 false
0  2 -1 0 0 true
0  2 -1 1 0 true
0  2 -1 2 0 true
0  2 -1 0 1 false
0  2 -1 1 1 false
1  0 -1 0 0 true
1  0 -1 0 1 true
1  0 -1 0 2 true
1  0 -1 1 0 true
1  0 -1 1 1 true

Please suggest more testcases in the comments.

This is code-golf. Shortest answer in bytes wins. Standard loopholes apply.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

/*

@xnor

lambda a,b,c,m,n:min(0,a,b,a+b)<=-a*m-b*n-c<=max(0,a,b,a+b)

We can tell which side of the line a point is by the sign of a*x+b*y+c. The line passes through the square (counting touching) unless all four vertices (m,n),(m,n+1),(m+1,n),(m+1,n+1) are strictly on the same side of the line. We can plug these values in an extract out the constant a*m+b*n+c that appears in all four:

a*m+b*n+c
a*m+b*n+c+a
a*m+b*n+c+b
a*m+b*n+c+a+b
So, the line passes through the square unless these four values are all positive or all negative. So, it suffices for their minimum to be <=0 and maximum to be >=0.

min(a*m+b*n+c,a*m+b*n+c+a,a*m+b*n+c+b,a*m+b*n+c+a+b)<=0<=max(a*m+b*n+c,a*m+b*n+c+a,a*m+b*n+c+b,a*m+b*n+c+a+b)
Subtracting the common a*m+b*n+c from each part gives the code.

A slightly longer approach is to check whether the set of signs (+,0,-) has length at least 2.

*/

bool
passthrough(int a, int b, int c, int m, int n)
{
	int s, s0, s1;

	s = (-a * m) - (b * n) - c;
	s0 = min(0, min(min(a, b), a + b));
	s1 = max(0, max(max(a, b), a + b));
	return s0 <= s && s <= s1;
}

int
main(void)
{
	assert(passthrough(1, 1, 0, 0, 0) == true);
	assert(passthrough(1, 1, 0, 1, 1) == false);
	assert(passthrough(1, 1, 0, 0, 2) == false);
	assert(passthrough(1, 1, -3, 0, 1) == true);
	assert(passthrough(1, 1, -3, 0, 0) == false);
	assert(passthrough(2, -1, 0, 1, 1) == true);
	assert(passthrough(2, -1, 0, 1, 0) == false);
	assert(passthrough(2, -1, 0, 0, 2) == true);
	assert(passthrough(2, -1, 0, 0, 1) == true);
	assert(passthrough(2, -1, 0, 1, 2) == true);
	assert(passthrough(2, 0, -1, 0, 0) == true);
	assert(passthrough(2, 0, -1, 0, 1) == true);
	assert(passthrough(2, 0, -1, 0, 2) == true);
	assert(passthrough(2, 0, -1, 1, 0) == false);
	assert(passthrough(2, 0, -1, 1, 1) == false);
	assert(passthrough(0, 2, -1, 0, 0) == true);
	assert(passthrough(0, 2, -1, 1, 0) == true);
	assert(passthrough(0, 2, -1, 2, 0) == true);
	assert(passthrough(0, 2, -1, 0, 1) == false);
	assert(passthrough(0, 2, -1, 1, 1) == false);
	assert(passthrough(1, 0, -1, 0, 0) == true);
	assert(passthrough(1, 0, -1, 0, 1) == true);
	assert(passthrough(1, 0, -1, 0, 2) == true);
	assert(passthrough(1, 0, -1, 1, 0) == true);
	assert(passthrough(1, 0, -1, 1, 1) == true);

	return 0;
}
