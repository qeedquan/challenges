/*

Compute the mean binary focal loss from predicted probabilities:

L[i] = -(1 - p[i])^gamma * y[i] * log(p[i]) - p[i]^gamma * (1 - y[i]) * log(1 - p[i])

Here, p[i] is the predicted probability for sample i, y is its binary label, and gamma.
Clip probabilities only for numerical stability, then return the mean of all L[i] values as a Python float.

Examples
Input: p = [0.9, 0.2, 0.7, 0.1], y = [1, 0, 1, 0], gamma = 2.0

Output: 0.010783

Explanation: Confident correct predictions receive small weights, so their mean focal loss is low.

Input: p = [0.5, 0.5, 0.5, 0.5], y = [1, 0, 1, 0], gamma = 2.0

Output: 0.173287

Input: p = [0.9, 0.2, 0.7, 0.1], y = [1, 0, 1, 0], gamma = 0.0

Output: 0.197635

Hint 1
Use np.clip(p, 1e-15, 1.0 - 1e-15) before taking logarithms.

Hint 2
Use np.log1p(-p) for the negative-class logarithm.

Hint 3
Average the negative sum of the positive and negative terms.

Requirements
Treat p as probabilities without applying sigmoid
Apply the focal-loss equation elementwise
Return the mean loss as a Python float
Constraints
p and y are equal-length nonempty numeric lists
Every label in y is 0 or 1
Every probability in p is between 0 and 1
gamma is between 0 and 5
Use NumPy only

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(focal_loss(
		[]float64{0.9, 0.2, 0.7, 0.1},
		[]float64{1, 0, 1, 0},
		2,
	))

	fmt.Println(focal_loss(
		[]float64{0.5, 0.5, 0.5, 0.5},
		[]float64{1, 0, 1, 0},
		2,
	))

	fmt.Println(focal_loss(
		[]float64{0.9, 0.2, 0.7, 0.1},
		[]float64{1, 0, 1, 0},
		0,
	))
}

func focal_loss(p, y []float64, gamma float64) float64 {
	L := 0.0
	for i := range p {
		A := -math.Pow(1-p[i], gamma) * y[i] * math.Log(p[i])
		B := math.Pow(p[i], gamma) * (1 - y[i]) * math.Log(1-p[i])
		L += A - B
	}
	return L / float64(len(p))
}
