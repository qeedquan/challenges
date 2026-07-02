/*

Objective
In this challenge, we practice calculating probability. Check out the Tutorial tab for a breakdown of probability fundamentals!

Task
In a single toss of 2 fair (evenly-weighted) six-sided dice, find the probability that their sum will be at most 9.

*/

package main

import "fmt"

func main() {
	fmt.Println(solve(9))
}

func solve(s int) (int, int) {
	n := 0
	d := 6
	for i := 1; i <= d; i++ {
		for j := 1; j <= d; j++ {
			if i+j <= s {
				n += 1
			}
		}
	}
	l := gcd(n, d*d)
	return n / d, (d * d) / l
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}
