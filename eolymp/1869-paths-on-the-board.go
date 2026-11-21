/*

Consider an infinite checkered board.

We call a sequence of cells a path if every two consecutive cells in the sequence are adjacent by a side. The length of a path is the number of cells in it, not counting the starting cell.

A path is called simple if it does not contain the same cell more than once.

Fix some cell on the board. How many simple paths of a given length begin at this cell?

Input
The first line contains an integer n (0≤n≤22).

Output
Print the number of simple paths of length n starting from this cell.

Examples

Input #1
0

Answer #1
1

*/

package main

func main() {
	assert(solve(0) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A001411
func solve(n int) int64 {
	tab := []int64{
		1, 4, 12, 36, 100, 284, 780, 2172, 5916, 16268, 44100, 120292, 324932,
		881500, 2374444, 6416596, 17245332, 46466676, 124658732, 335116620,
		897697164, 2408806028, 6444560484, 17266613812, 46146397316, 123481354908,
		329712786220, 881317491628,
	}

	if n < 0 || n >= len(tab) {
		return -1
	}
	return tab[n]
}
