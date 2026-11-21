/*

Given a string s, you need to partition it into one or more balanced substrings.
For example, if s == "ababcc" then ("abab", "c", "c"), ("ab", "abc", "c"), and ("ababcc") are all valid partitions,
but ("a", "bab", "cc"), ("aba", "bc", "c"), and ("ab", "abcc") are not. The unbalanced substrings are bolded.

Return the minimum number of substrings that you can partition s into.

Note: A balanced string is a string where each character in the string occurs the same number of times.

Example 1:

Input: s = "fabccddg"

Output: 3

Explanation:

We can partition the string s into 3 substrings in one of the following ways: ("fab, "ccdd", "g"), or ("fabc", "cd", "dg").

Example 2:

Input: s = "abababaccddb"

Output: 2

Explanation:

We can partition the string s into 2 substrings like so: ("abab", "abaccddb").

Constraints:

1 <= s.length <= 1000
s consists only of English lowercase letters.

Hint 1
Let dp[i] be the minimum number of partitions for the prefix ending at index i + 1.

Hint 2
dp[i] can be calculated as the min(dp[j]) over all j such that j < i and word[j+1…i] is valid.

*/

package main

import "math"

func main() {
	assert(substrings("fabccddg") == 3)
	assert(substrings("abababaccddb") == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func substrings(s string) int {
	n := len(s)
	p := make([]int, n+1)
	for i := 1; i <= n; i++ {
		p[i] = math.MaxInt
	}

	for i := 0; i < n; i++ {
		c := make(map[byte]int)
		d := 0
		m := 0
		for j := i; j >= 0; j-- {
			k := s[j]
			if c[k]++; c[k] == 1 {
				d++
			}
			m = max(m, c[k])
			if d*m == i-j+1 && p[j] != math.MaxInt {
				p[i+1] = min(p[i+1], p[j]+1)
			}
		}
	}

	return p[n]
}
