/*

Whenever you make a move on a Rubik's Cube, there is a reverse move which undoes the first move. Because of this, every algorithm (set of moves) has a reverse algorithm which undoes the first algorithm.

The goal of this challenge is to find the reverse of a given algorithm.

Specification:
The input consists of an array of individual moves. Each move is a string of length 1 or 2. Of course, you can use whatever input format makes the most sense in your language. Each move consists of the structure X or X' or X2, where X is an uppercase or lowercase letter.

To reverse X, simply replace it with X'. Likewise, X' becomes X. X2 on the other hand does not get changed.

To create the output, reverse each move, and then reverse the array.

Examples (strings separated by spaces):
R => R'

D U' => U D'

S T A C K => K' C' A' T' S'

A2 B2 => B2 A2

Scoring:
This is code-golf, so the fewest amount of bytes win. Standard loopholes are not allowed.

*/

package main

import (
	"bytes"
	"strings"
)

func main() {
	assert(undo("R") == "R'")
	assert(undo("D U'") == "U D'")
	assert(undo("S T A C K") == "K' C' A' T' S'")
	assert(undo("A2 B2") == "B2 A2")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func undo(s string) string {
	w := new(bytes.Buffer)
	t := strings.Split(s, " ")
	for i := len(t) - 1; i >= 0; i-- {
		u := t[i]
		n := len(u)
		if n > 1 && strings.HasSuffix(u, "'") {
			u = u[:n-1]
		} else if n == 1 {
			u += "'"
		}

		w.WriteString(u)
		if i > 0 {
			w.WriteString(" ")
		}
	}
	return w.String()
}
