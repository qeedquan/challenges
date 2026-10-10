/*

Implement the function which should return true if given object is a vowel (meaning a, e, i, o, u, uppercase or lowercase), and false otherwise.

*/

package main

import "regexp"

func main() {
	assert(vowel.MatchString("a") == true)
	assert(vowel.MatchString("e") == true)
	assert(vowel.MatchString("i") == true)
	assert(vowel.MatchString("o") == true)
	assert(vowel.MatchString("u") == true)
	assert(vowel.MatchString("A") == true)
	assert(vowel.MatchString("E") == true)
	assert(vowel.MatchString("I") == true)
	assert(vowel.MatchString("O") == true)
	assert(vowel.MatchString("U") == true)

	assert(vowel.MatchString("aeiou") == false)
	assert(vowel.MatchString("AEIOU") == false)
	assert(vowel.MatchString("") == false)
	assert(vowel.MatchString("12345") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

var vowel = regexp.MustCompile(`^[aeouiAEIOU]$`)
