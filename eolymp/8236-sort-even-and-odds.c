/*

Sequence of integers is given. Sort the given sequence so that first the odd numbers are arranged in ascending order, and then the even numbers are arranged in descending order.

Input
First line contains amount of numbers n (1≤n≤1000). Second line contains n integers, each no more than 2⋅10^9 by absolute value.

Output
Print in one line a sequence of numbers ordered according to the given condition.

Examples

Input #1
7
9 2 3 -6 -5 4 7

Answer #1
-5 3 7 9 4 2 -6

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
print(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;

	if ((x & 1) != (y & 1))
		return (x & 1) ? -1 : 1;

	if (x & 1) {
		if (x < y)
			return -1;
		if (x > y)
			return 1;
	}

	if (x > y)
		return -1;
	if (x < y)
		return 1;

	return 0;
}

void
solve(int *a, size_t n)
{
	qsort(a, n, sizeof(*a), cmp);
}

void
test(int *a, size_t n, int *r)
{
	solve(a, n);
	print(a, n);
	assert(!memcmp(a, r, n * sizeof(*r)));
}

int
main()
{
	int a1[] = { 9, 2, 3, -6, -5, 4, 7 };
	int r1[] = { -5, 3, 7, 9, 4, 2, -6 };

	test(a1, nelem(a1), r1);

	return 0;
}
