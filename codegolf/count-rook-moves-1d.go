/*

Given a position with a row of rooks and/or empty spaces, output how many different rook moves are possible. A rook can move left or right to an empty space, but not to one that requires passing over another rook. When a rook moves, the other rooks remain in place.

For example, from this position, 6 moves are possible:

.R..RRR.
The first (leftmost) rook can move 1 space left, or 1 or 2 spaces right (3 moves)
The next rook can only move 1 or 2 spaces left (2 moves)
The third rook cannot move at all because it's squeezed between two other rooks (0 moves)
The last rook can only move 1 space right (1 move)
Note that a position might have no rooks at all, or no empty spaces at all.

Input: A non-empty list (string, array, etc..) of rooks and empty spaces. You can represent them as True/False, 1/0, 'R'/'.', or any two consistent distinct single-byte characters or one-digit numbers of your choice. It's up to you which one means rook and which means empty space.

Output: A non-negative integer. Whole-number floats are also fine.

Test cases

The output is the number on the left.

6 .R..RRR.
0 .
0 R
4 R..RR
3 ...R
8 ..R..R..
0 ......
For more test cases, here are all inputs up to length 5.

0 .
0 R
0 ..
1 .R
1 R.
0 RR
0 ...
2 ..R
2 .R.
1 .RR
2 R..
2 R.R
1 RR.
0 RRR
0 ....
3 ...R
3 ..R.
2 ..RR
3 .R..
3 .R.R
2 .RR.
1 .RRR
3 R...
4 R..R
3 R.R.
2 R.RR
2 RR..
2 RR.R
1 RRR.
0 RRRR
0 .....
4 ....R
4 ...R.
3 ...RR
4 ..R..
4 ..R.R
3 ..RR.
2 ..RRR
4 .R...
5 .R..R
4 .R.R.
3 .R.RR
3 .RR..
3 .RR.R
2 .RRR.
1 .RRRR
4 R....
6 R...R
5 R..R.
4 R..RR
4 R.R..
4 R.R.R
3 R.RR.
2 R.RRR
3 RR...
4 RR..R
3 RR.R.
2 RR.RR
2 RRR..
2 RRR.R
1 RRRR.
0 RRRRR

*/

package main

import (
	"strings"
)

func main() {
	assert(count(".R..RRR.") == 6)
	assert(count(".") == 0)
	assert(count("R") == 0)
	assert(count("R..RR") == 4)
	assert(count("...R") == 3)
	assert(count("..R..R..") == 8)
	assert(count("......") == 0)
	assert(count(".") == 0)
	assert(count("R") == 0)
	assert(count("..") == 0)
	assert(count(".R") == 1)
	assert(count("R.") == 1)
	assert(count("RR") == 0)
	assert(count("...") == 0)
	assert(count("..R") == 2)
	assert(count(".R.") == 2)
	assert(count(".RR") == 1)
	assert(count("R..") == 2)
	assert(count("R.R") == 2)
	assert(count("RR.") == 1)
	assert(count("RRR") == 0)
	assert(count("....") == 0)
	assert(count("...R") == 3)
	assert(count("..R.") == 3)
	assert(count("..RR") == 2)
	assert(count(".R..") == 3)
	assert(count(".R.R") == 3)
	assert(count(".RR.") == 2)
	assert(count(".RRR") == 1)
	assert(count("R...") == 3)
	assert(count("R..R") == 4)
	assert(count("R.R.") == 3)
	assert(count("R.RR") == 2)
	assert(count("RR..") == 2)
	assert(count("RR.R") == 2)
	assert(count("RRR.") == 1)
	assert(count("RRRR") == 0)
	assert(count(".....") == 0)
	assert(count("....R") == 4)
	assert(count("...R.") == 4)
	assert(count("...RR") == 3)
	assert(count("..R..") == 4)
	assert(count("..R.R") == 4)
	assert(count("..RR.") == 3)
	assert(count("..RRR") == 2)
	assert(count(".R...") == 4)
	assert(count(".R..R") == 5)
	assert(count(".R.R.") == 4)
	assert(count(".R.RR") == 3)
	assert(count(".RR..") == 3)
	assert(count(".RR.R") == 3)
	assert(count(".RRR.") == 2)
	assert(count(".RRRR") == 1)
	assert(count("R....") == 4)
	assert(count("R...R") == 6)
	assert(count("R..R.") == 5)
	assert(count("R..RR") == 4)
	assert(count("R.R..") == 4)
	assert(count("R.R.R") == 4)
	assert(count("R.RR.") == 3)
	assert(count("R.RRR") == 2)
	assert(count("RR...") == 3)
	assert(count("RR..R") == 4)
	assert(count("RR.R.") == 3)
	assert(count("RR.RR") == 2)
	assert(count("RRR..") == 2)
	assert(count("RRR.R") == 2)
	assert(count("RRRR.") == 1)
	assert(count("RRRRR") == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func count(s string) int {
	s = strings.Replace(s, ".", " ", -1)
	s = strings.TrimSpace(s + s)
	t := strings.Split(s, " ")
	return len(t) - 1
}
