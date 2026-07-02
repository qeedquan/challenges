/*

There is a number n that you have to find.

There is also a pre-defined API int commonSetBits(int num), which returns the number of bits where both n and num are 1 in that position of their binary representation.
In other words, it returns the number of set bits in n & num, where & is the bitwise AND operator.

Return the number n.

Example 1:

Input: n = 31

Output: 31

Explanation: It can be proven that it's possible to find 31 using the provided API.

Example 2:

Input: n = 33

Output: 33

Explanation: It can be proven that it's possible to find 33 using the provided API.

Constraints:

    1 <= n <= 2^30 - 1
    0 <= num <= 2^30 - 1
    If you ask for some num out of the given range, the output wouldn't be reliable.

*/

package main

import (
	"math/bits"
)

func main() {
	assert(find(mksetbits(31)) == 31)
	assert(find(mksetbits(33)) == 33)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func mksetbits(x uint) func(uint) uint {
	return func(n uint) uint {
		return uint(bits.OnesCount(x & n))
	}
}

func find(setbits func(uint) uint) uint {
	r := uint(0)
	for i := range bits.UintSize {
		b := uint(1) << i
		if setbits(b) != 0 {
			r |= b
		}
	}
	return r
}
