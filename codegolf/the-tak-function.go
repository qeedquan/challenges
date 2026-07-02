/*

The TAK function is defined as follows for integers x, y, z:

t(x,y,z) = y if x <= y
           t(t(x-1,y,z),t(y-1,z,x),t(z-1,x,y)) otherwise

Since it can be proved that it always terminates and evaluates to the simple function below,

t(x,y,z) = y, if x <= y
           z, if x > y and y <= z
		   x, otherwise

your job is not to just implement the function, but count the number of calls to t when initially called with the given values of x, y, and z. (As per the standard rules, you don't need to implement t if there is a formula for this value.)

You may assume that the three input values are nonnegative integers.

Note that the task is slightly different from the definition of the function T (the number of "otherwise" branches taken) on the Mathworld page.

Standard code-golf rules apply. The shortest code in bytes wins.

Test cases
(x, y, z) -> output

(0, 0, 1) -> 1
(1, 0, 2) -> 5
(2, 0, 3) -> 17
(3, 0, 4) -> 57
(4, 0, 5) -> 213
(5, 0, 6) -> 893

(1, 0, 0) -> 5
(2, 0, 0) -> 9
(2, 1, 0) -> 9
(3, 0, 0) -> 13
(3, 1, 0) -> 29
(3, 2, 0) -> 17
(4, 0, 0) -> 17
(4, 1, 0) -> 89
(4, 2, 0) -> 53
(4, 3, 0) -> 57
(5, 0, 0) -> 21
(5, 1, 0) -> 305
(5, 2, 0) -> 149
(5, 3, 0) -> 209
(5, 4, 0) -> 213
Python implementation was used to generate the test cases.

*/

package main

import "fmt"

func main() {
	test(0, 0, 1, 1)
	test(1, 0, 2, 5)
	test(2, 0, 3, 17)
	test(3, 0, 4, 57)
	test(4, 0, 5, 213)
	test(5, 0, 6, 893)

	test(1, 0, 0, 5)
	test(2, 0, 0, 9)
	test(2, 1, 0, 9)
	test(3, 0, 0, 13)
	test(3, 1, 0, 29)
	test(3, 2, 0, 17)
	test(4, 0, 0, 17)
	test(4, 1, 0, 89)
	test(4, 2, 0, 53)
	test(4, 3, 0, 57)
	test(5, 0, 0, 21)
	test(5, 1, 0, 305)
	test(5, 2, 0, 149)
	test(5, 3, 0, 209)
	test(5, 4, 0, 213)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x, y, z, r int) {
	_, n := tak(x, y, z)
	fmt.Println(n)
	assert(n == r)
}

// https://mathworld.wolfram.com/TAKFunction.html
func tak(x, y, z int) (int, int) {
	if x <= y {
		return y, 1
	}

	tx, nx := tak(x-1, y, z)
	ty, ny := tak(y-1, z, x)
	tz, nz := tak(z-1, x, y)
	r, n := tak(tx, ty, tz)
	return r, nx + ny + nz + n + 1
}
