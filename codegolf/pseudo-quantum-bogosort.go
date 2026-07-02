/*

Pseudo-Quantum Bogosort
Quantum Bogosort is as follows:

Quantumly randomise the list, such that there is no way of knowing what order the list is in until it is observed.
This will divide the universe into O(n!) universes; however, the division has no cost, as it happens constantly anyway.

If the list is not sorted, destroy the universe. (This operation is left as an exercise to the reader.)

All remaining universes contain lists which are sorted.

Source

Given that we cannot destroy the universe, the next best thing is to destroy a thread!

The challenge is as follows: Make a new thread/branch for each possible permutation of a list and if the list is not sorted, destroy the thread/branch (or just dont output it)

Rules
Input is a list of length 4 or less

Output should be the randomized list for each thread or branch that successfully sorted it. Destroying/exiting the thread or branch is optional, but funny.

If there is a repeated number, output list duplicates.

This is standard code-golf

Test cases:

[1,4,2,9] -> [1,2,4,9]
[3,1,1,9] -> [1,1,3,9] and [1,1,3,9]
[3,1,1,3] -> [1,1,3,3] [1,1,3,3] [1,1,3,3] [1,1,3,3]

*/

package main

import (
	"fmt"
	"math/rand"
	"runtime"
)

func main() {
	fmt.Println(qbsort([]int{1, 4, 2, 9}))
	fmt.Println(qbsort([]int{3, 1, 1, 9}))
	fmt.Println(qbsort([]int{3, 1, 1, 3}))
	fmt.Println(qbsort([]int{9, 8, 7, 6, 5, 4}))
}

func qbsort(a []int) []int {
	n := runtime.NumCPU()
	ch := make(chan []int, n)

	var r []int
loop:
	for {
		for range n {
			go split(a, ch)
		}

		for range n {
			x := <-ch
			if sorted(x) {
				r = x
				break loop
			}
		}
	}
	return r
}

func split(a []int, ch chan []int) {
	n := len(a)
	p := rand.Perm(n)
	r := make([]int, n)
	for i := range r {
		r[i] = a[p[i]]
	}
	ch <- r
}

func sorted(a []int) bool {
	for i := 1; i < len(a); i++ {
		if a[i] < a[i-1] {
			return false
		}
	}
	return true
}
