/*

A rectangular garden plot of width n and length m is divided into squares of side 1.
Beds are dug in this plot.
A bed is a collection of squares that satisfies the following conditions:

From any square of the bed, it is possible to reach any other square of the same bed by moving along the bed from square to square through their common side.

No two beds intersect or touch each other vertically or horizontally (beds may touch at the corners of squares).

Count the number of beds in the garden plot.

Input
The first line contains two numbers n and m (1≤n,m≤200).
The following n lines each contain m characters.
The # symbol denotes the territory of a bed, and the dot denotes empty territory.
There are no other characters in the input.

Output
Print the number of beds in the garden plot.

Examples

Input #1
5 10
##......#.
.#..#...#.
.###....#.
..##....#.
........#.

Answer #1
3

*/

package main

func main() {
	assert(solve([][]byte{
		[]byte("##......#."),
		[]byte(".#..#...#."),
		[]byte(".###....#."),
		[]byte("..##....#."),
		[]byte("........#."),
	}) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(m [][]byte) int {
	r := 0
	for i := range m {
		for j := range m[i] {
			if m[i][j] == '#' {
				r += 1
				dfs(m, i, j)
			}
		}
	}
	return r
}

func dfs(m [][]byte, i, j int) {
	m[i][j] = '.'
	if at(m, i-1, j) == '#' {
		dfs(m, i-1, j)
	}
	if at(m, i+1, j) == '#' {
		dfs(m, i+1, j)
	}
	if at(m, i, j-1) == '#' {
		dfs(m, i, j-1)
	}
	if at(m, i, j+1) == '#' {
		dfs(m, i, j+1)
	}
}

func at(m [][]byte, i, j int) byte {
	if i < 0 || i >= len(m) || j < 0 || j >= len(m[i]) {
		return 0
	}
	return m[i][j]
}
