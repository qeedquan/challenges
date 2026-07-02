/*

Objective
Given a nonnegative integer, calculate its NDos-size as defined below, and output it.

NDos' numeral system
The concept of NDos-size comes from the numeral system I made. It represents every nonnegative integer by a nested list, as follows:

With the binary expansion of given nonnegative integer, each entry of the corresponding NDos-numeral stands for each set bit (1). The order of the entries is LSB-first.
The content of each entry is, recursively, the NDos-numeral of the number of the trailing 0s of the 1 that the entry stands for, counted till the end or another 1.
For illustrative purposes, here are representations of few integers in NDos' numeral system:

Integer = Binary = Intermediate representation = NDos-numeral

0 = []
1 = 1 = [0] = [[]]
2 = 10 = [1] = [[[]]]
3 = 11 = [0, 0] = [[], []]
4 = 100 = [2] = [[[[]]]]
5 = 101 = [0, 1] = [[], [[]]]
6 = 110 = [1, 0] = [[[]], []]
7 = 111 = [0, 0, 0] = [[], [], []]
8 = 1000 = [3] = [[[], []]]
9 = 1001 = [0, 2] = [[], [[[]]]]
The NDos-size of the given integer is the number of pairs of square brackets of the corresponding NDos-numeral. That gives the NDos-size of few integers as:

0 -> 1
1 -> 2
2 -> 3
3 -> 3
4 -> 4
5 -> 4
6 -> 4
7 -> 4
8 -> 4
9 -> 5
Note that this sequence is not monotone. 18 -> 6 and 24 -> 5 are one counterexample.

I/O format
Flexible. Standard loopholes apply.

Be careful not to abuse this loophole. For example, you cannot just input an NDos-numeral as a string and count its left brackets.

*/

package main

import (
	"math/bits"
)

func main() {
	tab := []int{1, 2, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 5, 6, 6, 6, 6, 6, 6, 6, 5, 6, 6, 6, 7, 7, 7, 7, 6, 7, 7, 7, 7, 7, 7, 7, 6, 6, 7, 7, 7, 7, 7, 7, 6, 7, 7, 7, 7, 7, 7, 7, 5, 6, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 7, 7, 8, 8, 8, 8, 8}

	for i, v := range tab {
		assert(ndos(i) == v)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A358372
func ndos(n int) int {
	if n < 1 {
		return 1
	}
	d := bits.Len(uint(n&-n)) - 1
	return ndos(d) + ndos(n>>(d+1))
}
