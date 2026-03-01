/*

Ore Numbers (also called Harmonic Divisor Numbers) are numbers for which the harmonic mean of all their divisors (including the number itself) equals an integer.

For example, 6 is an Ore Number because its harmonic mean is exactly 2:

H(6) = 4 / (1/1 + 1/2 + 1/3 + 1/6) = 2
Your task is to complete the function returns true if the given number is an Ore Number and false otherwise.

You can assume all inputs will be valid positive integers.

Hint: The harmonic mean is the total number of divisors divided by the sum of their reciprocals.

*/

package main

import (
	"math/big"
)

func main() {
	assert(isore(6) == true)
	assert(isore(10) == false)
	assert(isore(28) == true)
	assert(isore(32) == false)
	assert(isore(125) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A001599
func isore(n int64) bool {
	if n < 1 {
		return false
	}

	a := big.NewRat(0, 1)
	b := big.NewRat(0, 1)
	for i := int64(1); i <= n; i++ {
		if n%i == 0 {
			a.Add(a, big.NewRat(1, i))
			b.Add(b, big.NewRat(1, 1))
		}
	}
	a.Quo(b, a)

	return a.IsInt()
}
