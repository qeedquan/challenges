/*

Four points A(x1; y1), B(x2; y2), C(x3; y3), D(x4; y4) are the vertices of a parallelogram.
Determine the lengths of the diagonals and find the coordinates of their intersection.

https://static.e-olymp.com/content/c0/c04d98829be9f2f3b292891a9cc81938d1159546.jpg

Input
In four lines, the x and y coordinates of the consecutive vertices of the parallelogram are given, corresponding respectively to points A, B, C, and D.
All numbers do not exceed 100 in absolute value.

Output
Print the x and y coordinates of the intersection point O in the first line.
In the second line, print the lengths of diagonals AC and BD.
Output all values with an accuracy of three decimal places.

Examples

Input #1
4 6
11 6
10 2
3 2

Answer #1
7.000 4.000
7.211 8.944

Input #10
-100 100
100 100
100 -100
-100 -100

Answer #10
0.000 0.000
282.843 282.843

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(4, 6, 11, 6, 10, 2, 3, 2))
	fmt.Println(solve(-100, 100, 100, 100, 100, -100, -100, -100))
}

func solve(x1, y1, x2, y2, x3, y3, x4, y4 float64) (float64, float64, float64, float64) {
	BD := math.Hypot(x4-x2, y4-y2)
	AC := math.Hypot(x3-x1, y3-y1)
	x := (x3 + x1) / 2
	y := (y3 + y1) / 2
	return x, y, AC, BD
}
