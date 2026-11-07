/*

Description
You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k.
Each minute, you may take either the leftmost character of s, or the rightmost character of s.

Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.

Example 1:

Input: s = "aabaaaacaabc", k = 2
Output: 8
Explanation:
Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
A total of 3 + 5 = 8 minutes is needed.
It can be proven that 8 is the minimum number of minutes needed.

Example 2:

Input: s = "a", k = 1
Output: -1
Explanation: It is not possible to take one 'b' or 'c' so return -1.

Constraints:

1 <= s.length <= 10^5
s consists of only the letters 'a', 'b', and 'c'.
0 <= k <= s.length

*/

package main

func main() {
	assert(take("aabaaaacaabc", 2) == 8)
	assert(take("a", 1) == -1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func take(s string, k int) int {
	h := map[byte]int{'a': 0, 'b': 0, 'c': 0}
	for i := range len(s) {
		h[s[i]]++
	}

	for _, x := range h {
		if x < k {
			return -1
		}
	}

	m, j := 0, 0
	for i := range len(s) {
		for h[s[i]]--; h[s[i]] < k; j++ {
			h[s[j]]++
		}
		m = max(m, i-j+1)
	}
	return len(s) - m
}
