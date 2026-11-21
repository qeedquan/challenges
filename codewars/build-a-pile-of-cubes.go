/*

Your task is to construct a building which will be a pile of n cubes. The cube at the bottom will have a volume of n^3,
the cube above will have volume of (n - 1)^3 and so on until the top which will have a volume of 1^3.

You are given the total volume m of the building. Being given m can you find the number n of cubes you will have to build?

The parameter of the function findNb (find_nb, find-nb, findNb, ...)
will be an integer m and you have to return the integer n such as (n^3 + (n - 1)^3 + (n - 2)^3 + ... 1^3) = m if such n exists or -1 if there is no such n.

Examples:
findNb(1071225) --> 45

findNb(91716553919377) --> -1

*/

package main

import (
	"math"
)

func main() {
	assert(cubes(1) == 1)
	assert(cubes(1071225) == 45)
	assert(cubes(91716553919377) == -1)
	assert(cubes(4183059834009) == 2022)
	assert(cubes(24723578342962) == -1)
	assert(cubes(135440716410000) == 4824)
	assert(cubes(40539911473216) == 3568)
	assert(cubes(26825883955641) == 3218)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func cubes(n int64) int64 {
	if n < 1 {
		return 0
	}

	l := int64(math.Cbrt(float64(n)))
	x := search(l, func(i int64) bool {
		return sum(i) >= n
	})

	if sum(x) != n {
		return -1
	}
	return x
}

func sum(n int64) int64 {
	return n * n * (n + 1) * (n + 1) / 4
}

func search(n int64, f func(int64) bool) int64 {
	i, j := int64(0), n
	for i < j {
		h := int64(uint64(i+j) >> 1)
		if !f(h) {
			i = h + 1
		} else {
			j = h
		}
	}
	return i
}
