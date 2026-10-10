/*

After the second round of programming contests, the Olympiad participants decided to celebrate the event.
For this purpose, a large rectangular cake was ordered.
The participants gathered around a round table.
Naturally, they wondered: is it possible to put a rectangular cake on the round table so that no part of the cake extends beyond the edge of the table?
You are given the size of the cake and the radius of the table.

Input
The input contains three positive integers: the table radius r (1≤r≤1000), the cake width w, and the cake length l (1≤w≤l≤1000).

Output
Print YES if the cake can be placed on the table, or NO otherwise.

Examples

Input #1
38 40 60

Answer #1
YES

Input #2
35 20 70

Answer #2
NO

Input #3
50 60 80

Answer #3
YES

*/

package main

func main() {
	assert(solve(38, 40, 60) == "YES")
	assert(solve(35, 20, 70) == "NO")
	assert(solve(50, 60, 80) == "YES")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(r, w, l int) string {
	if sqr(2*r) >= sqr(w)+sqr(l) {
		return "YES"
	}
	return "NO"
}

func sqr(x int) int {
	return x * x
}
