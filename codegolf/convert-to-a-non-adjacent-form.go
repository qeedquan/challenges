/*

Consider a form of binary where digits can be any of 1, 0 and -1. We'll still call this "binary" because we convert the digits from base two.

For example,

[1,0,-1,1]2 = 1*2^3 + 0*2^2 + -1*2^1 + 1*2^0 = 8 - 2 + 1 = 7

We'll call a representation of a number in this format a "non-adjacent form" if no non-zero digits are adjacent. [1,0,-1,1]2 is not a non-adjacent form of 7, as the last two digits are adjacent and non-zero.
However, [1,0,0,-1]2 is a non-adjacent form of 7.

You should take a positive integer and convert it to a non-adjacent form. As every number has an infinite number of these forms (but only by prepending leading zeroes), you should output the form with no leading zeros.
If the standard binary format of the input is a non-adjacent form (e.g. 5=101[2]), you should output that. You can output a list of integers, or a single string, or any other format the clearly shows the output. You may optionally choose to use any three distinct characters in place of 1, 0 and -1.

This is code-golf, so the shortest code in bytes wins.

*/

package main

import (
	"fmt"
	"math/bits"
)

func main() {
	fmt.Println(prodinger(5))
	fmt.Println(prodinger(7))
	fmt.Println(prodinger(122))
	fmt.Println(prodinger(123))
	for i := uint(0); i <= 5e7; i++ {
		assert(naf2int(prodinger(i)) == i)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func naf2int(a []int) uint {
	x := uint(0)
	for i := range a {
		b := uint(1) << (len(a) - i - 1)
		switch a[i] {
		case 1:
			x += b
		case -1:
			x -= b
		}
	}
	return x
}

// https://en.wikipedia.org/wiki/Non-adjacent_form
func prodinger(x uint) []int {
	xh := x >> 1
	x3 := x + xh
	c := xh ^ x3
	np := x3 & c
	nm := xh & c

	z0 := bits.LeadingZeros(np)
	z1 := bits.LeadingZeros(nm)
	nb := bits.UintSize - min(z0, z1)

	r := make([]int, nb)
	for i := range r {
		b0 := np & (1 << i)
		b1 := nm & (1 << i)
		switch {
		case b0 != 0 && b1 == 0:
			r[nb-i-1] = 1
		case b0 == 0 && b1 != 0:
			r[nb-i-1] = -1
		}
	}
	return r
}
