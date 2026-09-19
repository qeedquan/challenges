/*

While preparing dinner for Mytsyk, the host cut the cheese into identical rectangular parallelepipeds with a square base of side A and height B.

However, Mytsyk preferred to enjoy cheese in slightly smaller portions.
For this, he would always stand the offered piece upright on the table with its square face down and cut it into two parts.
The knife was always placed along a diagonal of the square base, but he could not always split the piece exactly in half
because the blade formed a dihedral angle of Z∘ with the base.

Find the area S of the section created by Mytsyk's cut.

Input
The input contains integers A, B, Z (1≤A,B,Z≤90).

Output
Print the area S of the section, with 3 decimal places of precision.

Examples
Input #1
2 3 90

Answer #1
8.485

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Printf("%.3f\n", solve(2, 3, 90))
}

func solve(a, h, z int) float64 {
	if z == 90 {
		return float64(a*h) * math.Sqrt2
	}

	c := deg2rad(float64(z))
	d := math.Tan(c)
	if float64(2*h) < float64(a)*d {
		return (float64(a*a)/2 - sqr(float64(a)-float64(h)*math.Sqrt2/d)/2) / math.Cos(c)
	}
	return float64(a*a) / 2 / math.Cos(c)
}

func sqr(x float64) float64 {
	return x * x
}

func deg2rad(x float64) float64 {
	return x * math.Pi / 180
}
