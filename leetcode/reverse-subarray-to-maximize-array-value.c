/*

You are given an integer array nums. The value of this array is defined as the sum of |nums[i] - nums[i + 1]| for all 0 <= i < nums.length - 1.

You are allowed to select any subarray of the given array and reverse it. You can perform this operation only once.

Find maximum possible value of the final array.

Example 1:

Input: nums = [2,3,1,5,4]
Output: 10
Explanation: By reversing the subarray [3,1,5] the array becomes [2,5,1,3,4] whose value is 10.

Example 2:

Input: nums = [2,4,9,24,2,1,10]
Output: 68

Constraints:

2 <= nums.length <= 3 * 10^4
-10^5 <= nums[i] <= 10^5
The answer is guaranteed to fit in a 32-bit integer.

Hint 1
What's the score after reversing a sub-array [L, R] ?

Hint 2
It's the score without reversing it + abs(a[R] - a[L-1]) + abs(a[L] - a[R+1]) - abs(a[L] - a[L-1]) - abs(a[R] - a[R+1])

Hint 3
How to maximize that formula given that abs(x - y) = max(x - y, y - x) ?

Hint 4
This can be written as max(max(a[R] - a[L - 1], a[L - 1] - a[R]) + max(a[R + 1] - a[L], a[L] - a[R + 1]) - value(L) - value(R + 1))
over all L < R where value(i) = abs(a[i] - a[i-1])

Hint 5
This can be divided into 4 cases.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
min(int a, int b)
{
	return (a < b) ? a : b;
}

int
max(int a, int b)
{
	return (a > b) ? a : b;
}

int
solve(int *a, size_t n)
{
	int r, x, x0, x1;
	size_t i;

	if (n == 0)
		return 0;

	r = 0;
	x = 0;
	x0 = INT_MAX;
	x1 = INT_MIN;
	for (i = 1; i < n; i++) {
		r += abs(a[i - 1] - a[i]);
		x = max(x, abs(a[0] - a[i]) - abs(a[i - 1] - a[i]));
		x = max(x, abs(a[n - 1] - a[i - 1]) - abs(a[i - 1] - a[i]));
		x0 = min(x0, max(a[i - 1], a[i]));
		x1 = max(x1, min(a[i - 1], a[i]));
	}
	return r + max(x, (x1 - x0) * 2);
}

int
main()
{
	int a1[] = { 2, 3, 1, 5, 4 };
	int a2[] = { 2, 4, 9, 24, 2, 1, 10 };

	assert(solve(a1, nelem(a1)) == 10);
	assert(solve(a2, nelem(a2)) == 68);

	return 0;
}
