/*

Task:
Based on the received dimensions, a and b, of an ellipse, calculare its area and perimeter.

Example:
Input: elipse(5,2)

Output: "Area: 31.4, perimeter: 23.1"
Note: The perimeter approximation formula you should use: π * (3/2(a+b) - sqrt(ab))

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	assert(solve(5, 2) == "Area: 31.4, perimeter: 23.1")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b float64) string {
	A := math.Pi * a * b
	P := math.Pi * (1.5*(a+b) - math.Sqrt(a*b))
	return fmt.Sprintf("Area: %.1f, perimeter: %.1f", A, P)
}
