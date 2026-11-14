/*

Probability of a Hidden Path Problem
Given: A hidden path π followed by the states States and transition matrix Transition of an HMM (Σ, States, Transition, Emission).

Return: The probability of this path, Pr(π). You may assume that initial probabilities are equal.

Sample Dataset
AABBBAABABAAAABBBBAABBABABBBAABBAAAABABAABBABABBAB
--------
A   B
--------
    A   B
A   0.194   0.806
B   0.273   0.727

Sample Output
5.01732865318e-19

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test([][]float64{
		{0.194, 0.806},
		{0.273, 0.727},
	}, "AABBBAABABAAAABBBBAABBABABBBAABBAAAABABAABBABABBAB", 5.01732865318e-19)

	test([][]float64{
		{0.863, 0.137},
		{0.511, 0.489},
	}, "BBABBBABBAABABABBBAABBBBAAABABABAAAABBBBBAABBABABB", 3.26233331904e-21)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(T [][]float64, s string, r float64) {
	p := prob(T, s)
	fmt.Println(p)
	assert(math.Abs(p-r) < 1e-19)
}

func prob(T [][]float64, s string) float64 {
	p := 0.5
	for i := 1; i < len(s); i++ {
		t0 := s[i-1] - 'A'
		t1 := s[i] - 'A'
		p *= T[t0][t1]
	}
	return p
}
