/*

The problem
Given a binary number from 0 to 111111 convert it to trinary. (Base 3). Then print the result.

Rules
No using a list of conversions.

Don't cheat

You must use a string as the number

No compressing the input string As I will be testing the code with several different numbers I can't use compressed strings

Notes
By trinary I mean counting in base 3. So 0,1,2,10,11,12,20... ect

Leading zeros will be present 001101

Most important number is on the left.

Example
String input = "110111"
String a = code(input);
print(a);
To win
This is code golf!

Do it correctly and in the smallest size.

*/

package main

import (
	"strconv"
)

func main() {
	assert(bin2tri(0b0) == "0")
	assert(bin2tri(0b1) == "1")
	assert(bin2tri(0b10) == "2")
	assert(bin2tri(0b11) == "10")
	assert(bin2tri(0b100) == "11")
	assert(bin2tri(0b101) == "12")
	assert(bin2tri(0b110) == "20")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func bin2tri(x int64) string {
	return strconv.FormatInt(x, 3)
}
