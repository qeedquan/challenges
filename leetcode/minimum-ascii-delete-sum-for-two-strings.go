/*

Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

Example 1:

Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
Example 2:

Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d] + 101[e] + 101[e] to the sum.
Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.

Constraints:

1 <= s1.length, s2.length <= 1000
s1 and s2 consist of lowercase English letters.

Hint 1
Let dp(i, j) be the answer for inputs s1[i:] and s2[j:].

*/

package main

func main() {
	assert(minimal("sea", "eat") == 231)
	assert(minimal("delete", "leet") == 403)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func minimal(s1, s2 string) int {
	n1 := len(s1)
	n2 := len(s2)
	p := make([][]int, n1+1)
	for i := range p {
		p[i] = make([]int, n2+1)
	}

	for i := 1; i <= n2; i++ {
		p[0][i] = p[0][i-1] + int(s2[i-1])
	}

	for i := 1; i <= n1; i++ {
		p[i][0] = p[i-1][0] + int(s1[i-1])
	}

	for i := 1; i <= n1; i++ {
		for j := 1; j <= n2; j++ {
			if s1[i-1] == s2[j-1] {
				p[i][j] = p[i-1][j-1]
			} else {
				p[i][j] = min(p[i-1][j]+int(s1[i-1]), p[i][j-1]+int(s2[j-1]))
			}
		}
	}
	return p[n1][n2]
}
