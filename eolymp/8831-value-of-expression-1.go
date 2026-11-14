/*

Compute the value of the expression for the given real numbers x and y.

2x^2 - 4xy + 3y^2 + (x+y)/7

Input
Two real numbers x and y.

Output
Print the value of the given expression with precision to the thousandths.

Examples

Input #1
1.000 -2.000

Answer #1
21.857

*/

package main

import "fmt"

func main() {
	fmt.Printf("%.3f\n", solve(1, -2))
}

func solve(x, y float64) float64 {
	return 2*x*x - 4*x*y + 3*y*y + (x+y)/7
}
