/*

Implement String#six_bit_number?, which should return true if given object is a number representable by 6 bit unsigned integer (0-63), false otherwise.

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
		if isu6(s) {
			assert(0 <= i && i <= 63)
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func isu6(s string) bool {
	re0 := regexp.MustCompile(`^[1-5]?\d$`)
	re1 := regexp.MustCompile(`^6[0-3]$`)
	return re0.MatchString(s) && re1.MatchString(s)
}
