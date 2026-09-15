/*

The cells of the chessboard of size n×n are enumerated with positive integers from 1 to n^2 as shown in the picture.
Find the sum of integers on white cells.

Input
One even positive integer n (n≤10^3).

Output
Print the sum of integers on white cells.

Examples

Input #1
4

Answer #1
68

*/

package main

func main() {
	assert(solve(2) == 5)
	assert(solve(3) == 25)
	assert(solve(4) == 68)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int) int {
	if n < 1 {
		return 0
	}

	m := n*n + 1
	if n&1 == 0 {
		return n * n * m / 4
	}
	return m * m / 4
}
