/*

On a plane, a square is defined by the coordinates of two of its opposite vertices.

Your task is to determine the coordinates of the remaining two vertices of the square.

Input
The program will read from standard input (keyboard) two lines.
The first line contains the coordinates of one vertex of the square, Ax and Ay.
The second line contains the coordinates of the opposite vertex of the square, Cx and Cy.
All numbers are real and do not exceed 10^6 in absolute value.

Output
The program should output to standard output (screen) two lines, each containing two space-separated numbers: Bx By, and Dx Dy.
These represent the coordinates of the remaining two vertices of the square.
The order of the output should ensure that A, B, C, D are listed in a counterclockwise sequence, with each coordinate rounded to 4 decimal places.

Examples
Input #1
5 6
4 1

Answer #1
2 4
7 3

*/

package main

import (
	"fmt"
	"math"
)

type Point struct {
	x, y float64
}

type Vector Point

func main() {
	solve(Point{5, 6}, Point{4, 1})
}

func solve(a, c Point) {
	m := midpoint(c, a)
	v := sub(c, a)
	l := length(v)
	u := normalize(perp(v))
	b := add(m, scale(u, -l/2))
	d := add(m, scale(u, l/2))
	fmt.Println(b)
	fmt.Println(d)
	fmt.Println()
}

func (p Point) String() string {
	return fmt.Sprintf("%v %v", p.x, p.y)
}

func midpoint(a, b Point) Point {
	return Point{(a.x + b.x) / 2, (a.y + b.y) / 2}
}

func add(a Point, v Vector) Point {
	return Point{a.x + v.x, a.y + v.y}
}

func sub(a, b Point) Vector {
	return Vector{a.x - b.x, a.y - b.y}
}

func perp(v Vector) Vector {
	return Vector{-v.y, v.x}
}

func length(v Vector) float64 {
	return math.Hypot(v.x, v.y)
}

func normalize(v Vector) Vector {
	l := length(v)
	return Vector{v.x / l, v.y / l}
}

func scale(v Vector, s float64) Vector {
	return Vector{v.x * s, v.y * s}
}
