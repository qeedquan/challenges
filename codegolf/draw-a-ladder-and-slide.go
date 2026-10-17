/*

Your task is to create a program or function that takes, as input, a natural number (n) between 1 and 25 (inclusive) and prints an isometric representation of a slide and ladder with n number of rungs.

Ladder and slide specifications
The ladder is always oriented on the left and the slide on the right.
We're viewing it from the ladder side, so part of the slide is obscured at the top three levels.
The rungs are represented by four dashes (----) and the sides of the ladder and slide by slashes (/ and \).
The following is a diagram to represent the patterns of spaces needed for a slide with five rungs.

Slide              Blank space count
    /----/\        1234/----/\
   /----/  \       123/----/12\
  /----/    \      12/----/1234\
 /----/ \    \     1/----/1\1234\
/----/   \    \    /----/123\1234\

Examples
>>1
/----/\

>>3
  /----/\
 /----/  \
/----/    \

>>4
   /----/\
  /----/  \
 /----/    \
/----/ \    \

>>10
         /----/\
        /----/  \
       /----/    \
      /----/ \    \
     /----/   \    \
    /----/     \    \
   /----/       \    \
  /----/         \    \
 /----/           \    \
/----/             \    \

This is code-golf, so the answer with the lowest byte count wins.

Note: trailing white space is acceptable in the output, as long as it doesn't exceed the length of the line.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	ladderslide(1)
	ladderslide(3)
	ladderslide(4)
	ladderslide(10)
}

func ladderslide(n int) {
	fmt.Printf("n=%d\n", n)
	for i := range n {
		a := strings.Repeat(" ", n-i-1)
		b := strings.Repeat("  ", i) + `\    \`
		fmt.Printf("%s/----/%s\n", a, b[5:])
	}
	fmt.Println()
}
