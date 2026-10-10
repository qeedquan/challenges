/*

You are given a 0-indexed, strictly increasing integer array nums and a positive integer diff. A triplet (i, j, k) is an arithmetic triplet if the following conditions are met:

i < j < k,
nums[j] - nums[i] == diff, and
nums[k] - nums[j] == diff.
Return the number of unique arithmetic triplets.

Example 1:

Input: nums = [0,1,4,6,7,10], diff = 3
Output: 2
Explanation:
(1, 2, 4) is an arithmetic triplet because both 7 - 4 == 3 and 4 - 1 == 3.
(2, 4, 5) is an arithmetic triplet because both 10 - 7 == 3 and 7 - 4 == 3.
Example 2:

Input: nums = [4,5,6,7,8,9], diff = 2
Output: 2
Explanation:
(0, 2, 4) is an arithmetic triplet because both 8 - 6 == 2 and 6 - 4 == 2.
(1, 3, 5) is an arithmetic triplet because both 9 - 7 == 2 and 7 - 5 == 2.


Constraints:

3 <= nums.length <= 200
0 <= nums[i] <= 200
1 <= diff <= 50
nums is strictly increasing.

Hint:
Are the constraints small enough for brute force?
We can use three loops, each iterating through the array to go through every possible triplet. Be sure to not count duplicates.

*/

package main

func main() {
	assert(triplets([]int{0, 1, 4, 6, 7, 10}, 3) == 2)
	assert(triplets([]int{4, 5, 6, 7, 8, 9}, 2) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func triplets(a []int, d int) int {
	m := make(map[int]bool)
	r := 0
	for _, v := range a {
		if v >= 2*d && m[v-d] && m[v-2*d] {
			r++
		}
		m[v] = true
	}
	return r
}
