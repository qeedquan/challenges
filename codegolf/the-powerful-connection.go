/*

Introduction
There is a plantation defined by one big square-board like this one:

https://i.sstatic.net/UY6cv.png

The numbers inside each small square represents its area's value/cash/...

The farmer needs help to find the N squares that connected (it means all N squares should have at least one shared border) give him the greatest value.

For example:

If N=1, then the output must be 140.

If N=6, then..

https://i.sstatic.net/gR1q6.png

..the output must be 315.

Challenge
Your program/function must take the the matrix's values and the number N as input/arguments and must output the powerful connection's value.

Since this is code-golf, the shortest answer in bytes wins!

Examples
Input:

10 -7 11 7 3 31
33 31 2 5 121 15
22 -8 12 10 -19 43
12 -4 54 77 -7 -21
2 8 6 -70 109 1
140 3 -98 6 13 20
6
Output: 315

Input:

35 -7
-8 36
2
Output: 29

*/

package main

import (
	"math"
)

func main() {
	grid1 := [][]int{
		{10, -7, 11, 7, 3, 31},
		{33, 31, 2, 5, 121, 15},
		{22, -8, 12, 10, -19, 43},
		{12, -4, 54, 77, -7, -21},
		{2, 8, 6, -70, 109, 1},
		{140, 3, -98, 6, 13, 20},
	}

	grid2 := [][]int{
		{35, -7},
		{-8, 36},
	}

	assert(connection(grid1, 1) == 140)
	assert(connection(grid1, 6) == 315)
	assert(connection(grid2, 2) == 29)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func connection(grid [][]int, border int) int {
	if border < 1 {
		return 0
	}

	result := math.MinInt
	seen := make(map[[2]int]bool)
	for y := range grid {
		for x := range grid[y] {
			recurse(grid, border, 0, 0, x, y, seen, &result)
		}
	}
	return result
}

func recurse(grid [][]int, border, depth, area, x, y int, seen map[[2]int]bool, result *int) {
	directions := [][2]int{
		{-1, 0},
		{1, 0},
		{0, -1},
		{0, 1},
	}

	if depth >= border {
		*result = max(*result, area)
		return
	}

	key := [2]int{x, y}
	if y < 0 || y >= len(grid) || x < 0 || x >= len(grid[y]) || seen[key] {
		return
	}

	seen[key] = true
	area += grid[y][x]
	for _, direction := range directions {
		recurse(grid, border, depth+1, area, x+direction[0], y+direction[1], seen, result)
	}
	delete(seen, key)
}
