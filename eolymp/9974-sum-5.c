/*

Calculate the sum of the first n terms in the sequence:
1 + 3 + 9 + 27 + 81 + ...

Input
A natural number n, where 1≤n≤39.

Output
A single number representing the sum of the first n terms of the sequence.

Examples

Input #1
7

Answer #1
1093

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

uvlong
solvebf(uvlong n)
{
	uvlong i, p, r;

	r = 0;
	p = 1;
	for (i = 0; i < n; i++) {
		r += p;
		p *= 3;
	}
	return r;
}

// https://oeis.org/A003462
uvlong
solve(uvlong n)
{
	return (powl(3, n) - 1) / 2;
}

int
main()
{
	static const uvlong tab[] = {
		0, 1, 4, 13, 40, 121, 364, 1093, 3280, 9841, 29524, 88573, 265720, 797161,
		2391484, 7174453, 21523360, 64570081, 193710244, 581130733, 1743392200,
		5230176601, 15690529804, 47071589413, 141214768240, 423644304721,
		1270932914164
	};

	uvlong i;

	for (i = 0; i < nelem(tab); i++) {
		assert(solve(i) == tab[i]);
		assert(solve(i) == solvebf(i));
	}

	return 0;
}
