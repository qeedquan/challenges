/*

For the purposes of this challenge, a 1-2-3 sequence is an infinite sequence of increasing positive integers such that for any positive integer n, exactly one of n, 2n, and 3n appears in the sequence. There exist multiple such sequences, so any one will suffice.

Your challenge is to output any 1-2-3 sequence. Standard sequence rules apply - you may output as a function that takes n and outputs the nth term or first n terms, or output an infinite sequence in some form. You may use 0- or 1-indexing.

This is code-golf, so shortest wins!

Some additional math problems for anyone interested:

What is the cardinality of the set of 1-2-3 sequences?
Prove or disprove: the natural density of each 1-2-3 sequence in the natural numbers is 1/3

*/

package main

import (
	"math"
	"reflect"
)

func main() {
	tab := []int{1, 5, 6, 7, 8, 11, 13, 17, 19, 23, 25, 27, 29, 30, 31, 35, 36, 37, 40, 41, 42, 43, 47, 48, 49, 53, 55, 56, 59, 61, 64, 65, 66, 67, 71, 73, 77, 78, 79, 83, 85, 88, 89, 91, 95, 97, 101, 102, 103, 104, 107, 109, 113, 114, 115, 119, 121, 125, 127, 131, 133, 135}

	assert(reflect.DeepEqual(gen(len(tab)), tab))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A339746
func gen(n int) []int {
	m := map[int]bool{0: true}
	r := []int{}
	for i := 1; i < math.MaxInt && len(r) < n; {
		for m[i] && i < math.MaxInt {
			i += 1
		}

		r = append(r, i)

		m[i] = true
		m[i*2] = true
		m[i*3] = true
		m[i*4] = true
		m[i*9] = true
	}
	return r
}
