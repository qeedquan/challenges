/*

A line on the plane is described by an equation Ax + By + C = 0. You are to find any point on this line, whose coordinates are integer numbers from  - 5·10^18 to 5·10^18 inclusive, or to find out that such points do not exist.

Input
The first line contains three integers A, B and C ( - 2·10^9 ≤ A, B, C ≤ 2·10^9) — corresponding coefficients of the line equation. It is guaranteed that A2 + B2 > 0.

Output
If the required point exists, output its coordinates, otherwise output -1.

Examples

input
2 5 3

output
6 -3

*/

package main

import "fmt"

func main() {
	test(2, 5, 3, 6, -3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b, c, rx, ry int) {
	x, y := solve(a, b, c)
	fmt.Println(x, y)
	assert(x == rx)
	assert(y == ry)
}

func solve(a, b, c int) (int, int) {
	g, x, y := egcd(a, b)
	if g == 0 || c%g != 0 {
		return 0, 0
	}
	return -x * (c / g), -y * (c / g)
}

// https://anh.cs.luc.edu/331/notes/xgcd.pdf
func egcd(a, b int) (int, int, int) {
	px, x := 1, 0
	py, y := 0, 1
	for b != 0 {
		q := a / b
		x, px = px-q*x, x
		y, py = py-q*y, y
		a, b = b, a%b
	}
	return a, px, py
}
