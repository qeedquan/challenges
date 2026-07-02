/*

Let function f(x) be defined as

f(x) = sin(x) + sqrt(log_4(3*x)) + ceil(abs(3*exp(x)))

Calculate the value of f(x) for a given x.

Input
Each line contains one double value x (x≥1).

Output
For each value x print on a separate line the value f(x) with 6 digits after the decimal point.

Examples

Input #1
1
2.3
2.56
7.123456

Answer #1
10.731685
31.926086
40.762019
3725.231017

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Printf("%.6f\n", solve(1))
	fmt.Printf("%.6f\n", solve(2.3))
	fmt.Printf("%.6f\n", solve(2.56))
	fmt.Printf("%.6f\n", solve(7.123456))
}

func solve(x float64) float64 {
	return math.Sin(x) + math.Sqrt(math.Log2(3*x)/2) + math.Ceil(math.Abs(3*math.Exp(x)))
}
