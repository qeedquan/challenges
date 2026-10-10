/*

https://static.e-olymp.com/content/53/53de119ca21346bc658a51b2e42f1851c11e9ed9.jpg

The sides a, b, c, d and the diagonal f of a convex quadrilateral are given.
Determine the area of the quadrilateral using Heron's formula to calculate the area of a triangle.

Input
In one line, five real numbers are given: a, b, c, d, f (0<a,b,c,d,f≤100), as shown in the picture.

Output
Print the area of the quadrilateral, calculated to 4 decimal places.

Examples

Input #1
3 4 4 2 5

Answer #1
9.7997

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Printf("%.4f\n", solve(3, 4, 4, 2, 5))
}

func solve(a, b, c, d, f float64) float64 {
	p1 := (a + b + f) / 2
	p2 := (d + c + f) / 2
	S1 := math.Sqrt(p1 * (p1 - a) * (p1 - b) * (p1 - f))
	S2 := math.Sqrt(p2 * (p2 - d) * (p2 - c) * (p2 - f))
	S := S1 + S2
	return S
}
