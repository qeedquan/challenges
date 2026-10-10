/*

The segment is given by the coordinates of its endpoints: M(x1, y1) and N(x2, y2). Find the coordinates of the point O(x, y) that divides it in the ratio α.

Input
A single line contains the coordinates of the segment endpoints and the number α. All coordinates do not exceed 100 by absolute value.

Output
Print in one line the coordinates x and y of the required point, accurate to two decimal places.

Examples
Input #1
2 1 8 4 0.5

Answer #1
4.00 2.00

*/

package main

import "fmt"

func main() {
	fmt.Println(solve(2, 1, 8, 4, 0.5))
}

func solve(x1, y1, x2, y2, a float64) (float64, float64) {
	x := (a*x2 + x1) / (a + 1)
	y := (a*y2 + y1) / (a + 1)
	return x, y
}
