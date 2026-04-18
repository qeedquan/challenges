/*

You are given an array nums consisting of positive integers.

Starting with score = 0, apply the following algorithm:

Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
Add the value of the chosen integer to score.
Mark the chosen element and its two adjacent elements if they exist.
Repeat until all the array elements are marked.
Return the score you get after applying the above algorithm.

Example 1:

Input: nums = [2,1,3,4,5,2]
Output: 7
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,1,3,4,5,2].
- 2 is the smallest unmarked element, so we mark it and its left adjacent element: [2,1,3,4,5,2].
- 4 is the only remaining unmarked element, so we mark it: [2,1,3,4,5,2].
Our score is 1 + 2 + 4 = 7.

Example 2:

Input: nums = [2,3,5,1,3,2]
Output: 5
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,3,5,1,3,2].
- 2 is the smallest unmarked element, since there are two of them, we choose the left-most one, so we mark the one at index 0 and its right adjacent element: [2,3,5,1,3,2].
- 2 is the only remaining unmarked element, so we mark it: [2,3,5,1,3,2].
Our score is 1 + 2 + 2 = 5.

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^6

Hint 1
Try simulating the process of marking the elements and their adjacent.

Hint 2
If there is an element that was already marked, then you skip it.

*/

package main

import (
	"sort"
)

func main() {
	assert(findscore([]int{2, 1, 3, 4, 5, 2}) == 7)
	assert(findscore([]int{2, 3, 5, 1, 3, 2}) == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func findscore(numbers []int) int {
	indices := make([]int, len(numbers))
	for i := range indices {
		indices[i] = i
	}

	sort.Slice(indices, func(i, j int) bool {
		x := indices[i]
		y := indices[j]
		if numbers[x] == numbers[y] {
			return x < y
		}
		return numbers[x] < numbers[y]
	})

	seen := make([]bool, len(numbers))
	result := 0
	for _, i := range indices {
		if seen[i] {
			continue
		}
		seen[i] = true
		if i-1 >= 0 {
			seen[i-1] = true
		}
		if i+1 < len(seen) {
			seen[i+1] = true
		}
		result += numbers[i]
	}
	return result
}
