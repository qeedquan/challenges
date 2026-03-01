/*

Gobar primes (A347476) are numbers which give a prime number when 0's and 1's are interchanged in their binary representation.

For example, 10=0b1010, and if we flip the bits, we get 0b0101=5 which is prime. Therefore, 10 is a Gobar prime

As simple as that: print the series with any delimiter. Shortest code wins.

*/

package main

import (
	"math/big"
	"math/bits"
	"reflect"
)

func main() {
	tab := []uint{4, 5, 8, 10, 12, 13, 18, 20, 24, 26, 28, 29, 32, 34, 40, 44, 46, 50, 52, 56, 58, 60, 61, 66, 68, 74, 80, 84, 86, 90, 96, 98, 104, 108, 110, 114, 116, 120, 122, 124, 125, 128, 142, 146, 148, 152, 154, 158, 166, 172, 176, 182, 184, 188, 194, 196, 202, 208, 212}

	assert(reflect.DeepEqual(gen(len(tab)), tab))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A347476
func gen(n int) []uint {
	r := []uint{}
	for i := uint(2); len(r) < n; i++ {
		m := uint(1)<<(bits.UintSize-bits.LeadingZeros(i)) - 1
		if isprime(^i & m) {
			r = append(r, i)
		}
	}
	return r
}

func isprime(n uint) bool {
	x := big.NewInt(int64(n))
	return x.ProbablyPrime(2)
}
