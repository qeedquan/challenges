/*

Challenge
Given an integer in 32-bit two's complement format, return the index of the second least-significant zero digit in the binary representation, where an index of 0 represents the least significant bit, and an index of 31 represents the most significant bit.

If there is no second zero, you may return 0, any negative number, any falsy value, or report an error in a way that makes sense in your language.

You may use 1-indexing if you prefer, but the test cases below will use 0-indexing.

You may use unsigned integers if you prefer; if you do, then you must handle integers in the range [0, 2^32). If you use signed integers, you must handle integers in the range [-2^31, 2^31). The test cases here will use signed integers, but note that -x (signed) is 2^32 - x (unsigned).

Test Cases
0  (0b00)        -> 1
1  (0b001)       -> 2
10 (0b1010)      -> 2
11 (0b01011)     -> 4
12 (0b1100)      -> 1
23 (0b010111)    -> 5
-1 (0b11..11)    -> None
-2 (0b11..10)    -> None
-4 (0b11..00)    -> 1
-5 (0b11..1011)  -> None
-9 (0b11..10111) -> None
2^31-2 (0b0111..1110) -> 31

Scoring
This is code-golf, so the shortest answer in each language wins!

*/

package main

import (
	"math"
	"math/bits"
)

func main() {
	assert(secondzero(0) == 1)
	assert(secondzero(1) == 2)
	assert(secondzero(10) == 2)
	assert(secondzero(11) == 4)
	assert(secondzero(12) == 1)
	assert(secondzero(23) == 5)
	assert(secondzero(-1) == 0)
	assert(secondzero(-2) == 0)
	assert(secondzero(-4) == 1)
	assert(secondzero(-5) == 0)
	assert(secondzero(-9) == 0)
	assert(secondzero(math.MaxInt32-2) == 31)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func secondzero(x int32) int {
	v := uint32(x)
	return bits.TrailingZeros32(^v&(-v-2)) & 31
}
