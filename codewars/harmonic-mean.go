/*

The harmonic mean is reciprocal average of reciprocals.

It's calculated as the length of the array arr divided by the sum of reciprocals of the array arr.

If the array length is 0, return 0.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test([]float64{1, 2}, 1.3333333333333333)
	test([]float64{}, 0)
	test([]float64{5, 15, 6, 24, 50, 100, 60, 1}, 5.257393209200438)
	test([]float64{77}, 77)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []float64, r float64) {
	m := harmonic(a)
	fmt.Println(m)
	assert(math.Abs(m-r) < 1e-12)
}

func harmonic(a []float64) float64 {
	n := len(a)
	if n == 0 {
		return 0
	}

	r := 0.0
	for _, v := range a {
		r += 1 / v
	}
	return float64(n) / r
}
