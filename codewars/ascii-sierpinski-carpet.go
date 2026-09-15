/*

Task
Use the characters " " and "█" to draw the nth iteration of the Sierpiński carpet. In the following you are given the first three iterations. Implement sierpinski_carpet_string(n) which returns the Sierpiński carpet as string for n iterations.

n = 0:
██

n = 1:
██████
██░░██
██████

n = 2:
██████████████████
██░░████░░████░░██
██████████████████
██████░░░░░░██████
██░░██░░░░░░██░░██
██████░░░░░░██████
██████████████████
██░░████░░████░░██
██████████████████

Note
Every line but the last ends with \n
Your solution must be under 4000 chars to avoid hardcoding solutions.
Don't let this mislead you: ░ is only used to visualize space   above and in the test cases. Use space  . This is done since space is sometimes not displayed with a full length in Markdown which makes everything look bad.

*/

package main

import (
	"fmt"
	"strings"
	"unicode/utf8"
)

func main() {
	for order := range 5 {
		carpet(order)
	}
}

func carpet(order int) {
	const (
		white = "█"
		black = "░"
	)

	carpet := []string{white}
	for level := order; level > 0; level-- {
		hole := strings.Repeat(black, utf8.RuneCountInString(carpet[0]))
		middle := make([]string, len(carpet))
		for index, symbol := range carpet {
			middle[index] = symbol + hole + symbol
			carpet[index] = strings.Repeat(symbol, 3)
		}
		carpet = append(append(carpet, middle...), carpet...)
	}

	fmt.Printf("n=%d\n", order)
	for _, line := range carpet {
		fmt.Println(line)
	}
	fmt.Println()
}
