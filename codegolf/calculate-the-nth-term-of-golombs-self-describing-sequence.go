/*

Inspired by the previous question.
https://codegolf.stackexchange.com/questions/8369/generate-a-kolakoski-sequence

Golomb's self-describing sequence g(n) is a sequence where any natural number n is repeated within the sequence g(n) times.

The first few numbers in the sequence are:

n    1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20
g(n) 1  2  2  3  3  4  4  4  5  5  5  6  6  6  6  7  7  7  7  8
You can see that g(4)=3, and that "4" is repeated 3 times in the sequence.

Given an input of n, output g(n).

Limitations: n < 100000.

Smallest code wins.

*/

package main

import "slices"

func main() {
	tab := []int{1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18, 18, 19}

	x := golomb(len(tab))
	assert(slices.Equal(x[1:], tab))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A001462
func golomb(n int) []int {
	if n < 1 {
		return []int{}
	}

	r := []int{0, 1, 2, 2}
	for i := 3; i < n; i++ {
		for j := 1; j <= r[i]; j++ {
			r = append(r, i)
		}
	}
	return r[:n+1]
}
