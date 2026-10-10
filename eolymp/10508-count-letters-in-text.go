/*

The text is given. How many times each Latin letter (from 'a' to 'z') appears in the text? Do not distinguish the uppercase and lowercase letters.

Input
Contains sequence of characters - a text.

Output
Print 26 integers in a line: the number of times each Latin letter appears in the text.

Examples

Input #1
This is A man :-)
Hello "Ben"! I am here!....    fine

Answer #1
3 1 0 0 5 1 0 3 4 0 0 2 2 3 1 0 0 1 2 1 0 0 0 0 0 0

*/

package main

import (
	"fmt"
	"unicode"
)

func main() {
	fmt.Println(count("This is A man :-)\nHello \"Ben\"! I am here!....    fine"))
}

func count(s string) [26]int {
	var c [26]int
	for _, r := range s {
		r = unicode.ToLower(r)
		if 'a' <= r && r <= 'z' {
			c[r-'a'] += 1
		}
	}
	return c
}
