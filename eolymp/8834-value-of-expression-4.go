/*

Compute the value of the expression for the given real numbers x and y.

2xy/sqrt(x^2 + y^2) - (x + y - 1)^2/(xy)

Input
Values of the variables x and y.

Output
Print the value of the given expression with precision to the thousandths.

Examples

Input #1
1.000 -2.000

Answer #1
-1.143

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
	return 2*x*y/math.Sqrt(x*x+y*y) - (x+y-1)*(x+y-1)/(x*y)
}
