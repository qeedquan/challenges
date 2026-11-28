/*

The hold of a barge has the shape of a square with side C (C=1..1000), divided into unit squares (cells) numbered from left to right, row by row.
Each cell contains flammable cargo. Exactly at midnight, due to lightning, the cell with number N catches fire.
Each cell burns for 1 minute, and then the fire spreads to all neighboring cells that share a side.
How many hours (G) and minutes (H) does the fire last until all the cargo is completely burned?

Input
Two positive integers are given: C and N (N=1..C^2).

Output
Output two non-negative integers G and H (the number of hours and minutes).

Examples

Input #1
3 5

Answer #1
0 3

*/

package main

import "fmt"

func main() {
	fmt.Println(solve(3, 5))
}

func solve(c, n int) (int, int) {
	n -= 1
	a := n / c
	b := n % c

	r := dist(a, b, 0, 0)
	r = max(r, dist(a, b, c-1, c-1))
	r = max(r, dist(a, b, c-1, 0))
	r = max(r, dist(a, b, 0, c-1))
	r += 1

	return r / 60, r % 60
}

func dist(a, b, c, d int) int {
	return abs(a-c) + abs(b-d)
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
