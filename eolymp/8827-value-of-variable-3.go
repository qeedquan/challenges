/*

Find the value of the variable y for a given real value of the variable x.

y = (x^2 + 3x - 4) / (2x - 3) - (x + 2) / (x^2 - 5x + 7)

Input
One real number x.

Output
Print the value of the variable y rounded to three decimal places.

Examples
Input #1
1

Answer #1
-1.000

*/

package main

import "fmt"

func main() {
	fmt.Printf("%.3f\n", solve(1))
}

func solve(x float64) float64 {
	return (x*x+3*x-4)/(2*x-3) - (x+2)/(x*x-5*x+7)
}
