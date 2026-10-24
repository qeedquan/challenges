/*

Let's recall an old arithmetic problem.

A flock of geese was flying when a lone goose met them. "Greetings, 100 geese," said the goose. The leader of the flock replied: "There are not 100 of us. If our number were doubled, then increased by half, then by a quarter, and finally, with you joining us, we would be 100. How many geese are in the flock?"

You probably know the answer: there were 36 geese. Let's make the problem a bit more complicated.

A flock of geese was flying, and a lone goose approached them. "Greetings, N geese," said the goose. The leader of the flock replied: "There are not N of us. If our number were doubled, then increased by half, then by a quarter, and with you, goose, joining us, then there would be N." You are given a natural number N. You need to answer: how many geese are in the flock?

Input
The input contains a single natural number N (1≤N≤2⋅10^9).

Output
If for the given N it is possible to find a positive integer number of geese in the flock, output this number. Otherwise, output -1.

Examples

Input #1
100

Answer #1
36

*/

package main

func main() {
	assert(solve(100) == 36)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int) int {
	y := 4*n - 4
	if y%11 == 0 && n != 1 {
		return y / 11
	}
	return -1
}
