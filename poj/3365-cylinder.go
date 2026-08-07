/*

Description

Using a sheet of paper and scissors, you can cut out two faces to form a cylinder in the following way:

Cut the paper horizontally (parallel to the shorter side) to get two rectangular parts.
From the first part, cut out a circle of maximum radius. The circle will form the bottom of the cylinder.
Roll the second part up in such a way
that it has a perimeter of equal length with the circle's circumference, and attach one end of the roll to the circle. Note that the roll may have some overlapping parts in order to get the required length of the perimeter.
Given the dimensions of the sheet of paper, can you calculate the biggest possible volume of a cylinder which can be constructed using the procedure described above?

Input

The input consists of several test cases. Each test case consists of two numbers w and h (1 ≤ w ≤ h ≤ 100), which indicate the width and height of the sheet of paper.

The last test case is followed by a line containing two zeros.

Output

For each test case, print one line with the biggest possible volume of the cylinder. Round this number to 3 places after the decimal point.

Sample Input

10 10
10 50
10 30
0 0

Sample Output

54.247
785.398
412.095
Hint

In the first case, the optimal cylinder has a radius of about 1.591549, in the second case, the optimal cylinder has a radius of 5, and in the third case, the optimal cylinder has a radius of about 3.621795.

Source

Ulm Local 2007

*/
package main

import (
	"fmt"
	"math"
)

func main() {
	test(10, 10, 54.247)
	test(10, 50, 785.398)
	test(10, 30, 412.095)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(w, h, r float64) {
	v := volume(w, h)
	fmt.Println(v)
	assert(math.Abs(v-r) < 1e-3)
}

func volume(w, h float64) float64 {
	r1 := w / math.Pi
	r2 := min(w, h/(math.Pi+1))
	v1 := (r1 * r1 * math.Pi / 4) * (h - r1)
	v2 := (r2 * r2 * math.Pi / 4) * w
	return max(v1, v2)
}
