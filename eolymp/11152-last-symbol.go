/*

Print the last character of the string.

Input
One string with a length not exceeding 100 characters.

Output
Print the last character of the string.

Examples

Input #1
This is my home

Answer #1
e

*/

package main

import "unicode/utf8"

func main() {
	assert(solve("This is my home") == 'e')
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(s string) rune {
	r, _ := utf8.DecodeLastRuneInString(s)
	return r
}
