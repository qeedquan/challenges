package main

import "regexp"

func main() {
	assert(PASCAL.MatchString("1.2") == true)
	assert(PASCAL.MatchString("1.") == false)
	assert(PASCAL.MatchString("1.0e-55") == true)
	assert(PASCAL.MatchString("e-12") == false)
	assert(PASCAL.MatchString("6.5E") == false)
	assert(PASCAL.MatchString("1e-12") == true)
	assert(PASCAL.MatchString("+4.1234567890E-99999") == true)
	assert(PASCAL.MatchString("7.6e+12.5") == false)
	assert(PASCAL.MatchString("99") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

var PASCAL = regexp.MustCompile("^[-+]?\\d+(\\.\\d+([eE][-+]?\\d+)?|[eE][-+]?\\d+)$")
