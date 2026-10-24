/*

The Hilbert curves are a class of space-filling fractal curves where every bend in the path is at a right angle and the curve as a whole fills up a square, with the property that sequences of consecutive segments are always displayed as contiguous blocks.

Traditionally, the curve is drawn as a series of very squiggly lines inside a square such that each segment becomes smaller and smaller until they fill up the whole square. However, like the Walsh matrix, it is also possible to represent the limit curve as a sequence of line segments connecting lattice points that grows infinitely until it fills up an entire quadrant of lattice points on the Cartesian plane.

Suppose we define such a curve as the integral Hilbert curve, as follows:

Start at the origin.

Move one unit right (R), one unit up (U), and one unit left (L). Down will be notated as D.

Let RUL be H_1. Then define H_2 as H_1 U I_1 R I_1 D J_1 where:

I_1 is H_1 rotated 90 degrees counterclockwise and flipped horizontally.

J_1 is H_1 rotated 180 degrees.

Perform the steps of H_2 after H_1 to complete H_2.

Define H_3 as H_2 R I_2 U I_2 L J_2, where:

I_2 is H_2 rotated 90 degrees clockwise and flipped vertically.

J_2 is H_2 rotated 180 degrees.

Perform the steps of H_3 after H_2 to complete H_3.

Define H_4 and other H_n for even n the same way as H_2, but relative to H_{n-1}.

Define H_5 and other H_n for odd n the same way as H_3, but relative to H_{n-1}.

The integral Hilbert curve is H_infinity.

We get a function f(n) = (a, b) in this way, where (a, b) is the position of a point moving n units along the integral Hilbert curve starting from the origin. You may notice that if we draw this curve 2^{2n}-1 units long we get the nth iteration of the unit-square Hilbert curve magnified 2^n times.

Your task is to implement f(n). The shortest code to do so in any language wins.

Example inputs and outputs:

> 0
(0, 0)
> 1
(1, 0)
> 9
(2, 3)
> 17
(4, 1)
> 27
(6, 3)
> 41
(7, 6)
> 228
(9, 3)
> 325
(24, 3)

Note that your solution's algorithm must work in general; if you choose to implement your algorithm in a language where integers are of bounded size, that bound must not be a factor in your program's code.

*/

package main

import (
	"fmt"
	"strconv"
)

func main() {
	test(0, 0, 0)
	test(1, 1, 0)
	test(9, 2, 3)
	test(17, 4, 1)
	test(27, 6, 3)
	test(41, 7, 6)
	test(228, 9, 3)
	test(325, 24, 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n, rx, ry int) {
	x, y := hilbertxy(n)
	fmt.Println(x, y)
	assert(x == rx && y == ry)
}

/*

@Peter Taylor

It's essentially the iterative code from the Wikipedia article reversed so that it processes the base-4 representation of n from most-significant to least-significant digit instead of least-significant to most-significant. This simplifies the bookkeeping required to output x and y in the right order.

Pseudocode translation (not tested, may contain errors):

a = b = true;
x = y = 0;
foreach (digit in n base 4) {
    p = (digit % 3 == 0) ^ b;
    q = (digit < 2) ^ b;
    b ^= (digit == 3);
    if (a) swap(p, q);
    a ^= (digit % 3 != 0);
    y = 2*y + (p ? 1 : 0);
    x = 2*x + (q ? 1 : 0);
    swap(x, y);
}
swap(x, y)

*/

func hilbertxy(n int) (int, int) {
	a, b := 1, 1
	x, y := 0, 0
	s := strconv.FormatInt(int64(n), 4)
	for i := range s {
		d := int(s[i] - '0')
		p := truth(d%3 == 0) ^ b
		q := truth(d < 2) ^ b
		b ^= truth(d == 3)
		if a != 0 {
			p, q = q, p
		}
		a ^= truth(d%3 != 0)
		y = 2*y + truth(p != 0)
		x = 2*x + truth(q != 0)
		x, y = y, x
	}
	return y, x
}

func truth(b bool) int {
	if b {
		return 1
	}
	return 0
}
