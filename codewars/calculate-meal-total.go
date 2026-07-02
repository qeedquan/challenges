/*

Create a function that returns the total of a meal including tip and tax. You should not tip on the tax.

You will be given the subtotal, the tax as a percentage and the tip as a percentage. Please round your result to two decimal places.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(5, 5, 10, 5.75)
	test(36.97, 7, 15, 45.10)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(subtotal, tax, tip, expected float64) {
	value := total(subtotal, tax, tip)
	fmt.Printf("%.2f\n", value)
	assert(math.Abs(value-expected) < 1e-2)
}

func total(subtotal, tax, tip float64) float64 {
	percent := subtotal / 100
	return subtotal + percent*(tax+tip)
}
