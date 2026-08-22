/*

Let's do a simple approximation of the integral of a continuous function.

In this kata, we will implement: left_riemann(f, n, a, b)

In the test, we will pass a function that takes a single float argument to compute the value of the function. Your job is to approximate the integral of that function on the closed interval [a,b] with n rectangles. You will use the left hand rule. For a better explanation of the assigment visit the wikipedia page on riemann sums linked below:

http://en.wikipedia.org/wiki/Riemann_sum

f will always take a single float argument
f will always be a "nice" function, don't worry about NaN
n will always be a natural number (0, N]
b > a
and n will be chosen appropriately given the length of [a, b] (as in I will not have step sizes smaller than machine epsilon)

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(square, 1, 0, 1, 0)
	test(square, 4, 1, 2, 1.96875)
	test(cube, 2, -1, 1, -1)
	test(cube, 20, -2, 1, -4.441875)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(f func(float64) float64, n, a, b, r float64) {
	v := left_riemann(f, n, a, b)
	fmt.Println(v)
	assert(math.Abs(v-r) < 1e-6)
}

func left_riemann(f func(float64) float64, n, a, b float64) float64 {
	r := 0.0
	dx := (b - a) / n
	for i := 0.0; i < n; i += 1 {
		r += f(i*dx + a)
	}
	r *= dx
	return r
}

func square(x float64) float64 {
	return x * x
}

func cube(x float64) float64 {
	return x * x * x
}
