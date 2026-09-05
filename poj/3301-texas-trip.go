/*

Description

After a day trip with his friend Dick, Harry noticed a strange pattern of tiny holes in the door of his SUV. The local American Tire store sells fiberglass patching material only in square sheets. What is the smallest patch that Harry needs to fix his door?

Assume that the holes are points on the integer lattice in the plane. Your job is to find the area of the smallest square that will cover all the holes.

Input

The first line of input contains a single integer T expressed in decimal with no leading zeroes, denoting the number of test cases to follow. The subsequent lines of input describe the test cases.

Each test case begins with a single line, containing a single integer n expressed in decimal with no leading zeroes, the number of points to follow; each of the following n lines contains two integers x and y, both expressed in decimal with no leading zeroes, giving the coordinates of one of your points.

You are guaranteed that T ≤ 30 and that no data set contains more than 30 points. All points in each data set will be no more than 500 units away from (0,0).

Output

Print, on a single line with two decimal places of precision, the area of the smallest square containing all of your points.

Sample Input

2
4
-1 -1
1 -1
1 1
-1 1
4
10 1
10 -1
-10 1
-10 -1

Sample Output

4.00
242.00

Source

Waterloo Local Contest, 2007.7.14

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test([]vec2{
		{-1, -1},
		{1, -1},
		{1, 1},
		{-1, 1},
	}, 4)

	test([]vec2{
		{10, 1},
		{10, -1},
		{-10, 1},
		{-10, -1},
	}, 242)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(points []vec2, expected float64) {
	val := area(points)
	fmt.Println(val)
	assert(math.Abs(val-expected) < 1e-2)
}

func area(points []vec2) float64 {
	const eps = 1e-12
	lo, hi := 0.0, math.Pi
	for hi-lo > eps {
		mid1 := lo + (hi-lo)/3
		mid2 := hi - (hi-lo)/3
		q1 := bound(points, mid1)
		q2 := bound(points, mid2)
		if q1 < q2 {
			hi = mid2
		} else {
			lo = mid1
		}
	}

	val := bound(points, lo)
	return val * val
}

func bound(points []vec2, angle float64) float64 {
	xmin := math.MaxFloat64
	xmax := -math.MaxFloat64
	ymin := math.MaxFloat64
	ymax := -math.MaxFloat64

	sin, cos := math.Sincos(angle)
	for _, p := range points {
		tx := p.x*cos - p.y*sin
		ty := p.y*cos + p.x*sin
		xmin = min(xmin, tx)
		xmax = max(xmax, tx)
		ymin = min(ymin, ty)
		ymax = max(ymax, ty)
	}
	return max(xmax-xmin, ymax-ymin)
}

type vec2 struct {
	x, y float64
}
