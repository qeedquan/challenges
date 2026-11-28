/*

Implement RMSNorm independently over each final-dimension feature vector, without subtracting its mean.

RMSNorm(x) = x / sqrt(1/d * Sum[i=1, d] (x[i]^2 + eps)) * g

Here x is one feature vector, d is its width, i indexes a feature, g is the learned scale vector, epsilon is the supplied positive stabilizer, and the circled-dot operator means elementwise multiplication.

Return a PyTorch tensor with the same shape, dtype, and device as x.

Examples
Input: x = [[1,2],[3,4]], g = [1,1], epsilon = 0.00001

Output: [[0.632454,1.264909],[0.848528,1.13137]]

Explanation: Each row is divided by its own root mean square. The learned scale is [1,1], so it does not change the normalized values.

Input: x = [[3,4]], g = [2,0.5], epsilon = 0.000001

Output: [[1.697056,0.565685]]

Input: x = [[0,0,0]], g = [1,2,3], epsilon = 0.0001

Output: [[0,0,0]]

Hint 1
Tensor.mean with keepdim=True retains a broadcastable final axis.

Hint 2
torch.rsqrt computes a reciprocal square root.

Requirements
Use PyTorch with float32 arithmetic for normalization and learned scaling, preserving x's dtype in the result.
Supported input dtypes are float32 and bfloat16; public cases and custom Run inputs use float32.
Leave x and g unchanged.
Constraints
x is a floating-point PyTorch tensor with final dimension d at least 1.
g is a floating-point PyTorch tensor with shape (d) on the same device as x.
epsilon is a positive finite number.
Supported input dtypes are float32 and bfloat16.
All supplied tensor values are finite.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(rmsnorm(
		[][]float64{{1, 2}, {3, 4}},
		[]float64{1, 1},
		0.00001,
	))

	fmt.Println(rmsnorm(
		[][]float64{{3, 4}},
		[]float64{2, 0.5},
		0.000001,
	))

	fmt.Println(rmsnorm(
		[][]float64{{0, 0, 0}},
		[]float64{1, 2, 3},
		0.0001,
	))
}

func rmsnorm(x [][]float64, g []float64, eps float64) [][]float64 {
	r := [][]float64{}
	d := len(g)
	for i := range x {
		p := []float64{}
		s := 0.0
		for j := range d {
			s += x[i][j]*x[i][j] + eps
		}
		s = math.Sqrt(s / float64(d))
		for j := range d {
			p = append(p, x[i][j]/s*g[j])
		}
		r = append(r, p)
	}
	return r
}
