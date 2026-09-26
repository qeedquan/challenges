/*

Compute the value of the expression for the given real numbers x and y.

(2x + y)/(x^2 - xy + 4y^2) + (2x^2 - xy + y^2)/(x + 4y)

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

import "fmt"

func main() {
	fmt.Printf("%.3f\n", solve(1, -2))
}

func solve(x, y float64) float64 {
	return (2*x+y)/(x*x-x*y+4*y*y) + (2*x*x-x*y+y*y)/(x+4*y)
}
