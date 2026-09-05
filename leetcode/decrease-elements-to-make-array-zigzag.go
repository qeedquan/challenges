/*

Given an array nums of integers, a move consists of choosing any element and decreasing it by 1.

An array A is a zigzag array if either:

    Every even-indexed element is greater than adjacent elements, ie. A[0] > A[1] < A[2] > A[3] < A[4] > ...
    OR, every odd-indexed element is greater than adjacent elements, ie. A[0] < A[1] > A[2] < A[3] > A[4] < ...

Return the minimum number of moves to transform the given array nums into a zigzag array.

Example 1:

Input: nums = [1,2,3]
Output: 2
Explanation: We can decrease 2 to 0 or 3 to 1.

Example 2:

Input: nums = [9,6,1,6,2]
Output: 4

Constraints:

    1 <= nums.length <= 1000
    1 <= nums[i] <= 1000

Hint 1
Do each case (even indexed is greater, odd indexed is greater) separately.
In say the even case, you should decrease each even-indexed element until it is lower than its immediate neighbors.

*/

package main

import "math"

func main() {
	assert(zigzagify([]int{1, 2, 3}) == 2)
	assert(zigzagify([]int{9, 6, 1, 6, 2}) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func zigzagify(a []int) int {
	v := [2]int{}
	for i := range a {
		l := math.MaxInt
		r := math.MaxInt
		if i-1 >= 0 {
			l = a[i-1]
		}
		if i+1 < len(a) {
			r = a[i+1]
		}
		v[i&1] += max(a[i]-min(l, r)+1, 0)
	}
	return min(v[0], v[1])
}
