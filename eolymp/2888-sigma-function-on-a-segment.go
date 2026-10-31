/*

Calculate

S(L, R) = Sum[i=L, R] σ(i)

where σ(i) is the sum of the positive divisors of the number i.

Input
Contains no more than 10^5 queries.
Each query is given on a separate line and contains two numbers l and r (1≤l≤r≤5⋅10^6).

Output
For each query, output on a separate line one number S(l,r).

Examples

Input #1
3 10

Answer #1
83

*/

package main

import (
	"math"
)

func main() {
	assert(solve(3, 10) == 83)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(l, r int) int {
	return sumsigma(r) - sumsigma(l-1)
}

// https://oeis.org/A024916
func sumsigma(n int) int {
	r := 0
	s := int(math.Sqrt(float64(n)))
	for i := 1; i <= s; i++ {
		r += (i * (n / i)) + triangular(n/i)
	}
	r -= triangular(s) * s
	return r
}

func triangular(n int) int {
	return n * (n + 1) / 2
}
