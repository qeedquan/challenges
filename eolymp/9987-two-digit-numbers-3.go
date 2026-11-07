/*

Calculate the sum of all two-digit numbers where the digits are in descending order and their sum equals m.

Input
A natural number m, 0≤m≤20.

Output
A single integer representing the solution to the problem.

Examples

Input #1
3

Answer #1
51

Input #2
0

Answer #2
0

*/

package main

func main() {
	assert(solve(3) == 51)
	assert(solve(0) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(m int) int {
	r := 0
	for i := 1; i <= 9; i++ {
		for j := i - 1; j >= 0; j-- {
			n := i*10 + j
			if digsum(n) == m {
				r += n
			}
		}
	}
	return r
}

func digsum(n int) int {
	r := 0
	for ; n > 0; n /= 10 {
		r += n % 10
	}
	return r
}
