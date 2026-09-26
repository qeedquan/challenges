/*

This is intended to be an easy, bite-size code-golf.

The mex (minimal mex number) of a finite collection of numbers is the smallest non-negative integer 0, 1, 2, 3, 4, ... that does not appear in the collection. In other words, it's the minimum of the complement. The mex operation is central to the analysis of impartial games in combinatorial game theory.

Your goal is to write a program or named function to compute the mex using as few bytes as possible.

Input:

A list of non-negative integers in any order. May contain repeats. For concreteness, the length of the list and the allowed range of elements will both be between 0 and 20 inclusive.

The definition of "list" here is flexible. Any structure that represents a collection of numbers is fine, as long as it has a fixed ordering of elements and allows repeats. It may not include any auxiliary information except its length.

The input can be taken as a function argument or through STDIN.

Output

The smallest mex number. Output or print it.

Test cases

[1]
0
[0]
1
[2, 0]
1
[3, 1, 0, 1, 3, 3]
2
[]
0
[1, 2, 3]
0
[5, 4, 1, 5, 4, 8, 2, 1, 5, 4, 0, 7, 7]
3
[3, 2, 1, 0]
4
[0, 0, 1, 1, 2, 2, 3]
4
[1, 0, 7, 6, 3, 11, 15, 1, 9, 2, 3, 1, 5, 2, 3, 4, 6, 8, 1, 18]
10

*/

package main

import "math"

func main() {
	assert(mex([]int{1}) == 0)
	assert(mex([]int{0}) == 1)
	assert(mex([]int{2, 0}) == 1)
	assert(mex([]int{3, 1, 0, 1, 3, 3}) == 2)
	assert(mex([]int{}) == 0)
	assert(mex([]int{1, 2, 3}) == 0)
	assert(mex([]int{5, 4, 1, 5, 4, 8, 2, 1, 5, 4, 0, 7, 7}) == 3)
	assert(mex([]int{3, 2, 1, 0}) == 4)
	assert(mex([]int{0, 0, 1, 1, 2, 2, 3}) == 4)
	assert(mex([]int{1, 0, 7, 6, 3, 11, 15, 1, 9, 2, 3, 1, 5, 2, 3, 4, 6, 8, 1, 18}) == 10)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func mex(a []int) int {
	m := make(map[int]bool)
	for _, v := range a {
		m[v] = true
	}
	for i := 0; i < math.MaxInt; i++ {
		if !m[i] {
			return i
		}
	}
	return -1
}
