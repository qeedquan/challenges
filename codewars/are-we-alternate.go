/*

Create a function isAlt() that accepts a string as an argument and validates whether the vowels (a, e, i, o, u) and consonants are in alternate order.

isAlt("amazon")
// true
isAlt("apple")
// false
isAlt("banana")
// true
Arguments consist of only lowercase letters.

*/

package main

import "regexp"

func main() {
	assert(isalt("amazon") == true)
	assert(isalt("apple") == false)
	assert(isalt("banana") == true)
	assert(isalt("pump") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func isalt(s string) bool {
	m, _ := regexp.MatchString("^[aeiou]?([^aeiou][aeiou])*[^aeiou]?$", s)
	return m
}
