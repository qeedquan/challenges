/*

Given a string as input, print a new string with each letter pushed to the right by its respective alphabet index.

We all know that A is a slow and Z is a fast letter. This means that Z gets shifted to the right by 25 spaces, A doesn't get shifted at all and B gets shifted by 1 space.

Your program only has to handle uppercase letters from A-Z, and no other characters, no whitespaces, no punctuation.

Note that if 2 or more letters fall onto the same space after shifting, the latest character will be used. (Example: BA ->  A)

Examples
"AZ" -> "A                         Z"

"ABC" -> "A B C"

"ACE" -> "A  C  E"

"CBA" -> "  A"

"HELLOWORLD" -> "     E H    DLL   OLO   R  W"

Rules
This is code-golf, so the shortest code in any language bytes wins.
Standard loopholes are forbidden.

Input must be received as a string.

You may print the result to stdout or return a string.
A single trailing whitespace and/or newline is allowed.
You may also use lowercase letters as input or output, but only use either case.

*/

package main

import (
	"bytes"
)

func main() {
	assert(shift("AZ") == "A                         Z")
	assert(shift("ABC") == "A B C")
	assert(shift("ACE") == "A  C  E")
	assert(shift("CBA") == "  A")
	assert(shift("HELLOWORLD") == "     E H    DLL   OLO   R  W")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func shift(s string) string {
	n := 0
	m := make(map[int]rune)
	for i, r := range s {
		x := i + int(r) - 'A'
		n = max(n, x)
		m[x] = r
	}

	w := new(bytes.Buffer)
	for i := 0; i <= n; i++ {
		r, ok := m[i]
		if !ok {
			r = ' '
		}
		w.WriteRune(r)
	}

	return w.String()
}
