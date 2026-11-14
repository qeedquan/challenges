/*

Given 2 integer arrays nums1 and nums2 consisting only of 0 and 1, your task is to calculate the minimum possible largest number in arrays nums1 and nums2, after doing the following.

Replace every 0 with an even positive integer and every 1 with an odd positive integer. After replacement, both arrays should be increasing and each integer should be used at most once.

Return the minimum possible largest number after applying the changes.

Example 1:

Input: nums1 = [], nums2 = [1,0,1,1]

Output: 5

Explanation:

After replacing, nums1 = [], and nums2 = [1, 2, 3, 5].

Example 2:

Input: nums1 = [0,1,0,1], nums2 = [1,0,0,1]

Output: 9

Explanation:

One way to replace, having 9 as the largest element is nums1 = [2, 3, 8, 9], and nums2 = [1, 4, 6, 7].

Example 3:

Input: nums1 = [0,1,0,0,1], nums2 = [0,0,0,1]

Output: 13

Explanation:

One way to replace, having 13 as the largest element is nums1 = [2, 3, 4, 6, 7], and nums2 = [8, 10, 12, 13].

Constraints:

0 <= nums1.length <= 1000
1 <= nums2.length <= 1000
nums1 and nums2 consist only of 0 and 1.

*/

package main

func main() {
	assert(largest([]int{}, []int{1, 0, 1, 1}) == 5)
	assert(largest([]int{0, 1, 0, 1}, []int{1, 0, 0, 1}) == 9)
	assert(largest([]int{0, 1, 0, 0, 1}, []int{0, 0, 0, 1}) == 13)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func largest(a, b []int) int {
	m := len(a)
	n := len(b)
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}

	for i := 1; i <= m; i++ {
		f[i][0] = next(f[i-1][0], a[i-1])
	}
	for j := 1; j <= n; j++ {
		f[0][j] = next(f[0][j-1], b[j-1])
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			x := next(f[i-1][j], a[i-1])
			y := next(f[i][j-1], b[j-1])
			f[i][j] = min(x, y)
		}
	}
	return f[m][n]
}

func next(x, y int) int {
	if (x&1 ^ y) == 1 {
		return x + 1
	}
	return x + 2
}
