/*

Given a string S, return the number of substrings of length K with no repeated characters.

Example 1:

Input: S = "havefunonleetcode", K = 5
Output: 6
Explanation:
There are 6 substrings they are : 'havef','avefu','vefun','efuno','etcod','tcode'.

Example 2:

Input: S = "home", K = 5
Output: 0
Explanation:
Notice K can be larger than the length of S. In this case is not possible to find any substring.

Note:

1 <= S.length <= 10^4
All characters of S are lowercase English letters.
1 <= K <= 10^4

*/

package main

func main() {
	assert(solve("havefunonleetcode", 5) == 6)
	assert(solve("home", 5) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(s string, k int) int {
	r := 0
	m := make(map[byte]bool)
	for i, j := 0, 0; j < len(s); j++ {
		for m[s[j]] {
			delete(m, s[i])
			i += 1
		}
		m[s[j]] = true
		if j-i+1 >= k {
			r += 1
		}
	}
	return r
}
