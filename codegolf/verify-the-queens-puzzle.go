/*

If you don't know what a queen is in chess, it doesn't matter much; it's just a name :)

Your input will be a square of arbitrary width and height containing some amount of queens. The input board will look like this (this board has a width and height of 8):

...Q....
......Q.
..Q.....
.......Q
.Q......
....Q...
Q.......
.....Q..
There are 8 queens on this board. If there were, say, 7, or 1, or 10 on here, the board wouldn't be valid.

Here we use a . for an empty space, and a Q for a queen. You may, alternatively, use any non-whitespace character you wish instead.

This input can be verified as valid, and you should print (or return) a truthy value (if it is was not valid, you should print (or return) a falsy value). It is valid because no queen is in the same row, column, diagonal or anti-diagonal as another.

Examples (don't output things in brackets):
...Q....
......Q.
..Q.....
.......Q
.Q......
....Q...
Q.......
.....Q..

1

...Q.
Q....
.Q...
....Q
..Q..

0

Q.
Q.

0

..Q
...
.Q.

0 (this is 0 because there are only 2 queens on a 3x3 board)


..Q.
Q...
...Q
.Q..

1

Q

1 (this is valid, because the board is only 1x1, so there's no queen that can take another)
Let me stress that an input is only valid, if no queen is in the same row, column, diagonal or anti-diagonal as another.

Rules
You will never receive an empty input
If the input contains fewer queens than the sqaure root of the area of the board, it is not valid.
Note there are no valid solutions for a 2x2 or 3x3 board, but there is a solution for every other size square board, where the width and height is a natural number.
The input may be in any reasonable format, as per PPCG rules
The input will always be a sqaure
I used 1 and 0 in the examples, but you may use any truthy or falsy values (such as Why yes, sir, that is indeed the case and Why no, sir, that is not the case)
As this is code-golf, the shortest code wins!

*/

package main

func main() {
	assert(satisfy([]string{
		"...Q....",
		"......Q.",
		"..Q.....",
		".......Q",
		".Q......",
		"....Q...",
		"Q.......",
		".....Q..",
	}) == true)

	assert(satisfy([]string{
		"...Q.",
		"Q....",
		".Q...",
		"....Q",
		"..Q..",
	}) == false)

	assert(satisfy([]string{
		"Q.",
		"Q.",
	}) == false)

	assert(satisfy([]string{
		"..Q",
		"...",
		".Q.",
	}) == false)

	assert(satisfy([]string{
		"..Q.",
		"Q...",
		"...Q",
		".Q..",
	}) == true)

	assert(satisfy([]string{
		"Q",
	}) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func satisfy(s []string) bool {
	dirs := [][2]int{
		{-1, 0},
		{1, 0},
		{0, -1},
		{0, 1},
		{-1, -1},
		{1, 1},
		{-1, 1},
		{1, -1},
	}

	i, n := 0, len(s)
	for y := 0; y < n; y++ {
		for x := 0; x < n; x++ {
			if s[y][x] != 'Q' {
				continue
			}

			for _, d := range dirs {
				if !check(s, x, y, n, n, d[0], d[1]) {
					return false
				}
			}
			i += 1
		}
	}
	return i == n
}

func check(s []string, x, y, w, h, dx, dy int) bool {
	x, y = x+dx, y+dy
	for {
		if x < 0 || y < 0 || x >= w || y >= h {
			break
		}
		if s[y][x] == 'Q' {
			return false
		}
		x, y = x+dx, y+dy
	}

	return true
}
