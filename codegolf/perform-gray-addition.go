/*

Objective
Given two non-negative integers encoded in unbounded-length Gray code, add them and output the result, where the result is also encoded in Gray code.

Gray code
There are many equivalent formulations of Gray code, but here's an intuitive one.

The Gray code encodes each non-negative integer as an infinite bit-string. Starting from encoding zero, as the enumeration goes, the least significant bit keeps cycling through "0110". Each place of bit keeps cycling through what the previously significant bit cycles through, but doubled entry-wise. To summarize:

0th LSB: Cycles through "0110"
1st LSB: Cycles through "00111100"
2nd LSB: Cycles through "0000111111110000"
3rd LSB: Cycles through "00000000111111111111111100000000"
(And so on)
That gives the encodings of few non-negative integers as:

Integer = Gray code
("..." stands for infinitely many leading zeroes)
0 = "...00000"
1 = "...00001"
2 = "...00011"
3 = "...00010"
4 = "...00110"
5 = "...00111"
6 = "...00101"
7 = "...00100"
8 = "...01100"
9 = "...01101"
Note that, for each pair of integers differing by one, their Gray codes differ by only one bit.

I/O format
Flexible. Standard loopholes apply.

Examples
Here, inputs and outputs are Gray codes with their leading zeroes stripped off.

"" + "" = ""
"1" + "1" = "11"
"1" + "10" = "110"
"10" + "1" = "110"
"10" + "11" = "111"
"111" + "111" = "1111"

*/

package main

import (
	"math/bits"
)

func main() {
	assert(addgray(0b0, 0b0) == 0b0)
	assert(addgray(0b1, 0b1) == 0b11)
	assert(addgray(0b1, 0b10) == 0b110)
	assert(addgray(0b10, 0b11) == 0b111)
	assert(addgray(0b111, 0b111) == 0b1111)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://codereview.stackexchange.com/questions/86376/gray-codes-addition-take-2
func addgray(a, b uint) uint {
	for i := bits.UintSize >> 1; i > 1; i >>= 1 {
		a = a ^ (a >> i)
		b = b ^ (b >> i)
	}

	x := (a ^ (a >> 1)) + (b ^ (b >> 1))
	return (x >> 1) ^ x
}
