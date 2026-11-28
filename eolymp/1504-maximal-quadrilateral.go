/*

A circle is inscribed in a quadrilateral, and the circle touches all four sides of it.
Given the perimeter and the lengths of two adjacent sides of the quadrilateral, you must find the maximum possible radius of the circle.

Input
The first line of the input file contains an integer n (n≤100) that indicates how many sets of input there are.
Each of the next n lines contains three integers p, a, b. Here, p is the perimeter and a, b are the lengths of two adjacent sides of the quadrilateral.

Output
For each line of input except the first one, produce one line of output.
This line should contain the serial number, and then the maximum possible radius of the circle.
The radius should have six digits after the decimal point. If the formation of such a quadrilateral is impossible, print the line Eta Shombhob Na.
(Sorry! It is a sentence in Bangla, which means "This is impossible.").
The lengths of all sides of a valid quadrilateral should be positive.

Examples

Input #1
2
20 5 6
20 10 12

Answer #1
Case 1: 2.449490
Case 2: Eta Shombhob Na.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(20, 5, 6))
	fmt.Println(solve(20, 10, 12))
}

func solve(p, a, b float64) any {
	c := (p - 2*a) / 2
	d := (p - 2*b) / 2
	if a+b >= p || c <= 0 || d <= 0 {
		return "Eta Shombhob Na."
	}
	s := math.Sqrt(a * b * c * d)
	r := 2 * s / p
	return r
}
