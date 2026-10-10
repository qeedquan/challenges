/*

Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

Example 1:

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

Example 2:

Input: nums = [1,2,3], k = 0
Output: 0

Constraints:

1 <= nums.length <= 3 * 10^4
1 <= nums[i] <= 1000
0 <= k <= 10^6

Hint 1
For each j, let opt(j) be the smallest i so that nums[i] * nums[i+1] * ... * nums[j] is less than k. opt is an increasing function.

*/

package main

func main() {
	assert(solve([]int{10, 5, 2, 6}, 100) == 8)
	assert(solve([]int{1, 2, 3}, 0) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(nums []int, k int) int {
	if k <= 1 {
		return 0
	}

	res := 0
	start := 0
	prod := 1
	for i, num := range nums {
		prod *= num
		for prod >= k {
			prod /= nums[start]
			start += 1
		}
		res += i - start + 1
	}
	return res
}
