/*

Write a function that verifies that the provided argument is either an integer or a floating-point number, returning true if it is such or false otherwise.

Validation rules
Numeric quantities are signed (optionally when positive, e. g. "+5" is valid notation)
Floats less than 1 (note: not considering possible exponent) can be written without a leading "0" (e. g. ".00001")
Order-of-magnitude (i.e. 10, 100, 1000, etc.) can be written in E notation [ http://en.wikipedia.org/wiki/Scientific_notation ] (the exponent is also signed, optionally so if positive, e.g. all the following are valid 1e2, 1E2, 1e-2, 1E-2, 1e+2)
Probably obvious, but no spaces are allowed anywhere (we aim to represent a real-life number)
You can mix-n'-match any or all above pointers in any single numeric quantity

*/

package main

import (
	"regexp"
)

func main() {
	assert(regnum.MatchString("19.23") == true)
	assert(regnum.MatchString("-1") == true)
	assert(regnum.MatchString("2") == true)
	assert(regnum.MatchString("+45.6") == true)
	assert(regnum.MatchString("1e2") == true)
	assert(regnum.MatchString("1E2") == true)
	assert(regnum.MatchString("1e-2") == true)
	assert(regnum.MatchString("1E-2") == true)
	assert(regnum.MatchString("1e+2") == true)
	assert(regnum.MatchString("+45.6.2") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

var regnum = regexp.MustCompile(`^[+-]?(?:\d+\.?\d*|\.\d+)(?:[eE][+-]?\d+)?$`)
