/*

Write the following function:

function areaOfPolygonInsideCircle(circleRadius, numberOfSides)
It should calculate the area of a regular polygon of numberOfSides, number-of-sides, or number_of_sides sides inside a circle of radius circleRadius, circle-radius, or circle_radius which passes through all the vertices of the polygon (such circle is called circumscribed circle or circumcircle).

The answer should be a number rounded to 3 decimal places.

Input :: Output Examples

areaOfPolygonInsideCircle(3, 3) // returns 11.691

areaOfPolygonInsideCircle(5.8, 7) // returns 92.053

areaOfPolygonInsideCircle(4, 5) // returns 38.042
Note: if you need to use Pi in your code, use the native value of your language unless stated otherwise.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(3, 3, 11.691)
	test(5.8, 7, 92.053)
	test(4, 5, 38.042)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(r float64, n int, a float64) {
	p := area(r, n)
	fmt.Println(p)
	assert(math.Abs(p-a) < 1e-3)
}

// https://math.stackexchange.com/questions/2675082/calculating-the-area-of-a-polygon-with-equal-sides-inscribed-in-a-circle-with-ra
func area(r float64, n int) float64 {
	s := float64(n)
	return s * r * r * math.Sin(2*math.Pi/s) / 2
}
