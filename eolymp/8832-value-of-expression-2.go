/*

Compute the value of the expression for the given real numbers x and y.

(x^2 - 2xy + 4y^2)/(x + 5) + (3x^2 - y^2)/(y - 7)

Input
Values of the variables x and y.

Output
Print the value of the given expression with precision to the thousandths.

Examples

Input #1
1.000 -2.000

Answer #1
3.611

*/

package main

import "fmt"

func main() {
	fmt.Printf("%.3f\n", solve(1, -2))
}

func solve(x, y float64) float64 {
	return (x*x-2*x*y+4*y*y)/(x+5) + (3*x*x-y*y)/(y-7)
}
