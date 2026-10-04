/*

Vasya has become interested in creating new sequences and studying them.
This time, he wrote the following sequence on the board: 1 2 3 2 3 4 3 4 5 4 5 6 5 6 7 ...
Vasya wants to know at which position the number k appears for the first time in this sequence.

Write a program that answers his question.

Input
You are given a natural number k (1≤k≤100).

Output
Output a single number — the position where the number k appears for the first time. The elements of the sequence are numbered starting from one.

Examples
Input #1
1

Answer #1
1

*/

package main

import (
	"math"
)

func main() {
	tab := []int{
		1, 0, 1, 2, 1, 2, 3, 2, 3, 4, 3, 4, 5, 4, 5, 6, 5, 6, 7, 6, 7, 8, 7, 8,
		9, 8, 9, 10, 9, 10, 11, 10, 11, 12, 11, 12, 13, 12, 13, 14, 13, 14, 15,
		14, 15, 16, 15, 16, 17, 16, 17, 18, 17, 18, 19, 18, 19, 20, 19, 20, 21,
		20, 21, 22, 21, 22, 23, 22, 23, 24, 23, 24, 25, 24, 25, 26, 25, 26, 27,
		26, 27, 28,
	}

	for i := range tab {
		assert(seq(i) == tab[i])
	}

	assert(solve(1) == 1)
	assert(solve(2) == 2)
	assert(solve(3) == 3)
	assert(solve(4) == 6)
	assert(solve(5) == 9)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int) int {
	if n < 1 {
		return -1
	}
	for i := range math.MaxInt {
		if seq(i+4) == n {
			return i + 1
		}
	}
	return -1
}

// https://oeis.org/A008611
func seq(n int) int {
	if n < 0 {
		return 0
	}
	if n == 0 {
		return 1
	}
	return (n - 1) - 2*((n-1)/3)
}
