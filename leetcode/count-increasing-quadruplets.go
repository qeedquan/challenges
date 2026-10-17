/*

Given a 0-indexed integer array nums of size n containing all numbers from 1 to n, return the number of increasing quadruplets.

A quadruplet (i, j, k, l) is increasing if:

0 <= i < j < k < l < n, and
nums[i] < nums[k] < nums[j] < nums[l].


Example 1:

Input: nums = [1,3,2,4,5]
Output: 2
Explanation:
- When i = 0, j = 1, k = 2, and l = 3, nums[i] < nums[k] < nums[j] < nums[l].
- When i = 0, j = 1, k = 2, and l = 4, nums[i] < nums[k] < nums[j] < nums[l].
There are no other quadruplets, so we return 2.

Example 2:

Input: nums = [1,2,3,4]
Output: 0
Explanation: There exists only one quadruplet with i = 0, j = 1, k = 2, l = 3, but since nums[j] < nums[k], we return 0.


Constraints:

4 <= nums.length <= 4000
1 <= nums[i] <= nums.length
All the integers of nums are unique. nums is a permutation.

Hint 1
Can you loop over all possible (j, k) and find the answer?

Hint 2
We can pre-compute all possible (i, j) and (k, l) and store them in 2 matrices.

Hint 3
The answer will the sum of prefix[j][k] * suffix[k][j].

*/

package main

func main() {
	assert(count([]int{1, 3, 2, 4, 5}) == 2)
	assert(count([]int{1, 2, 3, 4}) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func count(a []int) int {
	n := len(a)
	f := make([][]int, n)
	g := make([][]int, n)
	for i := range n {
		f[i] = make([]int, n)
		g[i] = make([]int, n)
	}

	for j := 1; j < n-2; j++ {
		c := 0
		for l := j + 1; l < n; l++ {
			if a[l] > a[j] {
				c++
			}
		}
		for k := j + 1; k < n-1; k++ {
			if a[j] > a[k] {
				f[j][k] = c
			} else {
				c--
			}
		}
	}

	r := 0
	for k := 2; k < n-1; k++ {
		c := 0
		for i := 0; i < k; i++ {
			if a[i] < a[k] {
				c++
			}
		}
		for j := k - 1; j > 0; j-- {
			if a[j] > a[k] {
				g[j][k] = c
				r += f[j][k] * g[j][k]
			} else {
				c--
			}
		}
	}
	return r
}
