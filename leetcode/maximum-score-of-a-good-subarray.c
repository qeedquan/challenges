/*

You are given an array of integers nums (0-indexed) and an integer k.

The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). A good subarray is a subarray where i <= k <= j.

Return the maximum possible score of a good subarray.

Example 1:

Input: nums = [1,4,3,7,4,5], k = 3
Output: 15
Explanation: The optimal subarray is (1, 5) with a score of min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15.

Example 2:

Input: nums = [5,5,4,5,4,1,1,1], k = 0
Output: 20
Explanation: The optimal subarray is (0, 4) with a score of min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20.

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 2 * 10^4
0 <= k < nums.length

Hint 1
Try thinking about the prefix before index k and the suffix after index k as two separate arrays.

Hint 2
Using two pointers or binary search, we can find the maximum prefix of each array where the numbers are less than or equal to a certain value

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

ssize_t
maxscore(int *a, ssize_t n, ssize_t k)
{
	ssize_t m, s;
	ssize_t l, r;

	if (n == 0)
		return 0;

	s = a[k];
	m = s;
	l = k;
	r = k;
	while (l > 0 || r < n - 1) {
		if (l > 0 && r < n - 1) {
			if (a[l - 1] > a[r + 1])
				l -= 1;
			else if (a[l - 1] < a[r + 1])
				r += 1;
			else {
				l -= 1;
				r += 1;
			}
		} else if (l <= 0)
			r += 1;
		else if (r >= n - 1)
			l -= 1;
		else
			break;

		m = min(m, min(a[l], a[r]));
		s = max(s, m * (r - l + 1));
	}
	return s;
}

int
main()
{
	int a1[] = { 1, 4, 3, 7, 4, 5 };
	int a2[] = { 5, 5, 4, 5, 4, 1, 1, 1 };

	assert(maxscore(a1, nelem(a1), 3) == 15);
	assert(maxscore(a2, nelem(a2), 0) == 20);

	return 0;
}
