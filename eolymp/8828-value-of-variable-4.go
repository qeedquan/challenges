/*

Find the value of the variable y for a given real value of the variable x.

y = (2x-1)/x^2 + sqrt(x^2 + 1)/2

Input
One real number x.

Output
Print the value of the variable y rounded to three decimal places.

Examples
Input #1
1

Answer #1
1.707

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
	return (2*x-1)/(x*x) + math.Sqrt(x*x+1)/2
}
