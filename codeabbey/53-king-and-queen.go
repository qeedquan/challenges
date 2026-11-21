/*

Programming of game playing algorithms, like Chess, have two principal tasks:

assessing position, at least by checking which pieces could be taken;
constructing a kind of minimax algorithm to select a move leading to position with best value.
Let us start by solving a simple problem:

There is a chessboard with 8 x 8 squares. There are the White King and Black Queen on it. Check whether the Queen could take the King.

Remember - Queen could move to any distance vertically, horizontally or along any of two diagonals.

8  - Q - - - - - -     - - - - - - - -
7  - - - - Q - - -     - - - - - - Q -
6  - - - - - - - -     - - - - - - - -
5  - - - - - - - -     - - - Q - - - -
4  - K - - - - Q -     - - Q - - - - -
3  - - - - - - - -     - - - - - - - -
2  - - - Q - - - -     - - - - - K - -
1  - - - - - - - -     - Q - - - - - -
   a b c d e f g h     a b c d e f g h
See these two examples, with schematically drawn boards. On both the King is shown with letter K while marks Q shows variants of placing the Queen.

on the left scheme the King could be "eaten" by any of the four Queens;
on the right scheme the King is in safe position - none of the four Queens can move to take him.
Notice how the squares of the board are addressed. Columns (called files) are marked with latin letters from a to h, while rows (called ranks) are marked with digits from 1 to 8. So the King on the left diagram sits on the b4 square - and on the right diagram on the f2. We shall use this notation.

Input data contain the number of test-cases in the first line.
Next lines describe placement of the King and Queen for each testcase, by specifying their squares (King's first).
Answer should give only letter Y or N for each of test-cases, meaning that King could be taken or not respectively. Separate letters with spaces.

Example:

input data:
8
b4 b8
b4 e7
b4 d2
b4 g4
f2 b1
f2 c4
f2 d5
f2 g7

answer:
Y Y Y Y N N N N
In this example the positions are taken from both of diagrams above - cases 1..4 from the left diagram and others from the right.

*/

package main

const (
	AFILE = 0x0101010101010101
	HFILE = 0x8080808080808080
)

func main() {
	assert(capture("b4", "b8") == 'Y')
	assert(capture("b4", "e7") == 'Y')
	assert(capture("b4", "d2") == 'Y')
	assert(capture("b4", "g4") == 'Y')
	assert(capture("f2", "b1") == 'N')
	assert(capture("f2", "c4") == 'N')
	assert(capture("f2", "d5") == 'N')
	assert(capture("f2", "g7") == 'N')
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func capture(k, q string) rune {
	if gen(sq(q))&(1<<sq(k)) != 0 {
		return 'Y'
	}
	return 'N'
}

func gen(sq int) uint64 {
	p := uint64(1) << sq
	return north(p) | south(p) | east(p) | west(p) | northeast(p) | northwest(p) | southeast(p) | southwest(p)
}

func sq(s string) int {
	if len(s) < 2 {
		return 0
	}
	return 8*int(s[1]-'1') + int(s[0]-'a')
}

func south(gen uint64) uint64 {
	gen |= (gen >> 8)
	gen |= (gen >> 16)
	gen |= (gen >> 32)
	return gen
}

func north(gen uint64) uint64 {
	gen |= (gen << 8)
	gen |= (gen << 16)
	gen |= (gen << 32)
	return gen
}

func east(gen uint64) uint64 {
	pr0 := ^uint64(AFILE)
	pr1 := pr0 & (pr0 << 1)
	pr2 := pr1 & (pr1 << 2)
	gen |= pr0 & (gen << 1)
	gen |= pr1 & (gen << 2)
	gen |= pr2 & (gen << 4)
	return gen
}

func northeast(gen uint64) uint64 {
	pr0 := ^uint64(AFILE)
	pr1 := pr0 & (pr0 << 9)
	pr2 := pr1 & (pr1 << 18)
	gen |= pr0 & (gen << 9)
	gen |= pr1 & (gen << 18)
	gen |= pr2 & (gen << 36)
	return gen
}

func southeast(gen uint64) uint64 {
	pr0 := ^uint64(AFILE)
	pr1 := pr0 & (pr0 >> 7)
	pr2 := pr1 & (pr1 >> 14)
	gen |= pr0 & (gen >> 7)
	gen |= pr1 & (gen >> 14)
	gen |= pr2 & (gen >> 28)
	return gen
}

func west(gen uint64) uint64 {
	pr0 := ^uint64(HFILE)
	pr1 := pr0 & (pr0 >> 1)
	pr2 := pr1 & (pr1 >> 2)
	gen |= pr0 & (gen >> 1)
	gen |= pr1 & (gen >> 2)
	gen |= pr2 & (gen >> 4)
	return gen
}

func southwest(gen uint64) uint64 {
	pr0 := ^uint64(HFILE)
	pr1 := pr0 & (pr0 >> 9)
	pr2 := pr1 & (pr1 >> 18)
	gen |= pr0 & (gen >> 9)
	gen |= pr1 & (gen >> 18)
	gen |= pr2 & (gen >> 36)
	return gen
}

func northwest(gen uint64) uint64 {
	pr0 := ^uint64(HFILE)
	pr1 := pr0 & (pr0 << 7)
	pr2 := pr1 & (pr1 << 14)
	gen |= pr0 & (gen << 7)
	gen |= pr1 & (gen << 14)
	gen |= pr2 & (gen << 28)
	return gen
}
