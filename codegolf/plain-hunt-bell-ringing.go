/*

Your task is to create a plain hunt (a bell ringing pattern) with n bells. An example with 6 bells:

123456
214365
241635
426153
462513
645231
654321
563412
536142
351624
315264
132546
123456
Each number "bounces" off the side of the grid. From Wikipedia:

Each bell moves one position at each succeeding change, unless they reach the first or last position, when they remain there for two changes then proceed to the other end of the sequence.

In other words, you swap the bells in adjacent pairs, alternating between taking pairs starting from the the first bell and from the second bell. (Thanks to @xnor for this explanation.) You finish in the same order as the start.

This rule be applied to any number of bells, taken as input. Standard loopholes are forbidden.

Test Cases
6

123456
214365
241635
426153
462513
645231
654321
563412
536142
351624
315264
132546
123456
3

123
213
231
321
312
132
123
2

12
21
21
12
1

1
0: Falls in to "I don't care" situation.

*/

package main

import "fmt"

func main() {
	for i := range 7 {
		solve(i)
	}
}

// ported from @Chas Brown solution
func solve(n int) {
	fmt.Printf("n=%d\n", n)
	if n < 1 {
		return
	}

	x := make([]int, n)
	for i := range x {
		x[i] = i + 1
	}

	for k := range n*2 - 2/n + 1 {
		fmt.Println(x)
		for i := k % 2; i < n-1; i += 2 {
			x[i], x[i+1] = x[i+1], x[i]
		}
	}
	fmt.Println()
}
