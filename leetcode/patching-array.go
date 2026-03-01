/*

Given a sorted integer array nums and an integer n, add/patch elements to the array such that any number in the range [1, n] inclusive can be formed by the sum of some elements in the array.

Return the minimum number of patches required.

Example 1:
Input: nums = [1,3], n = 6
Output: 1
Explanation:
Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.

Example 2:
Input: nums = [1,5,10], n = 20
Output: 2
Explanation: The two patches can be [2, 4].

Example 3:
Input: nums = [1,2,2], n = 5
Output: 0

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 10^4
nums is sorted in ascending order.
1 <= n <= 2^31 - 1

*/

package main

func main() {
	assert(patches([]int{1, 3}, 6) == 1)
	assert(patches([]int{1, 5, 10}, 20) == 2)
	assert(patches([]int{1, 2, 2}, 5) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func patches(a []int, n int) int {
	p := 0
	for i, c := 0, 0; c < n; {
		if i < len(a) && a[i] <= c+1 {
			c += a[i]
			i += 1
		} else {
			c = 2*c + 1
			p += 1
		}
	}
	return p
}
