/*

The title says it all; Given a number in the binary (base-2) number system, output the same number expressed in unary (base-1).

You may use any reasonable input and output format, i.e. strings, list of characters / digits, etc. You can use any digits you like to represent the binary and unary numbers. You may choose to assume that the binary number will have no more than 8 bits, and/or that it will always be left-padded with zeroes to a certain length.

One method you may use to achieve this task is documented at this esolangs.org article:

Replace all 1s with 0* (Using * as the unary digit; you may use any character.)
Replace all *0s with 0**.
Remove all 0s.

Examples:

1001 → *********
1010 → **********
00111111 → ***************************************************************

This is code-golf, so the shortest answer in each language wins.

*/

package main

import (
	"strings"
)

func main() {
	assert(bin2un("1001") == "*********")
	assert(bin2un("1010") == "**********")
	assert(bin2un("00111111") == "***************************************************************")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func bin2un(s string) string {
	s = replace(s, "1", "0*")
	s = replace(s, "*0", "0**")
	s = replace(s, "0", "")
	return s
}

func replace(s, old, new string) string {
	for {
		t := strings.Replace(s, old, new, -1)
		if s == t {
			break
		}
		s = t
	}
	return s
}
