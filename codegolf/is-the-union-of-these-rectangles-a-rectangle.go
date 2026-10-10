/*

The intersection of two rectangles is always a rectangle (if you consider the empty set to be a rectangle). But the union of two rectangles is not necessarily a rectangle.

Given two rectangles as input determine if their union is also a rectangle.

The corners of the input rectangles will always have integer coordinates, and the edges will be parallel to the x and y axes.

The union of two rectangles is a rectangle if either:

One rectangle is completely contained within the other.
The two parallel edges of one rectangle each intersect with an edge parallel of the other rectangle parallel to them.

Specifications
You may take input in any of the following forms:

Each rectangle is given as is four corners (in any order).
Each rectangle is given as the two corners (in either order) in any of the following forms:
The upper left and lower right corner
The lower left and upper right corner
The corner closest to the origin and the corner opposite it.
Each rectangle is given as any corner as well as its width and height.
Each rectangle is given as 4 integers representing the smallest and largest x and y values in the rectangle.
Input rectangles will have positive area.

You should output one consistent value if the union of the input rectangles is a rectangle and another distinct consistent value if the union is not a rectangle.

This is code-golf so the goal is to minimize the size of your source code as measured in bytes.

Test cases
Rectangles are given as the corner closest to the origin and the corner opposite it.

((0,0),(1,1)) ((0,1),(1,12)) == true
((0,0),(1,1)) ((1,0),(12,1)) == true
((-1,-1),(1,1)) ((-1,1),(0,0)) == true
((10,2),(14,5)) ((11,3),(13,4)) == true
((0,0),(2,2)) ((0,3),(2,-6)) == true
((4,4),(8,12)) ((4,5),(8,16)) == true
((0,0),(3,3)) ((1,1),(2,3)) == true
((4,4),(8,12)) ((4,5),(7,16)) == False
((0,0),(2,2)) ((0,3),(2,4)) == False
((0,0),(3,3)) ((1,1),(2,4)) == False

*/

package main

func main() {
	assert(check(0, 0, 1, 1, 0, 1, 1, 12) == true)
	assert(check(0, 0, 1, 1, 1, 0, 12, 1) == true)
	assert(check(-1, -1, 1, 1, -1, 1, 0, 0) == true)
	assert(check(10, 2, 14, 5, 11, 3, 13, 4) == true)
	assert(check(0, 0, 2, 2, 0, 3, 2, -6) == true)
	assert(check(4, 4, 8, 12, 4, 5, 8, 16) == true)
	assert(check(0, 0, 3, 3, 1, 1, 2, 3) == true)
	assert(check(4, 4, 8, 12, 4, 5, 7, 16) == false)
	assert(check(0, 0, 2, 2, 0, 3, 2, 4) == false)
	assert(check(0, 0, 3, 3, 1, 1, 2, 4) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func check(l0, d0, r0, u0, l1, d1, r1, u1 int) bool {
	if r0 < l0 {
		l0, r0 = r0, l0
	}
	if u0 < d0 {
		d0, u0 = u0, d0
	}
	if r1 < l1 {
		l1, r1 = r1, l1
	}
	if u1 < d1 {
		d1, u1 = u1, d1
	}
	return unionable(l0, d0, r0-l0, u0-d0, l1, d1, r1-l1, u1-d1)
}

/*

ported from @gsitcia solution

Takes input as bottom-left corner, width, height. Returns true when the union is a rectangle.

Checks if the sum of the area of the two rectangles equals the area of the intersection plus the area of the bounding box.

*/

func unionable(left_0, bottom_0, width_0, height_0, left_1, bottom_1, width_1, height_1 int) bool {
	right_0 := left_0 + width_0
	right_1 := left_1 + width_1
	up_0 := bottom_0 + height_0
	up_1 := bottom_1 + height_1

	// side lengths of intersection (may be negative)
	C := min(right_0, right_1) - max(left_0, left_1)
	D := min(up_0, up_1) - max(bottom_0, bottom_1)

	rect_areas := width_0*height_0 + width_1*height_1
	bounding_area := (width_0 + width_1 - C) * (height_0 + height_1 - D)
	// width_0 + width_1 - C == max(right_0, right_1) - min(left_0, left_1)
	intersection_area := abs(C * D)
	// theoretically should be max(C,0)*max(D,0) but abs(C*D) is shorter and works

	return !(rect_areas < bounding_area+intersection_area)
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
