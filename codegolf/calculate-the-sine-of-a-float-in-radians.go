/*

…without using any operator/function besides addition (+), subtraction (-), multiplication (*), division (/), modulo (%), exponent/power pow() or any of the standard C bitwise operators (<<, >>, ~, &, |, ^) or unary operators (—, ++) or assignment/comparison operators (=, ==).

If these symbols represent a different operation in your chosen language, go with the spirit of the question and don't use them.

Rules:

You cannot use any mathematical functions your language might offer (Mathematica, looking at you.)
You cannot use any operator besides the bitwise operators or the arithmetic operators listed above.
Your output should be a float and be correct to at least 2 decimal places when truncated/rounded.
You can use constants your language's standard libraries might provide.
You can hardcode the values, but your program should work correctly for all floats (up to 2 decimal places) between 0 and 2π;
This is code-golf, so the shortest answer wins.

Example:

Input: 3.141592653 / 2
Output: 1.00xxxxxx…
Please also post an ungolfed version of your code.

*/

package main

import "math"

func main() {
	for x := -100 * math.Pi; x <= 100*math.Pi; x += 1e-3 {
		assert(math.Abs(math.Sin(x)-sinapx(x)) < 1e-2)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://realtimecollisiondetection.net/blog/?p=9
func sinrgr(x float64) float64 {
	// range reduce to [-2*PI, 2*PI]
	k := x * 1 / (2 * math.Pi)
	x = x - (math.Floor(k) * 2 * math.Pi)

	// map [-2*PI, 2*PI] to [-PI/2, PI/2]
	x = min(x, math.Pi-x)
	x = max(x, -math.Pi-x)
	x = min(x, math.Pi-x)
	return x
}

// https://en.wikipedia.org/wiki/Bh%C4%81skara_I%27s_sine_approximation_formula
func sinapx(x float64) float64 {
	x = sinrgr(x)
	s := 1.0
	if x < 0 {
		x += math.Pi
		s = -1
	}

	a := 16 * x * (math.Pi - x)
	b := 5*math.Pi*math.Pi - 4*x*(math.Pi-x)
	return s * (a / b)
}
