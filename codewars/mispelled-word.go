/*

Create a function mispelled(word1, word2):

mispelled("versed", "xersed"); // returns true
mispelled("versed", "applb"); // returns false
mispelled("versed", "v5rsed"); // returns true
mispelled("1versed", "versed"); // returns true
mispelled("versed", "versed"); // returns true

It checks if the word2 differs from word1 by at most one character.

This can include an extra char at the end or the beginning of either of words.

In the tests that expect true, the mispelled word will always differ mostly by one character. If the two words are the same, return True.

*/

package main

import "strings"

func main() {
	assert(mispelled("versed", "xersed") == true)
	assert(mispelled("versed", "applb") == false)
	assert(mispelled("versed", "v5rsed") == true)
	assert(mispelled("1versed", "versed") == true)
	assert(mispelled("versed", "versed") == true)
	assert(mispelled("versed", "aversed") == true)
	assert(mispelled("aaversed", "versed") == false)
	assert(mispelled("versed", "aaversed") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func mispelled(w1, w2 string) bool {
	r1 := []rune(w1)
	r2 := []rune(w2)
	n1 := len(r1)
	n2 := len(r2)
	if abs(n1-n2) == 1 && (strings.Index(w2, w1) >= 0 || strings.Index(w1, w2) >= 0) {
		return true
	}

	n := min(n1, n2)
	c := 0
	for i := 0; i < n && c < 2; i++ {
		if w1[i] != w2[i] {
			c++
		}
	}
	return c < 2
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
