/*

Implement a function f(x) = sqrt(x) + 2*x + sin(x).

Input
Each line contains one real number x.

Output
For each value x print in a separate line the value of the function f(x) with four digits after the decimal point.

Examples

Input #1
2.234
10.23
56.1
23.2651

Answer #1
6.7507
22.9375
119.2562
50.3973

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Printf("%.4f\n", solve(2.234))
	fmt.Printf("%.4f\n", solve(10.23))
	fmt.Printf("%.4f\n", solve(56.1))
	fmt.Printf("%.4f\n", solve(23.2651))
}

func solve(x float64) float64 {
	return math.Sqrt(x) + 2*x + math.Sin(x)
}
