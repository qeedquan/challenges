/*

Given an integer array arr and a target value target, return the integer value such that when we change all the integers larger than value in the given array to be equal to value, the sum of the array gets as close as possible (in absolute difference) to target.

In case of a tie, return the minimum such integer.

Notice that the answer is not neccesarilly a number from arr.

Example 1:

Input: arr = [4,9,3], target = 10
Output: 3
Explanation: When using 3 arr converts to [3, 3, 3] which sums 9 and that's the optimal answer.

Example 2:

Input: arr = [2,3,5], target = 10
Output: 5

Example 3:

Input: arr = [60864,25176,27249,21296,20204], target = 56803
Output: 11361


Constraints:

1 <= arr.length <= 10^4
1 <= arr[i], target <= 10^5

Hint:
If you draw a graph with the value on one axis and the absolute difference between the target and the array sum, what will you get?
That graph is uni-modal.
Use ternary search on that graph to find the best value.

*/

package main

import (
	"math"
	"sort"
)

func main() {
	assert(best([]int{4, 9, 3}, 10) == 3)
	assert(best([]int{2, 3, 5}, 10) == 5)
	assert(best([]int{60864, 25176, 27249, 21296, 20204}, 56803) == 11361)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func best(a []int, t int) int {
	n := len(a)
	if n == 0 {
		return 0
	}

	sort.Ints(a)

	p := 0
	for i, v := range a {
		r := int(math.Round(float64(t-p) / float64(n-i)))
		if r <= v {
			return r
		}
		p += v
	}
	return a[n-1]
}
