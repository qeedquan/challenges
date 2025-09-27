/*

You will be given an array of integers. All of the integers except one occur twice. That one is unique in the array.

Given an array of integers, find and print the unique element.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
lone(int *a, size_t n)
{
	size_t i;
	int v;

	v = 0;
	for (i = 0; i < n; i++)
		v ^= a[i];
	return v;
}

int
main(void)
{
	int a1[] = {1, 2, 3, 4, 3, 2, 1};
	int a2[] = {1};
	int a3[] = {1, 1, 2};
	int a4[] = {0, 0, 1, 2, 1};

	assert(lone(a1, nelem(a1)) == 4);
	assert(lone(a2, nelem(a2)) == 1);
	assert(lone(a3, nelem(a3)) == 2);
	assert(lone(a4, nelem(a4)) == 2);

	return 0;
}
