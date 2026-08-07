/*

Task
If string has more than one neighboring dashes(e.g. --) replace they with one dash(-).

Dashes are considered neighbors even if there is some whitespace between them.

Example

For str = "we-are- - - code----warriors.-"

The result should be "we-are- code-warriors.-"

Input/Output

[input] string str

[output] a string

*/

package main

import (
	"regexp"
)

func main() {
	assert(redash("we-are- - - code----warriors.-") == "we-are- code-warriors.-")
	assert(redash("a---b- - -c") == "a-b-c")
	assert(redash("a------") == "a-")
	assert(redash("Lorem - ipsum- - - dolor sit amet, consectetur adipiscing elit. Praesent tristique lectus non erat dapibus tincidunt. Integer non nibh fermentum, cursus-diam -------pharetra, mattis--risus.-------") == "Lorem - ipsum- dolor sit amet, consectetur adipiscing elit. Praesent tristique lectus non erat dapibus tincidunt. Integer non nibh fermentum, cursus-diam -pharetra, mattis-risus.-")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func redash(s string) string {
	re := regexp.MustCompile(`-[\s-]*-`)
	return re.ReplaceAllString(s, "-")
}
