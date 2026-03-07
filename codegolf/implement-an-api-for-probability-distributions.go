/*

Introduction
In this challenge, your task is to implement a collection of simple functions that together form a usable mini-library for simple probability distributions. To accommodate some of the more esoteric languages people like to use here, the following implementations are acceptable:

A code snippet defining a collection of named functions (or closest equivalents).
A collection of expressions that evaluate to named or anonymous functions (or closest equivalents).
A single expression that evaluates to several named or anonymous functions (or closest equivalents).
A collection of independent programs that take inputs from command line, STDIN or closest equivalent, and output to STDOUT or closest equivalent.
The functions
You shall implement the following functions, using shorter names if desired.

uniform takes as input two floating point numbers a and b, and returns the uniform distribution on [a,b]. You can assume that a < b; the case a ≥ b is undefined.
blend takes as inputs three probability distributions P, Q and R. It returns a probability distribution S, which draws values x, y and z from P, Q and R, respectively, and yields y if x ≥ 0, and z if x < 0.
over takes as input a floating point number f and a probability distribution P, and returns the probability that x ≥ f holds for a random number x drawn from P.
For reference, over can be defined as follows (in pseudocode):

over(f, uniform(a, b)):
    if f <= a: return 1.0
    else if f >= b: return 0.0
    else: return (b - f)/(b - a)

over(f, blend(P, Q, R)):
    p = over(0.0, P)
    return p*over(f, Q) + (1-p)*over(f, R)
You can assume that all probability distributions given to over are constructed using uniform and blend, and that the only thing a user is going to do with a probability distribution is to feed it to blend or over. You can use any convenient datatype to represent the distributions: lists of numbers, strings, custom objects, etc. The only important thing is that the API works correctly. Also, your implementation must be deterministic, in the sense of always returning the same output for the same inputs.

Test cases
Your output values should be correct to at least two digits after the decimal point on these test cases.

over(4.356, uniform(-4.873, 2.441)) -> 0.0
over(2.226, uniform(-1.922, 2.664)) -> 0.09550806803314438
over(-4.353, uniform(-7.929, -0.823)) -> 0.49676329862088375
over(-2.491, uniform(-0.340, 6.453)) -> 1.0
over(0.738, blend(uniform(-5.233, 3.384), uniform(2.767, 8.329), uniform(-2.769, 6.497))) -> 0.7701533851999125
over(-3.577, blend(uniform(-3.159, 0.070), blend(blend(uniform(-4.996, 4.851), uniform(-7.516, 1.455), uniform(-0.931, 7.292)), blend(uniform(-5.437, -0.738), uniform(-8.272, -2.316), uniform(-3.225, 1.201)), uniform(3.097, 6.792)), uniform(-8.215, 0.817))) -> 0.4976245638164541
over(3.243, blend(blend(uniform(-4.909, 2.003), uniform(-4.158, 4.622), blend(uniform(0.572, 5.874), uniform(-0.573, 4.716), blend(uniform(-5.279, 3.702), uniform(-6.564, 1.373), uniform(-6.585, 2.802)))), uniform(-3.148, 2.015), blend(uniform(-6.235, -5.629), uniform(-4.647, -1.056), uniform(-0.384, 2.050)))) -> 0.0
over(-3.020, blend(blend(uniform(-0.080, 6.148), blend(uniform(1.691, 6.439), uniform(-7.086, 2.158), uniform(3.423, 6.773)), uniform(-1.780, 2.381)), blend(uniform(-1.754, 1.943), uniform(-0.046, 6.327), blend(uniform(-6.667, 2.543), uniform(0.656, 7.903), blend(uniform(-8.673, 3.639), uniform(-7.606, 1.435), uniform(-5.138, -2.409)))), uniform(-8.008, -0.317))) -> 0.4487803553043079

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(
		over(4.356, uniform(-4.873, 2.441)),
		0,
	)

	test(
		over(2.226, uniform(-1.922, 2.664)),
		0.09550806803314438,
	)

	test(
		over(-4.353, uniform(-7.929, -0.823)),
		0.49676329862088375,
	)

	test(
		over(-2.491, uniform(-0.340, 6.453)),
		1.0,
	)

	test(
		over(0.738, blend(uniform(-5.233, 3.384), uniform(2.767, 8.329), uniform(-2.769, 6.497))),
		0.7701533851999125,
	)

	test(
		over(-3.577, blend(uniform(-3.159, 0.070), blend(blend(uniform(-4.996, 4.851), uniform(-7.516, 1.455), uniform(-0.931, 7.292)), blend(uniform(-5.437, -0.738), uniform(-8.272, -2.316), uniform(-3.225, 1.201)), uniform(3.097, 6.792)), uniform(-8.215, 0.817))),
		0.4976245638164541,
	)

	test(
		over(3.243, blend(blend(uniform(-4.909, 2.003), uniform(-4.158, 4.622), blend(uniform(0.572, 5.874), uniform(-0.573, 4.716), blend(uniform(-5.279, 3.702), uniform(-6.564, 1.373), uniform(-6.585, 2.802)))), uniform(-3.148, 2.015), blend(uniform(-6.235, -5.629), uniform(-4.647, -1.056), uniform(-0.384, 2.050)))),
		0,
	)

	test(
		over(-3.020, blend(blend(uniform(-0.080, 6.148), blend(uniform(1.691, 6.439), uniform(-7.086, 2.158), uniform(3.423, 6.773)), uniform(-1.780, 2.381)), blend(uniform(-1.754, 1.943), uniform(-0.046, 6.327), blend(uniform(-6.667, 2.543), uniform(0.656, 7.903), blend(uniform(-8.673, 3.639), uniform(-7.606, 1.435), uniform(-5.138, -2.409)))), uniform(-8.008, -0.317))),
		0.4487803553043079,
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x, y float64) {
	const eps = 1e-12
	fmt.Println(x)
	assert(math.Abs(x-y) < eps)
}

type PDF func(float64) float64

func uniform(a, b float64) PDF {
	return func(x float64) float64 {
		if x >= b {
			return 0
		}
		return min(1, (b-x)/(b-a))
	}
}

func blend(P, Q, R PDF) PDF {
	return func(x float64) float64 {
		return P(0)*(Q(x)-R(x)) + R(x)
	}
}

func over(f float64, P PDF) float64 {
	return P(f)
}
