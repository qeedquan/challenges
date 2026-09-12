/*

Given an array of integers.

Return a number that is the sum of

The product of all the non-negative numbers
The sum of all the negative numbers
Edge cases
If there are no non-negative numbers, assume the product of them to be 1.
Similarly, if there are no negative numbers, assume the sum of them to be 0.
If the array is null, result should be 0.

For example:
mathEngine([1, 2, 3, -4, -5]) // should return -3

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
mathengine(int *a, size_t n)
{
	size_t i;
	int p, s;

	if (n == 0)
		return 0;

	p = 1;
	s = 0;
	for (i = 0; i < n; i++) {
		if (a[i] >= 0)
			p *= a[i];
		else
			s += a[i];
	}
	return p + s;
}

int
main()
{
	int a1[] = {1, 2, 3, -4, -5};

	assert(mathengine(a1, nelem(a1)) == -3);
	assert(mathengine(NULL, 0) == 0);

	return 0;
}
