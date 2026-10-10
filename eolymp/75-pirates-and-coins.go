/*

n pirates divided a treasure of m gold coins fairly: each pirate received their share according to rank and seniority.
The youngest pirate took a coins, and each subsequent pirate took one more coin than the previous pirate.
The last pirate was the captain, who received twice as many coins as was initially planned for him.
After the captain, there were no coins left.

Input
The input contains two integers a and m (1≤a≤100, m<15150). All input data are valid.

Output
Output the number of pirates n.

Examples

Input #1
5 25

Answer #1
3

*/

package main

import "math"

func main() {
	assert(solve(5, 25) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, m int) int {
	d := sqr(2*a+1) - 4*(2*a-2-2*m)
	n := (math.Sqrt(float64(d)) - float64(2*a) - 1) / 2
	return int(n)
}

func sqr(x int) int {
	return x * x
}
