/*

(easy mode of Seven Slash Display)

Given a positive integer (or alternatively, a string/list of bits of its binary representation) output it with this diagonal ASCII-art formation:

(output for 53 / 110101)

       \
     /\ \
     \ \
    \ \/
  /\ \
  \ \
 \ \/
\ \
 \
This output has the MSB at the bottom left. Alternatively, you may choose to output with the LSB at the bottom left.

The output may include any extra whitespace as long as that doesn’t impact the presentation of the image.

This is a code-golf competition, so the shortest code wins.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	bsd([]int{1, 1, 0, 1, 0, 1})
	bsd([]int{1, 1, 1, 1})
	bsd([]int{0, 0, 0, 0, 0})
	bsd([]int{1, 1, 0, 0, 1, 1})
}

// ported from @squareroot12621 solution
func bsd(a []int) {
	output(diag(a))
}

func diag(a []int) []int {
	b := []int{}
	for _, v := range a {
		if v == 1 {
			b = append(b, []int{1}...)
		} else {
			b = append(b, []int{0, 2}...)
		}
	}
	return b
}

func output(b []int) {
	const fwd = `  /`
	for i := len(b); i >= 0; i-- {
		c0, c1, c2 := ' ', ' ', ' '
		if i > 0 {
			c0 = rune(fwd[b[i-1]])
			c1 = '\\'
		}
		if i+1 < len(b) {
			c2 = rune(fwd[b[i+1]])
		}

		s0 := strings.Repeat(" ", i)
		s1 := ""
		if i < len(b) {
			s1 = ` \`
		}

		fmt.Printf("%s%c%c%s%c\n", s0, c0, c1, s1, c2)
	}
	fmt.Println()
}
