/*

You want to send an ASCII letter to someone, but you need an envelope to put it in. Your task is to output an envelope given a size as input.

Rules:

Given positive integer input i, your envelope will be i characters tall (not counting the top row), and i*2 characters wide (not counting the side columns).
In other words, your envelope will be i+1 characters tall and (i*2)+2 characters wide.
Output must be in the form of text, using \, /, _, |, and  .
The flap of the envelope must be on the row above the bottom row of the envelope unless impossible (as with an envelope of size 1).
Trailing whitespace is allowed.
Example input and output:

1
->
 __
|\/|

2
->
 ____
|\__/|
|____|

3
->
 ______
|\    /|
| \__/ |
|______|

4
->
 ________
|\      /|
| \    / |
|  \__/  |
|________|

This is a code-golf challenge, so shortest code wins!

*/

package main

import "fmt"

func main() {
	for i := 1; i <= 4; i++ {
		envelope(i)
	}
}

func envelope(n int) {
	fmt.Printf("n=%d\n", n)

	w := 2*n + 2
	h := n + 1
	for y := range h {
		for x := range w {
			fmt.Printf("%c", at(x, y, w, h))
		}
		fmt.Println()
	}
	fmt.Println()
}

func at(x, y, w, h int) rune {
	if y == 0 {
		if x == 0 || x == w-1 {
			return ' '
		}
		return '_'
	}

	if y == h-1 {
		if x == 0 || x == w-1 {
			return '|'
		}

		if h == 2 {
			if x == 1 {
				return '\\'
			}
			if x == 2 {
				return '/'
			}
		}

		return '_'
	}

	if x == 0 || x == w-1 {
		return '|'
	}

	if x == y {
		return '\\'
	}

	if y == w-x-1 {
		return '/'
	}

	if x > y && y < w-x && y == h-2 {
		return '_'
	}

	return ' '
}
