/*

Given two strings s and t, find the number of ways you can choose a non-empty substring of s and replace a single character by a different character such that the resulting substring is a substring of t. In other words, find the number of substrings in s that differ from some substring in t by exactly one character.

For example, the underlined substrings in "computer" and "computation" only differ by the 'e'/'a', so this is a valid way.

Return the number of substrings that satisfy the condition above.

A substring is a contiguous sequence of characters within a string.

Example 1:

Input: s = "aba", t = "baba"
Output: 6
Explanation: The following are the pairs of substrings from s and t that differ by exactly 1 character:
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
The underlined portions are the substrings that are chosen from s and t.

Example 2:
Input: s = "ab", t = "bb"
Output: 3
Explanation: The following are the pairs of substrings from s and t that differ by 1 character:
("ab", "bb")
("ab", "bb")
("ab", "bb")
The underlined portions are the substrings that are chosen from s and t.

Constraints:

1 <= s.length, t.length <= 100
s and t consist of lowercase English letters only.

Hint 1
Take every substring of s, change a character, and see how many substrings of t match that substring.

Hint 2
Use a Trie to store all substrings of t as a dictionary.

*/

package main

func main() {
	assert(substrings("aba", "baba") == 6)
	assert(substrings("ab", "bb") == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func substrings(s, t string) int {
	c := 0
	for i := range len(s) {
		c += count(s, t, i, 0)
	}
	for j := 1; j < len(t); j++ {
		c += count(s, t, 0, j)
	}
	return c
}

func count(s, t string, i, j int) int {
	c := 0
	l := 0
	r := 0
	for k := range min(len(s)-i, len(t)-j) {
		r += 1
		if s[i+k] != t[j+k] {
			l, r = r, 0
		}
		c += l
	}
	return c
}
