/*

The singular value decomposition (SVD) is an extremely useful algorithm in linear algebra. Some people have called it a 'master algorithm' because if you are able to perform the SVD you can perform almost every other useful linear algebraic operation.

Among other things, it is used to solve systems of linear equations, to find low-rank approximations, and to do least-squares estimation and machine learning.

The definition of the SVD is as follows: A vector u and v are left and right singular vectors of a real matrix M, if and only if

Mv=su and M'u=sv
for some real scalar s. (M' denotes M transposed). The SVD of M is the set of ALL singular tuples (u,s,v) for which this is true.

Write a function that, given a 2x2 real matrix M, can output ONE of the singular tuples of M...that is find ONE of the left and right singular vectors from the Singular Value Decomposition (SVD) of M.

What makes this challenge VERY difficult is that you should not use a linear-algebra built-in function from a mathematical package to solve it..try to only use simple arithmetic operations such as matrix multiply, dot product, squareroot, etc.

Since there are dozens of ways to solve it, here are 3 different hints about properties of the SVD corresponding to 3 different solutions I have written.

Imagine a function f(u,v)=u'Mv .  If u,v, are singular vectors of M, then u,v are extrema of f and f(u,v)=s.

Imagine the matrix A=[0 M;M' 0];  If x is an eigenvector of A, then x*sqrt(2)=[u;v]

Since Mv=su and M'u=sv, then M'Mv=M'us=ssv, therefore M'Mv=ssv, so v is an eigenvector of M'M with eigenvalue s^2.  By a similar argument, u is an eigenvector of MM' with eigenvalue s^2.
For some testing, the matrix [1 0;1 -1] has these two svd tuples according to GNU Octave: (u=[-0.52573;-0.85065],s=1.61803,v=[-0.85065;0.52573]) and (u=[-0.85065;0.52573],s=0.61803,v=[-0.52573,-0.85065])

EDIT: as Ttl points out, if you get the opposite sign from the test case on the vectors in a tuple it doesn't matter, the answer is still correct.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(svd(1, 0, 1, -1))
}

/*

@Ttl

Signs are not the same as in the example but because multiplication by constant commutes: (-U)S(-V)' = (-1)(-1)USV' = USV' = M, it's still a valid answer when both vectors are multiplied by -1.

*/

func svd(a, b, c, d float64) (vec2, float64, vec2) {
	z := a*a + b*b + c*c + d*d
	x := b*c - a*d
	w := math.Sqrt(z*z - 4*x*x)
	e := a*a*a + 2*b*c*d + a*(b*b+c*c-d*d-w)
	r := a*b + c*d
	t := c*c*c + 2*a*b*d + c*(a*a-b*b+d*d-w)
	u := math.Abs(r) / (r * math.Sqrt(e*e+t*t))
	y := a*a - b*b + c*c - d*d - w
	v := 1 / (r * math.Sqrt(4+(y/r)*(y/r)))
	return vec2{-e * u, -t * u}, math.Sqrt((z - w) / 2), vec2{-y * v, -2 * r * v}
}

type vec2 struct {
	x, y float64
}
