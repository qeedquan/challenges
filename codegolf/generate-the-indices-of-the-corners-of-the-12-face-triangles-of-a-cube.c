/*

A cube has 6 faces. We can define it in terms of triangles only, by splitting each square face on the diagonal.

Each vertex of the cube is numbered 0 through 7. The coordinates of a vertex are that vertex's number encoded in binary. For example, the coordinates of vertex 5 are (1,0,1).

Requirements:

Your program must output a list of 12 triangles, where each triangle is named with its three vertices. For example, one valid output triangle is (2,3,6).

You can use whatever kind of delimiting you want between vertices (or none), but there must be a different delimiter between the vertices of a triangle, and between triangles. A minimal output might look like: 236 645 510...

The vertices of a given triangle may be listed in any order. The faces of the cube may each be split along either of their diagonals (but both triangles of a given face must share a diagonal!). No triangle may be repeated (including by listing the same triangle with multiple vertex orderings - if you output 623, you may no longer output 236).

Output must be ASCII numerals 0-7, and whatever delimiters you choose.

Standard code golf rules apply.

*/

#include <stdio.h>

// ported from @Level River St solution
void
gen()
{
	int i, x, y, z;

	for (i = 0; i < 12; i++) {
		x = (i / 6) * 7;
		y = 1 + (i % 6);
		z = (3 * y) % 7;
		printf("(%d, %d, %d)\n", x, y, z);
	}
}

int
main()
{
	gen();
	return 0;
}
