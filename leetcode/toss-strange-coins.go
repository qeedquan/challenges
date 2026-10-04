/*

Description

You have some coins. The i-th coin has a probability prob[i] of facing heads when tossed.

Return the probability that the number of coins facing heads equals target if you toss every coin exactly once.

Example 1:

Input: prob = [0.4], target = 1

Output: 0.40000

Example 2:

Input: prob = [0.5,0.5,0.5,0.5,0.5], target = 0

Output: 0.03125

Constraints:

1 <= prob.length <= 1000
0 <= prob[i] <= 1
0 <= target <= prob.length
Answers will be accepted as correct if they are within 10^-5 of the correct answer.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test([]float64{0.4}, 1, 0.4)
	test([]float64{0.5, 0.5, 0.5, 0.5, 0.5}, 0, 0.03125)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []float64, t int, r float64) {
	p := probability(a, t)
	fmt.Println(p)
	assert(math.Abs(p-r) < 1e-5)
}

func probability(a []float64, t int) float64 {
	if t < 0 {
		return 0
	}

	dp := make([]float64, t+1)
	dp[0] = 1

	for _, p := range a {
		for i := t; i >= 0; i-- {
			dp[i] = dp[i] * (1 - p)
			if i > 0 {
				dp[i] += dp[i-1] * p
			}
		}
	}
	return dp[t]
}
