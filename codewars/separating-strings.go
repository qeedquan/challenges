/*

Create a function that takes a string and separates it into a sequence of letters.

The array will be formatted as so:

[['J','L','L','M']
,['u','i','i','a']
,['s','v','f','n']
,['t','e','e','']]

The function should separate each word into individual letters, with the first word in the sentence having its letters in the 0th index of each 2nd dimension array, and so on.

Shorter words will have an empty string in the place once the word has already been mapped out. (See the last element in the last part of the array.)

Examples:

sepStr("Just Live Life Man")

// => [['J','L','L','M'],
// => ['u','i','i','a'],
// => ['s','v','f','n'],
// => ['t','e','e','']]);

sepStr("The Mitochondria is the powerhouse of the cell")

// => [ [ 'T', 'M', 'i', 't', 'p', 'o', 't', 'c' ],
// => [ 'h', 'i', 's', 'h', 'o', 'f', 'h', 'e' ],
// => [ 'e', 't', '', 'e', 'w', '', 'e', 'l' ],
// => [ '', 'o', '', '', 'e', '', '', 'l' ],
// => [ '', 'c', '', '', 'r', '', '', '' ],
// => [ '', 'h', '', '', 'h', '', '', '' ],
// => [ '', 'o', '', '', 'o', '', '', '' ],
// => [ '', 'n', '', '', 'u', '', '', '' ],
// => [ '', 'd', '', '', 's', '', '', '' ],
// => [ '', 'r', '', '', 'e', '', '', '' ],
// => [ '', 'i', '', '', '', '', '', '' ],
// => [ '', 'a', '', '', '', '', '', '' ]]

*/

package main

import (
	"fmt"
	"strings"
	"unicode/utf8"
)

func main() {
	show(sep("Just Live Life Man"))
	show(sep("The Mitochondria is the powerhouse of the cell"))
}

func sep(s string) [][]string {
	t := strings.Split(s, " ")
	n := 0
	for _, t := range t {
		n = max(n, utf8.RuneCountInString(t))
	}

	m := make([][]string, n)
	for i := range m {
		m[i] = make([]string, len(t))
		for j := range m[i] {
			m[i][j] = ""
		}
	}

	for i, t := range t {
		j := 0
		for _, r := range t {
			m[j][i], j = string(r), j+1
		}
	}

	return m
}

func show(m [][]string) {
	for i := range m {
		for j := range m[i] {
			if m[i][j] == "" {
				fmt.Print(" ")
			} else {
				fmt.Print(m[i][j])
			}
		}
		fmt.Println()
	}
	fmt.Println()
}
