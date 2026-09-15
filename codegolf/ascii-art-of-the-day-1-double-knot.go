/*

Write a full program or a function that takes a positive integer N as input via STDIN/command line/ARGV or function arguments and prints an ASCII double knot corresponding to the N to STDOUT.

The ASCII double knot looks like this:

  __  __  __  __  __  __
 /  \/  \/  \/  \/  \/  \
| /\/ /\/ /\/ /\/ /\/ /\ |
| \/ /\/ /\/ /\/ /\/ /\/ |
 \ \/\ \/\ \/\ \/\ \/\ \/
 /\ \/\ \/\ \/\ \/\ \/\ \
| /\/ /\/ /\/ /\/ /\/ /\ |
| \/ /\/ /\/ /\/ /\/ /\/ |
 \__/\__/\__/\__/\__/\__/

The above is for N = 6

Here are a few more double knots for other values of N:

If N = 1, the output double knot looks like:

  __
 /  \
| /\ |
| \/ |
 \ \/
 /\ \
| /\ |
| \/ |
 \__/

For N = 2, its

  __  __
 /  \/  \
| /\/ /\ |
| \/ /\/ |
 \ \/\ \/
 /\ \/\ \
| /\/ /\ |
| \/ /\/ |
 \__/\__/

For N = 3, its

  __  __  __
 /  \/  \/  \
| /\/ /\/ /\ |
| \/ /\/ /\/ |
 \ \/\ \/\ \/
 /\ \/\ \/\ \
| /\/ /\/ /\ |
| \/ /\/ /\/ |
 \__/\__/\__/

and similarly, the pattern continues and any larger value of N.

Details:

The input is always a positive integer greater than 0.
Trailing newline is optional
There should either be no trailing spaces in each line, or enough trailing spaces such that each row's length is 4*N + 2.
There should never be any leading space that aren't part of the specified pattern.
This is code-golf, so shortest code in bytes wins.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	for i := 0; i < 10; i++ {
		doubleknot(i)
	}
}

// Ported from @Matty solution
func doubleknot(n int) {
	if n < 1 {
		return
	}

	l := []string{
		` __ `,
		`/  \`,
		` /\/`,
		`/\/ `,
		`\ \/`,
		`/\ \`,
		` /\/`,
		`/\/ `,
		`\__/`,
	}
	w := `  ||  || `
	for i := range l {
		s := strings.Repeat(l[i], n)
		if i%4 > 1 {
			s = " " + s[1:len(s)-1] + " "
		}
		fmt.Printf("%c%s%c\n", w[i], s, w[i])
	}
}
