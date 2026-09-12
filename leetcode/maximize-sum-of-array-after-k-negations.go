/*

Given an integer array nums and an integer k, modify the array in the following way:

choose an index i and replace nums[i] with -nums[i].
You should apply this process exactly k times. You may choose the same index i multiple times.

Return the largest possible sum of the array after modifying it in this way.

Example 1:

Input: nums = [4,2,3], k = 1
Output: 5
Explanation: Choose index 1 and nums becomes [4,-2,3].

Example 2:

Input: nums = [3,-1,0,2], k = 3
Output: 6
Explanation: Choose indices (1, 2, 2) and nums becomes [3,1,0,2].

Example 3:

Input: nums = [2,-3,-1,5,-4], k = 2
Output: 13
Explanation: Choose indices (1, 4) and nums becomes [2,3,-1,5,4].

Constraints:

1 <= nums.length <= 10^4
-100 <= nums[i] <= 100
1 <= k <= 10^4

*/

package main

import (
	"math"
	"sort"
)

func main() {
	assert(solve([]int{4, 2, 3}, 1) == 5)
	assert(solve([]int{3, -1, 0, 2}, 3) == 6)
	assert(solve([]int{2, -3, -1, 5, -4}, 2) == 13)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a []int, k int) int {
	if len(a) == 0 || k < 1 {
		return 0
	}

	sort.Ints(a)

	r := k
	for i := 0; i < k && a[i] < 0; i++ {
		a[i], r = -a[i], r-1
	}

	s, m := 0, math.MaxInt
	for i := range a {
		s, m = s+a[i], min(m, a[i])
	}

	return s - (r%2)*m*2
}
