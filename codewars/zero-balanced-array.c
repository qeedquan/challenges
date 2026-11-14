/*

An array is called zero-balanced if its elements sum to 0 and for each positive element n, there exists another element that is the negative of n.
Write a function named ìsZeroBalanced that returns true if its argument is zero-balanced array, else return false.
Note that an empty array will not sum to zero.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

bool
zerobalanced(int *a, size_t n)
{
	size_t i;

	if (n == 0)
		return false;

	qsort(a, n, sizeof(*a), cmp);
	for (i = 0; i < n; i++) {
		if (a[i] != -a[n - i - 1])
			return false;
	}
	return true;
}

int
main()
{
	int a1[] = { 1, -1, 2, -2 };
	int a2[] = { 0, 1, -1 };
	int a3[] = { 3 };
	int a4[] = { 3, -2, -1 };
	int a5[] = { 1, 1, 1, 1, -1, 3, -3, -3 };
	int a6[] = { -3, -2, -1, 0, 1, 2, 3 };

	assert(zerobalanced(a1, nelem(a1)) == true);
	assert(zerobalanced(a2, nelem(a2)) == true);
	assert(zerobalanced(a3, nelem(a3)) == false);
	assert(zerobalanced(a4, nelem(a4)) == false);
	assert(zerobalanced(a5, nelem(a5)) == false);
	assert(zerobalanced(a6, nelem(a6)) == true);

	return 0;
}
