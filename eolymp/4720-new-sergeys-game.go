/*

C-student Sergey often asks A-student Vasya to do his homework.
Vasya is a genius, but he still cannot cope with the work instantly, so Sergey has to wait.
Sergey gets bored waiting with nothing to do. Not so long ago, he came up with a new game to pass the time.

On the white table with a coordinate system, Sergey puts a rectangular sheet of black paper.
Above it, he puts a rectangular sheet of white paper so that it may overlap a portion of the black sheet.
The sides of both sheets of paper are parallel to the coordinate axes.
After that, Sergey chooses a point on the plane of the table.
If it lands on the black sheet, Sergey believes that waiting is not boring; otherwise, he becomes upset.

Help Sergey to determine whether he gets upset or not.

Input
First, you are given the coordinates of the upper left corner and then the bottom right corner of the black rectangle,
then the coordinates of the corresponding corners of the white rectangle in the same format, and finally the coordinates of the point.
All coordinates are integers, not greater than 10000 by absolute value.

Output
Print "SAD" if Sergey is sad (if the point falls on the boundary, Sergey considers it as belonging to the black sheet), and "HAPPY" otherwise.

Examples

Input #1
2 10 5 3 4 4 6 1 2 9

Answer #1
HAPPY

Input #2
2 10 5 3 4 4 6 1 6 3

Answer #2
SAD

*/

package main

func main() {
	assert(solve(2, 10, 5, 3, 4, 4, 6, 1, 2, 9) == "HAPPY")
	assert(solve(2, 10, 5, 3, 4, 4, 6, 1, 6, 3) == "SAD")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5 int) string {
	if x5 > x3 && x5 < x4 && y5 < y3 && y5 > y4 {
		return "SAD"
	}
	if x5 >= x1 && x5 <= x2 && y5 <= y1 && y5 >= y2 {
		return "HAPPY"
	}
	return "SAD"
}
