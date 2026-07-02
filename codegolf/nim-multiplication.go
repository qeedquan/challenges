/*

Background
If you do much code golfing, you're likely aware of the bitwise XOR operation. Given two integers, it gives another integer with 1s in the bits where the two inputs differ. So, for example, 1010 XOR 0011 = 1001.

It turns out to be very useful in game theory, where it's better known as the "nim sum". If you have the sum of two games (that is, you're making moves in one game at a time), the value of the position is the nim sum of the values of the positions in each individual game.

But we can take this a step further. With nim addition and an appropriate definition of nim multiplication, we can form a field from the nonnegative integers. So the challenge is to golf nim multiplication.

Definition
Nim multiplication obeys the following rules:
The nim product of a Fermat 2-power n = (2^(2^k)) with any smaller number is the ordinary product.
The nim product of a Fermat 2-power n with itself is 3n/2.
Nim multiplication distributes over nim addition.
Nim multiplication is commutative and associative (as is nim addition).
The multiplicative identity is 1 (and the additive identity is 0).

Any nonnegative integer can be written as the nim sum of distinct powers of two, and any power of two can be written as the product of distinct Fermat numbers, so this is sufficient to define nim multiplication for all nonnegative integers.

Example
That was all pretty abstract, so let's work through an example. I'll use + to denote nim addition (XOR) and * for nim multiplication.

6 * 13
= (4 + 2) * (8 + 4 + 1)
= (4 + 2) * ((4 * 2) + 4 + 1)
= (4 * 4 * 2) + (4 * 2 * 2) + (4 * 4) + (4 * 2) + (4 * 1) + (2 * 1)
= (6 * 2) + (4 * 3) + 6 + 8 + 4 + 2
= ((4 + 2) * 2) + 12 + 6 + 8 + 4 + 2
= (4 * 2) + (2 * 2) + 12 + 6 + 8 + 4 + 2
= 8 + 3 + 12 + 6 + 8 + 4 + 2
= 15

Additional Test Cases
4, 4 -> 6
4, 3 -> 12
4, 7 -> 10
2, 4 -> 8
2, 3 -> 1
1, 42 -> 42
Challenge
Write a program or function which, given two nonnegative integers in any convenient form, computes their nim product.

This is code-golf, so shortest submission wins.

*/

package main

import (
	"math"
)

func main() {
	assert(nimprod(6, 13) == 15)
	assert(nimprod(4, 4) == 6)
	assert(nimprod(4, 3) == 12)
	assert(nimprod(4, 7) == 10)
	assert(nimprod(2, 4) == 8)
	assert(nimprod(2, 3) == 1)
	assert(nimprod(1, 42) == 42)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@Neil

The first step is to split both x and y into an XOR of powers of 2,
take their pairwise nim products, and then XOR the results (because nim product distributes over XOR).
Once we have recursed to the case of x and y both powers of 2, we note that Fermat powers multiply with each other using ordinary arithmetic,
so we can therefore factorise x and y into Fermat powers.
If x and y don't share a Fermat power we can reverse the process and simply return x * y.
However if they share a Fermat power, then we divide both x and y by that power, calculate the nim product, then take the nim product with the nim square of that Fermat power.

*/

func nimprod(x, y int) int {
	if x < 2 || y < 2 {
		return x * y
	}

	v := x & -x
	if x > v {
		return nimprod(v, y) ^ nimprod(x^v, y)
	}
	if y&(y-1) != 0 {
		return nimprod(y, x)
	}

	t := ilog2(x)
	u := ilog2(y)
	s := t & u
	if s == 0 {
		return x * y
	}

	r := s & -s
	return nimprod(nimprod(x>>r, y>>r), 3<<(r-1))
}

func ilog2(x int) int {
	return int(math.Log2(float64(x)))
}
