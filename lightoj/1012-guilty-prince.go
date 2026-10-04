/*

Once there was an Emperor named Akbar. He had a son named Jahangir. For an unforgivable reason, the king wanted him to leave the kingdom. Since he loved his son, he decided his son would be banished to a new place. The prince became sad, but he followed his father's will. On the way, he found that the place was a combination of land and water. Since he didn't know how to swim, he was only able to move on the land. He didn't know how many places might be his destination. So, he asked for your help.

For simplicity, you can consider the place as a rectangular grid consisting of some cells. A cell can be a land or can contain water. Each time the prince can move to a new cell from his current position if they share a side.

Now write a program to find the number of cells (unit land) he could reach including the cell he was initially in.

Input
Input starts with an integer T (≤ 500), denoting the number of test cases.

Each case starts with a line containing two positive integers W and H; W and H are the numbers of cells in the x and y directions, respectively. W and H will not be more than 20.

There will be H more lines in the data set, each of which includes W characters. Each character represents the status of a cell as follows.

. - land.
# - water.
@ - initial position of the prince (appears exactly once in a dataset).
Output
For each case, print the case number and the number of cells he can reach from the initial position (including self).

Sample
Input	Output
4
6 9
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........
11 6
..#..#..#..
..#..#..#..
..#..#..###
..#..#..#@.
..#..#..#..
..#..#..#..
7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..

Case 1: 45
Case 2: 59
Case 3: 6
Case 4: 13

*/

package main

func main() {
	assert(solve([][]byte{
		[]byte("....#."),
		[]byte(".....#"),
		[]byte("......"),
		[]byte("......"),
		[]byte("......"),
		[]byte("......"),
		[]byte("......"),
		[]byte("#@...#"),
		[]byte(".#..#."),
	}) == 45)

	assert(solve([][]byte{
		[]byte(".#........."),
		[]byte(".#.#######."),
		[]byte(".#.#.....#."),
		[]byte(".#.#.###.#."),
		[]byte(".#.#..@#.#."),
		[]byte(".#.#####.#."),
		[]byte(".#.......#."),
		[]byte(".#########."),
		[]byte("..........."),
	}) == 59)

	assert(solve([][]byte{
		[]byte("..#..#..#.."),
		[]byte("..#..#..#.."),
		[]byte("..#..#..###"),
		[]byte("..#..#..#@."),
		[]byte("..#..#..#.."),
		[]byte("..#..#..#.."),
	}) == 6)

	assert(solve([][]byte{
		[]byte("..#.#.."),
		[]byte("..#.#.."),
		[]byte("###.###"),
		[]byte("...@..."),
		[]byte("###.###"),
		[]byte("..#.#.."),
		[]byte("..#.#.."),
	}) == 13)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(m [][]byte) int {
	v := make(map[[2]int]bool)
	r := 0
	for y := range m {
		for x := range m[y] {
			if m[y][x] == '@' {
				dfs(m, x, y, v, &r)
			}
		}
	}
	return r
}

func dfs(m [][]byte, x, y int, v map[[2]int]bool, r *int) {
	dx := []int{1, -1, 0, 0}
	dy := []int{0, 0, 1, -1}

	k := [2]int{x, y}
	v[k], *r = true, *r+1
	for i := range 4 {
		nx := x + dx[i]
		ny := y + dy[i]
		if valid(m, nx, ny, v) {
			dfs(m, nx, ny, v, r)
		}
	}
}

func valid(m [][]byte, x, y int, v map[[2]int]bool) bool {
	k := [2]int{x, y}
	return 0 <= y && y < len(m) &&
		0 <= x && x < len(m[y]) &&
		m[y][x] != '#' && !v[k]
}
