/*

The Eulerian number A(n, m) is the number of permutations of [1, 2, ..., n] in which exactly m elements are greater than the previous element. These are also called rises. For example, if n = 3, there are 3! = 6 permutations of [1, 2, 3]

1 2 3
 < <  2 elements are greater than the previous

1 3 2
 < >  1 ...

2 1 3
 > <  1 ...

2 3 1
 < >  1 ...

3 1 2
 > <  1 ...

3 2 1
 > >  0 ...
So the outputs for A(3, m) for m in [0, 1, 2, 3] will be

A(3, 0) = 1
A(3, 1) = 4
A(3, 2) = 1
A(3, 3) = 0
Also, this is the OEIS sequence A173018.

Rules
This is code-golf so the shortest code wins.
The input n will be a nonnegative integer and m will be a integer in the range [0, 1, ..., n].
Test Cases
n   m   A(n, m)
0   0   1
1   0   1
1   1   0
2   0   1
2   1   1
2   2   0
3   0   1
3   1   4
3   2   1
3   3   0
4   0   1
4   1   11
4   2   11
4   3   1
4   4   0
5   1   26
7   4   1191
9   5   88234
10  5   1310354
10  7   47840
10  10  0
12  2   478271
15  6   311387598411
17  1   131054
20  16  1026509354985
42  42  0

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

// https://oeis.org/A173018
uvlong
eulerian(uvlong n, uvlong k)
{
	if (k == 0)
		return 1;
	if (k == n)
		return 0;
	return eulerian(n - 1, k) * (k + 1) + eulerian(n - 1, k - 1) * (n - k);
}

int
main(void)
{
	static const uvlong tab[] = {1, 1, 0, 1, 1, 0, 1, 4, 1, 0, 1, 11, 11, 1, 0, 1, 26, 66, 26, 1, 0, 1, 57, 302, 302, 57, 1, 0, 1, 120, 1191, 2416, 1191, 120, 1, 0, 1, 247, 4293, 15619, 15619, 4293, 247, 1, 0, 1, 502, 14608, 88234, 156190, 88234, 14608, 502, 1, 0, 1, 1013, 47840, 455192, 1310354, 1310354, 455192, 47840, 1013, 1, 0};

	uvlong i, j, l;

	for (i = l = 0; l < nelem(tab); i++) {
		for (j = 0; j <= i && l < nelem(tab); j++)
			assert(eulerian(i, j) == tab[l++]);
	}

	assert(eulerian(0, 0) == 1);
	assert(eulerian(1, 0) == 1);
	assert(eulerian(1, 1) == 0);
	assert(eulerian(2, 0) == 1);
	assert(eulerian(2, 1) == 1);
	assert(eulerian(2, 2) == 0);
	assert(eulerian(3, 0) == 1);
	assert(eulerian(3, 1) == 4);
	assert(eulerian(3, 2) == 1);
	assert(eulerian(3, 3) == 0);
	assert(eulerian(4, 0) == 1);
	assert(eulerian(4, 1) == 11);
	assert(eulerian(4, 2) == 11);
	assert(eulerian(4, 3) == 1);
	assert(eulerian(4, 4) == 0);
	assert(eulerian(5, 1) == 26);
	assert(eulerian(7, 4) == 1191);
	assert(eulerian(9, 5) == 88234);
	assert(eulerian(10, 5) == 1310354);
	assert(eulerian(10, 7) == 47840);
	assert(eulerian(10, 10) == 0);
	assert(eulerian(12, 2) == 478271);
	assert(eulerian(15, 6) == 311387598411);
	assert(eulerian(17, 1) == 131054);
	assert(eulerian(20, 16) == 1026509354985);
	assert(eulerian(42, 42) == 0);

	return 0;
}
