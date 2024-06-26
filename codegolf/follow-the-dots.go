/*

The Challenge
Given a rectangular grid of characters

A B C D E
F G H I J
K L M N O
P Q R S T
and a grid with the same dimensions of dots and spaces

. .     .
  .   . .
  .   .
  . . .
Output the string which is generated by following the dots through the grid starting in the upper left corner. This example would yield ABGLQRSNIJE

Notes
You may take the input grids as 2D-arrays or the closest alternative in your language instead of a multiline string.
You may use the NULL value of your language instead of spaces. But you have to use dots to mark the path.
You don't need to separate dots on the same line with spaces. I just added them for readability.
The smallest possible grid has the size 1x1.
The start and end dot will have only one neighbour. The dots between them will always have exact two vertical or horizontal neighbours. This guarantees that the path is unambiguously.
The path will not go diagonal.
The characters in the grid will be either all upper- or lowercase characters in the range [a-z] whatever is most convenient for you.
The path will always start in the upper left corner.
Rules
Function or full program allowed.
Default rules for input/output.
Standard loopholes apply.
This is code-golf, so lowest byte-count wins. Tiebreaker is earlier submission.
Test cases
Grid #1
A B C A B C W
D E F G H U Q
X L U S D Q Z
A S U K W X I
W U K O A I M
A I A I O U P
. .
  . . .
      .
. . . .
.
.
=> ABEFGSKUSAWA
. . . . . . .
            .
. . .       .
.   . .     .
.           .
. . . . . . .
=> ABCABCWQZIMPUOIAIAWAXLUUK
Grid #2
Note the triple spaces in the second lines of the first and second examples.

A B
C D
.

=> A
. .

=> AB
.
. .
=> ACD
Grid #3
A
.
=> A
Happy Coding!

*/

package main

import (
	"bytes"
)

func main() {
	assert(follow([][]byte{
		{'A', 'B', 'C', 'A', 'B', 'C', 'W'},
		{'D', 'E', 'F', 'G', 'H', 'U', 'Q'},
		{'X', 'L', 'U', 'S', 'D', 'Q', 'Z'},
		{'A', 'S', 'U', 'K', 'W', 'X', 'I'},
		{'W', 'U', 'K', 'O', 'A', 'I', 'M'},
		{'A', 'I', 'A', 'I', 'O', 'U', 'P'},
	}, [][]byte{
		{'.', '.', '0', '0', '0', '0', '0'},
		{'0', '.', '.', '.', '0', '0', '0'},
		{'0', '0', '0', '.', '0', '0', '0'},
		{'.', '.', '.', '.', '0', '0', '0'},
		{'.', '0', '0', '0', '0', '0', '0'},
		{'.', '0', '0', '0', '0', '0', '0'},
	}) == "ABEFGSKUSAWA")

	assert(follow([][]byte{
		{'A', 'B', 'C', 'A', 'B', 'C', 'W'},
		{'D', 'E', 'F', 'G', 'H', 'U', 'Q'},
		{'X', 'L', 'U', 'S', 'D', 'Q', 'Z'},
		{'A', 'S', 'U', 'K', 'W', 'X', 'I'},
		{'W', 'U', 'K', 'O', 'A', 'I', 'M'},
		{'A', 'I', 'A', 'I', 'O', 'U', 'P'},
	}, [][]byte{
		{'.', '.', '.', '.', '.', '.', '.'},
		{'0', '0', '0', '0', '0', '0', '.'},
		{'.', '.', '.', '0', '0', '0', '.'},
		{'.', '0', '.', '.', '0', '0', '.'},
		{'.', '0', '0', '0', '0', '0', '.'},
		{'.', '.', '.', '.', '.', '.', '.'},
	}) == "ABCABCWQZIMPUOIAIAWAXLUUK")

	assert(follow([][]byte{
		{'A', 'B'},
		{'C', 'D'},
	}, [][]byte{
		{'.', '.'},
		{'0', '0'},
	}) == "AB")

	assert(follow([][]byte{
		{'A', 'B'},
		{'C', 'D'},
	}, [][]byte{
		{'.', '0'},
		{'.', '.'},
	}) == "ACD")

	assert(follow([][]byte{
		{'A'},
	}, [][]byte{
		{'.'},
	}) == "A")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func follow(a, b [][]byte) string {
	dirs := [][2]int{
		{-1, +0},
		{+1, +0},
		{+0, -1},
		{+0, +1},
	}

	if len(a) == 0 || len(a[0]) == 0 {
		return ""
	}

	x := 0
	y := 0
	w := len(a[0])
	h := len(a)
	p := new(bytes.Buffer)
	s := make(map[[2]int]bool)
	for {
		if !isdot(b, s, x, y, w, h) {
			break
		}

		i := [2]int{x, y}
		s[i] = true
		p.WriteByte(a[y][x])

		for _, v := range dirs {
			nx, ny := x+v[0], y+v[1]
			if isdot(b, s, nx, ny, w, h) {
				x, y = nx, ny
				break
			}
		}
	}

	return p.String()
}

func isdot(b [][]byte, s map[[2]int]bool, x, y, w, h int) bool {
	if x < 0 || y < 0 || x >= w || y >= h {
		return false
	}
	if i := [2]int{x, y}; s[i] {
		return false
	}
	return b[y][x] == '.'
}
