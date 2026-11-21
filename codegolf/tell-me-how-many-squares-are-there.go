/*

Given a non-empty 2D array consisting of 0 and 1, find the number of squares whose 4 corners are all 1. The squares do not need to be "upright". All the rows are guaranteed to have the same length.

Reasonable input/output methods are allowed.

Testcases:

0001000
1000000
0000000
0000100
0100000
This returns 1.

10101
00000
10100
00000
10001
This returns 2.

1111
1111
1111
1111
This returns 20.

This is code-golf. Shortest answer in bytes wins. Standard loopholes apply.

*/

package main

func main() {
	assert(count([][]int{
		{0, 0, 0, 1, 0, 0, 0},
		{1, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0},
		{0, 1, 0, 0, 0, 0, 0},
	}) == 1)

	assert(count([][]int{
		{1, 0, 1, 0, 1},
		{0, 0, 0, 0, 0},
		{1, 0, 1, 0, 0},
		{0, 0, 0, 0, 0},
		{1, 0, 0, 0, 1},
	}) == 2)

	assert(count([][]int{
		{1, 1, 1, 1},
		{1, 1, 1, 1},
		{1, 1, 1, 1},
		{1, 1, 1, 1},
	}) == 20)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@Arnauld

How?
This function iterates on all pairs of cells (x, y), (X, Y) of the input matrix m such that:

m[ x, y ] = m[ X, Y ] = 1
x < X
y ≤ Y
Each matching pair describes the coordinates of a potential edge of a square. The inequations guarantee that each edge is tested only once.

We use the vector [ dx, dy ] = [ X - x, Y - y ] rotated 90° clockwise to test the cells located at [ x - dy, y + dx ] and [ X - dy, Y + dx ].
If they both contain a 1, we've found a valid square.

https://i.sstatic.net/yHt4Z.png

*/

func count(m [][]int) int {
	c := 0
	for y := range m {
		for x := range m[y] {
			for Y := y; Y < len(m); Y++ {
				for X := x + 1; X < len(m[Y]); X++ {
					dx := X - x
					dy := Y - y

					p := one(m, x, y)
					p += one(m, X, Y)
					p += one(m, x-dy, y+dx)
					p += one(m, X-dy, Y+dx)
					if p == 4 {
						c++
					}
				}
			}
		}
	}
	return c
}

func one(m [][]int, x, y int) int {
	if y < 0 || y >= len(m) || x < 0 || x >= len(m[y]) || m[y][x] != 1 {
		return 0
	}
	return 1
}
