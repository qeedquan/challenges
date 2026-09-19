/*

"Point reflection" or "point symmetry" is a basic concept in geometry where a given point, P, at a given position relative to a mid-point, Q has a corresponding point, P1, which is the same distance from Q but in the opposite direction.

Task
Given two points P and Q, output the symmetric point of point P about Q. Each argument is a two-element array of integers representing the point's X and Y coordinates.
Output should be in the same format, giving the X and Y coordinates of point P1. You do not have to validate the input.

This kata was inspired by the Hackerrank challenge Find Point

*/

package main

import (
	"fmt"
	"image"
)

func main() {
	fmt.Println(reflect(image.Pt(0, 0), image.Pt(1, 1)))
	fmt.Println(reflect(image.Pt(1, 1), image.Pt(2, 2)))
}

func reflect(p, q image.Point) image.Point {
	return image.Pt(q.X*2-p.X, q.Y*2-p.Y)
}
