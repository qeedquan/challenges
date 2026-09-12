/*

Challenge:

Take a vector / list of integers as input, and output the largest number that's adjacent to a zero.

Specifications:

As always, optional input and output format
You may assume that there will be at least one zero, and at least one non-zero element.
Test cases:

1 4 3 6 0 3 7 0
7

9 4 9 0 9 0 9 15 -2
9

-4 -6 -2 0 -9
-2

-11 0 0 0 0 0 -12 10
0

0 20
20

Good luck and happy golfing!

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
adjz(int *a, size_t n)
{
	size_t i;
	int r;

	r = INT_MIN;
	for (i = 0; i < n; i++) {
		if (a[i] != 0)
			continue;

		if (i > 0 && r < a[i - 1])
			r = a[i - 1];
		else if (i + 1 < n && r < a[i + 1])
			r = a[i + 1];
	}
	return r;
}

int
main(void)
{
	int a1[] = {1, 4, 3, 6, 0, 3, 7, 0};
	int a2[] = {9, 4, 9, 0, 9, 0, 9, 15, -2};
	int a3[] = {-4, -6, -2, 0, -9};
	int a4[] = {-11, 0, 0, 0, 0, 0, -12, 10};
	int a5[] = {0, 20};

	assert(adjz(a1, nelem(a1)) == 7);
	assert(adjz(a2, nelem(a2)) == 9);
	assert(adjz(a3, nelem(a3)) == -2);
	assert(adjz(a4, nelem(a4)) == 0);
	assert(adjz(a5, nelem(a5)) == 20);

	return 0;
}
