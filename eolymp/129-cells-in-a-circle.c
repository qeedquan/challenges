/*

On a sheet of graph paper with unit squares, a circle of radius R is drawn so that its center is at the intersection of grid lines.
Determine how many complete cells (unit squares) are entirely contained within the circle.

https://static.e-olymp.com/content/42/422b3874ba244da15ef4ffea49655abd93cbaf9d.jpg

Input
The only line contains one integer R (0≤R≤1000), the radius of the circle.

Output
Output a single integer: the number of unit squares entirely contained within the circle.

Examples

Input #1
2

Answer #1
4

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

/*

https://oeis.org/A119677
https://mathworld.wolfram.com/GausssCircleProblem.html

*/

int
solve(int r)
{
	int i, c;

	c = 0;
	for (i = 1; i <= r; i++)
		c += floor(sqrt((r * r) - (i * i)));
	return 4 * c;
}

int
main()
{
	static const int tab[] = {
		0, 0, 4, 16, 32, 60, 88, 120, 164, 216, 276, 332, 392, 476, 556, 648,
		732, 832, 936, 1052, 1176, 1288, 1428, 1560, 1696, 1860, 2016, 2180,
		2340, 2512, 2700, 2876, 3080, 3276, 3488, 3712, 3908, 4144, 4360, 4620,
		4864, 5096, 5356, 5616, 5900
	};

	size_t i;

	assert(solve(2) == 4);

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i) == tab[i]);

	return 0;
}
