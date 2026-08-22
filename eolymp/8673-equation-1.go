/*

For given positive integer k solve the equation

x^(1/4) + x^(1/2) + x = k

It is known that the equation has one root.

Input
One positive integer k (k≤10^9).

Output
Print the single root of the equation with 4 decimal digits.

Examples

Input #1
2

Answer #1
0.4776

*/

package main

import (
	"fmt"
	"math"
)

type fn func(float64) float64

func main() {
	fmt.Println(solve(2))
}

func solve(k float64) float64 {
	f, df := mkfn(k)
	return newton(f, df, k)
}

func newton(f, df fn, x0 float64) float64 {
	const eps = 1e-12
	x := x0
	for range 1000 {
		x -= f(x) / df(x)
		if math.Abs(f(x)) < eps {
			return x
		}
	}
	return math.NaN()
}

func mkfn(k float64) (f, df fn) {
	f = func(x float64) float64 {
		return math.Pow(x, 0.25) + math.Pow(x, 0.5) + x - k
	}

	df = func(x float64) float64 {
		return 0.25 * (1/math.Pow(x, 0.75) + 2/math.Pow(x, 0.5) + 4)
	}

	return
}
