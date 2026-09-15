/*

Find the value of the variable y for a given real value of the variable x.

y = x - (x^2+4)/2 + x^3 - 3/(x+7)

Input
One real number x.

Output
Print the value of the variable y rounded to three decimal places.

Examples
Input #1
1

Answer #1
-0.875

*/

package main

import "fmt"

func main() {
	fmt.Printf("%.3f\n", solve(1))
}

func solve(x float64) float64 {
	return x - (x*x+4)/2 + x*x*x - 3/(x+7)
}
