/*

Determine whether a given point belongs to a ray.

Input
Six integers are given: the coordinates of the point and the coordinates of the beginning and end of the vector.
All numbers do not exceed 10000 by absolute value.

Output
Print YES if the point belongs to the ray, and NO otherwise.

Examples

Input #1
1 6 3 7 5 8

Answer #1
NO

*/

package main

func main() {
	assert(solve(1, 6, 3, 7, 5, 8) == "NO")
	assert(solve(2, 2, 1, 1, 3, 3) == "YES")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(x, y, x1, y1, x2, y2 int) string {
	d := (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)
	d1 := (x-x1)*(x-x1) + (y-y1)*(y-y1)
	d2 := (x2-x)*(x2-x) + (y2-y)*(y2-y)
	if d1+d2 > d && d1 != d2+d {
		return "NO"
	}
	return "YES"
}
