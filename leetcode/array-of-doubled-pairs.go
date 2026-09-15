/*

Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.

Example 1:

Input: arr = [3,1,3,6]
Output: false
Example 2:

Input: arr = [2,1,2,6]
Output: false
Example 3:

Input: arr = [4,-2,2,-4]
Output: true
Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].


Constraints:

2 <= arr.length <= 3 * 10^4
arr.length is even.
-10^5 <= arr[i] <= 10^5

*/

package main

import "sort"

func main() {
	assert(reorderable([]int{3, 1, 3, 6}) == false)
	assert(reorderable([]int{2, 1, 2, 6}) == false)
	assert(reorderable([]int{4, -2, 2, -4}) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func reorderable(a []int) bool {
	c := make(map[int]int)
	for _, x := range a {
		c[x] += 1
	}

	k := []int{}
	for i := range c {
		k = append(k, i)
	}

	sort.Slice(k, func(i, j int) bool {
		return abs(k[i]) < abs(k[j])
	})

	for i := range k {
		if c[i] > c[2*i] {
			return false
		}
		c[2*i] -= c[i]
	}
	return true
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
