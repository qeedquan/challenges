/*

The following was a question that I received during a technical interview for an entry level software developer position. I thought I'd post it here so that everyone could give it a go:

You are given an unsorted array containing all the integers from 0 to 100 inclusively. However, one number is missing. Write a function to find and return this number. What are the time and space complexities of your solution?

*/

package main

import (
	"math/rand"
)

func main() {
	var x [101]int
	for i := range x {
		x[i] = i
	}

	for range 1000000 {
		rand.Shuffle(len(x), func(i, j int) {
			x[i], x[j] = x[j], x[i]
		})
		assert(missing(x[:100]) == x[100])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func missing(x []int) int {
	s := 0
	for i := range x {
		s += x[i]
	}
	return 5050 - s
}
