/*

Task
You have to write a madDiv(a,b) function returning a value of a / b without / in your code.

Coding Limitation:
Less than 30 characters

Input:
a and b : integer ( 0-10000 )

Note: Only first 10 decimal places will be evaluated.

*/

package main

import (
	"math"
)

func main() {
	n := 1e4
	s := 1.0
	for a := -n; a <= n; a += s {
		for b := -n; b <= n; b += s {
			x := a / b
			y := maddiv(a, b)
			if math.IsNaN(x) {
				assert(math.IsNaN(y))
			} else if math.IsInf(x, 0) {
				assert(math.IsInf(y, 0))
			} else {
				assert(math.Abs(x-y) < 1e-10)
			}
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func maddiv(a, b float64) float64 {
	return a * math.Pow(b, -1)
}
