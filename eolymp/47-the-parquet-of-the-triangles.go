/*

A rectangular room of size M×N (first along the horizontal, then along the vertical) is tiled with triangular tiles, which are numbered as shown in the figure.

In one step, you can move from one tile to an adjacent tile only through a shared side. Find the minimum number of steps required to move from tile A to tile B.

Input
The first line contains the dimensions M and N (1≤M,N≤100).

The second line contains the numbers of the tiles A and B.

Output
Output the minimum number of steps required.

Examples

Input #1
5 4
25 38

Answer #1
5

*/

package main

func main() {
	assert(parkets(25, 38, 5, 4) == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func parkets(a, b, m, n int) int {
	if a == b {
		return 0
	}

	if a > b {
		return parkets(b, a, m, n)
	}

	l0 := line(a, m)
	l1 := line(b, m)
	if l0 == l1 {
		return abs(a - b)
	}

	c0 := column(a, m)
	c1 := column(b, m)
	if c0 == c1 {
		if a%2 == 1 {
			return 1 + parkets(a+1, b, m, n)
		}
		return 1 + parkets(a+m*2-1, b, m, n)
	}

	if a%2 == 1 {
		if c0 > c1 {
			return 1 + parkets(a-1, b, m, n)
		}
		return 2 + parkets(a+2, b, m, n)
	}

	return 1 + parkets(a+m*2-1, b, m, n)
}

func line(a, m int) int {
	if a%2 == 0 {
		return line(a-1, m)
	}
	return a/(m*2) + 1
}

func column(a, m int) int {
	if a%2 == 0 {
		return column(a-1, m)
	}
	return (a%(m*2))/2 + 1
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
