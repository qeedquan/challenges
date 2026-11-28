/*

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
    ...

*/

package main

import "unicode"

func main() {
	assert(sheet2num("A") == 1)
	assert(sheet2num("Z") == 26)
	assert(sheet2num("AA") == 27)
	assert(sheet2num("AB") == 28)
	assert(sheet2num("ZY") == 701)
	assert(sheet2num("ZZ") == 702)
	assert(sheet2num("IV") == 256)
	assert(sheet2num("DF") == 110)
	assert(sheet2num("AZ") == 52)
	assert(sheet2num("BC") == 55)
	assert(sheet2num("QX") == 466)
	assert(sheet2num("AAA") == 703)
	assert(sheet2num("AAZ") == 728)
	assert(sheet2num("STVW") == 348059)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func sheet2num(s string) int {
	v, p := 0, 1
	for i := len(s) - 1; i >= 0; i-- {
		c := unicode.ToLower(rune(s[i]))
		if !('a' <= c && c <= 'z') {
			return -1
		}

		v += p * (int(c) - 'a' + 1)
		p *= 26
	}
	return v
}
