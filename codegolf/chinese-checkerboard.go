/*

The game of Chinese checkers is played on a board with spaces in the shape of a six-pointed star:

https://en.wikipedia.org/wiki/File:Chinese_checkers_start.png

We can create an ASCII-art representation of this board, using . for empty spots and the letters GYORPB for the six colored starting locations:

            G
           G G
          G G G
         G G G G
B B B B . . . . . Y Y Y Y
 B B B . . . . . . Y Y Y
  B B . . . . . . . Y Y
   B . . . . . . . . Y
    . . . . . . . . .
   P . . . . . . . . O
  P P . . . . . . . O O
 P P P . . . . . . O O O
P P P P . . . . . O O O O
         R R R R
          R R R
           R R
            R
To make it more interesting, we can also change the size. We'll measure the size of a board by the side length of its triangular starting locations: the board above is size 4.

Since it's really a pain to type all that by hand, let's write a program (or function) to do it!

Details
Your code should take a positive integer representing the size of the board, via STDIN, ARGV, or function argument. Output the checkerboard pattern to STDOUT (you may alternately return it as a string if your submission is a function).

Output must either

have no trailing spaces at all, or
have exactly enough trailing spaces to fill out the pattern to a perfect rectangle of width 6 * N + 1.
Output may optionally have a trailing newline. No other extra (leading, trailing) whitespace is permitted.

Examples
Size 1:

   G
B . . Y
 . . .
P . . O
   R
Size 2:

      G
     G G
B B . . . Y Y
 B . . . . Y
  . . . . .
 P . . . . O
P P . . . O O
     R R
      R
Size 4:

            G
           G G
          G G G
         G G G G
B B B B . . . . . Y Y Y Y
 B B B . . . . . . Y Y Y
  B B . . . . . . . Y Y
   B . . . . . . . . Y
    . . . . . . . . .
   P . . . . . . . . O
  P P . . . . . . . O O
 P P P . . . . . . O O O
P P P P . . . . . O O O O
         R R R R
          R R R
           R R
            R
Scoring
This is code-golf: the shortest code in bytes wins.

*/

package main

import (
	"fmt"
)

func main() {
	for i := range 9 {
		sternhalma(i)
	}
}

/*

@xnor

The idea is to use triangular coordinates, in which the triangular lattice corresponds to integer triples (a,b,c) with a+b+c=0.
(Here, the lattice points are drawn as hexagons.)

We can convert Cartesian coordinates to triangular ones as

a = (x+y)/2
b = (x-y)/2
c = -x
noting that x and y must have the same parity, or otherwise it's off-checkerboard and we should print a space.

In triangular coordinates, the bounding lines of the six-sided star have equations: a==n, b==n, c==n, a==-n, b==-n, c==-n.

So, we can determine what region we're in by which of [a,b,c,-a,-b,-c] are greater than n.

If none are, we're in the center and print a dot.
If exactly one is, we're in one of the six outer triangles, and print the letter corresponding to the index.
If two or more are, we're outside the board, and print a space.
The bounding rectangle requires that we do this for x in the closed interval [-2*n,2*n] and y in the closed interval [-3*n,3*n].

*/

func sternhalma(n int) {
	fmt.Printf("n=%d\n", n)
	for x := -2 * n; x <= 2*n; x++ {
		for y := -3 * n; y <= 3*n; y++ {
			fmt.Printf("%c", at(n, x, y))
		}
		fmt.Println()
	}
	fmt.Println()
}

func at(n, x, y int) byte {
	const sym = "OPGBYR"

	a := x + y
	b := x - y
	c := -x

	p := [6]int{a, b, c, -a, -b, -c}
	s := [6]int{2, 2, 1, 2, 2, 1}
	i, z := 0, 0
	for j, v := range p {
		if v > n*s[j] {
			i, z = j, z+1
		}
	}

	switch {
	case z == 0:
		return '.'
	case z != 1 || (x^y)&1 == 1:
		return ' '
	}
	return sym[i]
}
