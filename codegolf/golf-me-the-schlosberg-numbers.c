/*

Schlosberg Numbers

In issue 5 of Mathematical Reflections, Dorin Andrica proposed the problem of characterising the positive integers n such that \sum_{k=1}^n \lfloor \frac{n}{k} \rfloor is an even integer. Eight people submitted correct solutions showing that these are the integers n for which \lfloor \sqrt{n} \rfloor is even. The published solution was by Joel Schlosberg, so I call them the Schlosberg numbers.

These numbers may be found in OEIS as sequence A280682.

Your challenge is: given n, output the nth Schlosberg number. (0 or 1 indexed)

The first 50 Schlosberg numbers are: 0 4 5 6 7 8 16 17 18 19 20 21 22 23 24 36 37 38 39 40 41 42 43 44 45 46 47 48 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 100 101 102 103 104

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

// https://oeis.org/A280682
bool
schlosberg(uvlong n)
{
	uvlong s;

	s = sqrt(n);
	return !(s & 1);
}

int
main(void)
{
	static const uvlong tab[] = {0, 4, 5, 6, 7, 8, 16, 17, 18, 19, 20, 21, 22, 23, 24, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120};

	uvlong i, j;

	for (i = j = 0; i <= tab[nelem(tab) - 1]; i++) {
		if (schlosberg(i))
			assert(i == tab[j++]);
	}
	assert(j == nelem(tab));

	return 0;
}
