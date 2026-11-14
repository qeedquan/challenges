/*

Output the Nth term of the Van Eck Sequence.

Van Eck Sequence is defined as:

Starts with 0.
If the last term is the first occurrence of that term the next term is 0.
If the last term has occurred previously the next term is how many steps back was the most recent occurrence.
https://oeis.org/A181391

https://www.youtube.com/watch?v=etMJxB-igrc

https://www.youtube.com/watch?v=8VrnqRU7BVU

Sequence: 0,0,1,0,2,0,2,2,1,6,0,5,0,2,...

Tests:

Input | Output

1 | 0
8 | 2
19 | 5
27 | 9
52 | 42
64 | 0
EDIT

1 indexed is preferred, 0 indexed is acceptable; that might change some of the already submitted solutions.

Just the Nth term please.

Same (except for the seeing it already posted part), it seems code golfers and numberphile watchers have a decent overlap.

*/

package main

import (
	"math"
	"slices"
)

func main() {
	tab := []int{0, 0, 1, 0, 2, 0, 2, 2, 1, 6, 0, 5, 0, 2, 6, 5, 4, 0, 5, 3, 0, 3, 2, 9, 0, 4, 9, 3, 6, 14, 0, 6, 3, 5, 15, 0, 5, 3, 5, 2, 17, 0, 6, 11, 0, 3, 8, 0, 3, 3, 1, 42, 0, 5, 15, 20, 0, 4, 32, 0, 3, 11, 18, 0, 4, 7, 0, 3, 7, 3, 2, 31, 0, 6, 31, 3, 6, 3, 2, 8, 33, 0, 9, 56, 0, 3, 8, 7, 19, 0, 5, 37, 0, 3, 8, 8, 1}

	assert(slices.Equal(vaneck(len(tab)), tab))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A181391
func vaneck(n int) []int {
	if n < 1 {
		return []int{}
	}

	r := []int{0, 0}
loop:
	for i := 1; i < math.MaxInt && len(r) < n; i++ {
		for j := i - 1; j >= 0; j-- {
			if r[i] == r[j] {
				r = append(r, i-j)
				continue loop
			}
		}
		r = append(r, 0)
	}
	return r[:n]
}
