/*

Description
Consider a function that implements an algorithm similar to Binary Search. The function has two input parameters: sequence is a sequence of integers, and target is an integer value. The purpose of the function is to find if the target exists in the sequence.

The pseudocode of the function is as follows:

func(sequence, target)
  while sequence is not empty
    randomly choose an element from sequence as the pivot
    if pivot = target, return true
    else if pivot < target, remove pivot and all elements to its left from the sequence
    else, remove pivot and all elements to its right from the sequence
  end while
  return false
When the sequence is sorted, the function works correctly for all values. When the sequence is not sorted, the function does not work for all values, but may still work for some values.


Given an integer array nums, representing the sequence, that contains unique numbers and may or may not be sorted, return the number of values that are guaranteed to be found using the function, for every possible pivot selection.

Example 1:

Input: nums = [7]

Output: 1

Explanation:

Searching for value 7 is guaranteed to be found.

Since the sequence has only one element, 7 will be chosen as the pivot. Because the pivot equals the target, the function will return true.

Example 2:

Input: nums = [-1,5,2]

Output: 1

Explanation:

Searching for value -1 is guaranteed to be found.

If -1 was chosen as the pivot, the function would return true.

If 5 was chosen as the pivot, 5 and 2 would be removed. In the next loop, the sequence would have only -1 and the function would return true.


If 2 was chosen as the pivot, 2 would be removed. In the next loop, the sequence would have -1 and 5. No matter which number was chosen as the next pivot, the function would find -1 and return true.

Searching for value 5 is NOT guaranteed to be found.

If 2 was chosen as the pivot, -1, 5 and 2 would be removed. The sequence would be empty and the function would return false.

Searching for value 2 is NOT guaranteed to be found.


If 5 was chosen as the pivot, 5 and 2 would be removed. In the next loop, the sequence would have only -1 and the function would return false.

Because only -1 is guaranteed to be found, you should return 1.

Constraints:

1 <= nums.length <= 10^5
-10^5 <= nums[i] <= 10^5
All the values of nums are unique.
Follow-up: If nums has duplicates, would you modify your algorithm? If so, how?

*/

package main

import (
	"math"
)

func main() {
	assert(bsn([]int{7}) == 1)
	assert(bsn([]int{-1, 5, 2}) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func bsn(a []int) int {
	n := len(a)
	if n == 0 {
		return 0
	}

	r := 0
	p := make([]int, n)
	s := make([]int, n)

	p[0] = math.MinInt
	for i := 1; i < n; i++ {
		p[i] = max(p[i-1], a[i-1])
	}

	s[n-1] = math.MaxInt
	for i := n - 2; i >= 0; i-- {
		s[i] = min(s[i+1], a[i+1])
	}

	for i := 0; i < n; i++ {
		if p[i] < a[i] && a[i] < s[i] {
			r++
		}
	}

	return r
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
