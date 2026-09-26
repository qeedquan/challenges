/*

Write a program or function that given an integer radius r returns the number of unit squares the circle with radius r centered at the origin passes through. If the circle passes exactly through a point on the grid that does not count as passing through the adjacent unit squares.

Here's an illustration for r = 5:

Illustration by Kival Ngaokrajang, found on OEIS
https://i.sstatic.net/dX9ge.png

Examples:

0 → 0
1 → 4
4 → 28
5 → 28
49 → 388
50 → 380
325 → 2540
5524 → 44180
5525 → 44020

*/

#include <assert.h>
#include <math.h>

bool
issquare(long x)
{
	long s;

	s = sqrt(x);
	return s * s == x;
}

/*

@xnor

This estimates the output as 8*r, then corrects for vertex crossings. The result is 8*r-g(r*r), where g(x) counts the number of ways to write x as a sum of two squares (except g(0)=0).

If the circle never went through any vertices, the number of cells touched would equal the number of edges crossed. The circle passes through 2*r vertical gridlines and 2*r horizontal gridlines, passing each one in both directions, for a total of 8*r.

But, each crossing at a vertex counts as two edge crossings while only entering one new cell. So, we compensate by subtracting the number of vertex crossings. This includes the points on axes like (r,0) as well as Pythagorean triples like (4,3) for r=5.

We count for a single quadrant the points (x,y) with x>=0 and y>0 with x*x+y*y==n, then multiply by 4. We do this by counting the numer of sqrt(r*r-x*x) that are whole number for x in the interval [0,r).

*/

long
count(long r)
{
	long s, x;

	for (s = x = 0; x < r; x++) {
		if (issquare((r * r) - (x * x)))
			s++;
	}
	return (8 * r) - (4 * s);
}

int
main()
{
	assert(count(0) == 0);
	assert(count(1) == 4);
	assert(count(4) == 28);
	assert(count(5) == 28);
	assert(count(49) == 388);
	assert(count(50) == 380);
	assert(count(325) == 2540);
	assert(count(5524) == 44180);
	assert(count(5525) == 44020);

	return 0;
}
