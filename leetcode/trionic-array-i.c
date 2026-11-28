/*

You are given an integer array nums of length n.

An array is trionic if there exist indices 0 < p < q < n − 1 such that:

    nums[0...p] is strictly increasing,
    nums[p...q] is strictly decreasing,
    nums[q...n − 1] is strictly increasing.

Return true if nums is trionic, otherwise return false.

Example 1:

Input: nums = [1,3,5,4,2,6]

Output: true

Explanation:

Pick p = 2, q = 4:

    nums[0...2] = [1, 3, 5] is strictly increasing (1 < 3 < 5).
    nums[2...4] = [5, 4, 2] is strictly decreasing (5 > 4 > 2).
    nums[4...5] = [2, 6] is strictly increasing (2 < 6).

Example 2:

Input: nums = [2,1,3]

Output: false

Explanation:

There is no way to pick p and q to form the required three segments.

Constraints:

    3 <= n <= 100
    -1000 <= nums[i] <= 1000

Hint 1
Use brute force

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
trionic(int *a, size_t n)
{
	size_t i, p, q;

	if (n == 0)
		return false;

	p = 0;
	while (p + 1 < n && a[p] < a[p + 1])
		p++;

	q = p;
	while (q + 1 < n && a[q] > a[q + 1])
		q++;

	i = q;
	while (i + 1 < n && a[i] < a[i + 1])
		i++;

	return 0 < p && p < q && q < i && i == n - 1;
}

int
main()
{
	int a1[] = { 1, 3, 5, 4, 2, 6 };
	int a2[] = { 2, 1, 3 };

	assert(trionic(a1, nelem(a1)) == true);
	assert(trionic(a2, nelem(a2)) == false);

	return 0;
}
