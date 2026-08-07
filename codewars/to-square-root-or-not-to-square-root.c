/*

Write a method, that will get an integer array as parameter and will process every number from this array.

Return a new array with processing every number of the input-array like this:

If the number has an integer square root, take this, otherwise square the number.

Example
[4,3,9,7,2,1] -> [2,9,3,49,4,1]

Notes
The input array will always contain only positive numbers, and will never be empty or null.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
transform(int *a, size_t n)
{
	size_t i;
	int s;

	for (i = 0; i < n; i++) {
		if (a[i] >= 0) {
			s = sqrt(a[i]);
			if (s * s == a[i]) {
				a[i] = s;
				continue;
			}
		}
		a[i] *= a[i];
	}
}

void
test(int *a, size_t n, int *r)
{
	transform(a, n);
	assert(!memcmp(a, r, sizeof(*r) * n));
}

int
main()
{
	int a1[] = {4, 3, 9, 7, 2, 1};
	int r1[] = {2, 9, 3, 49, 4, 1};

	test(a1, nelem(a1), r1);

	return 0;
}
