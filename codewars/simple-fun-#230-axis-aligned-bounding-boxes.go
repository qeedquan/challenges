/*

Task
Given a set of points on the plane, find the area of its axis-aligned minimum bounding box.

The axis-aligned minimum bounding box for a given point set is its minimum bounding box with edges parallel to the (Cartesian) coordinate axes.

Input/Output
[input] integer array x

Non-empty array of integers representing the X coordinates of the points on the plane.

2 ≤ x.length ≤ 20,

-100 ≤ x[i] ≤ 100.

[input] integer array y

Array of integers representing the Y coordinates of the points. ith elements of both x and y correspond to a single point.

y.length = x.length,

-100 ≤ y[i] ≤ 100.

[output] an integer

The desired area.

Example
For x = [1, 0, 4] and y = [-1, 2, 2], the output should be 12.

In the image below points are given in blue, and the axis-aligned minimum bounding box is given in red. Its area is 3 * 4 = 12.

https://codefightsuserpics.s3.amazonaws.com/tasks/axisAlignedBoundingBox/img/plot.png?_tm=1490625562070

*/

package main

import "slices"

func main() {
	assert(aabb([]int{1, 0, 4}, []int{-1, 2, 2}) == 12)
	assert(aabb([]int{1, 2, 0, 0}, []int{1, 1, 1, 1}) == 0)
	assert(aabb([]int{1, 1, 1, 10}, []int{0, -1, 1, 0}) == 18)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func aabb(x, y []int) int {
	x0 := slices.Min(x)
	x1 := slices.Max(x)
	y0 := slices.Min(y)
	y1 := slices.Max(y)
	return (x1 - x0) * (y1 - y0)
}
