/*

Calculate the angle between two vectors.

Input
Four integers x1, y1, x2, y2 - the coordinates of two nonzero vectors. All values do not exceed 10000 by absolute value.

Output
Print the value of the undirected angle between the vectors with 5 decimal places, in the interval [0;π].

Examples

Input #1
2 1 3 5

Answer #1
0.56673

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Printf("%.5f\n", solve(2, 1, 3, 5))
}

func solve(x1, y1, x2, y2 float64) float64 {
	sp := x1*x2 + y1*y2
	m1 := math.Sqrt(x1*x1 + y1*y1)
	m2 := math.Sqrt(x2*x2 + y2*y2)
	return math.Acos(sp / (m1 * m2))
}
