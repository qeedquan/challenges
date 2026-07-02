/*

Task
The string is called prime if it cannot be constructed by concatenating some (more than one) equal strings together.

For example, "abac" is prime, but "xyxy" is not("xyxy"="xy"+"xy").

Given a string determine if it is prime or not.

Input/Output
[input] string s
string containing only lowercase English letters

[output] a boolean value
true if the string is prime, false otherwise

*/

package main

import "strings"

func main() {
	assert(primestring("abac") == true)
	assert(primestring("xyxy") == false)
	assert(primestring("abab") == false)
	assert(primestring("aaaa") == false)
	assert(primestring("x") == true)
	assert(primestring("abc") == true)
	assert(primestring("fdsyffdsyffdsyffdsyffdsyf") == false)
	assert(primestring("utdutdtdutd") == true)
	assert(primestring("abba") == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func primestring(s string) bool {
	return strings.Index((s + s)[1:], s) == len(s)-1
}
