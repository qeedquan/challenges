/*

https://static.e-olymp.com/content/92/927bc9e2642a130a98b69beca4362cab5bf7c920.jpg

Numbers from 1 to n^2 are written in an n×n square matrix in a spiral, starting from the top-left cell and proceeding clockwise, as shown in the figure.

Find the number located in the i-th row and j-th column.

Input
The input contains three natural numbers: n, i, j (1≤i,j≤n≤100).

Output
Print the number at coordinates i, j.

Examples

Input #1
5 4 2

Answer #1
23

*/

package main

func main() {
	assert(solve(4, 3, 2) == 16)
	assert(solve(5, 1, 1) == 1)
	assert(solve(5, 1, 2) == 2)
	assert(solve(5, 1, 3) == 3)
	assert(solve(5, 1, 4) == 4)
	assert(solve(5, 1, 5) == 5)
	assert(solve(5, 2, 1) == 16)
	assert(solve(5, 2, 2) == 17)
	assert(solve(5, 2, 3) == 18)
	assert(solve(5, 2, 4) == 19)
	assert(solve(5, 2, 5) == 6)
	assert(solve(5, 3, 1) == 15)
	assert(solve(5, 3, 2) == 24)
	assert(solve(5, 3, 3) == 25)
	assert(solve(5, 3, 4) == 20)
	assert(solve(5, 3, 5) == 7)
	assert(solve(5, 4, 1) == 14)
	assert(solve(5, 4, 2) == 23)
	assert(solve(5, 4, 3) == 22)
	assert(solve(5, 4, 4) == 21)
	assert(solve(5, 4, 5) == 8)
	assert(solve(5, 5, 1) == 13)
	assert(solve(5, 5, 2) == 12)
	assert(solve(5, 5, 3) == 11)
	assert(solve(5, 5, 4) == 10)
	assert(solve(5, 5, 5) == 9)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, i, j int) int {
	k := min(i, j, n-i+1, n-j+1)
	B := 4 * (k - 1) * (n - k + 1)
	m := n - (2 * k) + 1
	if i == k {
		return B + (j - k + 1)
	}
	if j == n-k+1 {
		return B + m + (i - k + 1)
	}
	if i == n-k+1 {
		return B + 2*m + (n - k + 1 - j + 1)
	}
	return B + 3*m + (n - k + 1 - i + 1)
}
