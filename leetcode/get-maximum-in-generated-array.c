/*

You are given an integer n. A 0-indexed integer array nums of length n + 1 is generated in the following way:

nums[0] = 0
nums[1] = 1
nums[2 * i] = nums[i] when 2 <= 2 * i <= n
nums[2 * i + 1] = nums[i] + nums[i + 1] when 2 <= 2 * i + 1 <= n
Return the maximum integer in the array nums​​​.

Example 1:

Input: n = 7
Output: 3
Explanation: According to the given rules:
  nums[0] = 0
  nums[1] = 1
  nums[(1 * 2) = 2] = nums[1] = 1
  nums[(1 * 2) + 1 = 3] = nums[1] + nums[2] = 1 + 1 = 2
  nums[(2 * 2) = 4] = nums[2] = 1
  nums[(2 * 2) + 1 = 5] = nums[2] + nums[3] = 1 + 2 = 3
  nums[(3 * 2) = 6] = nums[3] = 2
  nums[(3 * 2) + 1 = 7] = nums[3] + nums[4] = 2 + 1 = 3
Hence, nums = [0,1,1,2,1,3,2,3], and the maximum is max(0,1,1,2,1,3,2,3) = 3.

Example 2:

Input: n = 2
Output: 1
Explanation: According to the given rules, nums = [0,1,1]. The maximum is max(0,1,1) = 1.
Example 3:

Input: n = 3
Output: 2
Explanation: According to the given rules, nums = [0,1,1,2]. The maximum is max(0,1,1,2) = 2.


Constraints:

0 <= n <= 100

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

// https://oeis.org/A270362
int
maxgen(int n)
{
	int i, r, *p;

	if (n < 1)
		return 0;

	p = calloc(n + 1, sizeof(*p));
	if (!p)
		return -1;

	r = 0;
	p[0] = 0;
	p[1] = 1;
	for (i = 1; i <= n; i++) {
		if (2 * i <= n)
			p[2 * i] = p[i];

		if ((2 * i) - 1 <= n)
			p[(2 * i) - 1] = p[i] + p[i - 1];

		r = max(r, p[i]);
	}

	free(p);
	return r;
}

int
main(void)
{
	assert(maxgen(7) == 3);
	assert(maxgen(2) == 1);
	assert(maxgen(3) == 2);
	assert(maxgen(0) == 0);
	assert(maxgen(1) == 1);
	assert(maxgen(10000) == 521);

	return 0;
}
