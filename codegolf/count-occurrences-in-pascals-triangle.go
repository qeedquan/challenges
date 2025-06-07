/*

Pascal's triangle is a triangular diagram where the values of two numbers added together produce the one below them.

This is the start of it:

    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1
You can see that the outside is all 1s, and each number is the sum of the two above it. This continues forever.

Your challenge is to count the number of times a value >1
 appears in Pascal's triangle.

For example, with the value 6:

       1
      1 1
     1 2 1
   1  3 3  1
  1 4  6  4 1
 1 5 10  10 5 1
1 6 15 20 15 6 1
It occurs three times. It will never occur more because after this, all numbers other than 1s will be greater than it.

As pointed out by tsh, this is A003016.

Scoring
This is code-golf, shortest wins!

Testcases
2 => 1
4 => 2
6 => 3
10 => 4
28 => 4
20 => 3
120 => 6

*/

package main

import (
	"math"
)

func main() {
	tab := []int{0, 3, 1, 2, 2, 2, 3, 2, 2, 2, 4, 2, 2, 2, 2, 4, 2, 2, 2, 2, 3, 4, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}

	for i := range tab {
		assert(count(i) == tab[i])
	}
	assert(count(120) == 6)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A003016
func count(n int) int {
	switch {
	case n < 1:
		return 0
	case n == 1:
		return 3
	case n == 2:
		return 1
	case n == 3:
		return 2
	}

	x := 2
	k := 2
	r := isqrt(2*n) + 1
	c := r * (r - 1) / 2
	for {
		for c < n && k < r/2 {
			c *= r - k
			k += 1
			c /= k
		}

		if c == n {
			x += 2
			if r == 2*k {
				x -= 1
			}
		}

		if k >= r/2 {
			return x
		}

		c = c * (r - k) / r
		r -= 1
	}
}

func isqrt(x int) int {
	return int(math.Sqrt(float64(x)))
}
