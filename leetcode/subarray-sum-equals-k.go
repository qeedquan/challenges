/*

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2

Example 2:

Input: nums = [1,2,3], k = 3
Output: 2


Constraints:

1 <= nums.length <= 2 * 10^4
-1000 <= nums[i] <= 1000
-10^7 <= k <= 10^7

Hint 1
Will Brute force work here? Try to optimize it.

Hint 2
Can we optimize it by using some extra space?

Hint 3
What about storing sum frequencies in a hash table? Will it be useful?

Hint 4
sum(i,j)=sum(0,j)-sum(0,i), where sum(i,j) represents the sum of all the elements from index i to j-1. Can we use this property to optimize it.

*/

package main

func main() {
	assert(subsum([]int{1, 1, 1}, 2) == 2)
	assert(subsum([]int{1, 2, 3}, 3) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func subsum(a []int, k int) int {
	m := map[int]int{0: 1}
	s := 0
	r := 0
	for _, x := range a {
		s += x
		r += m[s-k]
		m[s] += 1
	}
	return r
}
