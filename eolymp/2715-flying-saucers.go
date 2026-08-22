/*

Recently, ufologists have discovered that flying saucers are square-shaped and, upon landing, they leave marks on the ground at the "vertices" of the saucer.
You have received a secret mission: determine whether the traces left tonight were made by a flying saucer.

Input
The input file contains four pairs of integers specifying the coordinates of the marks in the field.
All coordinates are integers and do not exceed 32767 in absolute value.

Output
Output YES if the traces were left by a UFO, otherwise output NO.

Examples

Input #1
100 100
32000 32000
100 32000
32000 100

Answer #1
YES

*/

package main

func main() {
	assert(solve(100, 100, 32000, 32000, 100, 32000, 32000, 100) == "YES")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(x1, y1, x2, y2, x3, y3, x4, y4 int) string {
	a := (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)
	b := (x2-x3)*(x2-x3) + (y2-y3)*(y2-y3)
	c := (x3-x4)*(x3-x4) + (y3-y4)*(y3-y4)
	d := (x4-x1)*(x4-x1) + (y4-y1)*(y4-y1)

	a1 := (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3)
	b1 := (x2-x3)*(x2-x3) + (y2-y3)*(y2-y3)
	c1 := (x2-x4)*(x2-x4) + (y2-y4)*(y2-y4)
	d1 := (x4-x1)*(x4-x1) + (y4-y1)*(y4-y1)

	a2 := (x1-x4)*(x1-x4) + (y1-y4)*(y1-y4)
	b2 := (x2-x4)*(x2-x4) + (y2-y4)*(y2-y4)
	c2 := (x2-x3)*(x2-x3) + (y2-y3)*(y2-y3)
	d2 := (x3-x1)*(x3-x1) + (y3-y1)*(y3-y1)

	if (a == b && b == c && c == d) || (a1 == b1 && b1 == c1 && c1 == d1) || (a2 == b2 && b2 == c2 && c2 == d2) {
		return "YES"
	}
	return "NO"
}
