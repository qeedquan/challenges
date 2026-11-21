/*

Connect Four is a game where two players take turns to drop disks into columns of a vertically mounted grid, and attempt to connect four disks orthogonally or diagonally. When a column is chosen, the disk falls to the lowest empty position in that column, so any game may be completely specified by the size of the grid and the sequence of columns chosen. The task is to generate the configuration of the grid given this information.

Input

Width w and Height h of the grid, both positive integers.
Sequence of columns c1, c2, ..., cn chosen by the players, in any reasonable format (list, array etc.); either 0-based (0 to w-1) or 1-based (1 to w) indexing can be used.
It may be assumed that all of the column numbers lie within the grid (so the sequence won't contain -3 or w+50) and that any column number appears at most h times in the sequence (so a column can't be chosen once it is full).

Note that the sequence of columns may not constitute a complete game, nor a legal game. For instance, the players could opt to continue playing even after a player has connected four disks.

Output

Any reasonable representation of the resulting state of each position in the grid, either "occupied by Player 1", "occupied by Player 2", or "empty". Player 1 always moves first.
For example, a string, array, tuple etc. with each position containing one of three symbols (ASCII character, number etc.) representing the state of that position in the grid. The grid may be transposed.

For list/tuple/array outputs, the separator cannot be one of the three representative symbols. For string outputs, trailing spaces at the end of each line are permitted, provided a space is not one of the three representative symbols. Trailing newlines at the very end are permitted.

Test cases

Here, string output is used, with X, O, . denoting "occupied by Player 1", "occupied by Player 2", "empty".

IN: Width 1 Height 1 Sequence (empty sequence)
OUT:
.

IN: Width 7 Height 6 Sequence 4 4 5 5 6 7 3 [1-based]
                              3 3 4 4 5 6 2 [0-based]
OUT:
.......
.......
.......
.......
...OO..
..XXXXO

IN: Width 5 Height 5 Sequence 1 1 1 1 1 2 2 2 2 2 3 3 3 3 3 4 4 4 4 4 5 5 5 5 5 [1-based]
                              0 0 0 0 0 1 1 1 1 1 2 2 2 2 2 3 3 3 3 3 4 4 4 4 4 [0-based]
OUT:
XOXOX
OXOXO
XOXOX
OXOXO
xOXOX

IN: Width 4 Height 4 Sequence 3 3 2 4 3 2 4 2 2 3 4 4 1 1 1 1 [1-based]
                              2 2 1 3 2 1 3 1 1 2 3 3 0 0 0 0 [0-based]
OUT:
OXOO
XOXX
OOOX
XXXO

IN: Width 10 Height 10 Sequence 1 2 1 3 1 4 1 5 1 6 1 7 1 8 1 9 1 10 1 10  [1-based]
                                0 1 0 2 0 3 0 4 0 5 0 6 0 7 0 8 0  9 0  9  [0-based]
OUT:
X.........
X.........
X.........
X.........
X.........
X.........
X.........
X.........
X........O
XOOOOOOOOO

Shortest code in bytes wins.

*/

package main

import "fmt"

func main() {
	draw(gen(7, 6, []int{3, 3, 4, 4, 5, 6, 2}))
	draw(gen(5, 5, []int{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4}))
	draw(gen(4, 4, []int{2, 2, 1, 3, 2, 1, 3, 1, 1, 2, 3, 3, 0, 0, 0, 0}))
	draw(gen(10, 10, []int{0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 7, 0, 8, 0, 9, 0, 9}))
}

func gen(w, h int, m []int) [][]byte {
	p := alloc(w, h)
	y := make([]int, w)
	ch := []byte{'X', 'O'}
	for i, x := range m {
		p[h-y[x]-1][x] = ch[i&1]
		y[x] += 1
	}
	return p
}

func alloc(w, h int) [][]byte {
	p := make([][]byte, h)
	t := make([]byte, w*h)
	for i := range p {
		p[i] = t[i*w : (i+1)*w]
		for j := range p[i] {
			p[i][j] = '.'
		}
	}
	return p
}

func draw(p [][]byte) {
	for y := range p {
		for x := range p[y] {
			fmt.Printf("%c", p[y][x])
		}
		fmt.Println()
	}
	fmt.Println()
}
