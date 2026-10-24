/*

Sexy primes are pairs of two primes that are 6 apart. In this kata, your job is to complete the function which returns true if x & y are sexy, false otherwise.

Examples
5, 11   -->  true
61, 67  -->  true
7, 13   -->  true
5, 7    -->  false
1, 7    -->  false  (1 is not a prime)

Note: x & y are always positive integers, but they are not always in order of precendence... For example you can be given either (5, 11) or (11, 5) - both are valid.

*/

package main

import "math/big"

func main() {
	assert(sexyprime(5, 11) == true)
	assert(sexyprime(61, 67) == true)
	assert(sexyprime(7, 13) == true)
	assert(sexyprime(5, 7) == false)
	assert(sexyprime(1, 7) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func sexyprime(x, y int64) bool {
	a := big.NewInt(x)
	b := big.NewInt(y)
	if abs(x-y) != 6 || !a.ProbablyPrime(2) || !b.ProbablyPrime(2) {
		return false
	}
	return true
}

func abs(x int64) int64 {
	if x < 0 {
		x = -x
	}
	return x
}
