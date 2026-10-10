/*

Given two numbers (which are multiples of 0.5) representing heads-percentage and tails-percentage from a series of coin-flipping, output the minimum amounts of heads and tails to produce percentages such as those. Input and output can be in any form. However, output must be in a readable format (Good examples are x y, [x y], etc).

Examples:

Input: 25 75 (25% heads, 75% tails) Output: 1 3 (an output of 25 75 is invalid since that is not the minimum amounts of heads and tails to produce those percentages)
Input: 30 70 (30% heads, 70% tails) Output: 3 7
Input: 99.5 0.5 (99.5% heads, 0.5% tails) Output: 199 1
You may assume that there will always be a digit before and after a decimal point in an input (no .5s or 15.s). You may also assume the input adds up to 100%. This is code-golf, shortest code in bytes wins!

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	test("25", "75", 1, 3)
	test("30", "70", 3, 7)
	test("99.5", "0.5", 199, 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s, t string, rn, rd int64) {
	n, d := headtail(s, t)
	fmt.Println(n, d)
	assert(n == rn && d == rd)
}

func headtail(s, t string) (int64, int64) {
	n0, d0 := value(s)
	n1, d1 := value(t)

	n := n0 * d1
	d := n1 * d0
	g := gcd(n, d)
	if g != 0 {
		n, d = n/g, d/g
	}
	return n, d
}

func value(s string) (int64, int64) {
	r := new(big.Rat)
	r.SetString(s)
	n := r.Num()
	d := r.Denom()
	return n.Int64(), d.Int64()
}

func gcd(a, b int64) int64 {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}
