/*

You should write a program or function that given an N by N equally spaced square grid and a solid inscribed circle outputs or returns the number of grid squares which are overlapped partially or fully by the solid circle.

0-sized overlaps (i.e. when the circle only touches a line) are not counted. (These overlaps occur at e.g. N = 10.)

Example
N = 8 (64 squares), Slices = 60

https://i.sstatic.net/J0y83.png

Input
An integer N > 0. (The grid wil have N * N squares.)
Output
An integer, the number of solid circle slices.

Examples
(input-output pairs)

Inputs:  1 2 3  4  5  6  7  8  9 10  11  12  13  14  15
Outputs: 1 4 9 16 25 36 45 60 77 88 109 132 149 172 201
This is code-golf so shortest entry wins.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

/*

@xnor

The grid points for an (n+1)*(n+1) square. A cell overlaps the circle if its grid point nearest the center is inside the circle.
So, we can count grid points, except this misses 2*n+1 grid points at axes (both for even and odd n), so we correct for that manually.

The inequality we need to test is:
a = x - n/2
b = y - n/2
c = n / 2

a^2 + b^2 < c^2

Combine like terms and multiply it by 4 to get rid of the need for floating point
4*(a^2 + b^2) = 2*n^2 - 4*n*x - 4*n*y + 4*x^2 + 4*y^2
4*c^2 = n^2

*/

int
overlap(int n)
{
	int x, y, s;
	int r0, r1;

	if (n < 1)
		return 0;

	s = 0;
	r1 = n * n;
	for (y = 0; y <= n; y++) {
		for (x = 0; x <= n; x++) {
			r0 = (2 * n * n) - (4 * n * x) - (4 * n * y) + (4 * x * x) + (4 * y * y);
			if (r0 < r1)
				s += 1;
		}
	}
	return s + n + n - 1;
}

int
main(void)
{
	static const int tab[] = {1, 4, 9, 16, 25, 36, 45, 60, 77, 88, 109, 132, 149, 172, 201};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(overlap(i + 1) == tab[i]);

	return 0;
}
