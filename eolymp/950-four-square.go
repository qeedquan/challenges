/*

The lines x=a and y=b divide the quadrilateral with vertices A(0,0), B(0,y1), C(x1,y1), D(x1,0) into four parts. Determine the areas of the resulting regions.

Input
A single line contains four integers a, b, x1, y1, separated by spaces. Each input value does not exceed 100 by absolute value.

Output
Output the area of quadrilateral APQM first, then the areas of PBOQ, QOCK, and MQKD, each separated by a space.
The results must be accurate to three decimal places.

Examples

Input #1
3 2 9 6

Answer #1
6.000 12.000 24.000 12.000

Input #2
-13 2 -9 6

Answer #2
26.000 52.000 16.000 8.000

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(3, 2, 9, 6))
	fmt.Println(solve(-13, 2, -9, 6))
}

func solve(a, b, x, y float64) (s1, s2, s3, s4 float64) {
	s1 = math.Abs(b * a)
	s2 = math.Abs((y - b) * a)
	s3 = math.Abs((y - b) * (x - a))
	s4 = math.Abs(b * (x - a))
	return
}
