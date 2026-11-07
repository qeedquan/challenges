/*

Given number A you must return number B so that

(int) (A + B) == 123

Note
B can't be negative

*/

package main

import (
	"math"
)

func main() {
	for a := -math.MaxInt32; a < math.MaxInt32; a++ {
		assert(int(uint(a)+number(a)) == 123)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func number(a int) uint {
	return uint(123 - a)
}
