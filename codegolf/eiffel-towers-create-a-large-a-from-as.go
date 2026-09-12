/*

Create a function which given a number of lines n, makes a bigA.

The horizontal bar of bigA must be at the middle row, or the lower of the two if n is even
Assume a monospace font for output
Output should be a string (or similar, eg character array) with clear linebreaks to break up the lines, and with correct whitespace for left-padding (you can assume \t to be 4 spaces). There can be any whitespace on the right.

Examples
n = 1
A

n = 2
 A
AAA
n = 3
  A
 AAA
A   A
n = 4
   A
  A A
 AAAAA
A     A
n = 5
    A
   A A
  AAAAA
 A     A
A       A

This is inspired by Create an "H" from smaller "H"s


*/

package main

import "fmt"

func main() {
	for i := 0; i <= 10; i++ {
		tower(i)
	}
}

func tower(n int) {
	w, h := 2*n-1, n
	fmt.Printf("n=%d\n", n)
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			switch xc := abs(x - w/2); {
			case xc < w/4+(w&3)-(w&1) && y == h/2:
				fallthrough
			case xc == y:
				fmt.Printf("A")
			default:
				fmt.Printf(" ")
			}
		}
		fmt.Println()
	}
	fmt.Println()
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
