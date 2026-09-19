/*

You're going to create a function that takes a function f and returns a new function that computes f's derivative (approximately). f will be a function of one variable.

You can assume that the input function will be differentiable.

Results should be accurate to two decimal places.

You can use testApprox(actual, expected) to test your answers.

*/

package main

import (
	"fmt"
	"math"
)

type fn func(float64) float64

func main() {
	f1 := derivative(square)
	f2 := derivative(cube)
	f3 := derivative(math.Exp)
	f4 := derivative(math.Sin)
	for i := 0.0; i <= 10; i++ {
		fmt.Println(i, f1(i), f2(i), f3(i), f4(i))
	}
}

func square(x float64) float64 {
	return x * x
}

func cube(x float64) float64 {
	return x * x * x
}

func derivative(f fn) fn {
	return func(x float64) float64 {
		const h = 1e-13
		return (f(x+h) - f(x)) / h
	}
}
