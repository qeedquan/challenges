/*

Compute Dice loss for two equally shaped prediction and target masks. First calculate the smoothed Dice coefficient:

Dice(P, Y) = (2 * (Sum(P*Y)) + eps) / (Sum(P) + Sum(Y) + eps)

Then calculate the loss:

1 - Dice(P, Y)

Here, Pi and Yi are corresponding mask values and ε is eps.
Sum across every dimension and return the loss as a Python float.

Examples
Input: p = [0.9, 0.7, 0.1, 0.0], y = [1, 1, 0, 0], eps = 1e-8

Output: 0.135135

Explanation: The soft intersection is 1.6, producing a Dice coefficient of approximately 0.864865.

Input: p = [1.0, 1.0, 0.0, 0.0], y = [1, 1, 0, 0], eps = 1e-8

Output: 0.0

Input: p = [1.0, 1.0], y = [0, 0], eps = 1e-8

Output: 1.0

Hint 1
Use np.sum(p * y) for the soft intersection.

Hint 2
Compute the coefficient before returning 1.0 - coefficient.

Requirements
Sum the intersection and both masks across every dimension
Add eps to the numerator and denominator
Return Dice loss as a Python float
Constraints
p and y are nonempty numeric lists with the same shape
Prediction values are between 0 and 1
Target values are 0 or 1
eps is positive
Use NumPy only

*/

package main

import "fmt"

func main() {
	fmt.Println(solve(
		[]float64{0.9, 0.7, 0.1, 0.0},
		[]float64{1, 1, 0, 0},
		1e-8,
	))

	fmt.Println(solve(
		[]float64{1.0, 1.0, 0.0, 0.0},
		[]float64{1, 1, 0, 0},
		1e-8,
	))

	fmt.Println(solve(
		[]float64{1, 1},
		[]float64{0, 0},
		1e-8,
	))
}

func solve(p, y []float64, eps float64) float64 {
	return 1 - dice(p, y, eps)
}

/*

https://en.wikipedia.org/wiki/Dice-S%C3%B8rensen_coefficient

Measures similarity of 2 samples.
In image processing, it can measure how much 2 segmentation masks overlap

*/

func dice(p, y []float64, eps float64) float64 {
	sum_py := 0.0
	sum_p := 0.0
	sum_y := 0.0
	for i := range p {
		sum_py += p[i] * y[i]
		sum_p += p[i]
		sum_y += y[i]
	}
	return (2*sum_py + eps) / (sum_p + sum_y + eps)
}
