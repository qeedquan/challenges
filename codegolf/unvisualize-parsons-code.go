/*

Introduction
The Parsons code is just a simple way to describe pitch variations in a piece of music, whether a note is higher or lower than the previous one.

Even if you suck at remembering tunes, you can still pretty much remember if a note goes up or down, thus the Parsons code can help you to identify a music using a search engine.

Description
Each variation is represented by a single character, which is one of the following:

R if the note is the same than the previous one (stands for "Repeat")
U if the note is higher than the previous one (stands for "Up")
D if the note is lower than the previous one (stands for "Down")
The initial note is written as *.

Example
Here is an example of Parsons code (beginning of "Ode to Joy"):

*RUURDDDDRUURDR
You can actually visualize it, like this:

      *-*
     /   \
    *     *
   /       \
*-*         *         *-*
             \       /   \
              *     *     *-*
               \   /
                *-*
We'll call that a contour from now on.

The rules for drawing such countours are considered self-explained by the above example.

Challenge
Now comes the real challenge.

Write a program that, given a contour as input, outputs its corresponding Parsons code.
You are not asked to draw the contour, but the opposite actually.
From the contour, find the original Parsons code.

Rules
The usual rules for code golfing apply
The shortest program in number of bytes wins
The input is a contour, and the output shall be a valid Parsons code
Details about extra whitespace for the input are irrelevant, do whatever works best for you
You are not allowed to hardcode, one way or another, parts of the output and / or the program using extra whitespace because of the previous rule

Notes
This might be useful for testing
The corresponding Parsons code for * is *
An empty string is not a valid contour
A Parsons code always starts with *

*/

package main

import (
	"bytes"
)

func main() {
	assert(parsons([]string{
		`      *-*                    `,
		`     /   \                   `,
		`    *     *                  `,
		`   /       \                 `,
		`*-*         *         *-*    `,
		`             \       /   \   `,
		`              *     *     *-*`,
		`               \   /         `,
		`                *-*          `,
	}) == "*RUURDDDDRUURDR")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func parsons(s []string) string {
	b := new(bytes.Buffer)
	b.WriteRune('*')

	if len(s) == 0 || len(s[0]) == 0 {
		return b.String()
	}

	y, w, h := 0, len(s[0]), len(s)
	for ; y < h; y++ {
		if s[y][0] == '*' {
			break
		}
	}
	if s[y][0] != '*' {
		return "invalid"
	}

	for x := 1; x < w; x += 2 {
		if y >= h {
			return "invalid"
		}

		dy := 0
		switch {
		case s[y][x] == '-':
			b.WriteRune('R')
		case y-1 > 0 && s[y-1][x] == '/':
			b.WriteRune('U')
			dy = -1
		case y+1 < h && s[y+1][x] == '\\':
			b.WriteRune('D')
			dy = 1
		default:
			return "invalid"
		}
		y += 2 * dy

		if x+1 >= w || y < 0 || y >= h || s[y][x+1] != '*' {
			return "invalid"
		}
	}

	return b.String()
}
