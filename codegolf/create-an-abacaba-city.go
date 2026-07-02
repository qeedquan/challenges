/*

Here is the 3rd ABACABA city:
  _
A|_|
B|__|
A|_|_
C|___|
A|_|
B|__|
A|_|
It is made out of the ABACABA sequence, which is basically:

A (1st iteration)
place B - AB
repeat A - ABA (2nd iteration)
Place C - ABAC
Repeat ABA - ABACABA (3rd iteration)
and you get the idea.

The buildings have a height (corresponded by no. of underscores) equal to the letters converted to numbers as A = 1, B = 2 e.t.c.

Input
An iteration number 1<=n<=26.

Output
The ABACABA city of order n, including the letters at the start of the lines.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	for n := range 6 {
		fmt.Printf("n=%d\n%s\n\n", n, city(n))
	}
}

// ported from @quintopia solution
func city(n int) string {
	return recurse(n, 1)
}

func recurse(n, s int) string {
	if n < 1 {
		return ""
	}

	r := ""
	if s == 1 {
		r = "  _"
	}
	r += recurse(n-1, 0)
	r += repeat("_", n-2)
	r += fmt.Sprintf("\n%c|%s|", 64+n, repeat("_", n))
	r += recurse(n-1, 0)
	return r
}

func repeat(s string, n int) string {
	return strings.Repeat(s, max(n, 0))
}
