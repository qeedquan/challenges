/*

Speedcubing is the hobby involving solving a variety of twisty puzzles, the most famous being the 3x3x3 puzzle or Rubik's Cube, as quickly as possible.

In the majority of Speedcubing competitions, a Cuber solves a scrambled cube 5 times, and their result is found by taking the average of the middle 3 solves (ie. the slowest and fastest times are disregarded, and an average is taken of the remaining times).

In some competitions, the unlikely event of a tie situation is resolved by comparing Cuber's fastest times.

Write a function cube_times(times) that, given an array of floats times returns an array / tuple with the Cuber's result (to 2 decimal places) AND their fastest solve.

For example:

cubeTimes([9.5, 7.6, 11.4, 10.5, 8.1]) = [9.37, 7.6]
// Because (9.5 + 10.5 + 8.1) / 3 = 9.37 and 7.6 was the fastest solve.

Note: times will always be a valid array of 5 positive floats (representing seconds)

*/

package main

import (
	"math"
	"slices"
)

func main() {
	test([]float64{9.5, 7.6, 11.4, 10.5, 8.1}, 9.37, 7.6)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(t []float64, r0, r1 float64) {
	const eps = 1e-2
	x0, x1 := cubetimes(t)
	assert(math.Abs(x0-r0) < eps)
	assert(math.Abs(x1-r1) < eps)
}

func cubetimes(t []float64) (float64, float64) {
	t0 := slices.Min(t)
	t1 := slices.Max(t)
	s := 0.0
	for i := range t {
		if t[i] != t0 && t[i] != t1 {
			s += t[i]
		}
	}
	return s / (float64(len(t) - 2)), t0
}
