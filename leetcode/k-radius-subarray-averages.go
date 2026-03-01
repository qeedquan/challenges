/*

You are given a 0-indexed array nums of n integers, and an integer k.

The k-radius average for a subarray of nums centered at some index i with the radius k is the average of all
elements in nums between the indices i - k and i + k (inclusive).
If there are less than k elements before or after the index i, then the k-radius average is -1.

Build and return an array avgs of length n where avgs[i] is the k-radius average for the subarray centered at index i.

The average of x elements is the sum of the x elements divided by x, using integer division. The integer division truncates toward zero, which means losing its fractional part.

For example, the average of four elements 2, 3, 1, and 5 is (2 + 3 + 1 + 5) / 4 = 11 / 4 = 2.75, which truncates to 2.

Example 1:

Input: nums = [7,4,3,9,1,8,5,2,6], k = 3
Output: [-1,-1,-1,5,4,4,-1,-1,-1]
Explanation:
- avg[0], avg[1], and avg[2] are -1 because there are less than k elements before each index.
- The sum of the subarray centered at index 3 with radius 3 is: 7 + 4 + 3 + 9 + 1 + 8 + 5 = 37.
  Using integer division, avg[3] = 37 / 7 = 5.
- For the subarray centered at index 4, avg[4] = (4 + 3 + 9 + 1 + 8 + 5 + 2) / 7 = 4.
- For the subarray centered at index 5, avg[5] = (3 + 9 + 1 + 8 + 5 + 2 + 6) / 7 = 4.
- avg[6], avg[7], and avg[8] are -1 because there are less than k elements after each index.

Example 2:

Input: nums = [100000], k = 0
Output: [100000]
Explanation:
- The sum of the subarray centered at index 0 with radius 0 is: 100000.
  avg[0] = 100000 / 1 = 100000.

Example 3:

Input: nums = [8], k = 100000
Output: [-1]
Explanation:
- avg[0] is -1 because there are less than k elements before and after index 0.


Constraints:

n == nums.length
1 <= n <= 10^5
0 <= nums[i], k <= 10^5

Hint 1
To calculate the average of a subarray, you need the sum and the K. K is already given. How could you quickly calculate the sum of a subarray?

Hint 2
Use the Prefix Sums method to calculate the subarray sums.

Hint 3
It is possible that the sum of all the elements does not fit in a 32-bit integer type. Be sure to use a 64-bit integer type for the prefix sum array.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{7, 4, 3, 9, 1, 8, 5, 2, 6}, 3, []int{-1, -1, -1, 5, 4, 4, -1, -1, -1})
	test([]int{100000}, 0, []int{100000})
	test([]int{8}, 100000, []int{-1})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []int, k int, r []int) {
	p := averages(a, k)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func averages(a []int, k int) []int {
	t := 0
	l := 2*k + 1
	r := make([]int, len(a))
	for i := range r {
		r[i] = -1
	}
	for i := range a {
		t += a[i]
		if i-l >= 0 {
			t -= a[i-l]
		}
		if i >= l-1 {
			r[i-k] = t / l
		}
	}
	return r
}
