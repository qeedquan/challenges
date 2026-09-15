/*

Find the eigenvalues of the matrix:

A = 1 2
    2 4

Your answer should have the eigenvalues separated by a single line resembling this(with smaller value coming first):

5
6

*/

package main

import (
	"fmt"
	"math/cmplx"
)

func main() {
	fmt.Println(eig2(Mat2{
		{1, 2},
		{2, 4},
	}))
}

type Mat2 [2][2]complex128

func eig2(m Mat2) [2]complex128 {
	return quadratic(1, -trace2(m), det2(m))
}

func quadratic(a, b, c complex128) [2]complex128 {
	d := cmplx.Sqrt(b*b - 4*a*c)
	return [2]complex128{
		(-b - d) / (2 * a),
		(-b + d) / (2 * a),
	}
}

func trace2(m Mat2) complex128 {
	return m[0][0] + m[1][1]
}

func det2(m Mat2) complex128 {
	return m[0][0]*m[1][1] - m[0][1]*m[1][0]
}
