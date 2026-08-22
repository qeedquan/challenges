/*

You are given four positive integers a,b,c,d. Determine if it is possible to form a rectangle with side lengths a,b,c,d.
If such a rectangle exists, print the sum of all four numbers. Otherwise, print "No".

Input
Four positive integers a,b,c,d, each not exceeding 10^9.

Output
If the rectangle exists, print the sum of all numbers. Otherwise, print "No".

Examples

Input #1
7 4 4 7

Answer #1
22

Input #2
9 9 9 6

Answer #2
No

*/

package main

import "sort"

func main() {
	assert(solve(7, 4, 4, 7) == 22)
	assert(solve(9, 9, 9, 6) == "No")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b, c, d int) any {
	v := []int{a, b, c, d}
	sort.Ints(v)
	if v[0] == v[3] || v[0] == v[1] && v[2] == v[3] {
		return v[0] + v[1] + v[2] + v[3]
	}
	return "No"
}
