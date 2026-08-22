/*

Implement String#whitespace?(str) (Ruby), String.prototype.whitespace(str) (JavaScript), String::whitespace(str) (CoffeeScript), or whitespace(str) (Python), which should return true/True if given object consists exclusively of zero or more whitespace characters, false/False otherwise.q

*/

package main

import (
	"regexp"
)

func main() {
	assert(rews.MatchString("\t ") == true)
	assert(rews.MatchString("\t fwf    ") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

var rews = regexp.MustCompile(`^\s*$`)
