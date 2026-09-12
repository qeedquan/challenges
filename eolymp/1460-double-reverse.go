/*

Given a sequence of natural numbers 1,2,3,…,n (1≤n≤1000).
Rearrange, in reverse order, the segment of this sequence from the a-th to the b-th element,
and then reverse the segment from the c-th to the d-th element (a<b, c<d, 1≤a,b,c,d≤1000).

Input
The integers n, a, b, c, d are given.

Output
Output the resulting sequence.

Examples

Input #1
9 2 5 6 9

Answer #1
1 5 4 3 2 9 8 7 6

Input #2
9 3 6 5 8

Answer #2
1 2 6 5 8 7 3 4 9

*/

package main

import (
	"fmt"
	"slices"
)

func main() {
	fmt.Println(solve(9, 2, 5, 6, 9))
	fmt.Println(solve(9, 3, 6, 5, 8))
}

func solve(n, a, b, c, d int) []int {
	r := make([]int, n)
	for i := range r {
		r[i] = i + 1
	}
	slices.Reverse(r[a-1 : b])
	slices.Reverse(r[c-1 : d])
	return r
}
