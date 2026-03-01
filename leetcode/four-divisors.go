/*

Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.

Example 1:

Input: nums = [21,4,7]
Output: 32
Explanation:
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.

Example 2:

Input: nums = [21,21]
Output: 64
Example 3:

Input: nums = [1,2,3,4,5]
Output: 0


Constraints:

1 <= nums.length <= 10^4
1 <= nums[i] <= 10^5

Hint:
Find the divisors of each element in the array.
You only need to loop to the square root of a number to find its divisors.

*/

package main

import (
	"math"
)

func main() {
	assert(fourdivisors([]int{21, 4, 7}) == 32)
	assert(fourdivisors([]int{21, 21}) == 64)
	assert(fourdivisors([]int{1, 2, 3, 4, 5}) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func fourdivisors(a []int) int {
	r := 0
	for _, n := range a {
		d := 0
		l := int(math.Sqrt(float64(n)))
		for i := 2; i <= l; i++ {
			if n%i != 0 {
				continue
			}

			if d == 0 {
				d = i
			} else {
				d = 0
				break
			}
		}

		if d > 0 && d*d < n {
			r += 1 + n + d + n/d
		}
	}
	return r
}
