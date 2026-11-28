/*

Polynomial feature expansion represents one numeric value using successive powers. This allows a linear model to learn relationships such as curves when the expanded values are supplied as separate features.

For each input value, generate powers from zero through degree:

phi(x) = [1, x, x^2, ..., x^d]

Here, x is an input value, d is the maximum degree, and the resulting vector is the expanded feature row. The first element is always 1 and serves as the intercept feature. Return one row containing degree + 1 values for every input value.

Examples
Input: values = [2, 3], degree = 2

Output: [[1, 2, 4], [1, 3, 9]]

Explanation: Each row contains powers zero, one, and two of its input value.

Input: values = [-2], degree = 3

Output: [[1, -2, 4, -8]]

Hint 1
Use range through degree inclusive for each input value.

Hint 2
Raise the value to every exponent, including zero for the intercept feature.

Requirements
For each value, generate powers from 0 to degree (inclusive)
Include x^0 = 1 as the first element (bias term)
Return a list of lists where each inner list has degree + 1 elements
Constraints
values has at least 1 element
degree >= 0
Return a list of lists of numbers
Time limit: 300 ms

*/

package main

import "fmt"

func main() {
	fmt.Println(solve([]float64{2, 3}, 2))
	fmt.Println(solve([]float64{-2}, 3))
}

func solve(values []float64, degree int) [][]float64 {
	result := [][]float64{}
	for _, value := range values {
		features := []float64{}
		polynomial := 1.0
		for range degree + 1 {
			features = append(features, polynomial)
			polynomial *= value
		}
		result = append(result, features)
	}
	return result
}
