/*

Background
A continued fraction is a way to represent a real number as a sequence of integers in the following sense:

x = a0 + (1 / (a1 + 1 / (a2 + ...(1/an))))

Finite continued fractions represent rational numbers; infinite continued fractions represent irrational numbers. This challenge will focus on finite ones for the sake of simplicity.

Let's take 277/642 as an example. It has the following continued fraction:

277/642 = [0; 2 3 6 1 3 3]

If we truncate the continued fraction at various places, we get various approximations of the number 277/642:

Continued Fraction | Fraction | Decimal    | Relative Error
[0]                  0/1        0.0...       1
[0; 2]               1/2        0.5...       0.15
[0; 2 3]             3/7        0.428...     0.0067
[0; 2 3 6]           19/44      0.4318...    0.00082
[0; 2 3 6 1]         22/51      0.43137...   0.00021
[0; 2 3 6 1 3]       85/197     0.431472...  0.000018
[0; 2 3 6 1 3 3]     277/642    0.4314641... 0

These are called convergents of the given number. In fact, the convergents are the best approximations among all fractions with the same or lower denominator.
This property was used in a proposed machine number system of rational numbers to find the approximation that fits in a machine word of certain number of bits.

https://ieeexplore.ieee.org/document/1676511/

(There are some subtle points around "best approximation", but we will ignore it and just use the convergents. As a consequence, if your language/library has a "best rational approximation" built-in, it is unlikely to correctly solve the following task.)

Task
Given a rational number r given as a finite continued fraction and a positive integer D, find the best approximation of r among its convergents so that its denominator does not exceed D.

The continued fraction is guaranteed to be a finite sequence of integers, where the first number is non-negative, and the rest are strictly positive.
You may output the result as a built-in rational number or two separate integers. The output fraction does not need to be reduced.

Standard code-golf rules apply. The shortest code in bytes wins.

Test cases
[0, 2, 3, 6, 1, 3, 3], 43 => 3/7
[0, 2, 3, 6, 1, 3, 3], 44 => 19/44
[5, 6, 7], 99 => 222/43

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	test([]int64{0, 2, 3, 6, 1, 3, 3}, 43, "3/7")
	test([]int64{0, 2, 3, 6, 1, 3, 3}, 44, "19/44")
	test([]int64{5, 6, 7}, 99, "222/43")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []int64, d int64, r string) {
	x := new(big.Rat)
	x.SetString(r)
	y := convergents(a, d)
	fmt.Println(y)
	assert(x.Cmp(y) == 0)
}

func convergents(a []int64, d int64) *big.Rat {
	r := big.NewRat(0, 1)
	dr := denominator(r)
	for i := 1; i < len(a); i++ {
		x := fraction(a[:i+1])
		dx := denominator(x)
		if dr < dx && dx <= d {
			r.Set(x)
		}
	}
	return r
}

func fraction(a []int64) *big.Rat {
	n := len(a)
	if n == 0 {
		return big.NewRat(0, 1)
	}

	x := big.NewRat(a[0], 1)
	y := big.NewRat(0, 1)
	for i := n - 1; i >= 1; i-- {
		z := big.NewRat(a[i], 1)
		y.Add(y, z)
		y.Inv(y)
	}
	x.Add(x, y)
	return x
}

func denominator(x *big.Rat) int64 {
	d := x.Denom()
	return d.Int64()
}
