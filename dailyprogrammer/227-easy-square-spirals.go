/*

Take a square grid, and put a cross on the center point, like this:

+ + + + +

+ + + + +

+ + X + +

+ + + + +

+ + + + +
The grid is 5-by-5, and the cross indicates point 1. Let's call the top-left corner location (1, 1), so the center point is at location (3, 3). Now, place another cross to the right, and trace the path:

+ + + + +

+ + + + +

+ + X-X +

+ + + + +

+ + + + +
This second point (point 2) is now at location (4, 3). If you continually move around anticlockwise as much as you can from this point, you will form a square spiral, as this diagram shows the beginning of:

+ + + + +

+ X-X-X .
  |   | .
+ X X-X .
  |     |
+ X-X-X-X

+ + + + +
Your challenge today is to do two things: convert a point number to its location on the spiral, and vice versa.

Formal Inputs and Outputs
Input Specification
On the first line, you'll be given a number S. This is the size of the spiral. If S equals 5, then the grid is a 5-by-5 grid, as shown in the demonstration above. S will always be an odd number.

You will then be given one of two inputs on the next line:

You'll be given a single number N - this is the point number of a point on the spiral.

You'll be given two numbers X and Y (on the same line, separated by a space) - this is the location of a point on the spiral.

Output Description
If you're given the point number of a point, work out its location. If you're given a location, find out its point number.

Sample Inputs and Outputs
Example 1
(Where is 8 on this spiral?)

5-4-3
|   |
6 1-2
|
7-8-9

Input
3
8
Output
(2, 3)

Example 2
This corresponds to the top-left point (1, 1) in this 7-by-7 grid.

Input
7
1 1
Output
37

Example 3
Input
11
50
Output
(10, 9)

Example 4
Input
9
6 8
Output
47
If your solution can't solve the next two inputs before the heat death of the universe, don't worry.

Example 5
Let's test how fast your solution is!

Input
1024716039
557614022
Output
(512353188, 512346213)

Example 6
:D

Input
234653477
11777272 289722
Output
54790653381545607

Finally
Got any cool challenge ideas? Submit them to r/DailyProgrammer_Ideas!

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(3, 2, 3, 8)
	test(7, 1, 1, 37)
	test(11, 10, 9, 50)
	test(9, 6, 8, 47)
	test(1024716039, 512353188, 512346213, 557614022)
	test(234653477, 11777272, 289722, 54790653381545607)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s, x, y, p int64) {
	nx, ny := p2xy(s, p)
	np := xy2p(s, x, y)
	fmt.Println(nx, ny, np)
	assert(x == nx)
	assert(y == ny)
	assert(p == np)
}

func p2xy(s, p int64) (int64, int64) {
	u := int64(math.Ceil(math.Sqrt(float64(p))))
	if u%2 == 0 {
		u = u / 2
	} else {
		u = (u - 1) / 2
	}
	v := p - sq(2*u-1)

	x, y := int64(0), int64(0)
	switch {
	case v < 2*u:
		x, y = u, u-v
	case v < 4*u:
		y, x = -u, 3*u-v
	case v < 6*u:
		x, y = -u, v-5*u
	case v < 8*u:
		y, x = u, v-7*u
	}
	x += (s + 1) / 2
	y += (s + 1) / 2

	return x, y
}

func xy2p(s, x, y int64) int64 {
	x -= (s + 1) / 2
	y -= (s + 1) / 2

	px := abs(x)
	py := abs(y)

	u := px
	if py > px {
		u = py
	}
	v := 1 + 2*(u-1)

	z := int64(0)
	switch {
	case x == u:
		z = u - y
	case y == -u:
		z = 3*u - x
	case x == -u:
		z = 5*u + y
	case y == u:
		z = 7*u + x
	}
	return z + sq(v)
}

func sq(x int64) int64 {
	return x * x
}

func abs(x int64) int64 {
	if x < 0 {
		x = -x
	}
	return x
}
