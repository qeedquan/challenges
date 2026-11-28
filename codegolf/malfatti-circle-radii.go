/*

Consider a triangle ABC whose sides BC,CA,AB have lengths a,b,c respectively. In this triangle we can construct circles GA,GB,GC such that

GA is tangent to CA,AB,GB,GC
GB is tangent to AB,BC,GC,GA
GC is tangent to BC,CA,GA,GB

https://en.wikipedia.org/wiki/File:Primo_punto_di_Malfatti.svg

These are the Malfatti circles. MathWorld goes to great lengths to derive a degree-8 polynomial for the circles' radii,
which is unnecessary because simple formulas in terms of the vertex angles and inradius r exist (see Milorad Stevanović, Triangle Centers Associated with the Malfatti Circles):

r(Ga) = r/2 * (1 + tan(B/4)) * (1 + tan(C/4)) / (1 + tan(A / 4))
r(Gb) = r/2 * (1 + tan(C/4)) * (1 + tan(A/4)) / (1 + tan(B / 4))
r(Gc) = r/2 * (1 + tan(A/4)) * (1 + tan(B/4)) / (1 + tan(C / 4))

The vertex angles and inradius are related to the side lengths as follows:

cos(A) = (b^2 + c^2 - a^2) / (2*b*c)
cos(B) = (c^2 + a^2 - b^2) / (2*c*a)
cos(C) = (a^2 + b^2 - c^2) / (2*a*b)

r = 1/2 * sqrt((b + c - a) * (c + a - b) * (a + b - c) / (a + b + c))

Task
Given the list of ABC's side lengths (a,b,c), output the list of Malfatti circle radii (r(GA),r(GB),r(GC)) such that the indices of a in the input and r(GA) in the output are the same, and similarly for b and c.

You may assume a,b,c are the side lengths of a real triangle (i.e. they are positive and satisfy the strict triangle inequality) and you may use any method to compute the radii.
In any case the relative error between your code's result and the correct result should be at most 10−3
.

Test cases
(a, b, c) -> (r(G_A), r(G_B), r(G_C))
(1, 1, 1) -> (0.18301270189221933, 0.18301270189221933, 0.18301270189221933)
(1, 2, 2) -> (0.3094492959984062, 0.21824583655185426, 0.21824583655185426)
(2, 2, 3) -> (0.4114378277661477, 0.4114378277661477, 0.27318176024732077)
(3, 4, 5) -> (0.7519993533825825, 0.6648941887395787, 0.5079339623524631)
(5, 3, 7) -> (0.640365201095977, 0.7285004715242018, 0.3513011180929225)
(10, 11, 14) -> (2.2065703506430276, 2.1074825138902256, 1.6650841022193923)
(13, 6, 9) -> (0.6922186457476552, 1.39919148968878, 1.2587888693420877)
(13, 12, 5) -> (1.0124184110483154, 1.193028374510743, 1.676406062697539)
(37, 61, 97) -> (3.1891628945840464, 3.079083210868478, 0.9712719448934755)
(28392, 21000, 25872) -> (3969, 4900, 4356)

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(1, 1, 1, 0.18301270189221933, 0.18301270189221933, 0.18301270189221933)
	test(1, 2, 2, 0.3094492959984062, 0.21824583655185426, 0.21824583655185426)
	test(2, 2, 3, 0.4114378277661477, 0.4114378277661477, 0.27318176024732077)
	test(3, 4, 5, 0.7519993533825825, 0.6648941887395787, 0.5079339623524631)
	test(5, 3, 7, 0.640365201095977, 0.7285004715242018, 0.3513011180929225)
	test(10, 11, 14, 2.2065703506430276, 2.1074825138902256, 1.6650841022193923)
	test(13, 6, 9, 0.6922186457476552, 1.39919148968878, 1.2587888693420877)
	test(13, 12, 5, 1.0124184110483154, 1.193028374510743, 1.676406062697539)
	test(37, 61, 97, 3.1891628945840464, 3.079083210868478, 0.9712719448934755)
	test(28392, 21000, 25872, 3969, 4900, 4356)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b, c, RA, RB, RC float64) {
	const eps = 1e-12
	GA, GB, GC := malfatti(a, b, c)
	fmt.Println(GA, GB, GC)
	assert(math.Abs(GA-RA) < eps)
	assert(math.Abs(GB-RB) < eps)
	assert(math.Abs(GC-RC) < eps)
}

func malfatti(a, b, c float64) (GA, GB, GC float64) {
	r := 0.5 * math.Sqrt((b+c-a)*(c+a-b)*(a+b-c)/(a+b+c))
	A := math.Acos((b*b + c*c - a*a) / (2 * b * c))
	B := math.Acos((c*c + a*a - b*b) / (2 * c * a))
	C := math.Acos((a*a + b*b - c*c) / (2 * a * b))
	GA = 0.5 * r * (1 + math.Tan(B/4)) * (1 + math.Tan(C/4)) / (1 + math.Tan(A/4))
	GB = 0.5 * r * (1 + math.Tan(C/4)) * (1 + math.Tan(A/4)) / (1 + math.Tan(B/4))
	GC = 0.5 * r * (1 + math.Tan(A/4)) * (1 + math.Tan(B/4)) / (1 + math.Tan(C/4))
	return
}
