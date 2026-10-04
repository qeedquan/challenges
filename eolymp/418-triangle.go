/*

https://static.e-olymp.com/content/b6/b6b9ff4bd07fd16406c8ad347d7dbd1fa1cfa29f.jpg

A triangle and a point inside it are given.
Through this point, lines parallel to the sides of the triangle are drawn.
These lines form three triangles inside the given triangle.
The areas of these triangles are known. Find the area of the original triangle.

Input
One line contains three positive real numbers S1, S2, and S3. Each number does not exceed 1000.

Output
Print the area of the original triangle with 8 digits after the decimal point.

Examples

Input #1
1.0 2.0 3.0

Answer #1
17.19150823

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Printf("%f\n", solve(1, 2, 3))
}

func solve(s1, s2, s3 float64) float64 {
	return s1 + s2 + s3 + 2*math.Sqrt(s1*s2) + 2*math.Sqrt(s1*s3) + 2*math.Sqrt(s3*s2)
}
