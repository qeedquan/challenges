/*

Write a program or function that takes in a positive integer and prints or returns an ASCII art depiction of an archery arrow, scaled according to the input.

If the input is 1 the output is

  /\
 /  \
 \__/
  ||
  ||
  ||
  ||
  ||
  ||
  ||
  ||
 /||\
/ || \
/ || \
//  \\
/    \
If the input is 2 the output is

     /\
    /  \
   /    \
  /      \
  \      /
   \____/
    |  |
    |  |
    |  |
    |  |
    |  |
    |  |
    |  |
    |  |
    |  |
    |  |
    |  |
    |  |
    |  |
    |  |
    |  |
    |  |
   /|  |\
  / |  | \
 /  |  |  \
/   |  |   \
/   |  |   \
/   |__|   \
/  /    \  \
/ /      \ \
//        \\
/          \
If the input is 3 the output is

        /\
       /  \
      /    \
     /      \
    /        \
   /          \
   \          /
    \        /
     \______/
      |    |
      |    |
      |    |
      |    |
      |    |
      |    |
      |    |
      |    |
      |    |
      |    |
      |    |
      |    |
      |    |
      |    |
      |    |
      |    |
      |    |
      |    |
      |    |
      |    |
      |    |
      |    |
      |    |
      |    |
     /|    |\
    / |    | \
   /  |    |  \
  /   |    |   \
 /    |    |    \
/     |    |     \
/     |    |     \
/     |    |     \
/     |____|     \
/    /      \    \
/   /        \   \
/  /          \  \
/ /            \ \
//              \\
/                \
If the input is 4 the output is

           /\
          /  \
         /    \
        /      \
       /        \
      /          \
     /            \
    /              \
    \              /
     \            /
      \          /
       \________/
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
        |      |
       /|      |\
      / |      | \
     /  |      |  \
    /   |      |   \
   /    |      |    \
  /     |      |     \
 /      |      |      \
/       |      |       \
/       |      |       \
/       |      |       \
/       |      |       \
/       |______|       \
/      /        \      \
/     /          \     \
/    /            \    \
/   /              \   \
/  /                \  \
/ /                  \ \
//                    \\
/                      \
The pattern continues on for larger input numbers - the arrow is scaled up accordingly.

Notice that for any input N:

The arrowhead is a pentagon with 2×N underscores at the base, N slashes on each of the sides extending from the base, and 2×N slashes on the two sides that form the arrow tip.
The shaft (including the part within the fletching) consists of 11×N lines of two vertical bars separated by 2×(N-1) spaces. The very last line has underscores instead of spaces.
The fletching surrounds the lower 3×N lines of the shaft. Two lines of 2×N slashes extend diagonally downward from either side of the shaft and are joined with vertical columns of slashes.
The complete arrow is 16×N lines high and 6×N characters wide.
In your output there should be no empty lines before the arrow tip and only up to one trailing newline.

None of the output lines should have unnecessary leading spaces (the left edge of the fletching should be as leftmost as possible) but any of the lines may have any number of trailing spaces.

The shortest submission in bytes wins.

*/

package main

import "fmt"

func main() {
	for i := 1; i <= 4; i++ {
		arrow(i)
	}
}

// Ported from @kevinsa5 solution
func arrow(n int) {
	fmt.Printf("n=%d\n", n)
	if n < 1 {
		return
	}

	m := alloc(n)

	// upper left of head
	fill(m, '/', 3*n, 1, -1, 1, 2*n)

	// upper right of head
	fill(m, '\\', 3*n+1, 1, 1, 1, 2*n)

	// lower left of head
	fill(m, '\\', n+1, 2*n+1, 1, 1, n)

	// lower right of head
	fill(m, '/', 5*n, 2*n+1, -1, 1, n)

	// bottom of head
	fill(m, '_', 2*n+1, 3*n, 1, 0, 2*n)

	// shaft
	fill(m, '|', 2*n+1, 3*n+1, 0, 1, 11*n)
	fill(m, '|', 4*n, 3*n+1, 0, 1, 11*n)
	fill(m, '_', 2*n+2, 14*n, 1, 0, 2*n-2)

	// upper fletching edges
	fill(m, '/', 2*n, 11*n+1, -1, 1, 2*n)
	fill(m, '\\', 4*n+1, 11*n+1, 1, 1, 2*n)

	// fletching sides
	fill(m, '/', 1, 13*n, 0, 1, 3*n)
	fill(m, '\\', 6*n, 13*n, 0, 1, 3*n)

	// lower fletching edges
	fill(m, '/', 2*n, 14*n+1, -1, 1, 2*n)
	fill(m, '\\', 4*n+1, 14*n+1, 1, 1, 2*n)

	show(m)
}

func alloc(n int) [][]byte {
	m := make([][]byte, 16*n+1)
	for i := range m {
		m[i] = make([]byte, 6*n+1)
		for j := range m[i] {
			m[i][j] = ' '
		}
	}
	return m
}

func fill(m [][]byte, c byte, x, y, dx, dy, n int) {
	for range n {
		m[y][x] = c
		x += dx
		y += dy
	}
}

func show(m [][]byte) {
	for i := range m {
		fmt.Printf("%s\n", m[i])
	}
	fmt.Println()
}
