/*

Create a function

hasTwoCubeSums(n)
which checks if a given number n can be written as the sum of two cubes in two different ways: n = a³+b³ = c³+d³. All the numbers a, b, c and d should be different and greater than 0.

E.g. 1729 = 9³+10³ = 1³+12³.

hasTwoCubeSums(1729); // true
hasTwoCubeSums(42);   // false

*/

package main

import (
	"math"
)

func main() {
	tab := []int{
		1729, 4104, 13832, 20683, 32832, 39312, 40033, 46683, 64232, 65728, 110656, 110808,
		134379, 149389, 165464, 171288, 195841, 216027, 216125, 262656, 314496, 320264, 327763,
		373464, 402597, 439101, 443889, 513000, 513856, 515375, 525824, 558441, 593047, 684019, 704977,
	}

	assert(twocubesums(1) == false)
	assert(twocubesums(1729) == true)
	assert(twocubesums(42) == false)
	assert(twocubesums(4104) == true)
	assert(twocubesums(4105) == false)

	n := 0
	for i := range tab[len(tab)-1] + 1 {
		switch {
		case i == tab[n]:
			assert(twocubesums(i) == true)
			n += 1
		default:
			assert(twocubesums(i) == false)
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A001235
func twocubesums(n int) bool {
	m := make(map[int]bool)
	l := int(math.Cbrt(float64(n)))
	c := 0
	for x := 1; x <= l; x++ {
		for y := 1; y <= l; y++ {
			if x*x*x+y*y*y != n || m[x] || m[y] {
				continue
			}

			m[x], m[y] = true, true
			if c++; c >= 2 {
				return true
			}
		}
	}
	return false
}
