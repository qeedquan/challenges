/*

Task
A rectangle with sides equal to even integers a and b is drawn on the Cartesian plane. Its center (the intersection point of its diagonals) coincides with the point (0, 0), but the sides of the rectangle are not parallel to the axes; instead, they are forming 45 degree angles with the axes.

How many points with integer coordinates are located inside the given rectangle (including on its sides)?

Example
For a = 6 and b = 4, the output should be 23.

The following picture illustrates the example, and the 23 points are marked green.

https://files.gitter.im/myjinxin2015/raYf/blob

Input/Output
[input] integer a
A positive even integer.
Constraints: 2 ≤ a ≤ 10000.

[input] integer b
A positive even integer.
Constraints: 2 ≤ b ≤ 10000.

[output] an integer
The number of inner points with integer coordinates.

*/

package main

import "math"

const SQRT8 = 2 * math.Sqrt2

func main() {
	assert(rectangle_rotation(6, 4) == 23)
	assert(rectangle_rotation(30, 2) == 65)
	assert(rectangle_rotation(8, 6) == 49)
	assert(rectangle_rotation(16, 20) == 333)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func rectangle_rotation(a, b int) int {
	return fullcell(a)*fullcell(b) + halfcell(a)*halfcell(b)
}

func fullcell(n int) int {
	return int(float64(n)/SQRT8)*2 + 1
}

func halfcell(n int) int {
	return (int((float64(n)-math.Sqrt2)/SQRT8) + 1) * 2

}
