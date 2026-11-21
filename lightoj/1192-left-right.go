/*

Two players, Alice and Bob are playing a strange game in a 1 x n board. The cells are numbered from 0 to n-1, where the left most cell is marked as cell 0. Each cell can contain at most one piece.

There are two kinds of pieces, gray and white. Alice moves all the gray pieces, and bob moves all the white ones. The pieces alternate, that is, leftmost piece is gray, next is white, next to that is gray, then it's white again, and so on. There will always be equal number of black and gray pieces. Alice can only move pieces to the right. Bob can only move pieces to the left.

In each move, a player selects one piece and moves that piece, either to its left (Bob) or to its right (Alice), any number of cells (at least 1) but, it can neither jump over other pieces, nor it can move outside of the board. The players alternate their turns.

For example, if Alice decides to move the left most gray piece, these two moves are available to her.

Illustration
Fig 1: Initial Position
https://static.lightoj.com/images/problem-1192/left_right_1-1605694893056.png

Fig 2: Alice moving the gray piece one cell to the right
https://static.lightoj.com/images/problem-1192/left_right_2-1605694906003.png

Fig 3: Alice moving the gray piece two cells to the right
https://static.lightoj.com/images/problem-1192/left_right_3-1605694920245.png

Alice moves first. The game ends, when someone is unable to make any move, and loses the game. You can assume that, both of them play optimally (that is, if it is possible to apply a strategy that will ensure someone's win, he/she will always use that strategy).

Now you are given a configuration of a board, you have to find the winner.

Input
Input starts with an integer T (≤ 200), denoting the number of test cases.

Each case starts with a line containing an integer k (1 ≤ k ≤ 100) denoting the number of gray pieces in the board. The next line contains 2k distinct integers (in ascending order) denoting the position of the pieces. The first integer denotes a gray piece, the second integer denotes a white piece, the next integer denotes a gray piece and so on. All the integers will lie in the range [0, 109].

Assume that n is sufficiently large to contain all the pieces. And at least one move is remaining.

Output
For each case, print the case number and Alice or Bob depending on the winner of the game.

Sample
Input	Output
2
2
0 3 7 9
2
1 3 7 9

Case 1: Alice
Case 2: Bob

*/

package main

func main() {
	assert(solve([]int{0, 3, 7, 9}) == "Alice")
	assert(solve([]int{1, 3, 7, 9}) == "Bob")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(x []int) string {
	n := len(x) / 2
	a := make([]int, n+2)
	b := make([]int, n+3)
	r := 0
	for i, j := 0, 0; i < 2*n; i++ {
		if i%2 == 0 {
			a[i/2], j = x[j], j+1
		} else {
			b[i/2], j = x[j], j+1
		}
	}
	for i := range n {
		r ^= (b[i] - a[i] - 1)
	}

	if r != 0 {
		return "Alice"
	}
	return "Bob"
}
