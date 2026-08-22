/*

You are given a 0-indexed array of integers nums.

A prefix nums[0..i] is sequential if, for all 1 <= j <= i, nums[j] = nums[j - 1] + 1. In particular, the prefix consisting only of nums[0] is sequential.

Return the smallest integer x missing from nums such that x is greater than or equal to the sum of the longest sequential prefix.

Example 1:

Input: nums = [1,2,3,2,5]
Output: 6
Explanation: The longest sequential prefix of nums is [1,2,3] with a sum of 6. 6 is not in the array, therefore 6 is the smallest missing integer greater than or equal to the sum of the longest sequential prefix.

Example 2:

Input: nums = [3,4,5,1,12,14,13]
Output: 15
Explanation: The longest sequential prefix of nums is [3,4,5] with a sum of 12. 12, 13, and 14 belong to the array while 15 does not. Therefore 15 is the smallest missing integer greater than or equal to the sum of the longest sequential prefix.

Constraints:

    1 <= nums.length <= 50
    1 <= nums[i] <= 50

Hint 1
To find the longest sequential prefix, iterate from left to right. For a fixed i, if nums[i] != nums[i - 1] + 1 then the longest sequential prefix ends at i - 1.

*/

package main

func main() {
	assert(missing([]int{1, 2, 3, 2, 5}) == 6)
	assert(missing([]int{3, 4, 5, 1, 12, 14, 13}) == 15)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func missing(a []int) int {
	if len(a) == 0 {
		return 0
	}

	t := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] != a[i-1]+1 {
			break
		}
		t += a[i]
	}

	m := make(map[int]int)
	for _, v := range a {
		m[v] += 1
	}

	for {
		if _, f := m[t]; f {
			t += 1
		} else {
			break
		}
	}

	return t
}
