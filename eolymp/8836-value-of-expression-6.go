/*

Compute the value of the expression for the given real numbers x and y.

(x - y)^2 / sqrt(x^2 + y^2 - 1) + sqrt(x^2 + y^2 - 1) / (2xy)

Input
Values of the variables x and y.

Output
Print the value of the given expression with precision to the thousandths.

Examples

Input #1
1.000 -2.000

Answer #1
4.000

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
	s := math.Sqrt(x*x + y*y - 1)
	return (x-y)*(x-y)/s + s/(2*x*y)
}
