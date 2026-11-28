/*

Task
Given some points(array A) on the same line, determine the minimum number of line segments with length L needed to cover all of the given points. A point is covered if it is located inside some segment or on its bounds.

Example
For A = [1, 3, 4, 5, 8] and L = 3, the output should be 2.

Check out the image below for better understanding:

https://codefightsuserpics.s3.amazonaws.com/tasks/segmentCover/img/example.png?_tm=1474900035857

For A = [1, 5, 2, 4, 3] and L = 1, the output should be 3.

segment1: 1-2(covered points 1,2),

segment2: 3-4(covered points 3,4),

segment3: 5-6(covered point 5)

For A = [1, 10, 100, 1000] and L = 1, the output should be 4.

segment1: 1-2(covered point 1),

segment2: 10-11(covered point 10),

segment3: 100-101(covered point 100),

segment4: 1000-1001(covered point 1000)

Input/Output
[input] integer array A

Array of point coordinates on the line (all points are different).

Constraints:

1 ≤ A.length ≤ 50,

-5000 ≤ A[i] ≤ 5000.

[input] integer L

Segment length, a positive integer.

Constraints: 1 ≤ L ≤ 100.

[output] an integer

The minimum number of line segments that can cover all of the given points.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

size_t
segmentcover(int *a, size_t n, int l)
{
	size_t c, i;
	int p;

	if (n == 0)
		return 0;

	qsort(a, n, sizeof(*a), cmp);

	p = a[0];
	for (c = i = 1; i < n; i++) {
		while (i < n && a[i] - p <= l)
			i++;

		if (i < n) {
			c += 1;
			p = a[i];
		}
	}
	return c;
}

int
main()
{
	int a1[] = {1, 3, 4, 5, 8};
	int a2[] = {-7, -2, 0, -1, -6, 7, 3, 4};
	int a3[] = {1, 5, 2, 4, 3};
	int a4[] = {1, 10, 100, 1000};

	assert(segmentcover(a1, nelem(a1), 3) == 2);
	assert(segmentcover(a2, nelem(a2), 4) == 3);
	assert(segmentcover(a3, nelem(a3), 1) == 3);
	assert(segmentcover(a4, nelem(a4), 1) == 4);
	return 0;
}
