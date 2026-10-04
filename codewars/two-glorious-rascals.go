/*

The Iconic Standoff: A Tale of Three Gunslingers (Lore)
In the classic spaghetti Western "The Good, the Bad and the Ugly" three gunslingers face off in an unforgettable Mexican standoff. Blondie (Clint Eastwood), Angel Eyes (Lee Van Cleef), and Tuco (Eli Wallach) confront each other in a tense, three-way duel over buried Confederate gold. This iconic scene, set in a circular cemetery, has become one of the most famous standoffs in cinema history.

next kata: "The Good, the Bad and the Ugly" (work in progress)

While the film features a thrilling three-way confrontation, our current code challenge serves as a warm-up, focusing on a duel between two opponents. This simplified version draws inspiration from the German title of the movie, "Zwei glorreiche Halunken," which translates to "Two Glorious Rascals".

Problem Description
In this turn-based duel, two gunslingers face off. Unlike the movie's Mexican standoff, they take turns shooting at each other. The first to hit their opponent wins the duel. Each gunslinger has a specific probability of hitting their target:

Person A has a chance p to hit and 1-p to miss.
Person B has a chance q to hit and 1-q to miss.
Your task is to calculate the probability of Person A winning the duel under two scenarios:

Person A shoots first
Person B shoots first
Note: floating points are used instead of fractions/rationals to support more programming languages

Input
p: float (0 ≤ p ≤ 1), Person A's probability of hitting
q: float (0 ≤ q ≤ 1), Person B's probability of hitting
Output
Return a tuple of two floating point numbers, representing:
item 1: float, probability of Person A winning when shooting first
item 2: float, probability of Person A winning when shooting second
Do not round floating point numbers, instead such values get verified using an error margin of 1e-6.
If it can be determined that no shooter ever wins, there is no duel, and you should return null / None (or the equivalent in your programming language).
Example
p = 0.8
q = 0.5

return [0.8888889, 0.4444445]
Footer
May your aim be true and your nerves steady, partner. The sun's high, the air's thick with tension, and your opponent's eyes are locked on you. It's time to see if you're the glorious rascal who walks away from this duel. Good luck!

*/

package main

import (
	"fmt"
	"math"
	"math/rand/v2"
)

func main() {
	test(0.8, 0.5, [2]float64{0.8888889, 0.4444445})
	test(0.5, 0.8, [2]float64{0.5555555555555556, 0.11111111111111109})
	test(1, 0.8, [2]float64{1.0, 0.19999999999999996})
	test(0.8, 1.0, [2]float64{0.8, 0})
	test(1, 1, [2]float64{1, 0})
	test(0.5, 0.5, [2]float64{0.6666666666666666, 0.3333333333333333})
	test(0.1, 0, [2]float64{1, 1})
	test(0.0, 0.1, [2]float64{0, 0})
	test(0, 0, [2]float64{math.NaN(), math.NaN()})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(p, q float64, r [2]float64) {
	x := solvesim(p, q)
	fmt.Println(x, r)
	for i := range x {
		if math.IsNaN(r[i]) {
			assert(math.IsNaN(x[i]))
		} else {
			assert(math.Abs(x[i]-r[i]) < 1e-4)
		}
	}
}

func solvesim(p, q float64) [2]float64 {
	const N = 1e8

	r0 := sim(p, q, N)
	r1 := 1 - sim(q, p, N)
	if math.IsNaN(r0) || math.IsNaN(r1) {
		return [2]float64{math.NaN(), math.NaN()}
	}
	return [2]float64{r0, r1}
}

func sim(p, q float64, n int) float64 {
	if (p < 0 || q < 0) || (p <= 0 && q <= 0) {
		return math.NaN()
	}
	if q <= 0 {
		return 1
	}
	if p <= 0 {
		return 0
	}

	c := 0
loop:
	for range n {
		x, y, i := p, q, 0
		for {
			if rand.Float64() <= x {
				if i == 0 {
					c += 1
				}
				continue loop
			}
			x, y, i = y, x, i^1
		}
	}
	return float64(c) / float64(n)
}
