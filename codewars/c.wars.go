/*

A person's full name is usually composed of a first name, middle name and last name; however in some cultures (for example in South India) there may be more than one middle name.

Write a function that takes the full name of a person, and returns the initials, separated by dots ('.'). The initials must be uppercase. The last name of the person must appear in full, with its first letter in uppercase as well.

See the pattern below:

"code wars"            ---> "C.Wars"
"Barack hussein obama" ---> "B.H.Obama"
Names in the full name are separated by exactly one space (' ' ) ; without leading or trailing spaces. Names will always be lowercase, except optionally their first letter.

*/

package main

import (
	"bytes"
	"fmt"
	"strings"
	"unicode"
)

func main() {
	assert(initials("code wars") == "C.Wars")
	assert(initials("Barack hussein obama") == "B.H.Obama")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func initials(name string) string {
	output := new(bytes.Buffer)
	fields := strings.Split(name, " ")
	for index, field := range fields {
		field = strings.TrimSpace(field)
		if field == "" {
			continue
		}

		first := unicode.ToUpper(rune(field[0]))
		if index+1 < len(fields) {
			fmt.Fprintf(output, "%c.", first)
		} else {
			fmt.Fprintf(output, "%c%s", first, field[1:])
		}
	}
	return output.String()
}
