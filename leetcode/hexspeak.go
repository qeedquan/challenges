/*

A decimal number can be converted to its Hexspeak representation by first converting it to an uppercase hexadecimal string, then replacing all occurrences of the digit 0 with the letter O, and the digit 1 with the letter I.
Such a representation is valid if and only if it consists only of the letters in the set {"A", "B", "C", "D", "E", "F", "I", "O"}.

Given a string num representing a decimal integer N, return the Hexspeak representation of N if it is valid, otherwise return "ERROR".

Example 1:

Input: num = "257"
Output: "IOI"
Explanation:  257 is 101 in hexadecimal.
Example 2:

Input: num = "3"
Output: "ERROR"


Constraints:

1 <= N <= 10^12
There are no leading zeros in the given string.
All answers must be in uppercase letters.

*/

package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	assert(hexspeak("257") == "IOI")
	assert(hexspeak("3") == "ERROR")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func hexspeak(s string) string {
	n, err := strconv.ParseUint(s, 10, 64)
	if err != nil {
		return "ERROR"
	}

	r := fmt.Sprintf("%X", n)
	r = strings.Replace(r, "0", "O", -1)
	r = strings.Replace(r, "1", "I", -1)
	if strings.IndexAny(r, "23456789") >= 0 {
		return "ERROR"
	}

	return r
}
