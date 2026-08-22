/*

Spin-off of this kata, here you will have to figure out an efficient strategy to solve the problem of finding the sole duplicate number among an unsorted array/list of numbers starting from 1 up to n.

Hints: a solution in linear time can be found; using the most intuitive ones to search for duplicates that can run in O(n²) time won't work.

*/

package main

import (
	"math/rand"
)

func main() {
	sim(1e4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func sim(n int) {
	for i := 1; i <= n; i++ {
		x, u := random(i)
		v := duplicate(x)
		assert(u == v)
	}
}

func duplicate(x []int) int {
	return sum(x) - triangular(len(x)-1)
}

func random(n int) ([]int, int) {
	x := make([]int, n+1)
	u := 1 + rand.Intn(n)
	for i := range n {
		x[i] = i + 1
	}
	x[n] = u

	rand.Shuffle(len(x), func(i, j int) {
		x[i], x[j] = x[j], x[i]
	})

	return x, u
}

func sum(x []int) int {
	s := 0
	for i := range x {
		s += x[i]
	}
	return s
}

func triangular(n int) int {
	return n * (n + 1) / 2
}
