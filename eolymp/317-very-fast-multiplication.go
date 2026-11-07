/*

Given two non-negative integers A and B, find their product A×B.

Input
The input contains a single line with two numbers A and B, separated by a space. The numbers do not have leading zeros and satisfy 0≤A,B≤10^195000.

Output
Output the product of A and B without leading zeros.

Examples
Input #1
762055 2229849264

Answer #1
1699267780877520

*/

package main

import (
	"fmt"
	"math/big"
	"math/rand/v2"
)

func main() {
	fmt.Println(mul(xint("762055"), xint("2229849264")))
	fmt.Println(mul(xrnd(), xrnd()))
}

func mul(a, b *big.Int) *big.Int {
	a.Mul(a, b)
	return a
}

func xint(s string) *big.Int {
	x := new(big.Int)
	x.SetString(s, 10)
	return x
}

func xrnd() *big.Int {
	x := big.NewInt(rand.Int64())
	x.Exp(x, big.NewInt(195000), nil)
	return x
}
