/*

Task
Sum all the numbers of a given array ( cq. list ), except the highest and the lowest element ( by value, not by index! ).

The highest or lowest element respectively is a single element at each edge, even if there are more than one with the same value.

Mind the input validation.

Example
{ 6, 2, 1, 8, 10 } => 16
{ 1, 1, 11, 2, 3 } => 6
Input validation
If an empty value ( null, None, Nothing etc. ) is given instead of an array, or the given array is an empty list or a list with only 1 element, return 0.

*/

#include <assert.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
sumarray(int *a, size_t n)
{
	int r, r0, r1;
	size_t i;

	if (n == 0)
		return 0;

	r = r0 = r1 = a[0];
	for (i = 1; i < n; i++) {
		r += a[i];
		r0 = min(r0, a[i]);
		r1 = max(r1, a[i]);
	}
	return r - r0 - r1;
}

int
main()
{
	int a1[] = { 6, 2, 1, 8, 10 };
	int a2[] = { 1, 1, 11, 2, 3 };
	int a3[] = { 6, 0, 1, 10, 10 };
	int a4[] = { -6, -20, -1, -10, -12 };
	int a5[] = { -6, 20, -1, 10, -12 };

	assert(sumarray(a1, nelem(a1)) == 16);
	assert(sumarray(a2, nelem(a2)) == 6);
	assert(sumarray(a3, nelem(a3)) == 17);
	assert(sumarray(a4, nelem(a4)) == -28);
	assert(sumarray(a5, nelem(a5)) == 3);

	return 0;
}
