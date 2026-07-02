/*

This is a code golf version of a similar question I asked on stack earlier but thought it'd be an interesting puzzle.

Given a string of length 10 which represents a base 36 number, increment it by one and return the resulting string.

This means the strings will only contain digits from 0 to 9 and letters from a to z.

Base 36 works as follows:

The right most digit is incremented, first by using 0 to 9

0000000000 > 9 iterations > 0000000009
and after that a to z is used:

000000000a > 25 iterations > 000000000z
If z needs to be incremented it loops back to zero and the digit to its left is incremented:

000000010
Further rules:
You may use upper case or lower case letters.
You may not drop leading zeros. Both input and output are strings of length 10.
You do not need to handle zzzzzzzzzz as input.
Test Cases:
"0000000000" -> "0000000001"
"0000000009" -> "000000000a"
"000000000z" -> "0000000010"
"123456zzzz" -> "1234570000"
"00codegolf" -> "00codegolg"

*/

package main

import (
	"math/big"
	"strings"
)

func main() {
	assert(inc36("0000000000") == "0000000001")
	assert(inc36("0000000009") == "000000000a")
	assert(inc36("000000000z") == "0000000010")
	assert(inc36("123456zzzz") == "1234570000")
	assert(inc36("00codegolf") == "00codegolg")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func inc36(s string) string {
	one := big.NewInt(1)

	x := new(big.Int)
	x.SetString(s, 36)
	x.Add(x, one)

	r := x.Text(36)
	if n := len(s) - len(r); n > 0 {
		r = strings.Repeat("0", n) + r
	}
	return r
}
