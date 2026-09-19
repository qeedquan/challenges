/*

You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there
are exactly x numbers in nums that are greater than or equal to x.

Notice that x does not have to be an element in nums.

Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.

Example 1:

Input: nums = [3,5]
Output: 2
Explanation: There are 2 values (3 and 5) that are greater than or equal to 2.

Example 2:

Input: nums = [0,0]
Output: -1
Explanation: No numbers fit the criteria for x.
If x = 0, there should be 0 numbers >= x, but there are 2.
If x = 1, there should be 1 number >= x, but there are 0.
If x = 2, there should be 2 numbers >= x, but there are 0.
x cannot be greater since there are only 2 numbers in nums.

Example 3:

Input: nums = [0,4,3,0,4]
Output: 3
Explanation: There are 3 values that are greater than or equal to 3.


Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000

Hint 1
Count the number of elements greater than or equal to x for each x in the range [0, nums.length].

Hint 2
If for any x, the condition satisfies, return that x. Otherwise, there is no answer.

*/

package main

import (
	"math"
)

func main() {
	assert(special([]int{3, 5}) == 2)
	assert(special([]int{0, 0}) == -1)
	assert(special([]int{0, 4, 3, 0, 4}) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func special(a []int) int {
	c := make(map[int]int)
	m := math.MinInt
	for _, x := range a {
		c[x], m = c[x]+1, max(m, x)
	}

	n := len(a)
	for i := range m + 1 {
		if i == n {
			return i
		}
		n -= c[i]
	}
	return -1
}
