/*

Your task is to program a mathematical function s, that takes a nonempty finite set A of points in the 2D plane, and outputs an uncircularity score s(A) that satisfies following properties:

Positive Definiteness: If there is a circle or a straight line that contains all points of A, then s(A)=0. Otherwise s(A)>0

Surjectivity: It is surjective to the nonnegative real numbers, that means for every nonnegative real number r there is a finite subset A of the plane such that s(A)=r.

Translation Invariance: s is translation invariant if s(A)=s(A+v) for every vector v and for all A.

Scale Invariance: s is scale invariant, if s(A)=s(tA) for every t≠0 and for all A.

Continuity. s is said to be continuous if the function f(p):=s(A∪{p}) (mapping the a point p to a real number) is continuous using the standard absolute value on the real numbers, and the standard euclidean norm on the points of the plane.

Intuitively speaking this uncircularness score can be thought of as something similar to the correlation coefficient in linear regression.

Details
Your function in theory has to work in the reals, but for the purpose of this challenge you can use floating point numbers as substitute.
Please provide an explanation of your submission and an argument why those five properties hold.
You can take two lists of coordinates or a list of tuples or similar formats as input.
You can assume that no point in the input is repeated i.e. all points are unique.

*/

package main

import (
	"fmt"
	"math"
	"math/cmplx"
)

func main() {
	fmt.Println(uncircularness([]complex128{
		1 + 1.0i,
		2 + 2.0i,
		3 + 3.0i,
		4 + 4.0i,
	}))

	fmt.Println(uncircularness([]complex128{
		245.5 + 45i,
		245.5 + 4556i,
		24245.5 + 4556835i,
		242545.5 + 455i,
	}))
}

/*

ported from @Anders Kaseorg solution

Takes A as a sequence of complex numbers (x + 1j*y), and sums Im(r)2/2|r| for all complex cross-ratios r of four points in A.

Properties
Positive Definiteness. All terms are nonnegative, and they’re all zero exactly when all the cross-ratios are real, which happens when the points are collinear or concyclic.

Surjectivity. Since the sum can be made arbitrarily large by adding many points, surjectivity will follow from continuity.

Translation Invariance. The cross-ratio is translation-invariant.

Scale Invariance. The cross-ratio is scale-invariant. (In fact, it’s invariant under all Möbius transformations.)

Continuity. The cross-ratio is a continuous map to the extended complex plane, and r ↦ Im(r)2/2|r| (with ∞ ↦ 0) is a continuous map from the extended complex plane to the reals.

(Note: A theoretically prettier map with the same properties is r ↦ (Im(r)/(C + |r|2))2, whose contour lines w.r.t. all four points of the cross-ratio are circular. If you actually need an uncircularness measure, you probably want that one.)

*/

func uncircularness(A []complex128) float64 {
	s := 0.0
	for _, a := range A {
		for _, b := range A {
			for _, c := range A {
				for _, d := range A {
					if a == d || d == b || b == c {
						continue
					}
					r := (a - c) * (b - d) / (a - d) / (b - c)
					s += imag(r) * imag(r) / math.Exp2(cmplx.Abs(r))
				}
			}
		}
	}
	return s
}
