/*

In probability theory, a Bernoulli variable is a random variable which has a single parameter p, and is equal to 1 with probability p, and 0 with probability 1−p.

In this challenge, there are a bunch of independent Bernoulli variables with parameters p1,p2,...,pn, and their XOR is calculated. The XOR is 1 if an odd number of variables are 1, and 0 if an even number of variables are 1. Your task is to calculate the probability the XOR is 1.

Test cases
# Format: [p1, p2, ..., pn] -> probability XOR is 1
[0.123] -> 0.123
[0.123, 0.5] -> 0.5
[0, 0, 1, 1, 0, 1] -> 1
[0, 0, 1, 1, 0, 1, 0.5] -> 0.5
[0.75, 0.75] -> 0.375
[0.75, 0.75, 0.75] -> 0.5625
[0.336, 0.467, 0.016, 0.469] -> 0.499350386816
[0.469, 0.067, 0.675, 0.707] -> 0.4961100146
[0.386, 0.224, 0.507, 0.099, 0.742] -> 0.499658027097344
[0.796, 0.019, 0, 1, 0.217] -> 0.338830368
[0.756, 0.924, 0.001, 0.046, 0.962, 0.001, 0.144] -> 0.6291619858201004

Rules

The input list will never be empty, 1≤n.
You can use any reasonable I/O format. Some particular examples:
You can choose whether to take pi or 1−pi.
You can choose whether to output p or 1−p.
You can take the list of probabilities in any reasonable format.
You can take the length of the list as an additional input.
You can take the probabilities as fractions instead of floating-point numbers.
You can assume the probabilities are sorted.
You can take the probabilities as a multiset, or a map from probability to number of appearances.
Your algorithm must in theory output exactly the correct answer, assuming its floating point calculations were perfect. In particular, you can't just simulate a finite number of trials.
Standard loopholes are disallowed.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test([]float64{0.123}, 0.123)
	test([]float64{0.123, 0.5}, 0.5)
	test([]float64{0, 0, 1, 1, 0, 1}, 1)
	test([]float64{0, 0, 1, 1, 0, 1, 0.5}, 0.5)
	test([]float64{0.75, 0.75}, 0.375)
	test([]float64{0.75, 0.75, 0.75}, 0.5625)
	test([]float64{0.336, 0.467, 0.016, 0.469}, 0.499350386816)
	test([]float64{0.469, 0.067, 0.675, 0.707}, 0.4961100146)
	test([]float64{0.386, 0.224, 0.507, 0.099, 0.742}, 0.499658027097344)
	test([]float64{0.796, 0.019, 0, 1, 0.217}, 0.338830368)
	test([]float64{0.756, 0.924, 0.001, 0.046, 0.962, 0.001, 0.144}, 0.6291619858201004)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(p []float64, r float64) {
	x := prob(p)
	fmt.Println(x)
	assert(math.Abs(x-r) < 1e-8)
}

// based on @xnor solution
func prob(p []float64) float64 {
	x := 0.0
	for _, p := range p {
		x += p - 2*p*x
	}
	return x
}
