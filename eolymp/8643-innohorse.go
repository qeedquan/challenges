/*

In Innokingdom there are special horses for chess knights, innohorses.
Each innohorse is represented by a pair of integers (x, y), 0≤x≤y.
Innohorse moves in the following way: first it moves x cells in one of the four general directions, then turns 90 degrees to the left or to the right,
then finally moves y more cells. For instance, an ordinary chess knight is an innohorse of type (1, 2).

Alex and Jane have just seen one innohorse, it jumped from cell A to cell B.
They wonder what is the type of this innohorse. Help them answer this question.

Input
Chessboard consists of 8 rows and 8 columns.
Rows are assigned integers from 1 to 8, and columns are assigned letters from a to h.
So every cell is represented by a pair of a letter and a digit.

Two lines consist of descriptions of cells A and B respectively.

Output
Print two integers x and y (0≤x≤y), representing the type of innohorse.

Examples

Input #1
a1
b3

Answer #1
1 2

Input #2
g5
d3

Answer #2
2 3

*/

package main

import "fmt"

func main() {
	fmt.Println(solve("a1", "b3"))
	fmt.Println(solve("g5", "d3"))
}

func solve(a, b string) (int, int) {
	if len(a) != 2 || len(b) != 2 {
		return -1, -1
	}
	x := abs(int(a[0]) - int(b[0]))
	y := abs(int(a[1]) - int(b[1]))
	if x > y {
		x, y = y, x
	}
	return x, y
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
