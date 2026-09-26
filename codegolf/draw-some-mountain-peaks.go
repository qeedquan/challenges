/*

Write a program or function that draws a mountain range, where each subsequent larger mountain peak is "behind" the ones in front, and alternates which side is visible.

This is a mountain range of size 1

/\
This is a mountain range of size 2

 /\
/\ \
This is a mountain range of size 3

  /\
 / /\
/ /\ \
This is a mountain range of size 4

   /\
  /\ \
 / /\ \
/ /\ \ \
This is a mountain range of size 5

    /\
   / /\
  / /\ \
 / / /\ \
/ / /\ \ \
And so on.

Input
A single positive integer in any convenient format, n > 0.

Output
An ASCII-art representation of the mountain range, following the above rules. Leading/trailing newlines or other whitespace are optional, provided that the peaks line up appropriately.

Rules
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	for i := range 16 {
		peaks(i)
	}
}

func peaks(n int) {
	fmt.Printf("n=%d\n", n)
	s := `/\`
	for n > 0 {
		n -= 1
		fmt.Println(strings.Repeat(" ", n), s)
		if n&1 == 0 {
			s = `/ ` + s
		} else {
			s = s + ` \`
		}
	}
	fmt.Println()
}
