/*

Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4

Constraints:

1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.

*/

package main

func main() {
	assert(distance("sea", "eat") == 2)
	assert(distance("leetcode", "etco") == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func distance(s, t string) int {
	m := len(s)
	n := len(t)
	p := [2][]int{}
	for i := range p {
		p[i] = make([]int, n+1)
	}
	for i := range m {
		for j := range n {
			i0 := i % 2
			i1 := (i + 1) % 2
			p[i1][j+1] = max(p[i0][j+1], p[i1][j], p[i0][j]+truth(s[i] == t[j]))
		}
	}
	return m + n - 2*p[m%2][n]
}

func truth(x bool) int {
	if x {
		return 1
	}
	return 0
}
