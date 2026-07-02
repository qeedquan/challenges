/*

Find the least common multiple of all integers from 1 to n.

The least common multiple of positive integers a1,a2,…,ak is a number A such that A is divisible by each ai for all i from 1 to k,
and A is the smallest positive integer with this property.

Input
One integer n (1≤n≤1000).

Output
Output one integer — the least common multiple of all integers from 1 to n.

Examples
Input #1
3

Answer #1
6

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	fmt.Println(solve(xint(3)))
}

// https://oeis.org/A003418
func solve(n *big.Int) *big.Int {
	zero := big.NewInt(0)
	one := big.NewInt(1)

	if n.Cmp(zero) <= 0 {
		return zero
	}

	r := big.NewInt(1)
	for i := big.NewInt(1); i.Cmp(n) <= 0; i.Add(i, one) {
		r = lcm(r, i)
	}
	return r
}

func lcm(a, b *big.Int) *big.Int {
	x := new(big.Int)
	y := new(big.Int)
	x.Mul(a, b)
	y.GCD(nil, nil, a, b)
	x.Quo(x, y)
	return x
}

func xint(n int64) *big.Int {
	return big.NewInt(n)
}
