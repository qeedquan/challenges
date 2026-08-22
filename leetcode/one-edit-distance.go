/*

Given two strings s and t, determine if they are both one edit distance apart.

Note:

There are 3 possiblities to satisify one edit distance apart:

Insert a character into s to get t
Delete a character from s to get t
Replace a character of s to get t
Example 1:

Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.
Example 2:

Input: s = "cab", t = "ad"
Output: false
Explanation: We cannot get t from s by only one step.
Example 3:

Input: s = "1203", t = "1213"
Output: true
Explanation: We can replace '0' with '1' to get t.

*/

package main

func main() {
	assert(oneedit("ab", "acb") == true)
	assert(oneedit("cab", "ad") == false)
	assert(oneedit("1203", "1213") == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func oneedit(s, t string) bool {
	m, n := len(s), len(t)
	if m > n {
		s, t = t, s
		m, n = n, m
	}

	if n-m > 1 {
		return false
	}

	p := n - m
	i := 0
	for i < m && s[i] == t[i] {
		i++
	}
	if p == 0 {
		i++
	}
	for i < m && s[i] == t[i+p] {
		i++
	}

	return i == m
}
