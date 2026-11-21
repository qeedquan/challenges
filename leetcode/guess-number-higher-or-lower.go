/*

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns three possible results:

-1: Your guess is higher than the number I picked (i.e. num > pick).
1: Your guess is lower than the number I picked (i.e. num < pick).
0: your guess is equal to the number I picked (i.e. num == pick).

Return the number that I picked.


Example 1:

Input: n = 10, pick = 6
Output: 6
Example 2:

Input: n = 1, pick = 1
Output: 1
Example 3:

Input: n = 2, pick = 1
Output: 1


Constraints:

1 <= n <= 2^31 - 1
1 <= pick <= n

*/

package main

import (
	"sort"
)

func main() {
	assert(guess(10, mknum(6)) == 6)
	assert(guess(1, mknum(1)) == 1)
	assert(guess(2, mknum(1)) == 1)
	assert(guess(2e5, mknum(1e4)) == 1e4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func guess(n int, f func(int) int) int {
	return sort.Search(n, func(i int) bool {
		return f(i) <= 0
	})
}

func mknum(n int) func(int) int {
	return func(i int) int {
		switch {
		case i > n:
			return -1
		case i == n:
			return 0
		default:
			return 1
		}
	}
}
