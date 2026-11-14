/*

You are visiting the Centre Pompidou which contains a lot of modern paintings. In particular you
notice one painting which consists solely of black and white squares, arranged in rows and columns like
in a chess board (no two adjacent squares have the same colour). By the way, the artist did not use
the tool of problem A to create the painting.
Since you are bored, you wonder how many 8 × 8 chess boards are embedded within this painting.
The bottom right corner of a chess board must always be white.

Input
The input contains several test cases. Each test case consists of one line with three integers n, m and
c. (8 ≤ n, m ≤ 40000), where n is the number of rows of the painting, and m is the number of columns
of the painting. c is always 0 or 1, where 0 indicates that the bottom right corner of the painting is
black, and 1 indicates that this corner is white.
The last test case is followed by a line containing three zeros.

Output
For each test case, print the number of chess boards embedded within the given painting.

Sample Input
8 8 0
8 8 1
9 9 1
40000 39999 0
0 0 0

Sample Output
0
1
2
799700028

*/

#include <assert.h>
#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef long long vlong;

void
swap(vlong *a, vlong *b)
{
	vlong t;

	t = *a;
	*a = *b;
	*b = t;
}

vlong
solve(vlong n, vlong m, vlong k)
{
	vlong rleft;
	vlong cleft;
	vlong a2, b2;
	vlong a, b;

	rleft = max(0, n - 7);
	cleft = max(0, m - 7);

	a = rleft / 2;
	b = rleft - a;
	if (k)
		swap(&a, &b);

	a2 = cleft / 2;
	b2 = cleft - a2;
	return (a * b2) + (b * a2);
}

int
main()
{
	assert(solve(8, 8, 0) == 0);
	assert(solve(8, 8, 1) == 1);
	assert(solve(9, 9, 1) == 2);
	assert(solve(40000, 39999, 0) == 799700028);

	return 0;
}
