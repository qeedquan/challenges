/*

Compute the value of the expression for the given real numbers x and y.

sqrt(x^2 + y^2)/(x - y)^2 - 2xy/sqrt(x^2 + y^2)

Input
Values of the variables x and y.

Output
Print the value of the given expression with precision to the thousandths.

Examples

Input #1
1.000 -2.000

Answer #1
2.037

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Printf("%.3f\n", solve(1, -2))
}

func solve(x, y float64) float64 {
	s := math.Sqrt(x*x + y*y)
	return s/((x-y)*(x-y)) - 2*x*y/s
}
