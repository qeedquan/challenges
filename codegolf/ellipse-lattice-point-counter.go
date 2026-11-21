/*

Challenge
Determine how many integer lattice points there are in an ellipse

x^2/a^2 + y^2/b^2 ≤ 1 centered at the origin with width 2a and height 2b where integers a, b > 0.

Input

The Semi-major a and Semi-minor b axes.

Output

Number of interior and boundary points.

Example
Ellipse plot showing a=5 and b=3 with 41 blue interior and 4 red boundary points.

https://i.stack.imgur.com/aLrCv.png

Input

5,3

Output

41,4

Test Cases
a	b	Interior	Boundary
5	3	41	4
5	15	221	12
8	5	119	4
8	1	15	4
9	15	417	4
15	15	697	12
20	20	1245	12

*/

package main

import "fmt"

func main() {
	test(5, 3, 41, 4)
	test(5, 15, 221, 12)
	test(8, 5, 119, 4)
	test(8, 1, 15, 4)
	test(9, 15, 417, 4)
	test(15, 15, 697, 12)
	test(20, 20, 1245, 12)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b, r0, r1 int) {
	c0, c1 := points(a, b)
	fmt.Println(c0, c1)
	assert(c0 == r0)
	assert(c1 == r1)
}

func points(a, b int) (int, int) {
	c0, c1 := 0, 0
	for y := -b; y <= b; y++ {
		for x := -a; x <= a; x++ {
			ex := x * x * b * b
			ey := y * y * a * a
			er := a * a * b * b
			if ex+ey < er {
				c0++
			} else if ex+ey == er {
				c1++
			}
		}
	}
	return c0, c1
}
