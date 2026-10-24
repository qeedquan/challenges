/*

Write a program or function that draws an ASCII star, given the size of the arms as input.

Here's a star of size 1

_/\_
\  /
|/\|
Here's a star of size 2

   /\
__/  \__
\      /
 \    /
 | /\ |
 |/  \|
Here's a star of size 3

     /\
    /  \
___/    \___
\          /
 \        /
  \      /
  |  /\  |
  | /  \ |
  |/    \|
And so on.

Input
A single positive integer in any convenient format, n > 0.

Output
An ASCII-art representation of a star, following the above rules. Leading/trailing newlines or other whitespace are optional, provided that the points line up appropriately.

Rules
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	for i := 1; i <= 5; i++ {
		fmt.Println(stars(i))
	}
}

// ported from @Jakob solution
func stars(x int) string {
	if x < 1 {
		return ""
	}

	n := "\n"
	s := "/"
	b := "\\"
	u := "_"
	i := 0
	o := fmt.Sprintf("n=%d\n", x)
	for x--; i < x; u += "_" {
		o += spaces(s, 2*x-i+1) + spaces(b, 2*i) + n
		i += 1
	}

	o += u + s + spaces(b, 2*i) + u + n
	for i >= 0 {
		o += spaces(b, x-i) + spaces(s, 4*x-2*(x-i-1)) + n
		i -= 1
	}

	for i < x {
		i += 1
		o += spaces("|", x) + spaces(s, x-i) + spaces(b, 2*i) + spaces("|", x-i) + n
	}

	return o
}

func spaces(s string, n int) string {
	return strings.Repeat(" ", n) + s
}
