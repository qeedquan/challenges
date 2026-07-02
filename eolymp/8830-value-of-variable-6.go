/*

Find the value of the variable y for a given real value of the variable x.

y = sqrt(x^4 + 1)/x^2 - sqrt(x^2/(x^2+1))

Input
Value of the variable x.

Output
Print the value of the variable y up to thousandths.

Examples

Input #1
1

Answer #1
0.707

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Printf("%.3f\n", solve(1))
}

func solve(x float64) float64 {
	return math.Sqrt(x*x*x*x+1)/(x*x) - math.Sqrt(x*x/(x*x+1))
}
