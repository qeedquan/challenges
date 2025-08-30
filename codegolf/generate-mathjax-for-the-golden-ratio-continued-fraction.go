/*

In anticipation of MathJax being temporarily disabled, the rendered MathJax in this question has been replaced with images. You are still welcome to post answers but you'll have to view the rendered MathJax on another site.

PPCG just got MathJax! This means we can now easily include well formatted mathematical formulas into posts. (Handy MathJax tutorial.)

For example, here is the golden ratio expressed as an infinite continued fraction:

https://i.stack.imgur.com/s8P0Y.png

The MathJax code for this equation is

$$\varphi=1+\cfrac1{1+\cfrac1{1+\cfrac1{1+\cfrac1{1+\ddots}}}}$$
You can find this by right clicking the formula and following Show Math As → TeX Commands.
The $$ means it is displayed on its own in the center of the page instead of inline. Use a single $ for inline.

Challenge
Write a program that takes in a non-negative integer, n, and outputs the MathJax code for that many "steps" of the continued fraction for the golden ratio.

To keep things standard across answers, you must use this exact MathJax syntax:

For n = 0, the output must be $$\varphi=1+\dots$$.
Which is rendered as:

https://i.stack.imgur.com/4jZNE.png

For n = 1, the output must be $$\varphi=1+\cfrac1{1+\ddots}$$.
Which is rendered as:

https://i.stack.imgur.com/FilKt.png

For n = 2, the output must be $$\varphi=1+\cfrac1{1+\cfrac1{1+\ddots}}$$.
Which is rendered as:

https://i.stack.imgur.com/9a23W.png

For n = 3, the output must be $$\varphi=1+\cfrac1{1+\cfrac1{1+\cfrac1{1+\ddots}}}$$.
Which is rendered as:

https://i.stack.imgur.com/Ts1zU.png

This pattern continues on for larger n. You could say that n represents the number of division lines in the equation.

Notes
\cfrac is used instead of the more common \frac.
\dots is used instead of \ddots for n = 0.
Take input from stdin or the command line.
Output to stdout (with an optional trailing newline).
Alternatively, you may write a function that takes in n as an integer and returns the MathJax code as a string (or still prints it).
Scoring
The smallest submission in bytes wins. Tiebreaker goes to the earlier submission.

*/

package main

import (
	"strings"
)

func main() {
	assert(mathjaxphi(0) == `$$\varphi=1+\dots$$`)
	assert(mathjaxphi(1) == `$$\varphi=1+\cfrac1{1+\ddots}$$`)
	assert(mathjaxphi(2) == `$$\varphi=1+\cfrac1{1+\cfrac1{1+\ddots}}$$`)
	assert(mathjaxphi(3) == `$$\varphi=1+\cfrac1{1+\cfrac1{1+\cfrac1{1+\ddots}}}$$`)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func mathjaxphi(n int) string {
	if n < 0 {
		return ""
	}

	s := `$$\varphi=1+\`
	s += strings.Repeat(`cfrac1{1+\`, n)
	if n >= 1 {
		s += "d"
	}
	s += "dots" + strings.Repeat("}", n) + "$$"
	return s
}
