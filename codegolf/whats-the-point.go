/*

Write a program or function that takes in two integers that represent the X and Y coordinates of a point on a Cartesian plane.

The input may come in any reasonable format as long as the X value comes before the Y. For example, 1 -2, (1,-2), [1, -2], or 1\n-2 would all be fine for X = 1, Y = -2.

Print or return a single character string (followed by an optional trailing newline) that describes the location of the point in the plane:

1 if the point is in quadrant I
2 if the point is in quadrant II
3 if the point is in quadrant III
4 if the point is in quadrant IV
X if the point is on the x-axis (lowercase x is not allowed)
Y if the point is on the y-axis (lowercase y is not allowed)
O if the point is on the origin (that's a capital letter "oh", not zero)
The shortest code in bytes wins. Tiebreaker goes to the higher voted answer.

Test Cases
(1,-2) -> 4
(30,56) -> 1
(-2,1) -> 2
(-89,-729) -> 3
(-89,0) -> X
(0,400) -> Y
(0,0) -> O
(0,1) -> Y
(0,-1) -> Y
(1,0) -> X
(-1,0) -> X
(1,1) -> 1
(1,-1) -> 4
(-1,1) -> 2
(-1,-1) -> 3

*/

package main

func main() {
	assert(location(1, -2) == 4)
	assert(location(30, 56) == 1)
	assert(location(-2, 1) == 2)
	assert(location(-89, -729) == 3)
	assert(location(-89, 0) == 'X')
	assert(location(0, 400) == 'Y')
	assert(location(0, 0) == 'O')
	assert(location(0, 1) == 'Y')
	assert(location(0, -1) == 'Y')
	assert(location(1, 0) == 'X')
	assert(location(-1, 0) == 'X')
	assert(location(1, 1) == 1)
	assert(location(1, -1) == 4)
	assert(location(-1, 1) == 2)
	assert(location(-1, -1) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func location(x, y int) int {
	switch {
	case x == 0 && y == 0:
		return 'O'
	case x == 0:
		return 'Y'
	case y == 0:
		return 'X'
	case x > 0:
		if y > 0 {
			return 1
		}
		return 4
	default:
		if y > 0 {
			return 2
		}
		return 3
	}
}
