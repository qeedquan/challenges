/*

Consider a horizontal line with vertical lines centered on the x-axis and placed at gaps of sqrt(2)/2.
For a positive integer n≥3, the first half of the lines have lengths 0, sqrt(2), 2*sqrt(2), 3*sqrt(2), ..., (n - 1)*sqrt(2) and then the second half have lengths (n-2)*sqrt(2),(n-3)*sqrt(2),...,0.

The goal is to find a circle center on the horizontal line so that for every pair of consecutive vertical lines, there exists a circle with that center which fits between them without touching either of them. For example, in the following illustration we can see that if we picked the origin for n=3
 and the center at the origin, it is possible.

https://i.stack.imgur.com/1wHMm.png

For n=4, we can see that the center can't be at the origin.

https://i.stack.imgur.com/W1u9W.png

https://i.stack.imgur.com/W1u9W.png

We instead will need to move the center to the left. If we move the center to -1, then it is just possible.

https://i.stack.imgur.com/Zf0Iz.png

For n=5 a center at -1 doesn't work and neither does -2.

https://i.stack.imgur.com/3XzAR.png

For n=5 the desired output is -3.

Task
Given an integer n≥3, output the largest integer valued circle center x≤0 so that there exists a circle with that center for each pair vertical lines that goes between the vertical lines and doesn't touch them.

*/

package main

import (
	"math"
)

func main() {
	tab := []int{0, -1, -3, -5, -9, -13, -17, -22, -28, -35, -43, -51, -60}
	for i := range tab {
		assert(circle(3+i) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@l4m2

Any counterexample where the longest one isn't bottleneck?

Looks correct. Proof: scale the circle smaller and see how the allowed distance also get smaller

*/

func circle(n int) int {
	r := float64(n*4-2-n*n)/math.Sqrt(8) - 1
	return int(r)
}
