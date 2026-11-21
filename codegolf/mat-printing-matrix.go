/*

A manufacturing company wants to print a design on mats of varying dimensions, and they hired you to program a robot to make these mats. The design consists of alternating rings of any 2 symbols on a mat. Below are some sample looks:

Column 9 by Row 7

Symbol 1: @

Symbol 2: -

Input: 9 7 @ -

@@@@@@@@@
@-------@
@-@@@@@-@
@-@---@-@
@-@@@@@-@
@-------@
@@@@@@@@@
Column 13 by Row 5

Symbol 1: @

Symbol 2: -

Input: 13 5 @ -

@@@@@@@@@@@@@
@-----------@
@-@@@@@@@@@-@
@-----------@
@@@@@@@@@@@@@
Column 3 by Row 5

Symbol 1: $

Symbol 2: +

Input: 3 5 $ +

$$$
$+$
$+$
$+$
$$$
Column 1 by Row 1

Symbol 1: #

Symbol 2: )

#
Write a program that takes in the length, breadth, symbol 1 and symbol 2 and prints out the mat design on the screen.

*The row and column number is always odd

Shortest code wins!

*/

package main

import "fmt"

func main() {
	mat(9, 7, '@', '-')
	mat(13, 5, '@', '-')
	mat(3, 5, '$', '+')
	mat(1, 1, '#', ')')
}

func mat(cols, rows int, char0, char1 rune) {
	grid := make([][]rune, rows)
	for row := range grid {
		grid[row] = make([]rune, cols)
		for col := range grid[row] {
			grid[row][col] = char1
		}
	}

	top := 0
	left := 0
	for {
		for row := top; row < rows-top; row++ {
			grid[row][left] = char0
			grid[row][cols-left-1] = char0
		}
		for col := left; col < cols-left; col++ {
			grid[top][col] = char0
			grid[rows-top-1][col] = char0
		}
		top += 2
		left += 2
		if top >= (rows/2)+(rows&1) || left >= (cols/2)+(cols&1) {
			break
		}
	}

	fmt.Printf("%d %d %c %c\n", rows, cols, char0, char1)
	for i := range grid {
		fmt.Printf("%s\n", string(grid[i]))
	}
	fmt.Println()
}
