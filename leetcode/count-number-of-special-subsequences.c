/*

A sequence is special if it consists of a positive number of 0s, followed by a positive number of 1s, then a positive number of 2s.

For example, [0,1,2] and [0,0,1,1,1,2] are special.
In contrast, [2,1,0], [1], and [0,1,2,0] are not special.
Given an array nums (consisting of only integers 0, 1, and 2), return the number of different subsequences that are special.
Since the answer may be very large, return it modulo 10^9 + 7.

A subsequence of an array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.
Two subsequences are different if the set of indices chosen are different.

Example 1:

Input: nums = [0,1,2,2]
Output: 3
Explanation: The special subsequences are bolded [0,1,2,2], [0,1,2,2], and [0,1,2,2].

Example 2:

Input: nums = [2,2,0,0]
Output: 0
Explanation: There are no special subsequences in [2,2,0,0].

Example 3:

Input: nums = [0,1,2,0,1,2]
Output: 7
Explanation: The special subsequences are bolded:
- [0,1,2,0,1,2]
- [0,1,2,0,1,2]
- [0,1,2,0,1,2]
- [0,1,2,0,1,2]
- [0,1,2,0,1,2]
- [0,1,2,0,1,2]
- [0,1,2,0,1,2]

Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 2

Hint 1
Can we first solve a simpler problem? Counting the number of subsequences with 1s followed by 0s.

Hint 2
How can we keep track of the partially matched subsequences to help us find the answer?

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

vlong
count(vlong *a, size_t n)
{
	static const vlong mod = 1000000007;

	vlong p[3];
	vlong x;
	size_t i;

	memset(p, 0, sizeof(p));
	for (i = 0; i < n; i++) {
		x = a[i];
		p[x] += p[x];
		if (x - 1 >= 0)
			p[x] += p[x - 1];
		else
			p[x] += 1;
		p[x] %= mod;
	}
	return p[2];
}

int
main()
{
	vlong a1[] = { 0, 1, 2, 2 };
	vlong a2[] = { 2, 2, 0, 0 };
	vlong a3[] = { 0, 1, 2, 0, 1, 2 };

	assert(count(a1, nelem(a1)) == 3);
	assert(count(a2, nelem(a2)) == 0);
	assert(count(a3, nelem(a3)) == 7);

	return 0;
}
