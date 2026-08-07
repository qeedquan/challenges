/*

We want to define the location x, y of a point on a two-dimensional plane where x and y are positive integers.

Our definition of such a point will return a function (procedure). There are several possible functions to do that.

Possible form of point:

(define (point a b)
  (lambda ...))

(procedure? (point 3 4)) -> #t
Of course we need to be able to extract from our point the two coordinates x and y.

The function fst must return the first element x and our function snd must return the second element y.

We will also write a function sqr-dist which returns the square of the distance between two points point1 and point2.

Last function to write line:

Given two points foo and bar this function return a list (l m n) or [l, m, n] where l, m, n are the coefficients in the general equation l*x + m*y + n = 0 (1) of the straight line through the points foo and bar.

Equation k*l*x + k*m*y + k*n = 0 is equivalent to (1) and the tests consider that they define the "same" line.

Examples: See "Sample Tests".
(define foo (point 3 5))
(procedure? (point 3 5)) -> #t
(fst foo) -> 3
(snd foo) -> 5
(sqr-dist (point 22 55) (point 75 66)) -> 2930
(line (point 20 22) (point 29 10)) -> '(12 9 -438) ['(4 3 -146) is a good answer too]

Note:
Please ask before translating: some translations are already written and published when/if the kata is approved.

*/

package main

import "image"

func main() {
	foo := point(3, 5)
	assert(fst(foo) == 3)
	assert(snd(foo) == 5)
	assert(sqrdist(point(22, 55), point(75, 66)) == 2930)
	assert(line(point(20, 22), point(29, 10)) == [3]int{12, 9, -438})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type pointfn func() image.Point

func point(x, y int) pointfn {
	return func() image.Point {
		return image.Point{x, y}
	}
}

func fst(pt pointfn) int {
	return pt().X
}

func snd(pt pointfn) int {
	return pt().Y
}

func sqrdist(pt1, pt2 pointfn) int {
	dx := fst(pt2) - fst(pt1)
	dy := snd(pt2) - snd(pt1)
	return dx*dx + dy*dy
}

func line(pt1, pt2 pointfn) [3]int {
	l := snd(pt1) - snd(pt2)
	m := fst(pt2) - fst(pt1)
	return [3]int{l, m, -(l*fst(pt1) + m*snd(pt1))}
}
