/*

Devil's Sequence
Problem

https://cloud.githubusercontent.com/assets/1553519/20080980/c85a971e-a55d-11e6-8cff-bd10cbc81aa7.png

Robodevil likes to do some mathematics between rehearsals of his orchestra. Today he invented devilish sequence No. 1729:
x0 = 0,
x1 = 1,
xn = (xn - 1 + xn - 2) / 2.

For example, x10 = 0.666015625. Robodevil became interested at once how many `sixes` there were at the beginning of an arbitrary xn. In 6 nanoseconds, he had a formula. Can you do the same?
Input
You are given an integer n; `2 ≤ n ≤ 100000`.
Output
Output the number of sixes at the beginning of xn in decimal notation.
Example
Input	Output
10	3

*/

package main

import (
	"math/big"
)

func main() {
	assert(sixes(10) == 3)
	assert(sixes(14) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

The numerators/denominators of the sequence:

https://oeis.org/A135318

The ratio of the fraction converges to 2/3 as n goes to infinity.
The rational number decimal value will gain one digit for every iteration of the sequence and it will always be exact (no repeating decimals).

The number of 6s at the beginning and has a monotonic increasing sequence with cycle of 2s and 4s lengths, ie
0 0 1 1 1 1 2 2 3 3 3 3 4 4 4 4 5 5 6 6 6 6

The sequence is:
https://oeis.org/A156080

*/

func sixes(n int) int {
	r := seq(n)
	p, _ := r.FloatPrec()
	s := r.FloatString(p)

	c := 0
	for i := 2; i < len(s); i++ {
		if s[i] == '6' {
			c += 1
		} else {
			break
		}
	}
	return c
}

func seq(n int) *big.Rat {
	two := big.NewRat(2, 1)
	x0 := big.NewRat(0, 1)
	x1 := big.NewRat(1, 1)
	x2 := big.NewRat(0, 1)
	for range n {
		x2.Add(x0, x1)
		x2.Quo(x2, two)
		x0.Set(x1)
		x1.Set(x2)
	}
	return x2
}
