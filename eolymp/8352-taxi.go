/*

At rush hour, three taxi buses arrived at the stop simultaneously, all following the same route, and passengers immediately boarded them.
The drivers noticed that the number of people in the different buses varied and decided to transfer some passengers so that each bus would have the same number of passengers.
Determine the minimum number of passengers that need to be transferred for this.

Input
Three natural numbers, not exceeding 100 — the number of passengers in the first, second, and third busses, respectively.

Output
Print a single number — the minimum number of passengers that need to be transferred. If this is impossible, print IMPOSSIBLE.

Examples

Input #1
1 2 3

Answer #1
1

*/

package main

func main() {
	assert(solve(1, 2, 3) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b, c int) any {
	if (a+b+c)%3 != 0 {
		return "IMPOSSIBLE"
	}
	m := (a + b + c) / 3
	return (abs(a-m) + abs(b-m) + abs(c-m)) / 2
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
