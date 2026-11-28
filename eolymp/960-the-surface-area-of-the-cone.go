/*

Calculate the total surface area of a truncated cone, given the base radii R, r, and height h.

Input
A single line contains the base radii R, r, and height h separated by spaces. All input values are integers not exceeding 100.

Output
Print the total surface area of the truncated cone in a single line. Output the result to two decimal places.

Examples

Input #1
4 3 5

Answer #1
190.67

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Printf("%.2f\n", area(4, 3, 5))
}

func area(R, r, h float64) float64 {
	if r == R {
		return 2*math.Pi*r*h + 2*math.Pi*r*r
	}

	h1 := r * h / (R - r)
	A1 := math.Pi * r * math.Sqrt(r*r+h1*h1)
	A2 := math.Pi * R * math.Sqrt(R*R+(h1+h)*(h1+h))
	return A2 - A1 + math.Pi*R*R + math.Pi*r*r
}
