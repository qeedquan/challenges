/*

This question is similar to Do the circles overlap?, except your program should return True if the circumference of one circle intersects the other, and false if they do not. If they touch, this is considered an intersection. Note that concentric circles only intersect when both radii are equal

Input is two x, y coordinates for the circle centres and two radius lengths, as either 6 floats or ints, in any order, and output a boolean value, (you may print True or False if you choose)

test cases are in format (x1, y1 x2, y2, r1, r2):

these inputs should output true:

0 0 2 2 2 2
1 1 1 5 2 2
0.55 0.57 1.97 2.24 1.97 2.12
these should output false:

0 0 0 1 5 3
0 0 5 5 2 2
1.57 3.29 4.45 6.67 1.09 3.25

*/

package main

func main() {
	assert(intersect(0, 0, 2, 2, 2, 2) == true)
	assert(intersect(1, 1, 1, 5, 2, 2) == true)
	assert(intersect(0.55, 0.57, 1.97, 2.24, 1.97, 2.12) == true)

	assert(intersect(0, 0, 0, 1, 5, 3) == false)
	assert(intersect(0, 0, 5, 5, 2, 2) == false)
	assert(intersect(1.57, 3.29, 4.45, 6.67, 1.09, 3.25) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func intersect(x1, y1, x2, y2, r1, r2 float64) bool {
	dx := x2 - x1
	dy := y2 - y1
	dr := r2 - r1
	ds := dx*dx + dy*dy - dr*dr
	return 0 <= ds && ds <= 4*r1*r2
}
