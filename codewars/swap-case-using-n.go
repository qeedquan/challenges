/*

Your job is to change the given string s using a non-negative integer n.

Each bit in n will specify whether or not to swap the case for each alphabetic character in s: if the bit is 1, swap the case; if its 0, leave it as is. When you finish with the last bit of n, start again with the first bit.

You should skip the checking of bits when a non-alphabetic character is encountered, but they should be preserved in their original positions.

Examples
swap("Hello world!", 11)  -->  "heLLO wORLd!"
...because 11 is 1011 in binary, so the 1st, 3rd, 4th, 5th, 7th, 8th and 9th alphabetical characters have to be swapped:

H e l l o   w o r l d !
1 0 1 1 1 x 0 1 1 1 0 x
^   ^ ^ ^    ^ ^ ^
More examples
swap("gOOd MOrniNg", 7864)        -->  "GooD MorNIng"
swap("", 11345)                   -->  ""
swap("the lord of the rings", 0)  -->  "the lord of the rings"

*/

package main

import (
	"bytes"
	"math/bits"
	"unicode"
)

func main() {
	assert(swap("Hello world!", 11) == "heLLO wORLd!")
	assert(swap("gOOd MOrniNg", 7864) == "GooD MorNIng")
	assert(swap("", 11345) == "")
	assert(swap("the lord of the rings", 0) == "the lord of the rings")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func swap(input string, bitmask uint) string {
	output := new(bytes.Buffer)
	length := bits.UintSize - bits.LeadingZeros(bitmask)
	if length == 0 {
		length = bits.UintSize
	}

	index := 0
	for _, symbol := range input {
		if bitmask&(1<<(length-index-1)) != 0 {
			if unicode.IsUpper(symbol) {
				symbol = unicode.ToLower(symbol)
			} else if unicode.IsLower(symbol) {
				symbol = unicode.ToUpper(symbol)
			}
		}
		if unicode.IsLetter(symbol) {
			index = (index + 1) % length
		}
		output.WriteRune(symbol)

	}
	return output.String()
}
