/*

Task
Given an array of numbers and an index, return either the index of the smallest number that is larger than the element at the given index, or -1 if there is no such index ( or, where applicable, Nothing or a similarly empty value ).

Notes
Multiple correct answers may be possible. In this case, return any one of them.
The given index will be inside the given array.
The given array will, therefore, never be empty.

Example
leastLarger( [4, 1, 3, 5, 6], 0 )  =>  3
leastLarger( [4, 1, 3, 5, 6], 4 )  => -1

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

ssize_t
leastlarger(int *a, size_t n, size_t i)
{
	size_t j;
	ssize_t m;

	m = -1;
	for (j = 0; j < n; j++) {
		if (a[j] > a[i] && (m < 0 || a[m] > a[j]))
			m = j;
	}
	return m;
}

int
main()
{
	int a1[] = {4, 1, 3, 5, 6};
	int a2[] = {1, 3, 5, 2, 4};

	assert(leastlarger(a1, nelem(a1), 0) == 3);
	assert(leastlarger(a1, nelem(a1), 4) == -1);
	assert(leastlarger(a2, nelem(a2), 0) == 3);
	return 0;
}
