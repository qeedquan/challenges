/*

A rectangular door has dimensions a and b, and a cabinet is shaped as a rectangular parallelepiped with dimensions x, y, and z.
Is it possible to carry the cabinet through the door if it can be carried so that each edge of the cabinet is parallel or perpendicular to the sides of the door?

Input
Five real numbers: a, b, x, y, z (0<a,b,x,y,z<10).

Output
Print 1 if the cabinet can be freely carried through the door, otherwise print 0.

Examples

Input #1
5 7 4 6 8

Answer #1
1

*/

package main

func main() {
	assert(solve(5, 7, 4, 6, 8) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b, x, y, z float64) int {
	switch {
	case a > x && b > y:
		return 1
	case a > y && b > x:
		return 1
	case a > z && b > x:
		return 1
	case a > x && b > z:
		return 1
	case a > y && b > z:
		return 1
	case a > z && b > y:
		return 1
	}
	return 0
}
