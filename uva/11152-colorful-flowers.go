/*

“Roses are red, violets are blue...”
Millionaire Mr Smith is well-known — not for his wealth, but for his odd sense of “art”... Mr Smith
has got a circular garden. On the boundary he picks three points and gets a triangle. He then finds
the largest circle in that triangular region. So he gets something like this:
Mr Smith then plants yellow sunflowers,
blue violets and red roses in the way shown in
the figure. (Nice combination, eh? :-) Given
the lengths of the three sides of the triangle,
you are to find the areas of the regions with
each kind of flowers respectively.

Input
Each line of input contains three integers a, b,
c, the lengths of the three sides of the triangular
region, with 0 < a ≤ b ≤ c ≤ 1000.

Output
For each case, your program should output the areas of the
regions with sunflowers, with violets and with roses respectively. Print your answers correct to 4 decimal places.

Sample Input
3 4 5

Sample Output
13.6350 2.8584 3.1416

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
	fmt.Println(solve(3, 4, 5))
}

func solve(a, b, c float64) (float64, float64, float64) {
	inner := incircle(a, b, c)
	outer := circumcircle(a, b, c)

	area_inner := inner * inner * math.Pi
	area_triangle := area(a, b, c) - area_inner
	area_outer := outer*outer*math.Pi - area_inner - area_triangle

	return area_outer, area_triangle, area_inner
}

func incircle(ab, bc, ca float64) float64 {
	return area(ab, bc, ca) / (0.5 * perimeter(ab, bc, ca))
}

func circumcircle(ab, bc, ca float64) float64 {
	return (ab * bc * ca) / (4.0 * area(ab, bc, ca))
}

func area(a, b, c float64) float64 {
	s := (a + b + c) / 2
	return math.Sqrt(s * (s - a) * (s - b) * (s - c))
}

func perimeter(a, b, c float64) float64 {
	return a + b + c
}

func dist(a, b Point) float64 {
	return math.Hypot(a.x-b.x, a.y-b.y)
}
