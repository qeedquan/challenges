/*

Pinball in Pascal's Triangle is a solo game designed for those with strong arithmetic skills. The playing field is structured as follows:

https://static.e-olymp.com/content/d4/d430c82938615c636a8b6b320a2d28686fdc9ce4.jpg

In each row of Pascal's Triangle, the numbers on the edges are ones, and any number inside is the sum of the two numbers directly above it.
The game begins with a token placed on the topmost one.
During each move, the player can slide the token one row down, choosing to move either half a column to the left or half a column to the right.
For instance, from the number four, the player can move to either five or ten.
After each move, the player scores points equal to the sum of the digits of the number they land on.
For simplicity, the player starts with one free point for the initial position at the top.

The objective is to navigate the token to the n-th row while maximizing the total points scored. Your task is to write a program to achieve this.

Input
The input consists of a single non-negative integer n, representing the target row number (n≤30).

Output
Output the maximum number of points that can be accumulated in this game.

Examples

Input #1
2

Answer #1
4

*/

package main

func main() {
	tab := []int{
		1, 2, 4, 7, 13, 16, 22, 30, 41, 53, 59, 71, 89, 107, 116, 134, 152, 170,
		197, 226, 257, 281, 313, 339, 369, 397, 427, 463, 490, 535, 580,
	}

	assert(solve(2) == 4)

	for i := range tab {
		assert(solve(i) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int) int {
	if n < 0 {
		return 0
	}

	a := make([][102]int, n+1)
	p := make([][102]int, n+1)

	a[0][50] = 1
	p[0][50] = 1
	for i := 1; i <= n; i++ {
		for j := 1; j <= 100; j++ {
			a[i][j] = a[i-1][j-1] + a[i-1][j+1]
			p[i][j] += digsum(a[i][j]) + max(p[i-1][j-1], p[i-1][j+1])
		}
	}

	r := 0
	for i := 0; i <= 100; i++ {
		r = max(r, p[n][i])
	}
	return r
}

func digsum(n int) int {
	r := 0
	for ; n > 0; n /= 10 {
		r += n % 10
	}
	return r
}
