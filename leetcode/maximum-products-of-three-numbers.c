/*

Given an integer array, find three numbers whose product is maximum and output the maximum product.

Note:
    The length of the given array will be in range [3,10^4] and all elements are in the range [-1000, 1000].
    Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
cmp(const void *a, const void *b)
{
	int x = *(int *)a;
	int y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

int
maxproduct3(int *a, size_t n)
{
	if (n < 3)
		return 0;
	qsort(a, n, sizeof(*a), cmp);
	return max(a[0] * a[1] * a[n - 1], a[n - 1] * a[n - 2] * a[n - 3]);
}

int
main(void)
{
	int a1[] = {1, 2, 3};
	int a2[] = {1, 2, 3, 4};
	int a3[] = {-1000, -981, -93, 20, 10, 1, 2, 3, 4, 5, 9};
	int a4[] = {-102, 1, 0, -23, 1, 3, 4};
	int a5[] = {-12, -10, -9, 0, 2, 3, 4, 5, 8};
	int a6[] = {-2, -3, -32, -19};
	int a7[] = {1, 4, 3, -6, -7, 0};
	int a8[] = {-10, -3, 5, 6, -20};
	int a9[] = {10, 3, 5, 6, 20};
	int a10[] = {-10, -3, -5, -6, -20};

	assert(maxproduct3(a1, nelem(a1)) == 6);
	assert(maxproduct3(a2, nelem(a2)) == 24);
	assert(maxproduct3(a3, nelem(a3)) == 19620000);
	assert(maxproduct3(a4, nelem(a4)) == 9384);
	assert(maxproduct3(a5, nelem(a5)) == 960);
	assert(maxproduct3(a6, nelem(a6)) == -114);
	assert(maxproduct3(a7, nelem(a7)) == 168);
	assert(maxproduct3(a8, nelem(a8)) == 1200);
	assert(maxproduct3(a9, nelem(a9)) == 1200);
	assert(maxproduct3(a10, nelem(a10)) == -90);

	return 0;
}
