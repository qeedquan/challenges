/*

Write a program to solve 9x9 Sudoku puzzles.

Thanks to EvanHahn for the challenge at r/dailyprogrammer_ideas .. If you have a challenge in your mind, head over there and post it!

*/

package main

import "fmt"

func main() {
	m1 := [][]int{
		{1, 0, 0, 0, 0, 7, 0, 9, 0},
		{0, 3, 0, 0, 2, 0, 0, 0, 8},
		{0, 0, 9, 6, 0, 0, 5, 0, 0},

		{0, 0, 5, 3, 0, 0, 9, 0, 0},
		{0, 1, 0, 0, 8, 0, 0, 0, 2},
		{6, 0, 0, 0, 0, 4, 0, 0, 0},

		{3, 0, 0, 0, 0, 0, 0, 1, 0},
		{0, 4, 0, 0, 0, 0, 0, 0, 7},
		{0, 0, 7, 0, 0, 0, 3, 0, 0},
	}

	m2 := [][]int{
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 3, 0, 8, 5},
		{0, 0, 1, 0, 2, 0, 0, 0, 0},

		{0, 0, 0, 5, 0, 7, 0, 0, 0},
		{0, 0, 4, 0, 0, 0, 1, 0, 0},
		{0, 9, 0, 0, 0, 0, 0, 0, 0},

		{5, 0, 0, 0, 0, 0, 0, 7, 3},
		{0, 0, 2, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 4, 0, 0, 0, 9},
	}

	solve(m1)
	solve(m2)

	show(m1)
	show(m2)
}

func show(m [][]int) {
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			fmt.Printf("%d ", m[i][j])
			if j > 0 && j < 8 && j%3 == 2 {
				fmt.Printf("| ")
			}
		}

		if i > 0 && i < 8 && i%3 == 2 {
			fmt.Println()
			for range 3 {
				fmt.Printf("-----   ")
			}
		}
		fmt.Println()
	}
	fmt.Println()
}

// ported from @skeeto solution
func solve(m [][]int) bool {
	var x, y, s int
	for i := 0; i < 9 && s == 0; i++ {
		for j := 0; j < 9 && s == 0; j++ {
			if m[i][j] == 0 {
				x = i
				y = j
				s = 1
			}
		}
	}

	if s == 0 {
		return true
	}

	d := [10]int{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	for i, j := 0, y; i < 9; i++ {
		d[m[i][j]] = 0
	}
	for i, j := x, 0; j < 9; j++ {
		d[m[i][j]] = 0
	}

	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			d[m[i+(x/3)*3][j+(y/3)*3]] = 0
		}
	}

	for i := 1; i < 10; i++ {
		if d[i] > 0 {
			m[x][y] = i
			if solve(m) {
				return true
			}
		}
	}

	m[x][y] = 0
	return false
}
