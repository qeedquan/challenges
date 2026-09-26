/*

In this problem, your task is to compute the discrete Fourier transform (DFT) of a polynomial.
The DFT is represented as a vector y=(y0, y1, ..., y[n-1]), where each coefficient is determined by the formula:

y[i] = A*exp(i*2*pi*k/n)

Input
The input begins with a single integer n (1≤n≤1000). The following line contains exactly n integers, which are the coefficients a k (−1000≤ak≤1000),
listed in order from a 0 to a[n−1].

Output
The output should consist of exactly n lines. Each line k should display two numbers: real(yk) and imag(yk), separated by a space.
These values must be presented with an absolute or relative error not exceeding 10^-6.
Here, real(⋅) refers to the real part, and imag(⋅) refers to the imaginary part of the complex number.

Examples

Input #1
2
1 2

Answer #1
3.0000000000 0.0000000000
-1.0000000000 0.0000000000

Input #2
4
1 2 3 4

Answer #2
10.0000000000 0.0000000000
-2.0000000000 -2.0000000000
-2.0000000000 0.0000000000
-2.0000000000 2.0000000000

*/

package main

import (
	"fmt"
	"math"
	"math/cmplx"
)

func main() {
	fmt.Printf("% .3f\n", solve([]complex128{1, 2}))
	fmt.Printf("% .3f\n", solve([]complex128{1, 2, 3, 4}))
}

func solve(in []complex128) []complex128 {
	out := make([]complex128, len(in))
	dft(in, out)
	return out
}

func dft(in, out []complex128) {
	n := len(in)
	for i := range n {
		out[i] = 0
		for j := range n {
			out[i] += in[j] * cmplx.Exp(2i*math.Pi*complex(float64(i*j)/float64(n), 0))
		}
	}
}
