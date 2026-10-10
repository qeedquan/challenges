/*

Computing the area of a single rectangle is extremely simple: width multiplied by height.
Computing the area of two rectangles is a little more challenging. They can either be separate and thus have their areas calculated individually, like this.
They can also intersect, in which case you calculate their individual areas, and subtract the area of the intersection, like this.
Once you get to 3 rectangles, there are multiple possibilities: no intersections, one intersection of two rectangles, two intersections of two rectangles,
or one intersection of three rectangles (plus three intersections of just two rectangles).
Obviously at that point it becomes impractical to account for each situation individually but it might be possible. But what about 4 rectangles? 5 rectangles? N rectangles?

Your challenge is, given any number of rectangles and their position/dimensions, find the area of the resultant overlapping (combined) shape.

Formal Inputs and Outputs
Input Description
On the console, you will be given a number N - this will represent how many rectangles you will receive. You will then be given co-ordinates describing opposite corners of N rectangles, in the form:

x1 y1 x2 y2
Where the rectangle's opposite corners are the co-ordinates (x1, y1) and (x2, y2).
Note that the corners given will be the top-left and bottom-right co-ordinates, in that order. Assume top-left is (0, 0).

Output Description
You must print out the area (as a number) of the compound shape given. No units are necessary.

Sample Inputs & Outputs
Sample Input
(representing this situation)

3
0 1 3 3
2 2 6 4
1 0 3 5
Sample Output
18
Challenge
Challenge Input
18
1.6 1.2 7.9 3.1
1.2 1.6 3.4 7.2
2.6 11.6 6.8 14.0
9.6 1.2 11.4 7.5
9.6 1.7 14.1 2.8
12.8 2.7 14.0 7.9
2.3 8.8 2.6 13.4
1.9 4.4 7.2 5.4
10.1 6.9 12.9 7.6
6.0 10.0 7.8 12.3
9.4 9.3 10.9 12.6
1.9 9.7 7.5 10.5
9.4 4.9 13.5 5.9
10.6 9.8 13.4 11.0
9.6 12.3 14.5 12.8
1.5 6.8 8.0 8.0
6.3 4.7 7.7 7.0
13.0 10.9 14.0 14.5
Challenge Output (hidden by default)
89.48

Notes
Thinking of each shape individually will only make this challenge harder. Try grouping intersecting shapes up, or calculating the area of regions of the shape at a time.
Allocating occupied points in a 2-D array would be the easy way out of doing this - however, this falls short when you have large shapes, or the points are not integer values. Try to come up with another way of doing it.

Because this a particularly challenging task, We'll be awarding medals to anyone who can submit a novel solution without using the above method.

*/

package main

import (
	"fmt"
	"math"
	"sort"
)

type Rect struct {
	x1, y1, x2, y2 float64
}

type Segment struct {
	a, b float64
}

func main() {
	test([]Rect{
		{0, 1, 3, 3},
		{2, 2, 6, 4},
		{1, 0, 3, 5},
	}, 18)

	test([]Rect{
		{1.6, 1.2, 7.9, 3.1},
		{1.2, 1.6, 3.4, 7.2},
		{2.6, 11.6, 6.8, 14.0},
		{9.6, 1.2, 11.4, 7.5},
		{9.6, 1.7, 14.1, 2.8},
		{12.8, 2.7, 14.0, 7.9},
		{2.3, 8.8, 2.6, 13.4},
		{1.9, 4.4, 7.2, 5.4},
		{10.1, 6.9, 12.9, 7.6},
		{6.0, 10.0, 7.8, 12.3},
		{9.4, 9.3, 10.9, 12.6},
		{1.9, 9.7, 7.5, 10.5},
		{9.4, 4.9, 13.5, 5.9},
		{10.6, 9.8, 13.4, 11.0},
		{9.6, 12.3, 14.5, 12.8},
		{1.5, 6.8, 8.0, 8.0},
		{6.3, 4.7, 7.7, 7.0},
		{13.0, 10.9, 14.0, 14.5},
	}, 89.48)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(r []Rect, v float64) {
	a := solve(r)
	fmt.Println(a)
	assert(math.Abs(a-v) < 1e-12)
}

// ported from @skeeto solution
// https://stackoverflow.com/questions/244452/what-is-an-efficient-algorithm-to-detect-overlapping-areas-of-rectangles/245245#245245
func solve(r []Rect) float64 {
	v := 0.0
	xs := horizons(r)
	for i := range len(xs) - 1 {
		ys, ye := intervals(r, xs[i])
		for _, s := range segments(ys, ye) {
			v += (xs[i+1] - xs[i]) * (s.b - s.a)
		}
	}
	return v
}

func horizons(r []Rect) []float64 {
	xs := []float64{}
	for i := range r {
		xs = append(xs, r[i].x1, r[i].x2)
	}
	sort.Float64s(xs)

	n := 0
	for i, j := 0, 0; i < len(xs); i = j {
		j = i + 1
		for j < len(xs) && xs[i] == xs[j] {
			j++
		}
		xs[n], n = xs[i], n+1
	}
	return xs[:n]
}

func intervals(r []Rect, x float64) ([]float64, []float64) {
	var ys, ye []float64
	for i := range r {
		if r[i].x1 <= x && r[i].x2 > x {
			ys = append(ys, r[i].y1)
			ye = append(ye, r[i].y2)
		}
	}
	sort.Float64s(ys)
	sort.Float64s(ye)
	return ys, ye
}

func segments(ys, ye []float64) []Segment {
	l := []Segment{}
	s := Segment{}
	d := 0
	for len(ys) > 0 || len(ye) > 0 {
		p, y := d, 0.0
		if len(ys) > 0 && ys[0] <= ye[0] {
			d, y, ys = d+1, ys[0], ys[1:]
		} else {
			d, y, ye = d-1, ye[0], ye[1:]
		}

		if p == 0 {
			s.a = y
		} else if d == 0 {
			s.b = y
			l = append(l, s)
		}
	}
	return l
}
