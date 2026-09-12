/*

You have an array of floating point numbers averages which is initially empty. You are given an array nums of n integers where n is even.

You repeat the following procedure n / 2 times:

Remove the smallest element, minElement, and the largest element maxElement, from nums.
Add (minElement + maxElement) / 2 to averages.
Return the minimum element in averages.

Example 1:

Input: nums = [7,8,3,4,15,13,4,1]

Output: 5.5

Explanation:

step	nums	averages
0	[7,8,3,4,15,13,4,1]	[]
1	[7,8,3,4,13,4]	[8]
2	[7,8,4,4]	[8,8]
3	[7,4]	[8,8,6]
4	[]	[8,8,6,5.5]
The smallest element of averages, 5.5, is returned.

Example 2:

Input: nums = [1,9,8,3,10,5]

Output: 5.5

Explanation:

step	nums	averages
0	[1,9,8,3,10,5]	[]
1	[9,8,3,5]	[5.5]
2	[8,5]	[5.5,6]
3	[]	[5.5,6,6.5]

Example 3:

Input: nums = [1,2,3,7,8,9]

Output: 5.0

Explanation:

step	nums	averages
0	[1,2,3,7,8,9]	[]
1	[2,3,7,8]	[5]
2	[3,7]	[5,5]
3	[]	[5,5,5]


Constraints:

2 <= n == nums.length <= 50
n is even.
1 <= nums[i] <= 50

Hint 1
If nums is sorted, then the elements of averages are (nums[i] + nums[n - i - 1]) / 2 for all i < n / 2.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

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

double
solve(int *a, size_t n)
{
	double r;
	size_t i;

	if (n == 0)
		return 0;

	qsort(a, n, sizeof(*a), cmp);
	r = DBL_MAX;
	for (i = 0; i < n / 2; i++)
		r = fmin(r, (a[i] + a[n - i - 1]) / 2.0);
	return r;
}

void
test(int *a, size_t n, double r)
{
	double v;

	v = solve(a, n);
	printf("%f\n", v);
	assert(fabs(v - r) < 1e-12);
}

int
main()
{
	int a1[] = { 7, 8, 3, 4, 15, 13, 4, 1 };
	int a2[] = { 1, 9, 8, 3, 10, 5 };
	int a3[] = { 1, 2, 3, 7, 8, 9 };

	test(a1, nelem(a1), 5.5);
	test(a2, nelem(a2), 5.5);
	test(a3, nelem(a3), 5);

	return 0;
}
