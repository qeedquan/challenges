/*

For an integer n that satisfies n > 0, write its value as a right-descending path based on its binary representation.

Rules
The first (most significant) set bit is always in the top-left corner.
When the next bit is set (a 1), draw a character ("filled") on the next line in the same column as the previous character drawn. Try to use spaces ("empty") to fill, but any character will do as long as it's always the same.
When the next bit is unset (a 0), draw a character ("filled") on the same line immediately to the the right of the previous character drawn.
Your code must support numbers with at least 20 significant bits.
Write a full program, a function, a lambda, etc. but no snippet.
No leading spaces (or "empty" char) / lines allowed
Any number of trailing spaces (or "empty" char) / lines allowed
Any kind of 1D input is accepted: number, string, array of booleans, etc. Keep the order of bits untouched though.
Any kind of visual 2D output is accepted: on stdout, a string (with any two distinct values representing "filled" and "empty"), you can even output a matrix if you want. A list of numbers seems hard to reconcile with the "no heading spaces" rule, but I'm open to it if you find a way to use it. Note: if you chose to print or return a string, the characters used must be ASCII characters in the codepoints range [32-126].
Standard loopholes are banned.
This is codegolf so the shortest code wins.

Examples
Input: 1

*
Input: 2

**
Input: 3

*
*
Input: 4

***
Input: 5

**
 *
Input: 6

*
**
Input: 7

*
*
*
Input: 25

*
***
  *
Input: 699050

**
 **
  **
   **
    **
     **
      **
       **
        **
         **
Input: 1047552

*
*
*
*
*
*
*
*
*
***********
Input: 525311

**********
         *
         *
         *
         *
         *
         *
         *
         *
         *
         *

*/

package main

import (
	"fmt"
	"image"
)

func main() {
	binpath(1)
	binpath(2)
	binpath(3)
	binpath(4)
	binpath(5)
	binpath(6)
	binpath(7)
	binpath(25)
	binpath(699050)
	binpath(1047552)
	binpath(525311)
}

func binpath(n uint) {
	if n == 0 {
		return
	}

	m := map[image.Point]bool{{0, 0}: true}
	p := image.Pt(0, 0)
	s := fmt.Sprintf("%b", n)
	for _, c := range s[1:] {
		if c == '1' {
			p.Y++
		} else {
			p.X++
		}
		m[p] = true
	}

	fmt.Printf("n=%d\n", n)
	w, h := p.X, p.Y
	for p.Y = 0; p.Y <= h; p.Y++ {
		for p.X = 0; p.X <= w; p.X++ {
			if m[p] {
				fmt.Printf("*")
			} else {
				fmt.Printf(" ")
			}
		}
		fmt.Printf("\n")
	}
}
