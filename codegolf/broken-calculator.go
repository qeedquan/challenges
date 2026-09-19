/*

The functions receives 5 numbers, let's call them a, b, c, d and e
You must display two numbers.
First one is (((a + b) - c) * d) % e = f
Second one is (((a + b) - c) * d - f) / e

Input:             Output:
7  5  9  3 8       1 1
1  2  3  4 5       0 0
19 25 9  7 11      3 22
21 12 99 3 13      -3 -15
21 12 99 3 -4      -2 49
Requirement: You are not allowed to use '+' '-' '*' '/' symbols (or equivalent) when doing the calculation. You may however use '%' symbol (or equivalent) when doing the calculation.
By equivalent I meant that you are not allowed to use functions such as BigInteger.add() (I am looking at you java users).

Shortest code wins.

EDIT: as Peter suggested a clarification. All input numbers are int, and will never be 0

*/

package main

import "fmt"

func main() {
	test(7, 5, 9, 3, 8, 1, 1)
	test(1, 2, 3, 4, 5, 0, 0)
	test(19, 25, 9, 7, 11, 3, 22)
	test(21, 12, 99, 3, 13, -3, -15)
	test(21, 12, 99, 3, -4, -2, 49)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b, c, d, e, r0, r1 int) {
	x0, x1 := calc(a, b, c, d, e)
	fmt.Println(x0, x1)
	assert(x0 == r0)
	assert(x1 == r1)
}

func calc(a, b, c, d, e int) (int, int) {
	if e == 0 {
		return 0, 0
	}
	f := ((a + b - c) * d) % e
	g := ((a+b-c)*d - f) / e
	return f, g
}
