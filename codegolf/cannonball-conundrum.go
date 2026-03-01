/*

Your task is to, with an input number p, find the smallest positive cannonball number of order p that is NOT 1.

Definition
A cannonball number (of order p) is a number which is both:

* An p-gonal number (See this page) [https://en.wikipedia.org/wiki/Polygonal_number].
* and an p-gonal pyramid number.
  * The nth p-gonal pyramid number is the sum of the 1st to nth p-gonal numbers.
    * (e.g. 4th square pyramid number = 1 + 4 + 9 + 16 = 30)
  * The picture below represents the 4th square pyramid number, as a square pyramid. enter image description here

For more info, visit this link.
https://en.wikipedia.org/wiki/Tetrahedral_number

The cannonball number of order 3, for example, is 10, because it is:

The fourth triangle number (1 + 2 + 3 + 4 = 10)
and the third triangular pyramid number. (1 + 3 + 6 = 10)

Formulas
NOTE: If you can find (or make) more useful formulae than my ones here, please post it here (or message me on the question chat thing).

If you're interested, the formula for the nth p-gonal number is:
((p-2)*n^2 - (p-4)*n) / 2

And the nth p-gonal pyramid number is:
((p-2)*n^3 + 3*n^2 - (p-5)*n) / 6

Specs
p is guaranteed to be larger than 2.
The program must check values for a solution for p up to (and including) 2^16. Your program may do anything if no solutions are found for p.
Only positive indices for n.
Test cases
3 outputs 10 (4th triangle number, 3rd triangle pyramid number)
4 outputs 4900 (70th square number, 24th square pyramid number)
This is code-golf, so shortest answer in bytes wins.

Note: If you do post a solution, please include a description of how the code works.

Should I start a bounty for a solution which is better and doesn't use my formulae?

*/

package main

import "math"

func main() {
	tab := map[int]int{
		3:  10,
		4:  4900,
		6:  946,
		8:  1045,
		10: 175,
		11: 23725,
		14: 441,
		17: 975061,
		23: 10680265,
		26: 27453385,
		30: 23001,
		32: 132361021,
		35: 258815701,
		41: 55202400,
		43: 245905,
		50: 314755,
		88: 48280,
	}

	for i, v := range tab {
		assert(solve(i) == v)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int) int {
	const limit = math.MaxInt

	b, y := 1, 1
	for a := 2; a < limit; a++ {
		x := pyramidal(a, n)
		for ; y < x && b < limit; b++ {
			y = ngonal(b, n)
			if x == y {
				return x
			}
		}
	}
	return -1
}

func pyramidal(x, n int) int {
	return (x*x*3 + x*x*x*(n-2) - x*(n-5)) / 6
}

func ngonal(x, n int) int {
	return (x*x*(n-2) - x*(n-4)) / 2
}
