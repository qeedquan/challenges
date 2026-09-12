/*

(Despite 60+ questions tagged chess, we don't have a simple n-queens challenge.)

In chess, the N-Queens Puzzle is described as follows: Given an n x n chessboard and n queens, arrange the queens onto the chessboard so that no two queens are threatening each other. Below is an example solution for n = 8, borrowed from Wikipedia.

https://i.sstatic.net/D32OV.png

Or, in ASCII rendering:

xxxQxxxx
xxxxxxQx
xxQxxxxx
xxxxxxxQ
xQxxxxxx
xxxxQxxx
Qxxxxxxx
xxxxxQxx
The challenge here will be to take input n and output an ASCII representation of a solution to the n-Queens puzzle. Since there are more than one possible solution (e.g., at the least, a rotation or reflection), your code only needs to output any valid solution.

Input
A single positive integer n with n >= 4 in any convenient format. (n=2 and n=3 have no solutions, and n=1 is trivial, so those are excluded)

Output
The resulting ASCII representation of a solution to the N-queens puzzle, as outlined above. You may choose any two distinct ASCII values to represent blank spaces and queens. Again, this can be output in any suitable format (single string, a list of strings, a character array, etc.).

Rules
Leading or trailing newlines or whitespace are all optional, as well as whitespace between characters, so long as the characters themselves line up correctly.
You can either use an algorithm to calculate the possible positions, or use the explicit "stair-step" style of solution, whichever is golfier for your code.
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
If possible, please include a link to an online testing environment so other people can try out your code!
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.
Examples
n=4
xQxx
xxxQ
Qxxx
xxQx

n=7
xxQxxxx
xxxxxxQ
xQxxxxx
xxxQxxx
xxxxxQx
Qxxxxxx
xxxxQxx

n=10
xxxxQxxxxx
xxxxxxxxxQ
xxxQxxxxxx
xxxxxxxxQx
xxQxxxxxxx
xxxxxxxQxx
xQxxxxxxxx
xxxxxxQxxx
Qxxxxxxxxx
xxxxxQxxxx

*/

package main

import "fmt"

func main() {
	for i := range 11 {
		queens(i)
	}
}

/*

Ported from @orlp solution

The problem allows any valid solution so we don't have to permute all positions.
One can generate one valid configuration directly where the queens are placed on a bunch of parallel lines (geometrically speaking).

*/

func queens(n int) {
	fmt.Printf("n=%d\n", n)
	if n < 4 {
		fmt.Println()
		return
	}

	m := n % 2
	n -= m
	for y := range n + m {
		w := 0
		if y < n {
			w = n + m
			w0 := n + y%(n/2)*2
			w1 := truth(y < n/2)
			if n%6 != 0 {
				if y < n/2 {
					w1 = n/2 - 1
				} else {
					w1 = 2 - n/2
				}
			}
			w = w - (w0+w1)%n
		}

		for range w - 1 {
			fmt.Printf(".")
		}
		fmt.Printf("Q")
		for range n - w {
			fmt.Printf(".")
		}
		fmt.Println()
	}
	fmt.Println()
}

func truth(x bool) int {
	if x {
		return 1
	}
	return 0
}
