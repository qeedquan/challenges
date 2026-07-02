/*

Your task is to write a regular expression that matches positive decimal integers divisible by 4. Negative numbers should be rejected, but leading zeroes are permitted.

Random tests can consist of numbers, ascii letters, some puctuation and brackets. But no need to check for line breaks (\n) and non-ASCII chatracters, nothing that fancy in the tests.

There is 50 characters limit for this regex to avoid hardcoding and keep the "puzzle" status :) Good luck!

*/

package main

import (
	"fmt"
	"regexp"
)

func main() {
	for i := -1000000; i <= 1000000; i++ {
		s := fmt.Sprint(i)
		if div4.MatchString(s) {
			assert(i%4 == 0)
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

var div4 = regexp.MustCompile(`^(?:\d*[02468][048]|\d*[13579][26]|[048])$`)
