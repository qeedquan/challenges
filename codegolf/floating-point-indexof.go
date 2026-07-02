/*

Given a sorted array of unique positive integers A (A0<A1<⋯<An−1), and an integer t, where A0≤t≤An−1. Output the value i such that:

If t∈A, Ai=t.
If t∉A, (i−⌊i⌋)⋅A⌈i⌉+(⌈i⌉−i)⋅A⌊i⌋=t. In other words, linearly interpolate between the indices of the two elements of A that most narrowly bound t.
In the above formula, ⌊i⌋ means rounding i down to integer; ⌈i⌉ means rounding i up to integer.

You may also choose 1-indexed array, though you need to adjust the formula and the test cases below accordingly.

Rules
This is code-golf, shortest code in bytes wins.
Floating point errors in output are allowed, but reasonable floating point precision is required. For testcases listed here, your output should be correct with at least 2 decimal places precision.
Fraction output is allowed as long as fractions are reduced to their lowest terms.
It is fine to use any built-ins in your language. But if built-ins trivialize the question, consider submitting a non-trivial one too.

Testcases
[42], 42 -> 0
[24, 42], 24 -> 0
[24, 42], 42 -> 1
[1, 3, 5, 7, 8, 10, 12], 1 -> 0
[1, 3, 5, 7, 8, 10, 12], 7 -> 3
[1, 3, 5, 7, 8, 10, 12], 12 -> 6
[24, 42], 33 -> 0.5
[24, 42], 30 -> 0.3333333333333333
[1, 3, 5, 7, 8, 10, 12], 2 -> 0.5
[1, 3, 5, 7, 8, 10, 12], 9 -> 4.5
[100, 200, 400, 800], 128 -> 0.28
[100, 200, 400, 800], 228 -> 1.14
[100, 200, 400, 800], 428 -> 2.07

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test([]float64{42}, 42, 0)
	test([]float64{24, 42}, 24, 0)
	test([]float64{24, 42}, 42, 1)
	test([]float64{1, 3, 5, 7, 8, 10, 12}, 1, 0)
	test([]float64{1, 3, 5, 7, 8, 10, 12}, 7, 3)
	test([]float64{1, 3, 5, 7, 8, 10, 12}, 12, 6)
	test([]float64{24, 42}, 33, 0.5)
	test([]float64{24, 42}, 30, 0.3333333333333333)
	test([]float64{1, 3, 5, 7, 8, 10, 12}, 2, 0.5)
	test([]float64{1, 3, 5, 7, 8, 10, 12}, 9, 4.5)
	test([]float64{100, 200, 400, 800}, 128, 0.28)
	test([]float64{100, 200, 400, 800}, 228, 1.14)
	test([]float64{100, 200, 400, 800}, 428, 2.07)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []float64, t, r float64) {
	p := indexof(a, t)
	fmt.Println(p)
	assert(math.Abs(p-r) < 1e-9)
}

func indexof(a []float64, t float64) float64 {
	r := 0.0
	i := 0
	for ; i < len(a) && a[i] < t; i++ {
		r++
	}
	if i > 0 {
		r -= (a[i] - t) / (a[i] - a[i-1] + 1e-9)
	}
	return r
}
