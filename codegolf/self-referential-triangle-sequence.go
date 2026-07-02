/*

Output the flattened version of the sequence A297359, which starts like the following:

1, 1, 1, 1, 2, 1, 1, 3, 3, 1, 2, 4, 6, 4, 2, 1, 6, 10, 10, 6, 1,
1, 7, 16, 20, 16, 7, 1, 3, 8, 23, 36, 36, 23, 8, 3, 3, 11, 31, 59,
72, 59, 31, 11, 3, 1, 14, 42, 90, 131, 131, 90, 42, 14, 1,...
----------------
                  1,
                1,   1,
              1,  2,   1,
            1,  3,   3,  1,
          2,  4,  6,   4,  2,
        1,  6,  10, 10,  6,  1,
      1, 7,  16,  20,  16,  7, 1,
    3, 8,  23,  36, 36,  23,  8, 3,
  3, 11, 31, 59,  72,  59, 31, 11, 3,
1, 14, 42, 90, 131, 131, 90, 42, 14, 1,
...
The defining property of the sequence is that

the entire triangle is generated like the Pascal's triangle (i.e. each entry inside the triangle is the sum of the two numbers above it), and
the left and right boundaries are identical to the entire triangle read by rows.
Standard code-golf rules and sequence I/O methods apply. See https://codegolf.stackexchange.com/tags/sequence/info and https://codegolf.stackexchange.com/tags/code-golf/info.

The shortest code in bytes wins.

*/

package main

import (
	"math"
)

func main() {
	tab := []int{1, 1, 1, 1, 2, 1, 1, 3, 3, 1, 2, 4, 6, 4, 2, 1, 6, 10, 10, 6, 1, 1, 7, 16, 20, 16, 7, 1, 3, 8, 23, 36, 36, 23, 8, 3, 3, 11, 31, 59, 72, 59, 31, 11, 3, 1, 14, 42, 90, 131, 131, 90, 42, 14, 1, 2, 15, 56, 132, 221, 262, 221, 132, 56, 15, 2, 4, 17, 71, 188, 353, 483, 483, 353, 188, 71, 17, 4, 6, 21, 88, 259, 541, 836, 966, 836, 541, 259}

	for i := range tab {
		assert(plrsrb(0, i) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A297359
func plrsrb(a, b int) int {
	if a < 0 || b < 0 {
		return 0
	}
	if a == 0 || b == 0 {
		return antidiagonal(max(a, b))
	}
	return plrsrb(a, b-1) + plrsrb(a-1, b)
}

func antidiagonal(x int) int {
	if x < 0 {
		return 0
	}
	if x < 2 {
		return 1
	}
	k := int((math.Sqrt(8*float64(x)+1) - 1) / 2)
	return plrsrb(x-k*(k+1)/2, (k+1)*(k+2)/2-x-1)
}
