/*

Given a 0-indexed integer array nums, return true if it can be made strictly increasing after removing exactly one element, or false otherwise. If the array is already strictly increasing, return true.

The array nums is strictly increasing if nums[i - 1] < nums[i] for each index (1 <= i < nums.length).

Example 1:

Input: nums = [1,2,10,5,7]
Output: true
Explanation: By removing 10 at index 2 from nums, it becomes [1,2,5,7].
[1,2,5,7] is strictly increasing, so return true.

Example 2:

Input: nums = [2,3,1,2]
Output: false
Explanation:
[3,1,2] is the result of removing the element at index 0.
[2,1,2] is the result of removing the element at index 1.
[2,3,2] is the result of removing the element at index 2.
[2,3,1] is the result of removing the element at index 3.
No resulting array is strictly increasing, so return false.

Example 3:

Input: nums = [1,1,1]
Output: false
Explanation: The result of removing any element is [1,1].
[1,1] is not strictly increasing, so return false.


Constraints:

2 <= nums.length <= 1000
1 <= nums[i] <= 1000

Hint 1
For each index i in nums remove this index.

Hint 2
If the array becomes sorted return true, otherwise revert to the original array and try different index.

*/

package main

func main() {
	assert(increasable([]int{1, 2, 10, 5, 7}) == true)
	assert(increasable([]int{2, 3, 1, 2}) == false)
	assert(increasable([]int{1, 1, 1}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func increasable(numbers []int) bool {
	deleted := false
	for i := 1; i < len(numbers); i++ {
		if numbers[i] > numbers[i-1] {
			continue
		}

		if deleted {
			return false
		}
		deleted = true

		if i >= 2 && numbers[i-2] > numbers[i] {
			numbers[i] = numbers[i-1]
		}
	}
	return true
}
