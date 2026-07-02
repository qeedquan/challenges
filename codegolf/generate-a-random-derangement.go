/*

Challenge description
A "derangement" of a sequence is a permutation where no element appears in its original position. For example ECABD is a derangement of ABCDE, but CBEDA is not:

ABCDE
 | |   <- B and D are in their orignal positions
CBEDA
Given a sequence, generate a random derangement of it.

Notes
You may take either a string as an input or an array/list of elements (integers, chars, objects...)

Instead of returning a new object, you can modify an existing one by swapping its elements

Each derangement should have an equal probability of being generated

You may assume that there is more than one element in the sequence and none appear more than once

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	fmt.Printf("%q\n", derangement([]int{'A', 'B', 'C', 'D', 'E'}))
}

func derangement(a []int) []int {
	n := len(a)
	p := perm(n)
	r := make([]int, n)
	for i := range r {
		r[i] = a[p[i]]
	}
	return r
}

func perm(n int) []int {
loop:
	for {
		p := rand.Perm(n)
		for i := range p {
			if p[i] == i {
				continue loop
			}
		}
		return p
	}
}
