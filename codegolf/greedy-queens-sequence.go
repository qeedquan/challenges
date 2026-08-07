/*

Challenge
Implement the "greedy queens" sequence (OEIS: A065188).

Details
Taken from the OEIS page.

This permutation [of natural numbers] is produced by a simple greedy algorithm: starting from the top left corner, walk along each successive antidiagonal of an infinite chessboard and place a queen in the first available position where it is not threatened by any of the existing queens. In other words, this permutation satisfies the condition that p(i+d)≠p(i)±d for all i and d≥1.

p(n)=k means that a queen appears in column n in row k.

Visualisation

+------------------------
| Q x x x x x x x x x ...
| x x x Q x x x x x x ...
| x Q x x x x x x x x ...
| x x x x Q x x x x x ...
| x x Q x x x x x x x ...
| x x x x x x x x x Q ...
| x x x x x x x x x x ...
| x x x x x x x x x x ...
| x x x x x Q x x x x ...
| ...

Rules
Standard sequence rules apply, so you can:

Take an index n and output the nth term, either 0 or 1 indexing.
Take a positive integer n and output the first n terms.
Output whole sequence as an infinite list.
This is code-golf, so shortest answer (per language) wins!

Test cases
First 70 terms:

1, 3, 5, 2, 4, 9, 11, 13, 15, 6, 8, 19, 7, 22, 10, 25, 27, 29, 31, 12, 14, 35, 37, 39, 41, 16, 18, 45, 17, 48, 20, 51, 53, 21, 56, 58, 60, 23, 63, 24, 66, 28, 26, 70, 72, 74, 76, 78, 30, 32, 82, 84, 86, 33, 89, 34, 92, 38, 36, 96, 98, 100, 102, 40, 105, 107, 42, 110, 43, 113
(See also: https://oeis.org/A065188/b065188.txt)

*/

package main

import (
	"math"
)

func main() {
	tab := []int{1, 3, 5, 2, 4, 9, 11, 13, 15, 6, 8, 19, 7, 22, 10, 25, 27, 29, 31, 12, 14, 35, 37, 39, 41, 16, 18, 45, 17, 48, 20, 51, 53, 21, 56, 58, 60, 23, 63, 24, 66, 28, 26, 70, 72, 74, 76, 78, 30, 32, 82, 84, 86, 33, 89, 34, 92, 38, 36, 96, 98, 100, 102, 40, 105, 107, 42, 110, 43, 113}

	for i := range tab {
		assert(greedyqueens(i) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

var cache = make(map[int]int)

// https://oeis.org/A065188
func greedyqueens(n int) int {
	if n < 0 {
		return 0
	}
	if r, ok := cache[n]; ok {
		return r
	}

loop:
	for i := 1; i < math.MaxInt; i++ {
		for m := range n {
			d := abs(i - greedyqueens(m))
			if d == 0 || n-m == d {
				continue loop
			}
		}
		cache[n] = i
		return i
	}
	return -1
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
