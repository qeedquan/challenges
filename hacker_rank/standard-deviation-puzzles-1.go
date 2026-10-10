/*

Objective
In this challenge, we practice calculating standard deviation.

Task
Find the largest possible value of N where the standard deviation of the values in the set {1, 2, 3, N} is equal to the standard deviation of the values in the set {1, 2, 3}.

Output the value of N, correct to two decimal places.

Output Format

Your output must be a floating point/decimal number, correct to a scale of 2 decimal places. You can submit solutions in either of the 2 following ways:

Solve the problem manually and submit your result as Plain Text.

Submit an R or Python program, which uses the above parameters (hard-coded), and computes the answer.

Your answer format should resemble something like:

4.23
(This is NOT the answer, just a demonstration of the answering format.)

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Printf("%.2f\n", solve())
}

func solve() float64 {
	const (
		step = 1e-3
		eps  = 1e-4
	)

	x := []float64{1, 2, 3, 0}
	sd0 := stddev(x[:3])
	for ; x[3] < math.MaxFloat64; x[3] += step {
		if sd := stddev(x); math.Abs(sd-sd0) < eps {
			return x[3]
		}
	}
	return -1
}

func mean(x []float64) float64 {
	n := len(x)
	if n == 0 {
		return 0
	}

	r := 0.0
	for i := range x {
		r += x[i]
	}
	return r / float64(n)
}

func stddev(x []float64) float64 {
	n := len(x)
	if n == 0 {
		return 0
	}

	r := 0.0
	xm := mean(x)
	for i := range x {
		r += (x[i] - xm) * (x[i] - xm)
	}
	return math.Sqrt(r / float64(n))
}
