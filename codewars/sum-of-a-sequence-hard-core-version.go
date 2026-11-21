/*

As the title suggests, this is the hard-core version of another neat kata.

The task is simple to explain: simply sum all the numbers from the first parameter being the beginning to the second parameter being the upper limit (possibly included), going in steps expressed by the third parameter:

sequenceSum(2,2,2) === 2
sequenceSum(2,6,2) === 12 // 2 + 4 + 6
sequenceSum(1,5,1) === 15 // 1 + 2 + 3 + 4 + 5
sequenceSum(1,5,3) === 5 // 1 + 4
If it is an impossible sequence (with the beginning being larger the end and a positive step or the other way around), just return 0. See the provided test cases for further examples :)

Note: differing from the other base kata, much larger ranges are going to be tested, so you should hope to get your algo optimized and to avoid brute-forcing your way through the solution.

*/

package main

import (
	"math"
)

func main() {
	assert(seq(2, 2, 2) == 2)
	assert(seq(2, 6, 2) == 12)
	assert(seq(1, 5, 1) == 15)
	assert(seq(1, 5, 3) == 5)
	assert(seq(-1, -5, -3) == -5)
	assert(seq(16, 5, 3) == 0)
	assert(seq(780, 6851543, 5) == 4694363402480)
	assert(seq(9383, 71418, 2) == 1253127200)
	assert(seq(20, 673388797, 5) == 45345247259849570)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func seq(x0, x1, dx float64) float64 {
	n := math.Floor((x1-x0)/dx) + 1
	if n < 0 {
		return 0
	}
	return (n / 2) * (2*x0 + (n-1)*dx)
}
