/*

Pascal's Rhombus (which is actually a triangle) is obtained by adding in the pattern:

  *
 ***
  x
instead of

* *
 x

 This means that each cell is the sum of the three cells on the row directly above it and one cell on the row 2 above it. Just like Pascal's triangle the zeroth row has a single 1 on it that generates the triangle.

Here are the first couple of rows of Pascal's Rhombus

      1
    1 1 1
  1 2 4 2 1
1 3 8 9 8 3 1

Task
Given a row number (starting from the top) and an column number (starting from the first non-zero item on that row) output the value at that particular cell. Both inputs may be either 1 or 0 indexed (you may mix and match if you desire).

This is code-golf so you should aim to make the file size of your source code as a small as possible.

OEIS A059317

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	table(4)
}

// https://oeis.org/A059317
func T(n, k int) int {
	if k < 0 || k > 2*n {
		return 0
	}
	if k == 0 || k == 2*n {
		return 1
	}
	return T(n-1, k-2) + T(n-1, k-1) + T(n-1, k) + T(n-2, k-2)
}

func table(n int) {
	for i := 0; i < n; i++ {
		fmt.Printf("%s", strings.Repeat(" ", 2*(n-i)))
		for j := 0; j <= 2*i; j++ {
			fmt.Printf("%d ", T(i, j))
		}
		fmt.Println()
	}
}
