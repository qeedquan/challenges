/*

Challenge
The primitive circle problem is the problem of determining how many coprime integer lattice points x,y there are in a circle centered at the origin and with radius r such that x^2+y^2≤r^2. It's a generalization of Code-Golf: Lattice Points inside a Circle.

https://i.stack.imgur.com/K42tj.png

Input

Radius r

Output

Number of coprime points

Test Cases
Sequence A175341 in the OEIS.

Radius	Number of coprime points
0	0
1	4
2	8
3	16
4	32
5	48

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A175341
int
prims(int r)
{
	int p, x, y;

	for (p = y = 0; y <= r * r; y++) {
		for (x = 0; x < y; x++) {
			if (!((x * x + 1) % y))
				p++;
		}
	}
	return 4 * p;
}

int
main(void)
{
	static const int tab[] = {0, 4, 8, 16, 32, 48, 72, 88, 120, 152, 192, 224, 264, 312, 384, 440, 480, 544, 616, 672, 768, 832, 928, 1000, 1112, 1192, 1280, 1384, 1488, 1584, 1704, 1816, 1960, 2072, 2224, 2344, 2480, 2600, 2752, 2912, 3064, 3184, 3360, 3480, 3696, 3856, 4016, 4176};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(prims(i) == tab[i]);

	return 0;
}
