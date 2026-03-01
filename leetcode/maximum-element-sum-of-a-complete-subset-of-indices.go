/*

You are given a 1-indexed array nums.
Your task is to select a complete subset from nums where every pair of selected indices multiplied is a perfect square,.
i. e. if you select ai and aj, i * j must be a perfect square.

Return the sum of the complete subset with the maximum sum.

Example 1:

Input: nums = [8,7,3,5,7,2,4,9]

Output: 16

Explanation:

We select elements at indices 2 and 8 and 2 * 8 is a perfect square.

Example 2:

Input: nums = [8,10,3,8,1,13,7,9,4]

Output: 20

Explanation:

We select elements at indices 1, 4, and 9. 1 * 4, 1 * 9, 4 * 9 are perfect squares.

Constraints:

1 <= n == nums.length <= 10^4
1 <= nums[i] <= 10^9

Hint 1
Define P(x) as the product of primes p with odd exponents in x's factorization.
Examples: For x = 18, factorization 21 × 32, P(18) = 2; for x = 45, factorization 32 × 51, P(45) = 5; for x = 50, factorization 21 × 52, P(50) = 2;
for x = 210, factorization 21 × 31 × 51 × 71, P(210) = 210.

Hint 2
If P(i) = P(j), nums[i] and nums[j] can be grouped together.

Hint 3
Pick the group with the largest sum.

*/

package main

func main() {
	assert(maxsum([]int{8, 7, 3, 5, 7, 2, 4, 9}) == 16)
	assert(maxsum([]int{8, 10, 3, 8, 1, 13, 7, 9, 4}) == 20)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://en.wikipedia.org/wiki/Basel_problem
func maxsum(a []int) int {
	r := 0
	for i := 1; i <= len(a); i++ {
		v := 0
		for x := 1; i*x*x-1 < len(a); x++ {
			v += a[i*x*x-1]
		}
		r = max(r, v)
	}
	return r
}
