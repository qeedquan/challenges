/*

A cow is grazing in the field. A rope in the field is tied with two pillars. The cow is kept tied with
the rope with the help of a ring. So the cow can be considered to be tied with any point of the rope.
Your job is to find the area of the field where the cow can reach and eat grass. If required assume that
π = 2 ∗ cos^-1(0) (Here angle is measured in radians). You can also assume that the thickness of the
rope is zero, the cow is a point object and the radius of the ring and the thickness of the pillars are
negligible. Please use double precision floating-point data type for floating-point calculations.

Input
First line of the input file contains an integer (N ≤ 100), which indicates how many sets of inputs are
there. Each of the next N lines contains two integers D (0 ≤ D ≤ 1000) and L (D < L ≤ 1500). The
first integer D denotes the distance in feet between the two pillars and the second integer L denotes
the length of the rope in feet.

Output
Your program should produce N lines of output. Each line contains a single floating-point number,
which has three digits after the decimal point. This floating-point number indicates the area of the
field which the cow can reach and eat grass.

Sample Input
3
10 12
23 45
12 18

Sample Output
62.517
1366.999
189.670

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(10, 12, 62.517)
	test(23, 45, 1366.999)
	test(12, 18, 189.670)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(d, l, r float64) {
	v := solve(d, l)
	fmt.Println(v)
	assert(math.Abs(v-r) < 1e-4)
}

func solve(d, l float64) float64 {
	a := l / 2
	b := math.Sqrt(l*l/4 - d*d/4)
	return math.Pi * a * b
}
