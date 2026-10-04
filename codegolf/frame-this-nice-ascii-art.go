/*

Introduction
I think everyone agrees that nice pictures have to have a nice frame. But most challenges on this site about ASCII-Art just want the raw picture and don't care about it's preservation.
Wouldn't it be nice if we had a program that takes some ASCII-Art and surrounds it with a nice frame?

The Challenge
Write a program that takes some ASCII-Art as input and outputs it surrounded by a nice frame.

Example:

*****
 ***
  *
 ***
*****
becomes

╔═══════╗
║ ***** ║
║  ***  ║
║   *   ║
║  ***  ║
║ ***** ║
╚═══════╝
You have to use the exact same characters for the frame as in the example: ═ ║ ╔ ╗ ╚ ╝
The top and the bottom of the frame get inserted before the first and after the last line of the input.
The left and rights parts of the frame have to have exact one space padding to the widest line of the input.
There may be no leading or trailing whitespaces in the output. Only a trailing newline is allowed.
You may assume that the input has no unnecessary leading whitespaces.
You may assume that the input has no trailing whitespaces on any line.
You don't have to handle empty input.
The input will only contain printable ASCII-characters and newlines.

Rules
Function or full program allowed.
Default rules for input/output.
Standard loopholes apply.
This is code-golf, so lowest byte-count wins. Tiebreaker is earlier submission.
Happy Coding!

Using some great ASCII-Art, that was produced in any challenge on this site, as input to your program and showing it with a nice frame is highly encouraged!

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	frame(ART1)
}

func frame(s string) {
	t := strings.Split(s, "\n")
	w := 0
	for _, t := range t {
		w = max(w, len(t))
	}

	fmt.Printf("╔%s╗\n", strings.Repeat("═", w))
	for _, t := range t {
		fmt.Printf("║%s%s║\n", t, strings.Repeat(" ", w-len(t)))
	}
	fmt.Printf("╚%s╝\n", strings.Repeat("═", w))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

const ART1 = `
*****
 ***
  *
 ***
*****
`
