/*

You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:

horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts.
Since the answer can be a large number, return this modulo 109 + 7.

Example 1:
https://assets.leetcode.com/uploads/2020/05/14/leetcode_max_area_2.png
Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
Output: 4
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green piece of cake has the maximum area.

Example 2:
https://assets.leetcode.com/uploads/2020/05/14/leetcode_max_area_3.png
Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
Output: 6
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green and yellow pieces of cake have the maximum area.

Example 3:

Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
Output: 9

Constraints:

2 <= h, w <= 109
1 <= horizontalCuts.length <= min(h - 1, 105)
1 <= verticalCuts.length <= min(w - 1, 105)
1 <= horizontalCuts[i] < h
1 <= verticalCuts[i] < w
All the elements in horizontalCuts are distinct.
All the elements in verticalCuts are distinct.

Hint 1
Sort the arrays, then compute the maximum difference between two consecutive elements for horizontal cuts and vertical cuts.

Hint 2
The answer is the product of these maximum values in horizontal cuts and vertical cuts.

*/

package main

import "sort"

func main() {
	assert(maxarea(5, 4, []int{1, 2, 4}, []int{1, 3}) == 4)
	assert(maxarea(5, 4, []int{3, 1}, []int{1}) == 6)
	assert(maxarea(5, 4, []int{3}, []int{3}) == 9)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func maxarea(h, w int, x, y []int) int {
	const mod = 1_000_000_007
	return (maxlen(h, x) * maxlen(w, y)) % mod
}

func maxlen(l int, c []int) int {
	n := len(c)
	if n == 0 {
		return 0
	}

	sort.Ints(c)

	l = max(c[0], l-c[n-1])
	for i := 1; i < n; i++ {
		l = max(l, c[i]-c[i-1])
	}
	return l
}
