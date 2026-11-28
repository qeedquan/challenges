/*

We already have studied several random number generators:

Neumann's - very early and extremely poor, quickly entering loops
LCG - quite popular before 2000s era, still very poor
Shift Register Randomizer - major improvement in XXI century
The book "Elementarmathematik vom algorithmischen Standpunkt" 1977 ("Elementary Mathematics from the algorithmic point of view", 1984) by A.Engel suggests yet another generator with very simple description:

X = frac((X + 3.1415926)^8)
I.e. for current random value X we find the next by adding pi, raising to the 8-th power and throwing out integer part (so only fraction in range [0 .. 1) remains).

Actually we use pi shortened to some number of digits after decimal point (and one may guess we can use different "additive" component).

Now, how does this sequence behave? It somewhat resembles Neumann's, but supposedly it doesn't fall into short loops. We may wonter, whether it gives uniform distribution or is it somewhat "skewed" due to usage of steep non-linear function. That is the goal of our experiment.

Problem Statement
Given initial value for X (e.g. "seed"), produce a random sequence according to the formula above. Split the range [0 .. 1) into a number of buckets and count how many values fall into every bucket.

Some issue to care about is that real values tend to be handled slightly differently by various programming languages and hardware. Let's try avoiding discrepancies by truncating values to 7 digits after decimal point on each iteration.

For example, let's start with X = 0.2023 and produce 10 values, spreading them into 10 buckets (e.g. [0 .. 0.1), [0.1 .. 0.2) and so on):

0.1445274   0.7592904   0.1094414   0.7789513   0.524233
0.77205     0.3091387   0.3087502   0.2083622   0.3065843
The resulting distribution is:

0 2 1 3 0 1 0 3 0 0
Input is just 3 values: X0 (for seed), B (for amount of buckets) and T (for "times").
Produce B * T random values (so that ideally every of B buckets should get some value exactly T times).

Answer should give B values, telling real distribution - e.g. how many values fell into every bucket.

Example

input:
0.1928 12 20

answer:
26 23 21 21 19 15 16 15 19 15 29 21

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	sim(0.2023, 10, 1)
	sim(0.1928, 12, 20)
}

func sim(x0 float64, b, t int) {
	x := x0
	h := make([]int, b)
	for range b * t {
		x = rng(x)
		i := int(math.Floor(x * float64(b)))
		h[i] += 1
	}
	fmt.Println(h)
}

func rng(x float64) float64 {
	_, f := math.Modf(math.Pow(x+math.Pi, 8))
	return f
}
