/*

You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

Return the length longest chain which can be formed.

You do not need to use up all the given intervals. You can select pairs in any order.

Example 1:

Input: pairs = [[1,2],[2,3],[3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4].

Example 2:

Input: pairs = [[1,2],[7,8],[4,5]]
Output: 3
Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].

Constraints:

n == pairs.length
1 <= n <= 1000
-1000 <= lefti < righti <= 1000

*/

package main

import "sort"

func main() {
	assert(longestchain([][2]int{{1, 2}, {2, 3}, {3, 4}}) == 2)
	assert(longestchain([][2]int{{1, 2}, {7, 8}, {4, 5}}) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func longestchain(p [][2]int) int {
	sort.SliceStable(p, func(i, j int) bool {
		return p[i][1] < p[j][1]
	})

	c := 0
	for i, j := 0, 0; j < len(p); j++ {
		if j == 0 || p[i][1] < p[j][0] {
			c += 1
			i = j
		}
	}
	return c
}
