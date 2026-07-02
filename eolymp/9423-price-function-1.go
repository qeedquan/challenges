/*

y = lg(a)^3 + cos(x)^5
a = c^4 + k^3
c = sqrt(|x|)

Calculate the value of the price function:

Input
Two real numbers x and k are given.

Output
Output the value of the price function y rounded to 2 decimal digits.

Examples
Input #1
5 8.2

Answer #1
21.04

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Printf("%.2f\n", solve(5, 8.2))
}

func solve(x, k float64) float64 {
	c := math.Sqrt(math.Abs(x))
	a := math.Pow(c, 4) + math.Pow(k, 3)
	y := math.Pow(math.Log10(a), 3) + math.Pow(math.Cos(x), 5)
	return y
}
