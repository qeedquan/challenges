/*

Find the perimeter of a rectangle.

Input
Two positive integers a and b (1≤a,b≤1000) — the sides of the rectangle.

Output
Print the perimeter of the rectangle.

Examples

Input #1
3 4

Answer #1
14

*/

package main

func main() {
	assert(solve(3, 4) == 14)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b int) int {
	return 2 * (a + b)
}
