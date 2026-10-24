/*

Implement String#digit? (in Java StringUtils.isDigit(String)), which should return true if given object is a digit (0-9), false otherwise.

*/

package main

import (
	"regexp"
)

func main() {
	assert(isdigit("") == false)
	assert(isdigit("7") == true)
	assert(isdigit(" ") == false)
	assert(isdigit("a") == false)
	assert(isdigit("a5") == false)
	assert(isdigit("14") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func isdigit(s string) bool {
	m, _ := regexp.MatchString(`^\d$`, s)
	return m
}
