/*

From any string, we can form a subsequence of that string by deleting some number of characters (possibly no deletions).

Given two strings source and target, return the minimum number of subsequences of source such that their concatenation equals target. If the task is impossible, return -1.

Example 1:
Input: source = "abc", target = "abcbc"
Output: 2
Explanation: The target "abcbc" can be formed by "abc" and "bc", which are subsequences of source "abc".

Example 2:
Input: source = "abc", target = "acdbc"
Output: -1
Explanation: The target string cannot be constructed from the subsequences of source string due to the character "d" in target string.

Example 3:
Input: source = "xyz", target = "xzyxz"
Output: 3
Explanation: The target string can be constructed as follows "xz" + "y" + "xz".

Constraints:

Both the source and target strings consist of only lowercase English letters from "a"-"z".
The lengths of source and target string are between 1 and 1000.

*/

package main

func main() {
	assert(shortest("abc", "abcbc") == 2)
	assert(shortest("abc", "acdbc") == -1)
	assert(shortest("xyz", "xzyxz") == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func shortest(s, t string) int {
	r, m, n := 0, len(s), len(t)
	for j := 0; j < n; r++ {
		f := false
		for i := 0; i < m && j < n; i++ {
			if s[i] == t[j] {
				f, j = true, j+1
			}
		}
		if !f {
			return -1
		}
	}
	return r
}
