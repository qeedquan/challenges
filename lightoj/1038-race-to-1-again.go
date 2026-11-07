/*

Rimi learned a new thing about integers, which is - any positive integer greater than 1 can be divided by its divisors. She is playing with this property now in the form of a game.

She first selects a number N. She then randomly chooses a divisor of N (1 to N) and divides N by the number to obtain a new N. She repeats this procedure until N becomes 1. What is the expected number of turns required for Rimi to end the game - meaning N becomes 1?

Input
Input starts with an integer T (≤ 10000), denoting the number of test cases.

Each case begins with an integer N (1 ≤ N ≤ 10^5).

Output
For each case of input you have to print the case number and the expected value. Errors less than 10^-6 will be ignored.

Sample
Input	Output
3
1
2
50

Case 1: 0
Case 2: 2.0
Case 3: 3.0333333333

*/

package main

import "fmt"

func main() {
	fmt.Println(solve(1))
	fmt.Println(solve(2))
	fmt.Println(solve(50))
}

func solve(n int) float64 {
	p := make([]float64, n+1)
	c := make([]float64, n+1)
	for i := 2; i <= n; i++ {
		m := c[i] + 2
		s := (p[i] + m) / (m - 1)
		p[i] = s
		for j := 2 * i; j <= n; j += i {
			c[j] += 1
			p[j] += s
		}
	}
	return p[n]
}
