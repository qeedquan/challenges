/*

The Challenge
Given a rational number, determine the smallest number which is a positive integer multiple of it. Eg.

Given: 1.25
   x1: 1.25
   x2: 2.5
   x3: 3.75
   x4: 5
 Thus: Answer is 5

Clarifications
Inputs will be a rational number in the range of (0,100] of which the Decimal Representation has no more than 4 digits after the point.

Output must be an integer that is the total after multiplication (5 in the example, rather than 4).

I/O may be in any Standard Format, including as a Fraction type.

Be careful if using repeated addition with floats, as 0.3 + 0.3... results in 2.9999....

Test Cases
1.250 -> 5
4.000 -> 4
0.300 -> 3
4.625 -> 37

Rules
Standard Loopholes Apply
This is code-golf so fewest bytes wins!
Have Fun!

*/

package main

import (
	"math"
	"math/big"
)

func main() {
	assert(multiple("1.25") == 5)
	assert(multiple("4") == 4)
	assert(multiple("0.3") == 3)
	assert(multiple("4.625") == 37)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func multiple(s string) int64 {
	a := new(big.Rat)
	b := new(big.Rat)
	c := new(big.Rat)

	a.SetString(s)
	for i := int64(1); i < math.MaxInt64; i++ {
		b.SetInt64(i)
		c.Mul(a, b)
		if c.IsInt() {
			n := c.Num()
			return n.Int64()
		}
	}
	return -1
}
