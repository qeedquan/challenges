/*

Background
Penney's game is a two-player game about coin tossing. Player A announces a sequence of heads and tails of length n, then player B selects a different sequence of same length.
The winner is the one whose sequence appears first as a substring (consecutive subsequence) in repeated coin toss.

Conway's algorithm describes how to calculate the odds of a single sequence of length n in Penney's game:

For every integer 1≤i≤n, add 2^i if its first i items match the last i items.
The sum is the expected amount of tosses before you will see the exact pattern. For example (all examples being n=6),

HHHHTT: Only matches at i=6, so the expected number of tosses is 64.
TTHHTT: Matches at i=1,2,6, so the expected number of tosses is 2+4+64=70.
HHHHHH: Matches everywhere, so 2+4+8+16+32+64=126.
This generalizes easily to p-sided dice: for each match, add p^i instead.

Task
Suppose we play Penney's game with p-sided dice, where p≥2.
Given the value of p and a sequence of outcomes S as input, calculate the expected tosses before you get the exact pattern S.

The elements of S can be 1…p or 0…p−1.

Standard code-golf rules apply. The shortest code in bytes wins.

Test cases
p  S                            ans
------------------------------------------
2  [0, 0, 0, 0, 1, 1]           64
2  [1, 1, 0, 0, 1, 1]           70
3  [1, 1, 1, 1, 1]              363
9  [0, 1, 2, 3, 4, 5, 6, 7, 8]  387420489

*/

package main

import (
	"slices"
)

func main() {
	assert(pennyconway(2, []int{0, 0, 0, 0, 1, 1}) == 64)
	assert(pennyconway(2, []int{1, 1, 0, 0, 1, 1}) == 70)
	assert(pennyconway(3, []int{1, 1, 1, 1, 1}) == 363)
	assert(pennyconway(9, []int{0, 1, 2, 3, 4, 5, 6, 7, 8}) == 387420489)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func pennyconway(p int, S []int) int {
	return recurse(p, S, 0)
}

func recurse(p int, S []int, i int) int {
	if slices.Equal(S, S[:i]) {
		return 1
	}

	x := 0
	j := len(S) - i
	if i == 0 {
		j = 0
	}
	if slices.Equal(S[:i], S[j:]) {
		x = 1
	}
	return x + p*recurse(p, S, i+1)
}
