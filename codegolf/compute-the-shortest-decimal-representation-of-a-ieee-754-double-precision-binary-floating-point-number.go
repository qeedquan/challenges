/*

Format

The format is a 64 bit value x representing a IEEE-754 double-precision binary floating-point number (a.k.a "a double"). x is assumed to represent a real number (not a NaN or Infinity).

Goal

The goal is to print/output the shortest string containing a decimal representation for which x is the closest IEEE 754 representation. Scientific notation is allowed. You can choose whether or not to allow a missing 0 in front of the ".".

x = 0x4000CCCCCCCCCCCD could be represented as "2.10000000000000008881784197001" but also as "2.1", which is much shorter. x = 0x3DDB7CDFD9D7BDBB can be represented as "1e-10" which is much shorter than alternative representation "1.0000000000000000364321973155E-10"

Rules

In addition to being correct, the program must run in a reasonable amount of time on a modern CPU, ruling out some forms of exhaustive search.

This being code-golf entries should be judged by concision, but voters should feel free to attribute points based on a discretionary judgment of elegance, and efficiency.

A few test cases

In these test cases, I represent the input as an hexadecimal number to make it clear that a IEEE 754 double 64 is passed. You can pass it as a double if the language supports it, or as a 64 bit integer, at your convenience.

f(0x4000CCCCCCCCCCCD) == "2.1"
f(0x3DDB7CDFD9D7BDBB) == "1e-10"
f(0x40934A456D5CFAAD) == "1234.5678" // N.B. not 1.2345678e3
f(0x3FEFFFFFFAA19C47) == "0.99999999"
f(0xC088A8CF13CEE9DD) == "-789.101112"`

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(0x4000CCCCCCCCCCCD, 2.1)
	test(0x3DDB7CDFD9D7BDBB, 1e-10)
	test(0x40934A456D5CFAAD, 1234.5678)
	test(0x3FEFFFFFFAA19C47, 0.99999999)
	test(0xC088A8CF13CEE9DD, -789.101112)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x uint64, r float64) {
	v := math.Float64frombits(x)
	fmt.Println(v)
	assert(math.Abs(v-r) < 1e-6)
}
