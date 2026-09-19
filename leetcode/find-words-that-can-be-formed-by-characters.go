/*

You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.

Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
Example 2:

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.


Constraints:

1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
words[i] and chars consist of lowercase English letters.

*/

package main

import "unicode/utf8"

func main() {
	assert(count([]string{"cat", "bt", "hat", "tree"}, "atach") == 6)
	assert(count([]string{"hello", "world", "leetcode"}, "welldonehoneyr") == 10)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func count(s []string, t string) int {
	r := 0
	a := histogram(t)
	for i := range s {
		b := histogram(s[i])
		if check(a, b) {
			r += utf8.RuneCountInString(s[i])
		}
	}
	return r
}

func histogram(s string) map[rune]int {
	m := make(map[rune]int)
	for _, r := range s {
		m[r]++
	}
	return m
}

func check(a, b map[rune]int) bool {
	for k, v := range b {
		if a[k] < v {
			return false
		}
	}
	return true
}
