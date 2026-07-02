/*

I decided to create a complete guide to the great game of tic-tac-toe.

I expected it to be extremely popular, so to save on paper while printing it I decided to encode all possible game positions.

I counted that there are exactly 6045 correct ways to put x and o on a 3\times3 board. EDIT: 6046, I forgot to count empty board.

A position is considered correct if the number of xs are equal to or one greater than the number of os.

Please help me write a function that accepts a position on the board and returns the encoded result.

This function should:

Accept a string consisting of exactly 9 symbols x, o or   (whitespace), where all inputs are correct positions.
It should return a string consisting of exactly 13 symbols, all of which are either 1 or 0.
The result should be unique for every board.
You can choose which encoding algorithm you want to use.

Example
The example

|x| | |
| |o|x|
|x| |o|
Corresponds to the input x   oxx o.

This is code-golf, so the shortest answer wins. All usual rules apply.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	tab := []string{"xxxxxoooo", "xxxx  ooo", "xxxx o oo", "xxxx oo o", "xxxx ooo ", "xxxx oooo", "ooooxxxxx"}
	for _, s := range tab {
		fmt.Printf("[%s] => %s\n", s, encode(s))
	}
}

// ported from @jdt solution
func encode(s string) string {
	const sym = "x o"

	r := make([]byte, max(20, len(s)))
	c := 0
	copy(r, s)
	for i := range 19682 {
		g := 1
		n := 9
		j := i
		for p := 8; p >= 0; p, j = p-1, j/3 {
			n -= j % 3
			if r[p] != sym[j%3] {
				g = 0
			}
		}

		for p := 13*g - 1; p >= 0; p, c = p-1, c/2 {
			r[p] = '0' + byte(c&1)
		}

		if n == 0 || n == 1 {
			c += 1
		}
	}
	return strings.TrimRight(string(r), "\x00")
}
