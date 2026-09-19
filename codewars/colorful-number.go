/*

Problem
Determine whether a non-negative integer number is colorful or not.

263 is a colorful number because [2, 6, 3, 2*6, 6*3, 2*6*3] are all different; whereas
236 is not colorful, because [2, 3, 6, 2*3, 3*6, 2*3*6] has 6 twice.

So take all consecutive subsets of digits, take their products, and ensure all the products are different.

Examples
263  -->  true
236  -->  false

*/

package main

import "fmt"

func main() {
	assert(colorful(5) == true)
	assert(colorful(23) == true)
	assert(colorful(263) == true)
	assert(colorful(235789) == true)
	assert(colorful(50) == false)
	assert(colorful(13) == false)
	assert(colorful(236) == false)
	assert(colorful(2357893) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func colorful(n int64) bool {
	if n < 0 {
		return false
	}

	s := fmt.Sprint(n)
	m := make(map[int64]bool)
	for i := range len(s) {
		p := int64(1)
		for _, d := range s[i:] {
			p *= int64(d - '0')
			if m[p] {
				return false
			}
			m[p] = true
		}
	}
	return true
}
