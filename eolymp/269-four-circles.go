/*

https://static.e-olymp.com/content/b6/b688da921ccd1cfe6288e01d8903e8f1c36a7cfc.jpg

Four circles are mutually tangent to one another as shown in the diagram.
If the radii of the three larger circles are a, b, and c, what is the radius of the fourth circle?

Input
The only line contains three integers a, b, c (1≤a,b,c≤1000) — the radii of the larger circles.

Output
Print the radius of the fourth, smallest, circle as a real number rounded to 4 digits after the decimal point.

Examples

Input #1
1 2 3

Answer #1
0.2609

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(1, 2, 3))
}

// https://en.wikipedia.org/wiki/Descartes%27_theorem
func solve(a, b, c float64) float64 {
	k1 := 1 / a
	k2 := 1 / b
	k3 := 1 / c
	k4 := k1 + k2 + k3 + 2*math.Sqrt(k1*k2+k2*k3+k3*k1)
	return 1 / math.Abs(k4)
}
