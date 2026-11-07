/*

We can arrange the positive integers like this:

1_| 2 | 5 | 10
4___3_| 6 | 11
9___8___7_| 12
16  15  14  13
That is, in L-shaped brackets expanding down and right infinitely.

Then, we can read it off with the antidiagonals:

1 2 5  10
 / /  /
4 3  6  11
 /  /  /
9  8  7  12
  /  /  /
16 15 14  13
For the above, we read 1, then 2, 4, then 5, 3, 9, then 10, 6, 8, 16, and so on.

Your challenge is to output this sequence. Standard sequence rules apply. This is A060736.

This is code-golf, shortest wins!

*/

package main

import "math"

func main() {
	tab := []int{
		1, 2, 4, 5, 3, 9, 10, 6, 8, 16, 17, 11, 7, 15, 25, 26, 18, 12, 14, 24,
		36, 37, 27, 19, 13, 23, 35, 49, 50, 38, 28, 20, 22, 34, 48, 64, 65, 51,
		39, 29, 21, 33, 47, 63, 81, 82, 66, 52, 40, 30, 32, 46, 62, 80, 100,
	}

	for i := range tab {
		assert(seq(i+1) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A060736
func seq(n int) int {
	if n < 1 {
		return 0
	}

	t := int((math.Sqrt(float64(8*n-7)) - 1) / 2)
	i := n - t*(t+1)/2
	j := (t*t+3*t+4)/2 - n
	if i >= j {
		return i*i - j + 1
	}
	return (j-1)*(j-1) + i
}
