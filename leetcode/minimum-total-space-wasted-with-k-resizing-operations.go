/*

You are currently designing a dynamic array. You are given a 0-indexed integer array nums, where nums[i] is the number of elements that will be in the array at time i.
In addition, you are given an integer k, the maximum number of times you can resize the array (to any size).

The size of the array at time t, sizet, must be at least nums[t] because there needs to be enough space in the array to hold all the elements.
The space wasted at time t is defined as sizet - nums[t], and the total space wasted is the sum of the space wasted across every time t where 0 <= t < nums.length.

Return the minimum total space wasted if you can resize the array at most k times.

Note: The array can have any size at the start and does not count towards the number of resizing operations.

Example 1:

Input: nums = [10,20], k = 0
Output: 10
Explanation: size = [20,20].
We can set the initial size to be 20.
The total wasted space is (20 - 10) + (20 - 20) = 10.

Example 2:

Input: nums = [10,20,30], k = 1
Output: 10
Explanation: size = [20,20,30].
We can set the initial size to be 20 and resize to 30 at time 2.
The total wasted space is (20 - 10) + (20 - 20) + (30 - 30) = 10.

Example 3:

Input: nums = [10,20,15,30,20], k = 2
Output: 15
Explanation: size = [10,20,20,30,30].
We can set the initial size to 10, resize to 20 at time 1, and resize to 30 at time 3.
The total wasted space is (10 - 10) + (20 - 20) + (20 - 15) + (30 - 30) + (30 - 20) = 15.

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 106
0 <= k <= nums.length - 1

Hint 1
Given a range, how can you find the minimum waste if you can't perform any resize operations?

Hint 2
Can we build our solution using dynamic programming using the current index and the number of resizing operations performed as the states?

*/

package main

import "math"

func main() {
	assert(wasted([]int{10, 20}, 0) == 10)
	assert(wasted([]int{10, 20, 30}, 1) == 10)
	assert(wasted([]int{10, 20, 15, 30, 20}, 2) == 15)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func wasted(a []int, k int) int {
	k += 1
	n := len(a)
	p := make([][]int, n+1)
	for i := range p {
		p[i] = make([]int, k+1)
		for j := range p[i] {
			p[i][j] = math.MaxInt
		}
	}

	p[0][0] = 0
	for i := 1; i <= n; i++ {
		t := 0
		z := 0
		for j := i; j >= 1; j-- {
			t += a[j-1]
			z = max(z, a[j-1])
			for m := 1; m <= k; m++ {
				if p[j-1][m-1] != math.MaxInt {
					p[i][m] = min(p[i][m], p[j-1][m-1]+(z*(i-j+1)-t))
				}
			}
		}
	}
	return p[n][k]
}
