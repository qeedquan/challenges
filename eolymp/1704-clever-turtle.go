/*

https://static.e-olymp.com/content/06/06375a09d4577d048e570ec8ed34b3cbf6652a11.gif

A grid of size m×n is given. A turtle is located in the bottom-left corner and can move only to the right or up.
Before reaching the top-right corner, the turtle wondered: how many different ways are there to get from the starting point to the top-right corner?

Although the turtle is clever, it cannot yet calculate such a large number of possibilities on its own. Help the turtle find the answer to its question.

Input
Two positive integers m and n, each not exceeding 30.

Output
Output the number of ways the turtle can reach the top-right corner from the bottom-left corner.

Examples
Input #1
4 3

Answer #1
10

*/

package main

func main() {
	assert(solve(4, 3) == 10)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, m int) int {
	if n < 0 || m < 0 {
		return 0
	}

	p := make([][]int, n+1)
	for i := range p {
		p[i] = make([]int, m+1)
	}

	p[1][0] = 1
	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			p[i][j] = p[i][j-1] + p[i-1][j]
		}
	}
	return p[n][m]
}
