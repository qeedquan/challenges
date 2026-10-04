/*

You are given an array nums of distinct positive integers. You need to sort the array in increasing order based on the sum of the digits of each number. If two numbers have the same digit sum, the smaller number appears first in the sorted order.

Return the minimum number of swaps required to rearrange nums into this sorted order.

A swap is defined as exchanging the values at two distinct positions in the array.

Example 1:

Input: nums = [37,100]

Output: 1

Explanation:

Compute the digit sum for each integer: [3 + 7 = 10, 1 + 0 + 0 = 1] → [10, 1]
Sort the integers based on digit sum: [100, 37]. Swap 37 with 100 to obtain the sorted order.
Thus, the minimum number of swaps required to rearrange nums is 1.
Example 2:

Input: nums = [22,14,33,7]

Output: 0

Explanation:

Compute the digit sum for each integer: [2 + 2 = 4, 1 + 4 = 5, 3 + 3 = 6, 7 = 7] → [4, 5, 6, 7]
Sort the integers based on digit sum: [22, 14, 33, 7]. The array is already sorted.
Thus, the minimum number of swaps required to rearrange nums is 0.
Example 3:

Input: nums = [18,43,34,16]

Output: 2

Explanation:

Compute the digit sum for each integer: [1 + 8 = 9, 4 + 3 = 7, 3 + 4 = 7, 1 + 6 = 7] → [9, 7, 7, 7]
Sort the integers based on digit sum: [16, 34, 43, 18]. Swap 18 with 16, and swap 43 with 34 to obtain the sorted order.
Thus, the minimum number of swaps required to rearrange nums is 2.

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
nums consists of distinct positive integers.

Hint 1
First, sort the array based on digit sum (and value as a tiebreaker). Then, map each original value to its index in the sorted array.

Hint 2
Now, the problem reduces to finding the minimum number of swaps to sort this mapped array. The answer is n - number_of_cycles in the permutation.

*/

package main

import "sort"

func main() {
	assert(swaps([]int{37, 100}) == 1)
	assert(swaps([]int{22, 14, 33, 7}) == 0)
	assert(swaps([]int{18, 43, 34, 16}) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func swaps(a []int) int {
	n := len(a)
	p := make([][2]int, n)
	for i := 0; i < n; i++ {
		p[i][0] = digsum(a[i])
		p[i][1] = a[i]
	}
	sort.Slice(p, func(i, j int) bool {
		if p[i][0] != p[j][0] {
			return p[i][0] < p[j][0]
		}
		return p[i][1] < p[j][1]
	})

	d := make(map[int]int, n)
	for i := range n {
		d[p[i][1]] = i
	}

	v := make([]bool, n)
	r := n
	for i := range n {
		if !v[i] {
			r -= 1
			j := i
			for !v[j] {
				v[j], j = true, d[a[j]]
			}
		}
	}
	return r
}

func digsum(n int) int {
	r := 0
	for ; n > 0; n /= 10 {
		r += n % 10
	}
	return r
}
