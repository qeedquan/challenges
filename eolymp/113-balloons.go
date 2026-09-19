/*

A balloon seller has n balloons.
Each balloon is of a certain color.
Recently, a new law was passed that balloons can only be sold in a single color.
To comply with the law and avoid losing profit, the seller decided to repaint some of the balloons.

Write a program to determine the minimum number of repaintings needed so that all balloons are the same color.

Input
The first line contains the number of balloons n (1≤n≤10^5).

The second line contains n integers from 1 to 9 — the colors of the balloons:1 — blue2 — green3 — light blue4 — red5 — pink6 — yellow7 — gray8 — black9 — white

Output
Output the minimum number of balloons that must be repainted so that all balloons are the same color.

Examples

Input #1
4
3 1 2 1

Answer #1
2

Input #2
4
4 9 9 6

Answer #2
2

Input #9
1
1

Answer #9
0

*/

package main

func main() {
	assert(solve([]int{3, 1, 2, 1}) == 2)
	assert(solve([]int{4, 9, 9, 6}) == 2)
	assert(solve([]int{1, 1}) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(balloons []int) int {
	count := make(map[int]int)
	maximum := 0
	for _, balloon := range balloons {
		count[balloon] += 1
		maximum = max(maximum, count[balloon])
	}
	return len(balloons) - maximum
}
