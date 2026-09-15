/*

Find such number x that x^2+ x = C with no less than 6 digits after the decimal point.

Input
One real number C (1.0≤C≤10^10).

Output
Print the root x with no less than 6 digits after the decimal point.

# Examples

Input #1
2.0000000000

Answer #1
1.000000000

Input #2
18.0000000000

Answer #2
4.000000000

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(2))
	fmt.Println(solve(18))
}

func solve(c float64) float64 {
	const eps = 1e-15

	lo := 0.0
	hi := math.MaxFloat64
	for hi-lo > eps {
		mid := lo + (hi-lo)/2
		if f(mid) >= c {
			hi = mid
		} else {
			lo = mid
		}
	}
	return hi
}

func f(x float64) float64 {
	return x*x + math.Sqrt(x)
}
