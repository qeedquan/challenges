/*

Three points may form a triangle if they are not aligned or they do not coincide. For every triangle we may have a circle that contains the three vertices of the triangle. This circle receives the name of the Circumscribed Circle For a Triangle as we can see in the image:

https://imgur.com/0hr7k1t

The center of this circle receives the name of the circumcenter and is the intersection of the perpendicular bisectors (m1, m2, m3). In the image we have above this lines intersects at the circumcenter.

If the triangle has vertices A, B and C, and their corresponding coordinates (xA, yA), (xB, yB) and (xC, yC), the coordinates of the circumcenter (Ux, Uy) are:

https://imgur.com/IC79nsL

The diameter, diam of the circumscribed circle is in function of the values of the sides AB, BC and AC, and the value of parameter D (seen above)

The value of the area should be always positive for our purposes, that is why we will use the absolute value. (abs(x) is equivalent in math to |x|)

https://imgur.com/EuCr1ut

With all these calculations in mind we will define the function circum_curvat() that will receive the coordinates of three vertices of the triangle and outputs a list of lists with the coordinates of the circumcenter and the radius of the circle equals to diam / 2.0. The results do not have to be rounded.

pointA = (xA, yA)
pointB = (xB, yB)
pointC = (xC, yC)
circum_curvat(pointA, pointB, pointC) -----> [["Circumcenter coord.", (Ux, Uy)], ["radius", diam/2.0]]
Let's see some cases:

pointA = (1, 4)
pointB = (2, 7)
pointC = (5, 1)
circum_curvat(pointA, pointB, pointC) == [['Circumcenter coord.', (4.5, 4.5)], ['radius', 3.535534]]

pointA = -2, 1
pointB = 2, -3
pointC = 4, 3
circum_curvat(pointA, pointB, pointC) == [['Circumcenter coord.', (1.5, 0.5)], ['radius', 3.535534]]
But if the points are aligned we will not have circumcenter and the radius of the circle will be ∞ (infinite), so we have to handle this special case.

If the points are aligned D = 0 In this case the function will output, "The three Points A, B, and C are aligned"

pointA = 1, 1
pointB = 4, 4
pointC = 7, 7
circum_curvat(pointA, pointB, pointC) == "The three Points A, B, and C are aligned"
If the point A has equal coordinates than the ones of point B, or the same situation for points B and C or enen more for points A and C. the function will return "There is coincidence with the given points"

pointA = 1, 1
pointB = 4, 4
pointC = 4, 4
circum_curvat(pointA, pointB, pointC) == "There is coincidence with the given points"
Enjoy it!!

*/

package main

import (
	"fmt"
	"math"
)

type vec2 struct {
	x, y float64
}

func main() {
	fmt.Println(circumscribe(vec2{1, 4}, vec2{2, 7}, vec2{5, 1}))
	fmt.Println(circumscribe(vec2{-2, 1}, vec2{2, -3}, vec2{4, 3}))
	fmt.Println(circumscribe(vec2{1, 1}, vec2{4, 4}, vec2{7, 7}))
	fmt.Println(circumscribe(vec2{1, 1}, vec2{4, 4}, vec2{4, 4}))
}

func circumscribe(a, b, c vec2) (vec2, float64, error) {
	ab := math.Hypot(b.x-a.x, b.y-a.y)
	bc := math.Hypot(c.x-b.x, c.y-b.y)
	ac := math.Hypot(c.x-a.x, c.y-a.y)

	a2 := a.x*a.x + a.y*a.y
	b2 := b.x*b.x + b.y*b.y
	c2 := c.x*c.x + c.y*c.y

	d := 2 * (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y))
	if d == 0 {
		if a == b || a == c || b == c {
			return vec2{}, 0, fmt.Errorf("There is coincidence with the given points")
		}
		return vec2{}, 0, fmt.Errorf("The three Points A, B, and C are aligned")
	}

	x := (a2*(b.y-c.y) + b2*(c.y-a.y) + c2*(a.y-b.y)) / d
	y := (a2*(c.x-b.x) + b2*(a.x-c.x) + c2*(b.x-a.x)) / d
	r := ab * bc * ac / math.Abs(d)

	return vec2{x, y}, r, nil
}
