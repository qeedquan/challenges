/*

Given an input of four integers x1, y1, x2, and y2, output whether a white king in chess (with coordinates (x1, y1)) could catch a black pawn (with coordinates (x2, y2)) and capture it if the pawn is moving to promote to a queen as fast as possible.

The coordinates of the board are as follows:

       first coordinate (x)
             12345678

           1 .#.#.#.#
           2 #.#.#.#.
           3 .#.#.#.#
  second   4 #.#.#.#.
coordinate 5 .#.#.#.#
    (y)    6 #.#.#.#.
           7 .#.#.#.#
           8 #.#.#.#.
Assume it is white to move (the king's turn) and that both players play optimally (the king will move as fast as possible to catch the pawn, and the pawn will move as fast as possible to promote).
The input coordinates will always be distinct, and the pawn will never start with a y-coordinate of 8.

The king moves one square in any direction every turn (it can move diagonally), and the pawn can only move one space forwards (decrease its y-coordinate),
unless it's at its initial position (with our coordinate system, y-coordinate of 7), in which case it can move two spaces forwards.

The input can be given as a whitespace-/comma-separated string, an array of strings/integers, or four function/command line/etc arguments.
The coordinates can be given in whichever order is most convenient/golfy (so, accepting input as [y2, y1, x1, y2] is okay as long as it's consistent). The output must be a truthy or falsy value.

Since this is code-golf, the shortest code in bytes wins.

Truthy test cases:
5 3 3 2
6 1 1 7
3 3 3 2
4 1 4 7
7 7 1 7
1 8 1 7

Falsy test cases:
6 4 3 2
8 8 1 7
3 4 3 2

*/

package main

func main() {
	assert(catch(5, 3, 3, 2) == true)
	assert(catch(6, 1, 1, 7) == true)
	assert(catch(3, 3, 3, 2) == true)
	assert(catch(4, 1, 4, 7) == true)
	assert(catch(7, 7, 1, 7) == true)
	assert(catch(1, 8, 1, 7) == true)

	assert(catch(6, 4, 3, 2) == false)
	assert(catch(8, 8, 1, 7) == false)
	assert(catch(3, 4, 3, 2) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@grc

The king has coordinates (x, y) and the pawn (p, q).

There are three significant cases:

The pawn is on rank 7 and the king on rank 8. To capture the pawn, the king must be on the same file or an adjacent one.

Result: q = 7  ⋀  y = 8  →  |x - p| ≤ 1

The pawn is on rank 7. To capture the pawn, the king must be within six files.

Result: q = 7  →  |x - p| ≤ 6

The pawn is on a lower rank. To capture the pawn, the king must be able to reach the promotion square at most one move after the pawn.

Result: q < 7  →  |x - p| ≤ q  ⋀  y - 1 ≤ q

*/

func catch(x, y, p, q int) bool {
	return y-2 < q && q >= abs(x-p)+q/7+y/8*5
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
