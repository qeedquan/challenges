/*

Input
A non-empty string or list of capital letters k with length between 3 to 5000.

Output
A value indicating whether k can be expressed as a+b+b, where a and b are non-empty.

Truthy test cases
SSS
SNYYY
SNYY
SNNYY
SNYNY

Falsy test cases
FALSYTESTCASES
FALSYFALSYTESTCASES
FALSYTESTCASESXFALSYTESTCASES
FALSYTESTCASESFALSYTESTCASES
SMARTIEATIE

Neglegible cases:
XX
lowercase
123
ABC (repeated 2000 times)

*/

package main

import (
	"strings"
)

func main() {
	assert(doubletalk("SSS") == true)
	assert(doubletalk("SNYYY") == true)
	assert(doubletalk("SNYY") == true)
	assert(doubletalk("SNNYY") == true)
	assert(doubletalk("SNYNY") == true)

	assert(doubletalk("FALSYTESTCASES") == false)
	assert(doubletalk("FALSYFALSYTESTCASES") == false)
	assert(doubletalk("FALSYTESTCASESXFALSYTESTCASES") == false)
	assert(doubletalk("FALSYTESTCASESFALSYTESTCASES") == false)
	assert(doubletalk("SMARTIEATIE") == false)

	assert(doubletalk("") == false)
	assert(doubletalk("a") == false)
	assert(doubletalk("XX") == false)
	assert(doubletalk("lowercase") == false)
	assert(doubletalk("123") == false)
	assert(doubletalk(strings.Repeat("ABC", 2000)) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func doubletalk(s string) bool {
	n := len(s)
	m := 1 + (n & 1)
	for i := 1; i < n; i += m {
		j := (n - i) / 2
		if s[i:i+j] == s[i+j:] {
			return true
		}
	}
	return false
}
