/*

You goal is to implement the operation of XOR (carryless) multiplication, defined below, in as few bytes as possible.

If we think of bitwise XOR (^) as binary addition without carrying

   101   5
^ 1001   9
  ----
  1100  12

  5^9=12

we can perform XOR multiplication @ by doing binary long-multiplication but doing the adding step without carrying as bitwise XOR ^.

     1110  14
   @ 1101  13
    -----
     1110
       0
   1110
^ 1110
  ------
  1000110  70

  14@13=70
(For mathematicians, this is multiplication in the polynomial ring F2[x], identifying polynomials with natural numbers by evaluating at x=2 as a polynomial over Z.)

XOR multiplication commutes a@b=b@a, associates (a@b)@c=a@(b@c), and distributes over bitwise XOR a@(b^c)=(a@b)^(a@c). In fact, it is the unique such operation that matches multiplication a@b=a*b whenever a and b are powers of 2 like 1,2,4,8....

Requirements

Take two non-negative integers as input and output or print their XOR-product. This should be as numbers or their decimal string representations, not their binary expansions. Fewest bytes wins.

Don't worry about integer overflows.

Here are some test cases formatted as a b a@b.

0 1 0
1 2 2
9 0 0
6 1 6
3 3 5
2 5 10
7 9 63
13 11 127
5 17 85
14 13 70
19 1 19
63 63 1365

*/

package main

func main() {
	assert(xormul(0, 1) == 0)
	assert(xormul(1, 2) == 2)
	assert(xormul(9, 0) == 0)
	assert(xormul(6, 1) == 6)
	assert(xormul(3, 3) == 5)
	assert(xormul(2, 5) == 10)
	assert(xormul(7, 9) == 63)
	assert(xormul(13, 11) == 127)
	assert(xormul(5, 17) == 85)
	assert(xormul(14, 13) == 70)
	assert(xormul(19, 1) == 19)
	assert(xormul(63, 63) == 1365)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func xormul(a, b uint) uint {
	r := uint(0)
	for b != 0 {
		r ^= (b & 1) * a
		a <<= 1
		b >>= 1
	}
	return r
}
