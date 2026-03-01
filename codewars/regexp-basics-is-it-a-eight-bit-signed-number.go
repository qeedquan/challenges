/*

Implement:

String.prototype.signedEightBitNumber()

which should return true if given object is a number representable by 8 bit signed integer (-128 to -1 or 0 to 127), false otherwise.

It should only accept numbers in canonical representation, so no leading +, extra 0s, spaces etc.

*/

package main

import (
	"fmt"
	"regexp"
)

func main() {
	for i := -100000; i <= 100000; i++ {
		s := fmt.Sprint(i)
		if iss8(s) {
			assert(-128 <= i && i <= 127)
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func iss8(s string) bool {
	re := regexp.MustCompile(`(^-128$)|(^-?[1-9][0-9]$)|(^-?1[0-1][0-9]$)|(^-?12[0-7]$)|(^-[1-9]$)|(^\d$)`)
	return re.MatchString(s)
}
