/*

Find the value of the variable y for a given real value of the variable x.

y = x^3 - 5x^2/7 + 9x - 3/x + 1

Input
One real number x.

Output
Print the value of the variable y rounded to three decimal places.

Examples
Input #1
1

Answer #1
7.286

*/

package main

import "fmt"

func main() {
	fmt.Printf("%.3f\n", solve(1))
}

func solve(x float64) float64 {
	return x*x*x - 5*x*x/7 + 9*x - 3/x + 1
}
