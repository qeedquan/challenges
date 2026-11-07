/*

You are standing at position 0 on an infinite number line. There is a destination at position target.

You can make some number of moves numMoves so that:

On each move, you can either go left or right.
During the ith move (starting from i == 1 to i == numMoves), you take i steps in the chosen direction.
Given the integer target, return the minimum number of moves required (i.e., the minimum numMoves) to reach the destination.

Example 1:

Input: target = 2
Output: 3
Explanation:
On the 1st move, we step from 0 to 1 (1 step).
On the 2nd move, we step from 1 to -1 (2 steps).
On the 3rd move, we step from -1 to 2 (3 steps).
Example 2:

Input: target = 3
Output: 2
Explanation:
On the 1st move, we step from 0 to 1 (1 step).
On the 2nd move, we step from 1 to 3 (2 steps).

Constraints:

-10^9 <= target <= 10^9
target != 0

*/

package main

import "math"

func main() {
	tab := []int{
		0, 1, 3, 2, 3, 5, 3, 5, 4, 5, 4, 5, 7, 5, 7, 5, 7, 6, 7, 6, 7, 6, 7, 9,
		7, 9, 7, 9, 7, 9, 8, 9, 8, 9, 8, 9, 8, 9, 11, 9, 11, 9, 11, 9, 11, 9,
		11, 10, 11, 10, 11, 10, 11, 10, 11, 10, 11, 13, 11, 13, 11, 13, 11, 13,
		11, 13, 11, 13, 12, 13, 12, 13, 12, 13, 12, 13, 12, 13, 12, 13, 15, 13,
		15, 13,
	}

	for i := range tab {
		assert(reach(i) == tab[i])
	}

	assert(reach(2) == 3)
	assert(reach(3) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A140358
func reach(n int) int {
	if n < 0 {
		return 0
	}

	n = abs(n)
	k := int(math.Ceil((math.Sqrt(1+8*float64(n)) - 1) / 2))
	n -= k * (k + 1) / 2
	if n&1 == 0 {
		return k
	}
	return k + 1 + (k & 1)
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
