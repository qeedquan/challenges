/*

Implement this function mapping 3 real coordinates to 3 real coordinates:

f(x, y, z) = ((1+x*y)**3*z+y**2*(1+x*y)*(4+3*x*y),
               y+3*x*(1+x*y)**2*z+3*x*y**2*(4+3*x*y),
               2*x-3*x**2*y-x**3*z)

This counterexample to the longstanding Jacobian Conjecture was found by Levent Alpöge and the LLM Fable during the World Cup.
https://xcancel.com/__alpoge__/status/2079028340955197566#m

Your code should work for real inputs. It's fine if float limitations cause tiny inaccuracies.

Python for copy-pasting:

f=lambda x,y,z:((1+x*y)**3*z+y**2*(1+x*y)*(4+3*x*y), y+3*x*(1+x*y)**2*z+3*x*y**2*(4+3*x*y), 2*x-3*x**2*y-x**3*z)
Test cases:

(0, 0, -0.25) -> (-0.25, 0.0, 0.0)
(1, -1.5, 6.5) -> (-0.25, 0.0, 0.0)
(-1, 1.5, 6.5) -> (-0.25, 0.0, 0.0)
(7, 20, 2026) -> (5703239346, 849418646, -697844)

*/

package main

import "fmt"

func main() {
	fmt.Println(f(0, 0, -0.25))
	fmt.Println(f(1, -1.5, 6.5))
	fmt.Println(f(-1, 1.5, 6.5))
	fmt.Println(f(7, 20, 2026))
}

func f(x, y, z float64) (float64, float64, float64) {
	X := cube(1+x*y)*z + sqr(y)*(1+x*y)*(4+3*x*y)
	Y := y + 3*x*sqr(1+x*y)*z + 3*x*sqr(y)*(4+3*x*y)
	Z := 2*x - 3*sqr(x)*y - cube(x)*z
	return X, Y, Z
}

func sqr(x float64) float64 {
	return x * x
}

func cube(x float64) float64 {
	return x * x * x
}
