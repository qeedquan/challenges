/*

About the series
This question is now part of a series about the AGM method. This first post in the series will be about actually calculating the AGM. You may treat this like any other code golf challenge, and answer it without worrying about the series at all. However, there is a leaderboard across all challenges.

What is the Arithmetic–Geometric Mean
The Arithmetic–Geometric Mean of two numbers is defined as the number that repeatedly taking the arithmetic and geometric means converges to. Your task is to find this number after some n iterations.

Clarifications
You take three numbers, a, b, n in any reasonable format.
For n iterations, take the arithmetic and geometric mean of a and b and set those to a and b.
For two numbers a and b, the arithmetic mean is defined as (a + b) / 2.
The geometric mean is defined as √(a * b).
a and b should be approaching each other.
Then, output both a and b.
You don't have to worry about float imprecision and such.
This is code-golf so shortest code in bytes wins!
Test Cases
[0, [24, 6]] -> [24, 6]
[1, [24, 6]] -> [15.0, 12.0]
[2, [24, 6]] -> [13.5, 13.416407864998739]
[5, [24, 6]] -> [13.458171481725616, 13.458171481725616]
[10, [100, 50]] -> [72.83955155234534, 72.83955155234534]

The next one is 1/Gauss's Constant:
[10, [1, 1.41421356237]] -> [1.198140234734168, 1.1981402347341683]

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(0, 24, 6, 24, 6)
	test(1, 24, 6, 15, 12)
	test(2, 24, 6, 13.5, 13.416407864998739)
	test(5, 24, 6, 13.458171481725616, 13.458171481725616)
	test(10, 100, 50, 72.83955155234534, 72.83955155234534)
	test(10, 1, 1.41421356237, 1.198140234734168, 1.1981402347341683)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, a, b, ra, rb float64) {
	const eps = 1e-8
	ca, cb := agm(n, a, b)
	fmt.Println(ca, cb)
	assert(math.Abs(ca-ra) < eps)
	assert(math.Abs(cb-rb) < eps)
}

func agm(n int, a, b float64) (float64, float64) {
	for i := 0; i < n; i++ {
		a, b = (a+b)/2, math.Sqrt(a*b)
	}
	return a, b
}
