/*

In this challenge, you receive a string as input containing a string of X's, Y's and Z's eg. "XYZZ". X, Y and Z represent a particular character. This pattern is then compared with a second string input. If the pattern exists as a substring in the second input, return True, otherwise, return False. Once a pattern is found in the word, the program stops searching and returns True.

Examples
Pattern: "XXYY"

succeed ---> True (pattern found: ccee)
success ---> False (pattern not matched)
balloon ---> True (pattern found: lloo)
Pattern: "XYXYZ"

bananas ---> True (pattern found: nanas)
banana  ---> False (pattern not found)
Note: This is not the actual input. This is an example of how the program should work. Your program should output True or False, or other Truthy/Falsy values.
Other important/useful information
The pattern does not need to contain an X, Y and a Z, it could contain X's and Y's or even (although somewhat pointless) just X's.
The pattern cannot be empty, but this will not be used as a test case.
The search string will not be empty, and will be lowercase.
The alphabetic order of X, Y and Z in the pattern does not matter.
X, Y and Z must be unique characters.
You may use any library you wish.
The score is determined by the code size, in bytes. Lowest score wins.
Good luck!

*/

package main

import "strings"

func main() {
	assert(match("XXYY", "succeed") == true)
	assert(match("XXYY", "success") == false)
	assert(match("XXYY", "balloon") == true)

	assert(match("XYXYZ", "bananas") == true)
	assert(match("XYXYZ", "banana") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// ported from @Kevin Cruijssen solution
func match(p, s string) bool {
	if len(s) < len(p) {
		return false
	}
	for i := len(p) - 1; i >= 0; i-- {
		x := strings.IndexByte(p, p[i])
		y := strings.IndexByte(s, s[i])
		if x != y {
			return match(p, s[1:])
		}
	}
	return true
}
