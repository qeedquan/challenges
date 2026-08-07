/*

On a social network consisting of m users and some friendships between users, two users can communicate with each other if they know a common language.

You are given an integer n, an array languages, and an array friendships where:

There are n languages numbered 1 through n,
languages[i] is the set of languages the i user knows, and
friendships[i] = [ui, vi] denotes a friendship between the users ui and vi.
You can choose one language and teach it to some users so that all friends can communicate with each other. Return the minimum number of users you need to teach.

Note that friendships are not transitive, meaning if x is a friend of y and y is a friend of z, this doesn't guarantee that x is a friend of z.

Example 1:

Input: n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]]
Output: 1
Explanation: You can either teach user 1 the second language or user 2 the first language.

Example 2:

Input: n = 3, languages = [[2],[1,3],[1,2],[3]], friendships = [[1,4],[1,2],[3,4],[2,3]]
Output: 2
Explanation: Teach the third language to users 1 and 3, yielding two users to teach.


Constraints:

2 <= n <= 500
languages.length == m
1 <= m <= 500
1 <= languages[i].length <= n
1 <= languages[i][j] <= n
1 <= ui < vi <= languages.length
1 <= friendships.length <= 500
All tuples (ui, vi) are unique
languages[i] contains only unique values

*/

package main

import (
	"slices"
)

func main() {
	assert(teachings(2, [][]int{{1}, {2}, {1, 2}}, [][2]int{{1, 2}, {1, 3}, {1, 2}}) == 1)
	assert(teachings(3, [][]int{{2}, {1, 3}, {1, 2}, {3}}, [][2]int{{1, 4}, {1, 2}, {3, 4}, {2, 3}}) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func teachings(n int, l [][]int, f [][2]int) int {
	s := map[int]bool{}
	for _, e := range f {
		u, v := e[0], e[1]
		if !check(l, u, v) {
			s[u], s[v] = true, true
		}
	}

	if len(s) == 0 {
		return 0
	}

	c := make([]int, n+1)
	for u := range s {
		for _, l := range l[u-1] {
			c[l]++
		}
	}
	return len(s) - slices.Max(c)
}

func check(l [][]int, u, v int) bool {
	for _, x := range l[u-1] {
		for _, y := range l[v-1] {
			if x == y {
				return true
			}
		}
	}
	return false
}
