/*

A queen is placed on an m×n chessboard. Determine how many squares are under its attack.

Input
Four positive integers: the size of the chessboard m and n, as well as the coordinates of the queen x and y (1≤x≤m≤10^9, 1≤y≤n≤10^9).

Output
Print the number of squares under the queen's attack.

Examples

Input #1
8 8
4 5

Answer #1
27

*/

package main

func main() {
	assert(solve(8, 8, 4, 5) == 27)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, m, a, b int) int {
	return n - 1 + m - 1 + min(a-1, b-1) + min(a-1, m-b) + min(n-a, b-1) + min(n-a, m-b)
}
