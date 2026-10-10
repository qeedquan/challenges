/*

You are given two integers n and x. You have to construct an array of positive integers nums of size n where for every 0 <= i < n - 1,
nums[i + 1] is greater than nums[i], and the result of the bitwise AND operation between all elements of nums is x.

Return the minimum possible value of nums[n - 1].

Example 1:

Input: n = 3, x = 4

Output: 6

Explanation:

nums can be [4,5,6] and its last element is 6.

Example 2:

Input: n = 2, x = 7

Output: 15

Explanation:

nums can be [7,15] and its last element is 15.

Constraints:

1 <= n, x <= 10^8

Hint 1
Each element of the array should be obtained by “merging” x and v where v = 0, 1, 2, …(n - 1).

Hint 2
To merge x with another number v, keep the set bits of x untouched, for all the other bits, fill the set bits of v from right to left in order one by one.

Hint 3
So the final answer is the “merge” of x and n - 1.

*/

#include <assert.h>

typedef long long vlong;

vlong
minend(vlong n, vlong x)
{
	vlong bn, bx;
	vlong r;

	if (n < 1 || x < 1)
		return 0;

	r = x;
	n -= 1;
	for (bn = bx = 1; bn <= n; bx <<= 1) {
		if (x & bx)
			continue;
		if (n & bn)
			r |= bx;
		bn <<= 1;
	}
	return r;
}

int
main()
{
	assert(minend(3, 4) == 6);
	assert(minend(2, 7) == 15);

	return 0;
}
