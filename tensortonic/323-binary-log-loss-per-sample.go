/*

Compute binary log loss independently for every sample. Clip each predicted probability before applying the logarithm:

ph = min(1-eps, max(eps, p))
L(y, p) = -(y*ln(ph) + (1-y)*ln(1-p))

Here, y is a binary target, p is its predicted probability, and ε is eps.
Use the natural logarithm and return a list of losses in input order.

Examples
Input: y_true = [1, 0, 1], y_pred = [0.9, 0.1, 0.8], eps = 1e-15

Output: [0.105361, 0.105361, 0.223144]

Explanation: Each confident correct prediction produces a small positive loss.

Input: y_true = [1, 0], y_pred = [1, 0], eps = 1e-15

Output: [0, 0]

Hint 1
Clip with max(eps, min(1 - eps, probability)).

Hint 2
Append -(y * math.log(p) + (1 - y) * math.log(1 - p)) for each pair.

Requirements
Clip every prediction to [eps, 1 - eps]
Compute binary log loss separately for each pair
Use the natural logarithm
Return a list of Python floats in sample order
Constraints
1 <= len(y_true) == len(y_pred) <= 10000
Targets are 0 or 1
Predictions lie between 0 and 1
0 < eps < 0.5

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(log_loss(
		[]float64{1, 0, 1},
		[]float64{0.9, 0.1, 0.8},
		1e-15,
	))

	fmt.Println(log_loss(
		[]float64{1, 0},
		[]float64{1, 0},
		1e-15,
	))
}

func log_loss(y_true, y_pred []float64, eps float64) []float64 {
	r := []float64{}
	for i, y := range y_true {
		p := min(1-eps, max(eps, y_pred[i]))
		r = append(r, -(y*math.Log(p) + (1-y)*math.Log(1-p)))
	}
	return r
}
