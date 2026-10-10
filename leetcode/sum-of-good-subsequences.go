/*

You are given an integer array nums.
A good subsequence is defined as a subsequence of nums where the absolute difference between any two consecutive elements in the subsequence is exactly 1.

Return the sum of all possible good subsequences of nums.

Since the answer may be very large, return it modulo 10^9 + 7.

Note that a subsequence of size 1 is considered good by definition.

Example 1:

Input: nums = [1,2,1]

Output: 14

Explanation:

Good subsequences are: [1], [2], [1], [1,2], [2,1], [1,2,1].
The sum of elements in these subsequences is 14.
Example 2:

Input: nums = [3,4,5]

Output: 40

Explanation:

Good subsequences are: [3], [4], [5], [3,4], [4,5], [3,4,5].
The sum of elements in these subsequences is 40.

Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5

Hint 1
Consider counting how many times each element occurs in all possible good subsequences. This can help you derive the final answer more easily.

Hint 2
Use dynamic programming to track both the count and the sum of subsequences where the last element is nums[i].

*/

package main

func main() {
	assert(goods([]int{1, 2, 1}) == 14)
	assert(goods([]int{3, 4, 5}) == 40)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func goods(a []int) int {
	const mod = 1_000_000_007

	p := make(map[int]int)
	c := make(map[int]int)
	for _, x := range a {
		y := c[x-1] + c[x+1] + 1
		c[x] = (c[x] + y) % mod
		p[x] = (p[x] + p[x-1] + p[x+1] + x*y) % mod
	}

	r := 0
	for _, x := range p {
		r = (r + x) % mod
	}
	return r
}
