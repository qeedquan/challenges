/*

Implement String#hex_number? (in Java StringUtils.isHexNumber(String)), which should return true if given object is a hexadecimal number, false otherwise.

Hexadecimal numbers consist of one or more digits from range 0-9 A-F (in any case), optionally prefixed by 0x.

*/

package main

import "regexp"

func main() {
	assert(rehex.MatchString("") == false)
	assert(rehex.MatchString("0x") == false)
	assert(rehex.MatchString("0") == true)
	assert(rehex.MatchString("0xDEADBEEF") == true)
	assert(rehex.MatchString("1337bAbe") == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

var rehex = regexp.MustCompile(`^(0x)?[0-9A-Fa-f]+$`)
