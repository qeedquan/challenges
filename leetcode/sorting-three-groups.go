/*

You are given an integer array nums.
Each element in nums is 1, 2 or 3.
In each operation, you can remove an element from nums.
Return the minimum number of operations to make nums non-decreasing.

Example 1:

Input: nums = [2,1,3,2,1]

Output: 3

Explanation:

One of the optimal solutions is to remove nums[0], nums[2] and nums[3].

Example 2:

Input: nums = [1,3,2,1,3,3]

Output: 2

Explanation:

One of the optimal solutions is to remove nums[1] and nums[2].

Example 3:

Input: nums = [2,2,2,2,3,3]

Output: 0

Explanation:

nums is already non-decreasing.

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 3

Follow-up: Can you come up with an algorithm that runs in O(n) time complexity?

Hint 1
The problem asks to change the array nums to make it sorted (i.e., all the 1s are on the left of 2s, and all the 2s are on the left of 3s.).

Hint 2
We can try all the possibilities to make nums indices range in [0, i) to 0 and [i, j) to 1 and [j, n) to 2.
Note the ranges are left-close and right-open; each might be empty. Namely, 0 <= i <= j <= n.

Hint 3
Count the changes we need for each possibility by comparing the expected and original values at each index position.

*/

package main

func main() {
	assert(ops([]int{2, 1, 3, 2, 1}) == 3)
	assert(ops([]int{1, 3, 2, 1, 3, 3}) == 2)
	assert(ops([]int{2, 2, 2, 2, 3, 3}) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func ops(a []int) int {
	n := len(a)
	if n == 0 {
		return 0
	}

	p := make([]int, n)
	for _, x := range a {
		p[x-1] += 1
		for i := x; i < n; i++ {
			p[i] = max(p[i], p[i-1])
		}
	}
	return n - p[n-1]
}
