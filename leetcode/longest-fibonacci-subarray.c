/*

You are given an array of positive integers nums.

A Fibonacci array is a contiguous sequence whose third and subsequent terms each equal the sum of the two preceding terms.

Return the length of the longest Fibonacci subarray in nums.

Note: Subarrays of length 1 or 2 are always Fibonacci.

Example 1:

Input: nums = [1,1,1,1,2,3,5,1]

Output: 5

Explanation:

The longest Fibonacci subarray is nums[2..6] = [1, 1, 2, 3, 5].

[1, 1, 2, 3, 5] is Fibonacci because 1 + 1 = 2, 1 + 2 = 3, and 2 + 3 = 5.

Example 2:

Input: nums = [5,2,7,9,16]

Output: 5

Explanation:

The longest Fibonacci subarray is nums[0..4] = [5, 2, 7, 9, 16].

[5, 2, 7, 9, 16] is Fibonacci because 5 + 2 = 7, 2 + 7 = 9, and 7 + 9 = 16.

Example 3:

Input: nums = [1000000000,1000000000,1000000000]

Output: 2

Explanation:

The longest Fibonacci subarray is nums[1..2] = [1000000000, 1000000000].

[1000000000, 1000000000] is Fibonacci because its length is 2.

Constraints:

3 <= nums.length <= 10^5
1 <= nums[i] <= 10^9

Hint 1
Any subarray of length <= 2 is valid. Start with length 2.

Hint 2
If a[i] == a[i - 1] + a[i - 2], extend; otherwise reset length to 2.

Hint 3
Track the maximum length during one pass.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef long long vlong;

vlong
longest(vlong *a, size_t n)
{
	size_t i;
	vlong r, c;

	if (n < 3)
		return 0;

	r = c = 2;
	for (i = 2; i < n; i++) {
		if (a[i] != a[i - 1] + a[i - 2])
			c = 2;
		else {
			c += 1;
			r = max(r, c);
		}
	}
	return r;
}

int
main()
{
	vlong a1[] = { 1, 1, 1, 1, 2, 3, 5, 1 };
	vlong a2[] = { 5, 2, 7, 9, 16 };
	vlong a3[] = { 1000000000, 1000000000, 1000000000 };

	assert(longest(a1, nelem(a1)) == 5);
	assert(longest(a2, nelem(a2)) == 5);
	assert(longest(a3, nelem(a3)) == 2);

	return 0;
}
