/*

Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.

Battleships can only be placed horizontally or vertically on board.
In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size.
At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).

Example 1:
https://assets.leetcode.com/uploads/2024/06/21/image.png
Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
Output: 2

Example 2:
Input: board = [["."]]
Output: 0

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is either '.' or 'X'.

Follow up: Could you do it in one-pass, using only O(1) extra memory and without modifying the values board?

*/

package main

func main() {
	assert(battleships([][]byte{
		[]byte("X..X"),
		[]byte("...X"),
		[]byte("...X"),
	}) == 2)

	assert(battleships([][]byte{
		[]byte("."),
	}) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func battleships(b [][]byte) int {
	c := 0
	for i := range b {
		for j := range b[i] {
			if b[i][j] == 'X' && (i == 0 || b[i-1][j] != 'X') && (j == 0 || b[i][j-1] != 'X') {
				c += 1
			}
		}
	}
	return c
}
