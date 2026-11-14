/*

Objective
Given an integer n interpreted as two's complement binary, output two integers, namely the integer consisting of n's bits at places of 2^0,2^2,2^4,⋯, and the integer consisting of n's bits at places of 2^1,2^3,2^5,⋯.

Note that the input may be negative. Since n is interpreted as two's complement binary, nonnegative integers start with infinitely many zeros, and negative integers start with infinitely many ones.
As a consequence, nonnegative inputs split into nonnegative outputs, and negative inputs split into negative outputs.

Examples
Here, the integers are represented as decimal.

Input, Output even, Output odd
0, 0, 0
1, 1, 0
2, 0, 1
3, 1, 1
4, 2, 0
5, 3, 0
6, 2, 1
7, 3, 1
8, 0, 2
9, 1, 2
10, 0, 3
11, 1, 3
12, 2, 2
13, 3, 2
14, 2, 3
15, 3, 3
-1, -1, -1
-2, -2, -1
-3, -1, -2
-4, -2, -2

Worked Example
Say the input is 43, or 101011 in binary.

The "even" output selects the bits like this:

...0000101011
... ^ ^ ^ ^ ^
which is ...00001, or 1 in decimal.

The "odd" output selects the bits like this:

...0000101011
...^ ^ ^ ^ ^
which is ...00111, or 7 in decimal.

I/O format
Flexible; default I/O policies apply.

*/

package main

import (
	"fmt"
	"math/bits"
)

func main() {
	test(0, 0, 0)
	test(1, 1, 0)
	test(2, 0, 1)
	test(3, 1, 1)
	test(4, 2, 0)
	test(5, 3, 0)
	test(6, 2, 1)
	test(7, 3, 1)
	test(8, 0, 2)
	test(9, 1, 2)
	test(10, 0, 3)
	test(11, 1, 3)
	test(12, 2, 2)
	test(13, 3, 2)
	test(14, 2, 3)
	test(15, 3, 3)
	test(-1, -1, -1)
	test(-2, -2, -1)
	test(-3, -1, -2)
	test(-4, -2, -2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n, re, ro int) {
	e, o := bitbreak(n)
	fmt.Println(e, o)
	assert(e == re)
	assert(o == ro)
}

func bitbreak(n int) (e, o int) {
	for i := 0; i < bits.UintSize; i++ {
		e |= bit(n, 2*i)
		o |= bit(n, 2*i+1)
	}
	return
}

func bit(n, b int) int {
	if (b >= bits.UintSize && n < 0) || n&(1<<b) != 0 {
		return 1 << (b >> 1)
	}
	return 0
}
