/*

Anton's favourite geometric figures are regular polyhedrons. Note that there are five kinds of regular polyhedrons:

Tetrahedron. Tetrahedron has 4 triangular faces.
Cube. Cube has 6 square faces.
Octahedron. Octahedron has 8 triangular faces.
Dodecahedron. Dodecahedron has 12 pentagonal faces.
Icosahedron. Icosahedron has 20 triangular faces.
All five kinds of polyhedrons are shown on the picture below:


Anton has a collection of n polyhedrons. One day he decided to know, how many faces his polyhedrons have in total. Help Anton and find this number!

Input
The first line of the input contains a single integer n (1 ≤ n ≤ 200 000) — the number of polyhedrons in Anton's collection.

Each of the following n lines of the input contains a string si — the name of the i-th polyhedron in Anton's collection. The string can look like this:

"Tetrahedron" (without quotes), if the i-th polyhedron in Anton's collection is a tetrahedron.
"Cube" (without quotes), if the i-th polyhedron in Anton's collection is a cube.
"Octahedron" (without quotes), if the i-th polyhedron in Anton's collection is an octahedron.
"Dodecahedron" (without quotes), if the i-th polyhedron in Anton's collection is a dodecahedron.
"Icosahedron" (without quotes), if the i-th polyhedron in Anton's collection is an icosahedron.

Output
Output one number — the total number of faces in all the polyhedrons in Anton's collection.

Examples

input
4
Icosahedron
Cube
Tetrahedron
Dodecahedron
output
42

input
3
Dodecahedron
Octahedron
Octahedron
output
28

Note
In the first sample Anton has one icosahedron, one cube, one tetrahedron and one dodecahedron. Icosahedron has 20 faces, cube has 6 faces, tetrahedron has 4 faces and dodecahedron has 12 faces. In total, they have 20 + 6 + 4 + 12 = 42 faces.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
faces(const char **s, size_t n)
{
	static const struct Shape {
		const char *name;
		int faces;
	} shapes[] = {
	    {"Tetrahedron", 4},
	    {"Cube", 6},
	    {"Octahedron", 8},
	    {"Dodecahedron", 12},
	    {"Icosahedron", 20},
	};

	const struct Shape *p;
	size_t i, j;
	int r;

	r = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < nelem(shapes); j++) {
			p = shapes + j;
			if (!strcmp(p->name, s[i]))
				r += p->faces;
		}
	}
	return r;
}

int
main(void)
{
	const char *s1[] = {
	    "Icosahedron",
	    "Cube",
	    "Tetrahedron",
	    "Dodecahedron",
	};

	const char *s2[] = {
	    "Dodecahedron",
	    "Octahedron",
	    "Octahedron",
	};

	assert(faces(s1, nelem(s1)) == 42);
	assert(faces(s2, nelem(s2)) == 28);

	return 0;
}
