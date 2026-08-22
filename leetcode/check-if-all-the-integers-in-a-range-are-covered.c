/*

You are given a 2D integer array ranges and two integers left and right. Each ranges[i] = [starti, endi] represents an inclusive interval between starti and endi.

Return true if each integer in the inclusive range [left, right] is covered by at least one interval in ranges. Return false otherwise.

An integer x is covered by an interval ranges[i] = [starti, endi] if starti <= x <= endi.

Example 1:

Input: ranges = [[1,2],[3,4],[5,6]], left = 2, right = 5
Output: true
Explanation: Every integer between 2 and 5 is covered:
- 2 is covered by the first range.
- 3 and 4 are covered by the second range.
- 5 is covered by the third range.

Example 2:

Input: ranges = [[1,10],[10,20]], left = 21, right = 21
Output: false
Explanation: 21 is not covered by any range.


Constraints:

1 <= ranges.length <= 50
1 <= starti <= endi <= 50
1 <= left <= right <= 50

Hint 1
Iterate over every integer point in the range [left, right].

Hint 2
For each of these points check if it is included in one of the ranges.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	const int *x, *y;
	size_t i;

	x = a;
	y = b;
	for (i = 0; i < 2; i++) {
		if (x[i] < y[i])
			return -1;
		if (x[i] > y[i])
			return 1;
	}
	return 0;
}

bool
covered(int ranges[][2], ssize_t nranges, ssize_t left, ssize_t right)
{
	int *range;
	ssize_t index;

	qsort(ranges, nranges, sizeof(*ranges), cmp);
	for (index = 0; index < nranges; index++) {
		range = ranges[index];
		if (range[0] <= left && left <= range[1])
			left = range[1] + 1;
	}
	return left > right;
}

int
main()
{
	int ranges1[][2] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
	int ranges2[][2] = { { 1, 10 }, { 10, 20 }, { 5, 6 } };

	assert(covered(ranges1, nelem(ranges1), 2, 5) == true);
	assert(covered(ranges2, nelem(ranges2), 21, 21) == false);

	return 0;
}
