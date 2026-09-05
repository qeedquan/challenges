/*

Following on from Points of Reflection, given a number of points and a single midpoint, a 2D shape can be inferred.

Task:

You will be given two inputs. The first will be a two-dimensional sequence in which the inner sequences contain two elements representing partial coordinates of a 2D shape. The second input will be a two-element sequence representing the shape's mid-point. Using the existing coordinates and the mid-point, return the complete shape as a two-dimensional array.

The output sorting must be the original points of shape followed by the reflected points in the same order than the points in shape.

Oh and, nice try cheaters! You will now have to refactor. You may no longer modify the test inputs ;) Thanks to FArekkusu and hobovsky for their contributions to improving this kata.

*/

package main

import (
	"fmt"
	"image"
	"reflect"
)

func main() {
	test(
		[]image.Point{{-1, -1}, {1, 2}}, image.Point{0, 0},
		[]image.Point{{-1, -1}, {1, 2}, {1, 1}, {-1, -2}},
	)

	test(
		[]image.Point{{1, 1}, {-1, -2}}, image.Point{0, 0},
		[]image.Point{{1, 1}, {-1, -2}, {-1, -1}, {1, 2}},
	)

	test(
		[]image.Point{{-1, -1}, {1, 2}}, image.Point{2, 3},
		[]image.Point{{-1, -1}, {1, 2}, {5, 7}, {3, 4}},
	)

	test(
		[]image.Point{{-5, 6}, {1, -5}, {-1, -1}, {1, 2}}, image.Point{6, 1},
		[]image.Point{{-5, 6}, {1, -5}, {-1, -1}, {1, 2}, {17, -4}, {11, 7}, {13, 3}, {11, 0}},
	)

	test(
		[]image.Point{{-12, -7}, {10, 2}, {-1, -2}, {-1, -1}, {1, 2}}, image.Point{-10, 5},
		[]image.Point{{-12, -7}, {10, 2}, {-1, -2}, {-1, -1}, {1, 2}, {-8, 17}, {-30, 8}, {-19, 12}, {-19, 11}, {-21, 8}},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(shape []image.Point, midpoint image.Point, expected []image.Point) {
	result := symmetry(shape, midpoint)
	fmt.Println(result)
	assert(reflect.DeepEqual(result, expected))
}

func symmetry(shape []image.Point, midpoint image.Point) []image.Point {
	result := append([]image.Point{}, shape...)
	for i := range shape {
		result = append(result, image.Point{
			2*midpoint.X - shape[i].X,
			2*midpoint.Y - shape[i].Y,
		})
	}
	return result
}
