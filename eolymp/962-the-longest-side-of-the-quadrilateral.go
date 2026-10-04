/*

Given a quadrilateral on the plane defined by the coordinates of its vertices. Calculate the length of its longest side.

Input
A single line containing the X and Y coordinates of the vertices of the quadrilateral, separated by spaces: the first point A, then B, then C, and D.
All input data are integers with absolute values not exceeding 100.

Output
Output a single number — the length of the longest side, accurate to two decimal places.

Examples

Input #1
3 5 6 6 7 2 1 1

Answer #1
6.08

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Printf("%.2f\n", solve(3, 5, 6, 6, 7, 2, 1, 1))
}

func solve(a1, a2, b1, b2, c1, c2, d1, d2 float64) float64 {
	AB := math.Sqrt((b1-a1)*(b1-a1) + (b2-a2)*(b2-a2))
	BC := math.Sqrt((c1-b1)*(c1-b1) + (c2-b2)*(c2-b2))
	CD := math.Sqrt((d1-c1)*(d1-c1) + (d2-c2)*(d2-c2))
	DA := math.Sqrt((a1-d1)*(a1-d1) + (a2-d2)*(a2-d2))
	return max(AB, BC, CD, DA)
}
