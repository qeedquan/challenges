/*

You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.

Example 1:

Input: n = 1
Output: true
Example 2:

Input: n = 10
Output: false


Constraints:

1 <= n <= 10^9

*/

package main

import (
	"math/bits"
)

func main() {
	assert(rp2(0) == false)
	assert(rp2(1) == true)
	assert(rp2(10) == false)
	assert(rp2(215) == true)
	assert(rp2(1023) == false)
	assert(rp2(8192) == true)
	assert(rp2(9182) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func rp2(n uint) bool {
	d := digits(n)
	for i := 0; i < bits.UintSize; i++ {
		if d == digits(1<<i) {
			return true
		}
	}
	return false
}

func digits(n uint) [10]uint {
	var d [10]uint
	for {
		d[n%10]++
		if n /= 10; n == 0 {
			break
		}
	}
	return d
}
