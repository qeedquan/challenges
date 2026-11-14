/*

Find the value of the variable y for a given real value of the variable x.

y = 2x/(sqrt(x^2 + 1)) - sqrt(x^2 + 1)/x^3

Input
Value of the variable x.

Output
Print the value of the variable y up to thousandths.

Examples

Input #1
1

Answer #1
0.000

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Printf("%.4f\n", solve(1))
}

func solve(x float64) float64 {
	s := math.Sqrt(x*x + 1)
	return 2*x/s - s/(x*x*x)
}
