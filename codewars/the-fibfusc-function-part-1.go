/*

The fibfusc function is defined recursively as follows:

fibfusc(0) = (1, 0)
fibfusc(1) = (0, 1)
fibfusc(2n) = ((x + y)(x - y), y(2x + 3y)), where (x, y) = fibfusc(n)
fibfusc(2n + 1) = (-y(2x + 3y), (x + 2y)(x + 4y)), where (x, y) = fibfusc(n)

Your job is to produce the code for the fibfusc function. In this kata, your function will be tested with small values of n, so you should not need to be concerned about stack overflow or timeouts.

*/

package main

func main() {
	test(0, 1, 0)
	test(1, 0, 1)
	test(2, -1, 3)
	test(3, -3, 8)
	test(4, -8, 21)
	test(5, -21, 55)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n, rx, ry int) {
	x, y := fibfusc(n)
	assert(x == rx)
	assert(y == ry)
}

func fibfusc(n int) (int, int) {
	if n < 0 {
		return 0, 0
	}
	if n == 0 {
		return 1, 0
	}
	if n == 1 {
		return 0, 1
	}

	x, y := fibfusc(n / 2)
	a := (x + y) * (x - y)
	b := y * (2*x + 3*y)
	if n&1 == 0 {
		return a, b
	}
	return -b, (x + 2*y) * (x + 4*y)
}
