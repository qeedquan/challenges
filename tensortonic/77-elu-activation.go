/*

The Exponential Linear Unit (ELU) is an activation function that pushes mean activations closer to zero, which speeds up learning. Unlike ReLU, ELU produces a smooth curve for negative inputs, reducing the impact of the vanishing gradient problem.

Given a list of values and a parameter alpha, apply the ELU activation to each element.

Formula
ELU(x) = x             if x > 0
         a*(e^x - 1)   if x <= 0

The parameter alpha controls the negative saturation value. As x approaches negative infinity, ELU(x) approaches -alpha.

Examples
Input: x = [1, -1, 0, 2, -0.5], alpha = 1

Output: [1, -0.6321205588, 0, 2, -0.3934693403]

Explanation: Positive values pass through, while nonpositive values use the exponential branch.

Input: x = [-1, -2, -3], alpha = 2

Output: [-1.2642411177, -1.7293294335, -1.9004258633]

Hint 1
Use the original value when it is positive.

Hint 2
Use alpha times exp(value) minus one for the nonpositive branch.

Requirements
Apply the ELU formula element-wise to each value in the input list
Use the alpha parameter for negative values
Return a list of floats with the same length as the input
Constraints
Input list has at least one element
alpha >= 0
Return a list of floats with the same length as input
Time limit: 300 ms

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	x1 := []float64{1, -1, 0, 2, -0.5}
	x2 := []float64{-1, -2, -3}

	fmt.Println(solve(x1, 1))
	fmt.Println(solve(x2, 2))
}

func solve(x []float64, alpha float64) []float64 {
	for i := range x {
		x[i] = elu(x[i], alpha)
	}
	return x
}

func elu(x, alpha float64) float64 {
	if x > 0 {
		return x
	}
	return alpha * (math.Exp(x) - 1)
}
