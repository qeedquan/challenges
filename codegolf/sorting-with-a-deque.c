/*

You're given an array of positive integers. Your job is to sort them using an initially empty deque (double-ended queue) by the following procedure:

Take a number from the front of the array, and push it into one of the two ends of the deque. Repeat this until the array is empty.
Determine if it is possible that the deque is sorted from left to right in the end.

You may assume that the array is not empty. The input numbers are not necessarily distinct.

For output, you can choose to

output truthy/falsy using your language's convention (swapping is allowed), or
use two distinct, fixed values to represent true (affirmative) or false (negative) respectively.
Standard code-golf rules apply. The shortest code in bytes wins.

Test cases
Truthy:

[1]
[1, 2, 3, 4]
[4, 3, 2, 1]
[10, 10, 10, 10]
[3, 4, 2, 5, 1, 6]
[4, 3, 5, 2, 6, 1]
[5, 4, 4, 5, 3, 5, 3, 6, 2, 6]

Falsy:

[1, 3, 2]
[3, 1, 2]
[4, 3, 2, 3, 2, 1]
[1, 2, 3, 2, 3, 4]
[4, 5, 4, 3, 4, 5]

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

/*

@akamayu

Each element must be either the minimum or the maximum of it and all elements before it.

*/

bool
sortable(int *a, size_t n)
{
	size_t i;
	int mi, ma;

	if (n == 0)
		return true;

	mi = ma = a[0];
	for (i = 1; i < n; i++) {
		if (a[i] > mi && a[i] < ma)
			return false;

		mi = min(mi, a[i]);
		ma = max(ma, a[i]);
	}

	return true;
}

int
main()
{
	int a1[] = {1};
	int a2[] = {1, 2, 3, 4};
	int a3[] = {4, 3, 2, 1};
	int a4[] = {10, 10, 10, 10};
	int a5[] = {3, 4, 2, 5, 1, 6};
	int a6[] = {4, 3, 5, 2, 6, 1};
	int a7[] = {5, 4, 4, 5, 3, 5, 3, 6, 2, 6};

	int a8[] = {1, 3, 2};
	int a9[] = {3, 1, 2};
	int a10[] = {4, 3, 2, 3, 2, 1};
	int a11[] = {1, 2, 3, 2, 3, 4};
	int a12[] = {4, 5, 4, 3, 4, 5};

	assert(sortable(a1, nelem(a1)) == true);
	assert(sortable(a2, nelem(a2)) == true);
	assert(sortable(a3, nelem(a3)) == true);
	assert(sortable(a4, nelem(a4)) == true);
	assert(sortable(a5, nelem(a5)) == true);
	assert(sortable(a6, nelem(a6)) == true);
	assert(sortable(a7, nelem(a7)) == true);

	assert(sortable(a8, nelem(a8)) == false);
	assert(sortable(a9, nelem(a9)) == false);
	assert(sortable(a10, nelem(a10)) == false);
	assert(sortable(a11, nelem(a11)) == false);
	assert(sortable(a12, nelem(a12)) == false);

	return 0;
}
