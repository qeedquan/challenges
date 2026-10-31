/*

Military decorations in the kingdom of Geometry are represented by stars with different number of rays. Each star is designed as consisting of intersecting line segments and precious gems are incrusted at each point where these lines cross each other. The more gems - the more valuable is the medal.

Suppose the star has N rays (each ending with a point) and its line segments connect the points with the step of T. As an example you see above the typical pentagram - the star with 5 points connected with the step of 2.

You are to tell the value of the star-medal - i.e. how many gems it has.

Of course with the step of T = 1 stars became simple polygons and have no gems.

Input data contains the number of medals for which you are to count gems.
Next lines have a pair of values N T each.
Answer should contain the amount of gems for each of medals.

N and T will be always coprime since this allows to draw a line as a single figure - in contrast to Star of David for example which is build of two triangles.

Example:

input data:
2
5 2
7 2

answer:
5 7

*/

#include <assert.h>

// https://ospi.k12.wa.us/sites/default/files/2023-08/star-polygons-ada.pdf
int
solve(int n, int t)
{
	if (n < 1 || t < 1)
		return 0;
	return n * (t - 1);
}

int
main()
{
	assert(solve(5, 2) == 5);
	assert(solve(7, 2) == 7);
	return 0;
}
