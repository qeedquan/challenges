/*

Find the largest integer b such that b^2≤a, given a positive integer a.

Input
A positive integer a (a≤10^100).

Output
Print the maximum positive integer b whose square does not exceed a. The number b must be printed without leading zeros.

Examples

Input #1
17

Answer #1
4

*/

package main

import (
	"math/big"
)

func main() {
	assert(solve("17") == "4")
	assert(solve("10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000") == "100000000000000000000000000000000000000000000000000")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(s string) string {
	x := new(big.Int)
	x.SetString(s, 10)
	x.Sqrt(x)
	return x.String()
}
