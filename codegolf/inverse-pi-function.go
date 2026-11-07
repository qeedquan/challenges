/*

The Pi function is an extension of the factorial over the reals (or even complex numbers). For integers n, Π(n) = n!, but to get a definition over the reals we define it using an integral:

Pi(z) = Integral[0, oo] (e^-t * t^z) dt

In this challenge we will invert the Π function.

Given a real number z ≥ 1, find positive x such that Π(x) = z. Your answer must be accurate for at least 5 decimal digits.

Examples:

120 -> 5.0000
10 -> 3.39008
3.14 -> 2.44815
2017 -> 6.53847
1.5 -> 1.66277

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(120, 5)
	test(10, 3.39008)
	test(3.14, 2.44815)
	test(2017, 6.53847)
	test(1.5, 1.66277)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(z, r float64) {
	x := invpi(z)
	fmt.Println(x)
	assert(math.Abs(x-r) < 1e-5)
}

/*

@Digital Trauma

gamma(x+1) is a monotonically increasing function over the range in question, this is just a binary search until the difference between successive values is small.
The starting lower bound is 0 and the starting upper bound is 2*x.

*/

func invpi(z float64) float64 {
	u := 2 * z
	l := 0.0
	g := u
	p := 0.0
	for math.Log(math.Abs(g-p)) > -1e16 {
		p = g
		g = (u + l) / 2
		if math.Gamma(g+1) > z {
			u = g
		} else {
			l = g
		}
	}
	return g
}
