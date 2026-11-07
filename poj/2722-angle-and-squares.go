/*

Description

Here is a geometric problem. You have an angle and some squares in the first quadrant of the plane rectangular coordinates. The vertex of the angle is fixed on the origin O of the coordinates, and both of its radial lines are specified by the input. The sizes of the squares are also specified by the input, and the squares can shift vertically and horizontally. Now your job is to use the squares and the radial lines of the angle to enclose the maximum area, which excludes the area of the squares (see Figure 1). You should note that the edges of the squares must be parallel to the axes.

http://poj.org/images/2722_1.jpg

Input

There are several test cases. Each test case starts with a line consisting of one positive integer N (0 < N < 10), which is the number of the squares. The next line contains four decimal numbers: xa, ya, xb, yb, which denote two points A (xa, ya) and B (xb, yb). The radial lines OA and OB form the angle. Each of the following N lines contains a decimal number, which is the edge length of a square. All the decimal numbers mentioned above are in the range [1, 20]. A test case with N = 0 ends the input, and should not be processed.
Output

For each data case, output one line containing a decimal number, which is the maximum area that can be enclosed by the radial lines of the angle and the squares. The value should be rounded to three digits after the decimal point.
Sample Input

1
2.000 3.000 3.000 2.000
1.000
0
Sample Output

2.000

Source

Beijing 2005

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(2, 3, 3, 2, []float64{1}, 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(xa, ya, xb, yb float64, l []float64, r float64) {
	p := radial(xa, ya, xb, yb, l)
	fmt.Println(p)
	assert(math.Abs(p-r) < 1e-3)
}

func radial(xa, ya, xb, yb float64, l []float64) float64 {
	A := ya / xa
	B := yb / xb
	if A < B {
		A, B = B, A
	}

	L := 0.0
	R := 0.0
	for _, t := range l {
		L += t
		R += t * t
	}

	x1 := (L*B + L) / (A - B)
	x2 := (L*A + L) / (A - B)
	y1 := x1 * A
	y2 := x2 * B
	return (x2*y1 - x1*y2 - R) / 2
}
