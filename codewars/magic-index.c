/*

A magic index in an array A[1...n-1] is defined to be an index such that A[i] = i. Given a sorted array of distinct integers, write a method to find a magic index, if one exists, in array A.

findMagic([-20,-10,2,10,20]); // Returns 2

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	int i, j;

	i = (int *)b - (int *)a;
	j = *(int *)b;
	if (i < j)
		return -1;
	if (i == j)
		return 0;
	return 1;
}

int
magicindex(int *a, size_t n)
{
	int *p;

	p = bsearch(a, a, n, sizeof(*a), cmp);
	return (p) ? *p : -1;
}

int
main()
{
	int a1[] = {-10, -5, 0, 3, 7};
	int a2[] = {0, 2, 5, 8, 17};
	int a3[] = {-10, -5, 3, 4, 7, 9};
	int a4[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int a5[] = {0, 1, 1, 3};
	int a6[] = {-20, -10, 2, 10, 20};

	assert(magicindex(a1, nelem(a1)) == 3);
	assert(magicindex(a2, nelem(a2)) == 0);
	assert(magicindex(a3, nelem(a3)) == -1);
	assert(magicindex(a4, nelem(a4)) == 5);
	assert(magicindex(a5, nelem(a5)) == 3);
	assert(magicindex(NULL, 0) == -1);
	assert(magicindex(a6, nelem(a6)) == 2);

	return 0;
}
