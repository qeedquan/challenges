/*

Rearrange a given list such that all the odd numbers appear before all the even numbers. Besides for this requirement, the output list may be in any order.

The input will only contain integers, but they may be negative and there may be duplicates, and they may appear in any order.

Shortest solution wins.
Test cases

[1,2] → [1,2]

[2,1] → [1,2]

[1,0,0] → [1,0,0]

[0,0,-1] → [-1,0,0]

[3,4,3] → [3,3,4]

[-4,3,3] → [3,3,-4]

[2,2,2,3] → [3,2,2,2]

[3,2,2,2,1,2] → [1,3,2,2,2,2] or [3,1,2,2,2,2]

[-2,-2,-2,-1,-2,-3] → [-1,-3,-2,-2,-2,-2,] or [-3,-1,-2,-2,-2,-2,]

[] → []

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
dump(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void
sortodds(int *a, size_t n, int *r)
{
	size_t i, j, k;

	j = 0;
	k = n;
	for (i = 0; i < n; i++) {
		if (a[i] & 1)
			r[j++] = a[i];
		else
			r[--k] = a[i];
	}
}

void
test(int *a, size_t n, int *r)
{
	int p[32];

	sortodds(a, n, p);
	dump(p, n);
	assert(!memcmp(p, r, n * sizeof(*r)));
}

int
main(void)
{
	int a1[] = { 1, 2 };
	int r1[] = { 1, 2 };

	int a2[] = { 2, 1 };
	int r2[] = { 1, 2 };

	int a3[] = { 1, 0, 0 };
	int r3[] = { 1, 0, 0 };

	int a4[] = { 0, 0, -1 };
	int r4[] = { -1, 0, 0 };

	int a5[] = { 3, 4, 3 };
	int r5[] = { 3, 3, 4 };

	int a6[] = { -4, 3, 3 };
	int r6[] = { 3, 3, -4 };

	int a7[] = { 2, 2, 2, 3 };
	int r7[] = { 3, 2, 2, 2 };

	int a8[] = { 3, 2, 2, 2, 1, 2 };
	int r8[] = { 3, 1, 2, 2, 2, 2 };

	int a9[] = { -2, -2, -2, -1, -2, -3 };
	int r9[] = { -1, -3, -2, -2, -2, -2 };

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);
	test(a3, nelem(a3), r3);
	test(a4, nelem(a4), r4);
	test(a5, nelem(a5), r5);
	test(a6, nelem(a6), r6);
	test(a7, nelem(a7), r7);
	test(a8, nelem(a8), r8);
	test(a9, nelem(a9), r9);

	return 0;
}
