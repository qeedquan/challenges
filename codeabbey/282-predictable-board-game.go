/*

Two friends invented a new board game. They used a board which was a large grid of squares. The bottom left square on the board is the origin of the grid, having coordinates (0,0). Other squares on the board can be described by the usual (x,y) coordinates. The values of x and y can be 0 or any positive integer up to a maximum of 100,000.

A disc is placed on one square of the board and the friends take it in turns to move the disc. The first player to move the disc to the origin wins the game. The friends decided to allow three different kinds of move.

A move to the left decreases the x value of the position of the disc. Any size move is allowed provided that the disc remains on the board.

A move downwards decreases the y value of the position of the disc. Any size move is allowed provided that the disc remains on the board.

A diagonal move decreases both the x and y values of the position of the disc by the same amount. Any size move is allowed provided that the disc remains on the board.

Note that it is not possible for either the x or the y value of the disc position to increase.

For example, from the square (3,4) it is possible to move directly to any of the squares (2,4), (1,4), (0,4), (3,3), (3,2), (3,1), (3,0), (2,3), (1,2) and (0,1).

To make the game fair one player would place the disc on the board and the other player would get the first move. The two friends were pleased with their invention and enjoyed playing many games until they began to suspect that the game outcome is determined by the starting position of the disc; assuming optimal play.

We can describe some squares as winning squares (W) because the player making the first move is guaranteed to win the game, no matter what sequence of moves is played by their opponent; provided that the first player plays optimally.

Similarly we can describe squares as losing squares (L) because the first player is guaranteed to lose the game, no matter what sequence of moves they play, provided that their opponent plays optimally.

When squares are close to the origin it is easy to classify them. (8,8) is clearly a winning square because we can reach the origin in a single move. (1,2) is a losing square. The only valid moves from this square go to (0,2), (1,1), (1,0) or (0,1). From any of these positions the second player can make a move to the origin and win the game.

As positions get further from the origin it becomes harder to decide whether they are winning or losing positions. That is the object of this puzzle.

Input / Output description:
The first line of the input data will contain a single integer N.
N lines will follow. On each line there will be a pair of integers (separated by a space). These are the (x,y) coordinates of the disc position. For each position answer W or L to indicate winning or losing.
Give all answers on a single line, separated by single spaces.

Example

input:
14
1 2
8 8
45 73
57 32
162 100
353 216
645 1039
1262 2043
3062 4955
4303 6961
11181 6914
12537 7748
42312 26150
90853 56153

answer:
L W L W L W W W L W W L L W

*/

package main

import (
	"math"
)

func main() {
	assert(winner(1, 2) == 'L')
	assert(winner(8, 8) == 'W')
	assert(winner(45, 73) == 'L')
	assert(winner(57, 32) == 'W')
	assert(winner(162, 100) == 'L')
	assert(winner(353, 216) == 'W')
	assert(winner(645, 1039) == 'W')
	assert(winner(1262, 2043) == 'W')
	assert(winner(3062, 4955) == 'L')
	assert(winner(4303, 6961) == 'W')
	assert(winner(11181, 6914) == 'W')
	assert(winner(12537, 7748) == 'L')
	assert(winner(42312, 26150) == 'L')
	assert(winner(90853, 56153) == 'W')
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://en.wikipedia.org/wiki/Wythoff%27s_game
func winner(x, y int) rune {
	phi := (1 + math.Sqrt(5)) / 2
	if x > y {
		x, y = y, x
	}
	y = int(float64(y-x) * phi)
	if x != y {
		return 'W'
	}
	return 'L'
}
