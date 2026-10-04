/*

Create a function that returns the lowest product of 4 consecutive digits in a number given as a string.

This should only work if the number has 4 digits or more. If not, return "Number is too small".

Example
lowestProduct("123456789") --> 24 (1x2x3x4)
lowestProduct("35") --> "Number is too small"

*/

package main

import (
	"math"
)

func main() {
	assert(lowestproduct("123456789") == 24)
	assert(lowestproduct("234567899") == 120)
	assert(lowestproduct("2345611117899") == 1)
	assert(lowestproduct("333") == "Number is too small")
	assert(lowestproduct("1234111") == 4)
	assert(lowestproduct("35") == "Number is too small")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func lowestproduct(s string) any {
	if len(s) < 4 {
		return "Number is too small"
	}

	r := math.MaxInt
	for i := 0; i+3 < len(s); i++ {
		p := 1
		for j := range 4 {
			p *= int(s[i+j] - '0')
		}
		r = min(r, p)
	}
	return r
}
