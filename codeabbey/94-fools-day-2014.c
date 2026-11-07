/*

Today I wanted to create new task and found it is April 1 2014 - the Fool's Day when people are trying to overjoke each other.

So here is a small programming problem without the problem statement. Nevertheless you can do it! Good luck! :)

Example:

input data:
5
1 2
1 2 3
2 3 4
2 4 6 8 10
7 11 19

answer:
5 14 29 220 531

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
solve(int *a, size_t n)
{
	size_t i;
	int r;

	r = 0;
	for (i = 0; i < n; i++)
		r += a[i] * a[i];
	return r;
}

int
main()
{
	int a1[] = { 1, 2 };
	int a2[] = { 1, 2, 3 };
	int a3[] = { 2, 3, 4 };
	int a4[] = { 2, 4, 6, 8, 10 };
	int a5[] = { 7, 11, 19 };

	assert(solve(a1, nelem(a1)) == 5);
	assert(solve(a2, nelem(a2)) == 14);
	assert(solve(a3, nelem(a3)) == 29);
	assert(solve(a4, nelem(a4)) == 220);
	assert(solve(a5, nelem(a5)) == 531);

	return 0;
}
