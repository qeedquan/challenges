/*

What you need to do is create a function/program that takes a decimal as input, and outputs the result of repeatedly taking the reciprocal of the fractional part of the number, until the number becomes an integer.

More specifically, the process is as follows:

1. Let x be the input

2. If x is an integer, output it.

3. Otherwise: x <- 1/frac(x). Go back to 2.

frac(x) is the fractional component of x, and equals x−⌊x⌋. ⌊x⌋ is the floor of x, which is the greatest integer less than x.

Test cases:

0 = 0
0.1 = 1/10 -> 10
0.2 = 1/5 -> 5
0.3 = 3/10 -> 10/3 -> 1/3 -> 3
0.4 = 2/5 -> 5/2 -> 1/2 -> 2
0.5 = 1/2 -> 2
0.6 = 3/5 -> 5/3 -> 2/3 -> 3/2 -> 1/2 -> 2
0.7 = 7/10 -> 10/7 -> 3/7 -> 7/3 -> 1/3 -> 3
0.8 = 4/5 -> 5/4 -> 1/4 -> 4
0.9 = 9/10 -> 10/9 -> 1/9 -> 9
1 = 1
3.14 = 157/50 -> 7/50 -> 50/7 -> 1/7 -> 7
6.28 = 157/25 -> 7/25 -> 25/7 -> 4/7 -> 7/4 -> 3/4 -> 4/3 -> 1/3 -> 3
Summary for 0 to 1 at increments of 0.1: 0, 10, 5, 3, 2, 2, 2, 3, 4, 9, 1

This is code-golf, so fewest bytes wins.

Clarifications:

"Bonus points" for no round-off error
Should work for any non-negative rational number (ignoring round-off error)
You can, but don't have to output the steps taken
You can take input as a decimal, fraction, or pair of numbers, which can be in a string.
Sorry for all the issues, this is my first question on this website.

*/

package main

import (
	"math/big"
)

func main() {
	assert(reciprocals("0") == 0)
	assert(reciprocals("0.1") == 10)
	assert(reciprocals("0.2") == 5)
	assert(reciprocals("0.3") == 3)
	assert(reciprocals("0.4") == 2)
	assert(reciprocals("0.5") == 2)
	assert(reciprocals("0.6") == 2)
	assert(reciprocals("0.7") == 3)
	assert(reciprocals("0.8") == 4)
	assert(reciprocals("0.9") == 9)
	assert(reciprocals("1") == 1)
	assert(reciprocals("3.14") == 7)
	assert(reciprocals("6.28") == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func reciprocals(s string) int64 {
	x := new(big.Rat)
	x.SetString(s)
	for {
		if x.IsInt() {
			break
		}
		frac(x)
		x.Inv(x)
	}
	r := x.Num()
	return r.Int64()
}

func frac(x *big.Rat) *big.Rat {
	n := new(big.Int)
	n.Set(x.Num())
	n.Quo(n, x.Denom())

	y := new(big.Rat)
	y.SetInt(n)
	x.Sub(x, y)
	return x
}
