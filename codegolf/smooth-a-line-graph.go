/*

Given an input of an integer n and a list of positive integers m1, m2, ..., output a list of integers m1', m2', ... where mx' is defined as the average of mx-n through mx+n.

When calculating these averages, ignore indices that are out of bounds (and adjust what you are dividing the sum by accordingly). n will always be ≥ 1 but never half of the length of m (rounded down) or more. This means that the minimum length of m is 4. The elements in m will be positive integers, but the output must be accurate to at least 3 decimal places.

The input / output elements that are lists may be either whitespace-/comma-separated strings or arrays/lists/etc. For input, if your solution is a function, you may additionally take a first argument of n and additional arguments as mx (this applies to command line arguments as well).

Here is a visual representation of n=1:

1 4 5 7 10
__/ | | |
L avg(1,4) = 2.5
    | | |
\___/ | |
  L avg(1,4,5) = 3.333
      | |
  \___/ |
    L avg(4,5,7) = 5.333
        |
    \___/
      L avg(5,7,10) = 7.333

      \___
        L avg(7,10) = 8.5

Final output: 2.5 3.333 5.333 7.333 8.5
Since this is code-golf, the shortest code in bytes wins.

Test cases (these were done manually; please notify me of any errors):

In                             Out
----------------------------------------------------------------------
n=1, m=12 6 3 9                9 7 6 6
n=1, m=1 4 5 7 10              2.5 3.333 5.333 7.333 8.5
n=1, m=1 3 3 7 4 2 4 2         2 2.333 4.333 4.666 4.333 3.333 2.666 3
n=2, m=1 3 5 9 10 14 15 16 23  3 4.5 5.6 8.2 10.6 12.8 15.6 17 18
n=3, m=1 1 1 1 1 1 1 1         1 1 1 1 1 1 1 1
n=3, m=1 2 3 4 5 6 7 8         2.5 3 3.5 4 5 5.5 6 6.5

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test([]int{12, 6, 3, 9}, 1, []float64{9, 7, 6, 6})
	test([]int{1, 4, 5, 7, 10}, 1, []float64{2.5, 3.333, 5.333, 7.333, 8.5})
	test([]int{1, 3, 3, 7, 4, 2, 4, 2}, 1, []float64{2, 2.333, 4.333, 4.666, 4.333, 3.333, 2.666, 3})
	test([]int{1, 3, 5, 9, 10, 14, 15, 16, 23}, 2, []float64{3, 4.5, 5.6, 8.2, 10.6, 12.8, 15.6, 17, 18})
	test([]int{1, 1, 1, 1, 1, 1, 1, 1}, 3, []float64{1, 1, 1, 1, 1, 1, 1, 1})
	test([]int{1, 2, 3, 4, 5, 6, 7, 8}, 3, []float64{2.5, 3, 3.5, 4, 5, 5.5, 6, 6.5})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []int, n int, r []float64) {
	const eps = 1e-3
	p := smooth(a, n)
	fmt.Println(p)
	for i := range p {
		assert(math.Abs(p[i]-r[i]) < eps)
	}
}

func smooth(a []int, n int) []float64 {
	r := []float64{}
	for i := range a {
		n0 := max(0, i-n)
		n1 := min(i+n+1, len(a))
		r = append(r, mean(a[n0:n1]))
	}
	return r
}

func mean(a []int) float64 {
	n := len(a)
	if n == 0 {
		return 0
	}

	m := 0
	for _, v := range a {
		m += v
	}
	return float64(m) / float64(n)
}
