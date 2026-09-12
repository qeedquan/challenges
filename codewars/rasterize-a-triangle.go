/*

Objective
Create a rasterized binary image of a triangle.

Given
(x1, y1), (x2, y2), and (x3, y3) - Integer coordinates of triangle vertices.
n - Size of the output image.

Expected Output
An n-by-n image of 1s and 0s.

Details
1 <= n <= 100
The origin of the coordinate system is the upper-left pixel with coordinates (0,0).
The x coordinate increases to the right and the y coordinate increases downward.
A pixel should be set to 1 only if it's coordinate is either inside the triangle or on it's boundary.
Triangle coordinates may be outside the image bounds.
No degenerate triangles will be provided.

Example
https://imgur.com/JJz4s0l

The triangle shown above is defined by vertices (2,1), (0,3), and (5,4).

For n=6 the expected output is

[ [0,0,0,0,0,0],
  [0,0,1,0,0,0],
  [0,1,1,1,0,0],
  [1,1,1,1,1,0],
  [0,0,0,0,0,1],
  [0,0,0,0,0,0] ]
For n=3 the expected output is

[ [0,0,0],
  [0,0,1],
  [0,1,1] ]

*/

package main

import (
	"fmt"
	"image"
	"reflect"
)

func main() {
	test([3]image.Point{
		{2, 1},
		{0, 3},
		{5, 4},
	}, 6, [][]int{
		{0, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0},
		{0, 1, 1, 1, 0, 0},
		{1, 1, 1, 1, 1, 0},
		{0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0},
	})

	test([3]image.Point{
		{2, 1},
		{0, 3},
		{5, 4},
	}, 3, [][]int{
		{0, 0, 0},
		{0, 0, 1},
		{0, 1, 1},
	})

	test([3]image.Point{
		{0, 0},
		{0, 2},
		{2, 2},
	}, 3, [][]int{
		{1, 0, 0},
		{1, 1, 0},
		{1, 1, 1},
	})

	test([3]image.Point{
		{-2, 0},
		{-2, 2},
		{-4, 2},
	}, 4, [][]int{
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	})

	test([3]image.Point{
		{-2, -2},
		{6, -2},
		{2, 2},
	}, 5, [][]int{
		{0, 1, 1, 1, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
	})

	test([3]image.Point{
		{1, -49997},
		{2, 3},
		{3, 50002},
	}, 6, [][]int{
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0},
	})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(v [3]image.Point, n int, r [][]int) {
	m := rasterize(v, n)
	output(m)
	assert(reflect.DeepEqual(m, r))
}

func output(m [][]int) {
	for i := range m {
		fmt.Println(m[i])
	}
	fmt.Println()
}

func rasterize(v [3]image.Point, n int) [][]int {
	m := alloc(n)
	for y := range n {
		for x := range n {
			p := image.Pt(x, y)
			if in(v[0], v[1], v[2], p) {
				m[y][x] = 1
			}
		}
	}
	return m
}

func alloc(n int) [][]int {
	m := make([][]int, n)
	t := make([]int, n*n)
	for i := range m {
		m[i] = t[i*n : (i+1)*n]
	}
	return m
}

func in(v0, v1, v2, p image.Point) bool {
	b1 := sign(p, v0, v1) <= 0
	b2 := sign(p, v1, v2) <= 0
	b3 := sign(p, v2, v0) <= 0
	return b1 == b2 && b2 == b3
}

func sign(a, b, c image.Point) int {
	return (a.X-c.X)*(b.Y-c.Y) - (b.X-c.X)*(a.Y-c.Y)
}
