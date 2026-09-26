/*

You are given three parameters: start(int), end(int) and list(of int);

Make a function that returns the amount of times all the numbers between start and end are multiples of the elements in the list. example:

start = 15; end = 18; list = [2, 4, 3];
15 => 1 (is multiple of 3)
16 => 2 (is multiple of 2 and 4)
17 => 0
18 => 2 (is multiple of 2 and 3)
result = 5

The function should accept two positive integer numbers and an array of integers as parameters, returning the total integer number. Assume that start is less <= end.

examples:

Multiple(1, 10, [1, 2]); => 15
Multiple(1, 800, [7, 8]); => 214
Multiple(301, 5000,[13, 5]); => 1301
The shortest solution is the victor!!! May he odds be ever in your favor...

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
times(int i0, int i1, int *a, size_t n)
{
	int i, r;
	size_t j;

	r = 0;
	for (i = i0; i <= i1; i++) {
		for (j = 0; j < n; j++) {
			if ((i % a[j]) == 0)
				r++;
		}
	}
	return r;
}

int
main(void)
{
	int a1[] = {2, 4, 3};
	int a2[] = {1, 2};
	int a3[] = {7, 8};
	int a4[] = {13, 5};

	assert(times(15, 18, a1, nelem(a1)) == 5);
	assert(times(1, 10, a2, nelem(a2)) == 15);
	assert(times(1, 800, a3, nelem(a3)) == 214);
	assert(times(301, 5000, a4, nelem(a4)) == 1301);

	return 0;
}
