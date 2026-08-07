/*

Once upon a time, three goats wandered into Ivan Petrovich's vegetable patch.
Goats are known to be quite aggressive, especially when competing for delicious cabbage.
So, when each goat noticed the others, they all froze and began to watch each other: one eye on one goat and the other eye on the second goat.
Naturally, this required the goats to squint their eyes.

Your task is to determine the largest angle at which the goats had to squint their eyes.

Input
The program receives input in the form of coordinates for three points, representing the positions of the goats (first the coordinates of the first goat, then the second, and finally the third).
Each coordinate is a pair of integers, with absolute values not exceeding 10^4.

Output
Output a single number, representing the magnitude of the largest angle at which the goats squint their eyes, with a precision of at least 6 decimal places.

Examples
Input #1
0 0
3 0
0 4

Answer #1
90.000000

*/

package main

import (
	"fmt"
	"math"
)

type Point struct {
	x, y float64
}

func main() {
	fmt.Println(solve(
		Point{0, 0},
		Point{3, 0},
		Point{0, 4},
	))
}

func solve(A, B, C Point) float64 {
	a := dist(A, B)
	b := dist(B, C)
	c := dist(A, C)

	if a > b {
		a, b = b, a
	}
	if a > c {
		a, c = c, a
	}
	if b > c {
		b, c = c, b
	}

	return rad2deg(math.Acos((a*a + b*b - c*c) / (2 * a * b)))
}

func dist(A, B Point) float64 {
	return math.Hypot(A.x-B.x, A.y-B.y)
}

func rad2deg(x float64) float64 {
	return x * 180 / math.Pi
}
