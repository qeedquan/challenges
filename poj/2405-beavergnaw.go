/*

Description

When chomping a tree the beaver cuts a very specific shape out of the tree trunk. What is left in the tree trunk looks like two frustums of a cone joined by a cylinder with the diameter the same as its height. A very curious beaver tries not to demolish a tree but rather sort out what should be the diameter of the cylinder joining the frustums such that he chomped out certain amount of wood. You are to help him to do the calculations.
We will consider an idealized beaver chomping an idealized tree. Let us assume that the tree trunk is a cylinder of diameter D and that the beaver chomps on a segment of the trunk also of height D. What should be the diameter d of the inner cylinder such that the beaver chmped out V cubic units of wood?

Input

Input contains multiple cases each presented on a separate line. Each line contains two integer numbers D and V separated by whitespace. D is the linear units and V is in cubic units. V will not exceed the maximum volume of wood that the beaver can chomp. A line with D=0 and V=0 follows the last case.

Output

For each case, one line of output should be produced containing one number rounded to three fractional digits giving the value of d measured in linear units.

Sample Input

10 250
20 2500
25 7000
50 50000
0 0

Sample Output

8.054
14.775
13.115
30.901

Source

Waterloo local 2002.07.01

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(10, 250, 8.054)
	test(20, 2500, 14.775)
	test(25, 7000, 13.115)
	test(50, 50000, 30.901)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(D, V, r float64) {
	d := diameter(D, V)
	fmt.Println(d)
	assert(math.Abs(d-r) < 1e-3)
}

func diameter(D, V float64) float64 {
	R := D / 2
	Vt := math.Pi * R * R * D
	Vs := Vt - V
	r := math.Cbrt((3*Vs - 2*math.Pi*R*R*R) / (4.0 * math.Pi))
	d := 2 * r
	return d
}
