/*

Given an array of integers arr, return the number of subarrays with an odd sum.

Since the answer can be very large, return it modulo 10^9 + 7.

Example 1:

Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.
Example 2:

Input: arr = [2,4,6]
Output: 0
Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.
Example 3:

Input: arr = [1,2,3,4,5,6,7]
Output: 16


Constraints:

1 <= arr.length <= 10^5
1 <= arr[i] <= 100


Hint 1
Can we use the accumulative sum to keep track of all the odd-sum sub-arrays ?

Hint 2
if the current accu sum is odd, we care only about previous even accu sums and vice versa.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

vlong
subs(vlong *a, size_t n)
{
	static const vlong mod = 1000000007;

	vlong p[2], c, r;
	size_t i;

	p[0] = 1;
	p[1] = 0;
	r = 0;
	c = 0;
	for (i = 0; i < n; i++) {
		c ^= a[i] & 1;
		p[c] += 1;
		r = (r + p[c ^ 1]) % mod;
	}
	return r;
}

int
main()
{
	vlong a1[] = { 1, 3, 5 };
	vlong a2[] = { 2, 4, 6 };
	vlong a3[] = { 1, 2, 3, 4, 5, 6, 7 };

	assert(subs(a1, nelem(a1)) == 4);
	assert(subs(a2, nelem(a2)) == 0);
	assert(subs(a3, nelem(a3)) == 16);

	return 0;
}
