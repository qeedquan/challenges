/*

You are given a 0-indexed integer array nums representing the strength of some heroes. The power of a group of heroes is defined as follows:

Let i0, i1, ... ,ik be the indices of the heroes in a group. Then, the power of this group is max(nums[i0], nums[i1], ... ,nums[ik])2 * min(nums[i0], nums[i1], ... ,nums[ik]).
Return the sum of the power of all non-empty groups of heroes possible. Since the sum could be very large, return it modulo 10^9 + 7.

Example 1:

Input: nums = [2,1,4]
Output: 141
Explanation:
1st group: [2] has power = 22 * 2 = 8.
2nd group: [1] has power = 12 * 1 = 1.
3rd group: [4] has power = 42 * 4 = 64.
4th group: [2,1] has power = 22 * 1 = 4.
5th group: [2,4] has power = 42 * 2 = 32.
6th group: [1,4] has power = 42 * 1 = 16.
7th group: [2,1,4] has power = 42 * 1 = 16.
The sum of powers of all groups is 8 + 1 + 64 + 4 + 32 + 16 + 16 = 141.

Example 2:

Input: nums = [1,1,1]
Output: 7
Explanation: A total of 7 groups are possible, and the power of each group will be 1. Therefore, the sum of the powers of all groups is 7.

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9

Hint 1
At first glance, the solution seems to be greedy, but if you try to greedily take the largest value from the beginning or the end, this will not be optimal.

Hint 2
You should try all scenarios but this will be costly.

Hint 3
Memoizing the pre-visited states while trying all the possible scenarios will reduce the complexity, and hence dp is a perfect choice here.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	long x, y;

	x = *(long *)a;
	y = *(long *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

long
sop(long *a, size_t n)
{
	static const long mod = 1000000007;

	long r, p, x;
	size_t i;

	qsort(a, n, sizeof(*a), cmp);

	r = p = 0;
	for (i = 0; i < n; i++) {
		x = a[i];
		r = (r + (((x * x) % mod) * (p + x) % mod)) % mod;
		p = (p + (p + x)) % mod;
	}
	return r;
}

int
main()
{
	long a1[] = { 2, 1, 4 };
	long a2[] = { 1, 1, 1 };

	assert(sop(a1, nelem(a1)) == 141);
	assert(sop(a2, nelem(a2)) == 7);

	return 0;
}
