/*

Given a binary matrix like this:

0 1 1 1 1 0
1 0 0 1 1 1
1 0 1 1 1 1
1 1 1 1 1 1
0 1 1 1 1 0
Output the clues for a nonogram puzzle in the format of "top clues, empty line, bottom clues", with clues separated by spaces:

3
1 2
1 3
5
5
3

4
1 3
1 4
6
4
That is, count the contiguous groups of "1" bits and their sizes, first in columns, then in rows.

Thanks to nooodl for suggesting this problem at r/dailyprogrammer_ideas! If you have a problem that you think would be good for us, why not head over there and post it!

*/

package main

import "fmt"

func main() {
	nonogram([][]int{
		{0, 1, 1, 1, 1, 0},
		{1, 0, 0, 1, 1, 1},
		{1, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1},
		{0, 1, 1, 1, 1, 0},
	})
}

func nonogram(m [][]int) {
	if len(m) == 0 || len(m[0]) == 0 {
		return
	}

	for i := 0; i < len(m[0]); i++ {
		clues(m, 0, i, 1, 0)
	}
	fmt.Println()
	for j := 0; j < len(m); j++ {
		clues(m, j, 0, 0, 1)
	}
}

func clues(m [][]int, x, y, dx, dy int) {
	c := 0
	for x < len(m) && y < len(m[0]) {
		if m[x][y] == 1 {
			c += 1
		} else if c > 0 {
			fmt.Printf("%d ", c)
			c = 0
		}
		x += dx
		y += dy
	}
	if c > 0 {
		fmt.Printf("%d ", c)
	}
	fmt.Println()
}
