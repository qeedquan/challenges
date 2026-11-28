/*

Implement the sigmoid activation function:

o(x) = 1 / (1 + e^(-x))

Return a float when x is a scalar. For a list or nested list, return a NumPy array of floats with the same shape as x.

Examples
Input: x = [0, 2, -2]

Output: [0.5, 0.88079708, 0.11920292]

Input: x = 0

Output: 0.5

Input: x = [[-1, 0], [1, 2]]

Output: [[0.26894142, 0.5], [0.73105858, 0.88079708]]

Hint 1
Convert the input with np.asarray(x, dtype=float) before applying elementwise operations.

Hint 2
Use np.exp on the negated array when computing the sigmoid expression.

Requirements
Input x may be a scalar, a Python list, or a nested Python list
Return a float when x is a scalar
Return a NumPy array of floats with the same shape when x is a list
Use a fully vectorized implementation without Python loops
Constraints
Vectorized implementation only
Time limit: 200 ms; Memory: 64 MB
Allowed library: NumPy only

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	x1 := []float64{0, 2, -2}
	x2 := 0.0
	x3 := [][]float64{{-1, 0}, {1, 2}}

	fmt.Println(solve(x1))
	fmt.Println(solve(x2))
	fmt.Println(solve(x3))
}

func solve(x any) any {
	switch x := x.(type) {
	case float64:
		return sigmoid(x)
	case []float64:
		for i := range x {
			x[i] = sigmoid(x[i])
		}
		return x
	case [][]float64:
		for i := range x {
			for j := range x {
				x[i][j] = sigmoid(x[i][j])
			}
		}
		return x
	default:
		panic("unreachable")
	}
}

func sigmoid(x float64) float64 {
	return 1 / (1 + math.Exp(-x))
}
