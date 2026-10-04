/*

You are given two integers m and n representing a 0-indexed m x n grid.
You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj]
represent the positions of the ith guard and jth wall respectively.

A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard.
A cell is guarded if there is at least one guard that can see it.

Return the number of unoccupied cells that are not guarded.

Example 1:
https://assets.leetcode.com/uploads/2022/03/10/example1drawio2.png
Input: m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
Output: 7
Explanation: The guarded and unguarded cells are shown in red and green respectively in the above diagram.
There are a total of 7 unguarded cells, so we return 7.

Example 2:
https://assets.leetcode.com/uploads/2022/03/10/example2drawio.png
Input: m = 3, n = 3, guards = [[1,1]], walls = [[0,1],[1,0],[2,1],[1,2]]
Output: 4
Explanation: The unguarded cells are shown in green in the above diagram.
There are a total of 4 unguarded cells, so we return 4.

Constraints:

1 <= m, n <= 10^5
2 <= m * n <= 10^5
1 <= guards.length, walls.length <= 5 * 10^4
2 <= guards.length + walls.length <= m * n
guards[i].length == walls[j].length == 2
0 <= rowi, rowj < m
0 <= coli, colj < n
All the positions in guards and walls are unique.

Hint 1
Create a 2D array to represent the grid. Can you mark the tiles that can be seen by a guard?

Hint 2
Iterate over the guards, and for each of the 4 directions, advance the current tile and mark the tile. When should you stop advancing?

*/

package main

func main() {
	assert(unguarded(4, 6, [][2]int{{0, 0}, {1, 1}, {2, 3}}, [][2]int{{0, 1}, {2, 2}, {1, 4}}) == 7)
	assert(unguarded(3, 3, [][2]int{{1, 1}}, [][2]int{{0, 1}, {1, 0}, {2, 1}, {1, 2}}) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func unguarded(m, n int, g, w [][2]int) int {
	p := make([][]int, m)
	for i := range p {
		p[i] = make([]int, n)
	}

	for _, e := range g {
		p[e[0]][e[1]] = 2
	}
	for _, e := range w {
		p[e[0]][e[1]] = 2
	}

	dirs := [5]int{-1, 0, 1, 0, -1}
	for _, e := range g {
		for k := range 4 {
			x, y := e[0], e[1]
			a, b := dirs[k], dirs[k+1]
			for x+a >= 0 && x+a < m && y+b >= 0 && y+b < n && p[x+a][y+b] < 2 {
				x, y = x+a, y+b
				p[x][y] = 1
			}
		}
	}

	r := 0
	for i := range p {
		for j := range p[i] {
			if p[i][j] == 0 {
				r++
			}
		}
	}
	return r
}
