/*

Write a program or function that takes in a positive integer N.

When N is 1, output

/\
\/
When N is 2, output

/\/\
\/ /
/ /
\/
When N is 3, output

/\/\/\
\/ / /
/ / /
\/ /
/ /
\/
When N is 4, output

/\/\/\/\
\/ / / /
/ / / /
\/ / /
/ / /
\/ /
/ /
\/
For larger N the pattern continues, a new layer is added every time N is incremented.

"Output" means print the slash pattern or return it as a string.
A single trailing newline in the output is allowed.
Trailing spaces in the output are allowed but leading spaces are not.
The shortest code in bytes wins.

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	for i := 0; i <= 10; i++ {
		fmt.Printf("n=%v\n%v\n", i, slashcake(i))
	}
}

func slashcake(n int) string {
	w := new(bytes.Buffer)
	n *= 2
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			c := ' '
			switch m := i + j; {
			case m > n:
			case m&1 == 0:
				c = '/'
			case i == 0 || j == 0:
				c = '\\'
			}
			fmt.Fprintf(w, "%c", c)
		}
		fmt.Fprintln(w)
	}
	return w.String()
}
