/*

The block of a string S at position i is defined as the largest substring starting at position i that matches a prefix of S.
The length of the block at position 0 is considered to be zero.

Find the lengths of the blocks of string S for all positions.

Input
One string S (∣S∣≤10^6).

Output
Print a single line containing the lengths of the blocks of string S for all positions.

Examples

Input #1
abaabaab

Answer #1
0 0 1 5 0 1 2 0

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test("abaabaab", []int{0, 0, 1, 5, 0, 1, 2, 0})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r []int) {
	z := solve(s)
	fmt.Println(z)
	assert(reflect.DeepEqual(z, r))
}

func solve(s string) []int {
	return zfunction(s)
}

func zfunction(s string) []int {
	n := len(s)
	l := 0
	r := 0
	z := make([]int, n)
	for i := 1; i < n; i++ {
		if i <= r {
			z[i] = min(r-i+1, z[i-l])
		}
		for i+z[i] < n && s[z[i]] == s[i+z[i]] {
			z[i] += 1
		}
		if i+z[i]-1 > r {
			l = i
			r = i + z[i] - 1
		}
	}
	return z
}
