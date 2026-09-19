/*

The pyramid begins with the row 1 1. We'll call this row 1. For each subsequent row, start with the previous row and insert the current row number between every adjacent pair of numbers that sums to the current row number.

          1 1
         1 2 1
       1 3 2 3 1
     1 4 3 2 3 4 1
 1 5 4 3 5 2 5 3 4 5 1
1 6 5 4 3 5 2 5 3 4 5 6 1

This pyramid is an example of a false pattern. It seems to encode the prime numbers in the lengths of its rows, but the pattern breaks down later on. You may wish to learn more about this sequence from a recent Numberphile video which is the inspiration for this question.

Task
Output the sequence. You may do so in any of the following ways:

Method	Example input	Example output
The infinite sequence as rows. We must be able to tell the rows apart somehow.
    1 1
   1 2 1
  1 3 2 3 1
1 4 3 2 3 4 1
...

The infinite sequence as numbers, top to bottom, left to right.	1 1 1 2 1 1 3...

The first n rows of the pyramid, 1-indexed. We must be able to tell the rows apart somehow.
3
   1 1
  1 2 1
1 3 2 3 1

The first n rows of the pyramid, 0-indexed. We must be able to tell the rows apart somehow.
3
      1 1
     1 2 1
   1 3 2 3 1
 1 4 3 2 3 4 1

The first n numbers in the pyramid, 1-indexed.	4	1 1 1 2
The first n numbers in the pyramid, 0-indexed.	4	1 1 1 2 1
The nth row in the pyramid, 1-indexed.	        2   1 2 1
The nth row in the pyramid, 0-indexed.          2   1 3 2 3 1
The nth number in the pyramid, 1-indexed.       7   3
The nth number in the pyramid, 0-indexed.       7   2

Rules
Please specify which of the above methods your answer uses.
Output format is highly flexible. It may take the form of your language's collection type, for instance.
Sequence rules apply, so infinite output may be in the form of a lazy list or generator, etc.
This is code-golf, so the answer with the fewest bytes (in each language) wins.
Standard loopholes are forbidden.

*/

package main

import (
	"math"
	"slices"
)

func main() {
	tab := []int{1, 1, 1, 2, 1, 1, 3, 2, 3, 1, 1, 4, 3, 2, 3, 4, 1, 1, 5, 4, 3, 5, 2, 5, 3, 4, 5, 1, 1, 6, 5, 4, 3, 5, 2, 5, 3, 4, 5, 6, 1, 1, 7, 6, 5, 4, 7, 3, 5, 7, 2, 7, 5, 3, 7, 4, 5, 6, 7, 1, 1, 8, 7, 6, 5, 4, 7, 3, 8, 5, 7, 2, 7, 5, 8, 3, 7, 4, 5, 6, 7, 8, 1, 1, 9, 8, 7, 6, 5, 9, 4, 7, 3, 8, 5, 7, 9, 2, 9, 7, 5, 8, 3, 7}

	assert(slices.Equal(gen(len(tab)), tab))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func gen(n int) []int {
	r := []int{}
	for i := 0; i < math.MaxInt && len(r) < n; i++ {
		r = append(r, primepyramid(i)...)
	}
	return r[:n]
}

// https://oeis.org/A006843
func primepyramid(n int) []int {
	return recurse(n, 1, 1)
}

func recurse(n, b, d int) []int {
	if n < 1 || d < 0 || b < 0 {
		return []int{}
	}

	if d == 0 || b == 0 || d%b == 1 {
		return []int{1}
	}

	return append([]int{d}, recurse(n, d+n, n-b%d)...)
}
