/*

We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(987654321))
}

/*

https://euler.beerbaronbill.com/en/latest/solutions/32.html
Gives much better bounds on what a and b can be

*/
func solve(n uint64) uint64 {
	m := make(map[uint64]bool)
	l := uint64(math.Sqrt(float64(n))) / 2
	for a := uint64(1); a <= l; a++ {
		for b := a + 1; b <= l; b++ {
			if pandigital(a, b) {
				m[a*b] = true
			}
		}
	}
	return sum(m)
}

func sum(m map[uint64]bool) uint64 {
	r := uint64(0)
	for v := range m {
		r += v
	}
	return r
}

func digits(n uint64, d []uint64) {
	for {
		d[n%10]++
		n /= 10
		if n == 0 {
			break
		}
	}
}

func pandigital(a, b uint64) bool {
	var d [10]uint64
	digits(a, d[:])
	digits(b, d[:])
	digits(a*b, d[:])

	for i := range d {
		if (i == 0 && d[i] != 0) || (i > 0 && d[i] != 1) {
			return false
		}
	}
	return true
}
