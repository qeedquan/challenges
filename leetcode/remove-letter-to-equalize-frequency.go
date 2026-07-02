/*

You are given a 0-indexed string word, consisting of lowercase English letters. You need to select one index and remove the letter at that index from word so that the frequency of every letter present in word is equal.

Return true if it is possible to remove one letter so that the frequency of all letters in word are equal, and false otherwise.

Note:

The frequency of a letter x is the number of times it occurs in the string.
You must remove exactly one letter and cannot chose to do nothing.


Example 1:

Input: word = "abcc"
Output: true
Explanation: Select index 3 and delete it: word becomes "abc" and each character has a frequency of 1.
Example 2:

Input: word = "aazz"
Output: false
Explanation: We must delete a character, so either the frequency of "a" is 1 and the frequency of "z" is 2, or vice versa. It is impossible to make all present letters have equal frequency.


Constraints:

2 <= word.length <= 100
word consists of lowercase English letters only.

Hint:
Brute force all letters that could be removed.
Use a frequency array of size 26.

*/

package main

func main() {
	assert(equalizable("abcc") == true)
	assert(equalizable("aazz") == false)
	assert(equalizable("aa") == true)
	assert(equalizable("abcd") == true)
	assert(equalizable("tazeman") == true)
	assert(equalizable("xxxyyz") == false)
	assert(equalizable("abccee") == false)
	assert(equalizable("aaaaabbbbbp") == true)
	assert(equalizable("") == false)
	assert(equalizable("xyyz") == true)
	assert(equalizable("xyyzz") == true)
	assert(equalizable("xxxxyyzz") == false)
	assert(equalizable("q") == true)
	assert(equalizable("qqqqqqqqqqqqqqqqqqqq") == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func equalizable(s string) bool {
	h := make(map[rune]int)
	for _, r := range s {
		h[r]++
	}

	for r := range h {
		h[r]--
		if same(h) {
			return true
		}
		h[r]++
	}
	return false
}

func same(f map[rune]int) bool {
	x := -1
	for _, v := range f {
		if v == 0 {
			continue
		}
		if x < 0 {
			x = v
		}
		if x != v {
			return false
		}
	}
	return true
}
