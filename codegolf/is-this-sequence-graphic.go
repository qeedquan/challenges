/*

A graphic sequence is a sequence of positive integers each denoting the number of edges for a node in a simple graph. For example the sequence 2 1 1 denotes a graph with 3 nodes one with 2 edges and 2 with one connection.

Not all sequences are graphic sequences. For example 2 1 is not a graphic sequence because there is no way to connect two nodes so that one of them has two edges.

Task
You will take a sequence of integers by any reasonable method. This includes, but is not limited to, an array of integers and its size, a linked list of unsigned integers, and a vector of doubles. You may assume that there will be no zeros in the input. You may also assume the input is sorted from least to greatest or greatest to least.

You must output whether or not the sequence is a graphic sequence. A truthy value if it is a falsy value otherwise.

Goal
This is code-golf the goal is to minimize the number of bytes in your program

Testcases
Sorted greatest to least

                  -> True
3 3 3 2 2 2 1 1 1 -> True
3 3 2 2 1 1       -> True
3 3 2             -> False
8 1 1 1 1 1 1 1 1 -> True
1 1 1 1           -> True
1 1 1             -> False
9 5 4             -> False

*/

package main

import (
	"sort"
)

func main() {
	assert(isgraphic([]int{2, 1}) == false)
	assert(isgraphic([]int{2, 1, 1}) == true)
	assert(isgraphic([]int{}) == true)
	assert(isgraphic([]int{3, 3, 3, 2, 2, 2, 1, 1, 1}) == true)
	assert(isgraphic([]int{3, 3, 2, 2, 1, 1}) == true)
	assert(isgraphic([]int{3, 3, 2}) == false)
	assert(isgraphic([]int{8, 1, 1, 1, 1, 1, 1, 1, 1}) == true)
	assert(isgraphic([]int{1, 1, 1, 1}) == true)
	assert(isgraphic([]int{1, 1, 1}) == false)
	assert(isgraphic([]int{9, 5, 4}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

https://en.wikipedia.org/wiki/Havel%E2%80%93Hakimi_algorithm

@xnor

Uses a version of the Havel-Hakimi algorithm.
Repeatedly decrements both the largest element k and the k'th largest element (not counting k itself), which corresponding to assigning an edge between the two vertices with those degrees.
Terminates successfully when the list becomes all zeroes.
Otherwise, if there's an index out of bounds, fails with error.
Any negative values created also eventually lead to an out-of-bounds error.

*/

func isgraphic(a []int) bool {
	n := len(a)
	for !allzeros(a) {
		sort.Ints(a)
		k := n - 1 - a[n-1]
		if k < 0 || k >= n {
			return false
		}
		a[k], a[n-1] = a[k]-1, a[n-1]-1
	}
	return true
}

func allzeros(a []int) bool {
	for _, v := range a {
		if v != 0 {
			return false
		}
	}
	return true
}
