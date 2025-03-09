/*

Consider a regular grid, where each cell has integer coordinates. We can group the cells into (square-shaped) "rings" where the cells in each ring have the same Chebyshev distance (or chessboard distance) from the origin.
Your task is to take such a cell coordinate and rotate that cell by one position counter-clockwise within its ring. This implements the following mapping:

https://i.stack.imgur.com/skFsp.png

So for example if the input is (3, -2) you should output (3, -1). Note that (0, 0) is the only input that should map to itself.

Rules
The I/O format is fairly flexible. You can use two individual numbers, a pair/list/array/tuple of numbers, a single complex number, a string containing two numbers, etc.

You may assume that -128 < x,y < 128.

You may write a program or a function and use any of the our standard methods of receiving input and providing output.

You may use any programming language, but note that these loopholes are forbidden by default.

This is code-golf, so the shortest valid answer – measured in bytes – wins.

Test Cases
(0, 0)       => (0, 0)
(1, 0)       => (1, 1)
(1, 1)       => (0, 1)
(0, 1)       => (-1, 1)
(-1, 1)      => (-1, 0)
(-1, 0)      => (-1, -1)
(-1, -1)     => (0, -1)
(0, -1)      => (1, -1)
(1, -1)      => (1, 0)
(95, -12)    => (95, -11)
(127, 127)   => (126, 127)
(-2, 101)    => (-3, 101)
(-65, 65)    => (-65, 64)
(-127, 42)   => (-127, 41)
(-9, -9)     => (-8, -9)
(126, -127)  => (127, -127)
(105, -105)  => (105, -104)

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(int x, int y)
{
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

void
chebyrot(int x, int y, int *rx, int *ry)
{
	int d;

	*rx = x;
	*ry = y;

	d = (x * x) - (y * y);
	if (d <= 0)
		*rx += cmp(-y, x);
	if (d >= 0)
		*ry += cmp(x, y);
}

int
main(void)
{
	static const int tab[][2][2] = {
	    {{0, 0}, {0, 0}},
	    {{1, 0}, {1, 1}},
	    {{1, 1}, {0, 1}},
	    {{0, 1}, {-1, 1}},
	    {{-1, 1}, {-1, 0}},
	    {{-1, 0}, {-1, -1}},
	    {{-1, -1}, {0, -1}},
	    {{0, -1}, {1, -1}},
	    {{1, -1}, {1, 0}},
	    {{95, -12}, {95, -11}},
	    {{127, 127}, {126, 127}},
	    {{-2, 101}, {-3, 101}},
	    {{-65, 65}, {-65, 64}},
	    {{-127, 42}, {-127, 41}},
	    {{-9, -9}, {-8, -9}},
	    {{126, -127}, {127, -127}},
	    {{105, -105}, {105, -104}},
	};

	int x, y, nx, ny, rx, ry;
	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		x = tab[i][0][0];
		y = tab[i][0][1];
		rx = tab[i][1][0];
		ry = tab[i][1][1];

		chebyrot(x, y, &nx, &ny);
		assert(nx == rx && ny == ry);
	}

	return 0;
}
