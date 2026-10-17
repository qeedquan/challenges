/*

Challenge

Given an integer n ≥ 4, output a permutation of the integers [0, n-1] with the property that no two consecutive integers (integers with absolute difference 1) are next to each other.

Examples

4 → [1, 3, 0, 2]
5 → [0, 2, 4, 1, 3]
6 → [0, 2, 4, 1, 3, 5]
7 → [0, 2, 4, 1, 5, 3, 6]
You may use 1-indexing instead (using integers [1, n] instead of [0, n-1]).

Your code must run in polynomial time in n, so you can't try all permutations and test each one.

*/

package main

import "fmt"

func main() {
	for i := 4; i <= 20; i++ {
		fmt.Println(i, gen(i))
	}
}

func gen(n int) []int {
	r := []int{}
	for i := 1; i < n; i += 2 {
		r = append(r, i)
	}
	for i := 0; i < n; i += 2 {
		r = append(r, i)
	}
	return r
}
