/*

Implement String#eight_bit_number?, which should return true if given object is a number representable by 8 bit unsigned integer (0-255), false otherwise.

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
		if isu8(s) {
			assert(0 <= i && i <= 255)
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func isu8(s string) bool {
	re := regexp.MustCompile(`^(1[0-9][0-9]|2[0-4][0-9]|25[0-5]|[1-9][0-9]|[0-9])$`)
	return re.MatchString(s)
}
