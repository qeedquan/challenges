/*

We can scramble a string s to get a string t using the following algorithm:

If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.

Example 1:

Input: s1 = "great", s2 = "rgeat"
Output: true
Explanation: One possible scenario applied on s1 is:
"great" --> "gr/eat" // divide at random index.
"gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
"gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at random index each of them.
"g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
"r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
"r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
The algorithm stops now, and the result string is "rgeat" which is s2.
As one possible scenario led s1 to be scrambled to s2, we return true.

Example 2:

Input: s1 = "abcde", s2 = "caebd"
Output: false
Example 3:

Input: s1 = "a", s2 = "a"
Output: true

Constraints:

s1.length == s2.length
1 <= s1.length <= 30
s1 and s2 consist of lowercase English letters.

*/

package main

func main() {
	assert(scramble("great", "rgeat") == true)
	assert(scramble("abcde", "caebd") == false)
	assert(scramble("a", "a") == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func scramble(s1, s2 string) bool {
	if len(s1) != len(s2) || len(s1) == 0 || len(s2) == 0 {
		return false
	}
	if s1 == s2 {
		return true
	}

	n := len(s1)
	p := make([][][]bool, n+1)
	for i := range p {
		p[i] = make([][]bool, n)
		for j := range p[i] {
			p[i][j] = make([]bool, n)
		}
	}

	for i := range n {
		for j := range n {
			p[1][i][j] = (s1[i] == s2[j])
		}
	}

	for k := 2; k <= n; k++ {
		for i := 0; i < n-k+1; i++ {
			for j := 0; j < n-k+1; j++ {
				p[k][i][j] = false
				for d := 1; d < k && !p[k][i][j]; d++ {
					p[k][i][j] = (p[d][i][j] && p[k-d][i+d][j+d]) || (p[d][i][j+k-d] && p[k-d][i+d][j])
				}
			}
		}
	}

	return p[n][0][0]
}
