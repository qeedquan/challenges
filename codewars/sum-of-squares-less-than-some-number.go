/*

Write a function getNumberOfSquares (C, F#, Haskell) / get_number_of_squares (Python, Ruby) that will return how many integer (starting from 1, 2...) numbers raised to power of 2 and then summed up are less than some number given as a parameter.

E.g 1: For n = 6 result should be 2 because 1^2 + 2^2 = 1 + 4 = 5 and 5 < 6 E.g 2: For n = 15 result should be 3 because 1^2 + 2^2 + 3^2 = 1 + 4 + 9 = 14 and 14 < 15

*/

package main

import (
	"sort"
)

func main() {
	assert(solve(1) == 0)
	assert(solve(2) == 1)
	assert(solve(5) == 1)
	assert(solve(6) == 2)
	assert(solve(15) == 3)

	for i := range 100000 {
		assert(solve(i) == solvebf(i))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int) int {
	if n < 1 {
		return 0
	}

	i := sort.Search(n, func(x int) bool {
		return pyramidal(x) >= n
	})
	return i - 1
}

func solvebf(n int) int {
	s := 0
	for i := 1; i <= n; i++ {
		s += i * i
		if s >= n {
			return i - 1
		}
	}
	return 0
}

// https://oeis.org/A000330
func pyramidal(n int) int {
	return n * (n + 1) * (2*n + 1) / 6
}
