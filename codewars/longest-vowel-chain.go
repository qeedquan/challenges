/*

The vowel substrings in the word codewarriors are o,e,a,io. The longest of these has a length of 2. Given a lowercase string that has alphabetic characters only (both vowels and consonants) and no spaces, return the length of the longest vowel substring. Vowels are any of aeiou.

Good luck!

*/

package main

import (
	"strings"
)

func main() {
	assert(vowelchain("") == 0)
	assert(vowelchain("codewarriors") == 2)
	assert(vowelchain("suoidea") == 3)
	assert(vowelchain("ultrarevolutionariees") == 3)
	assert(vowelchain("strengthlessnesses") == 1)
	assert(vowelchain("cuboideonavicuare") == 2)
	assert(vowelchain("chrononhotonthuooaos") == 5)
	assert(vowelchain("iiihoovaeaaaoougjyaw") == 8)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func vowelchain(s string) int {
	c := 0
	for i := 0; i < len(s); i++ {
		for i < len(s) && !isvowel(s[i]) {
			i++
		}

		n := 0
		for i < len(s) && isvowel(s[i]) {
			i++
			n++
		}
		c = max(c, n)
	}
	return c
}

func isvowel(c byte) bool {
	return strings.IndexByte("aeiouAEIOU", c) >= 0
}
