/*

Complete the function, which calculates how much you need to tip based on the total amount of the bill and the service.

You need to consider the following ratings:

Terrible: tip 0%
Poor: tip 5%
Good: tip 10%
Great: tip 15%
Excellent: tip 20%
The rating is case insensitive (so "great" = "GREAT"). If an unrecognised rating is received, then you need to return:

"Rating not recognised" in Javascript, Python and Ruby...
...or null in Java
...or -1 in C#
Because you're a nice person, you always round up the tip, regardless of the service.

*/

package main

import (
	"math"
	"strings"
)

func main() {
	assert(tip(30, "poor") == 2)
	assert(tip(20, "Excellent") == 4)
	assert(tip(20, "hi") == -1)
	assert(tip(107.65, "GReat") == 17)
	assert(tip(20, "Excellent") == 4)
	assert(tip(20, "great!") == -1)
	assert(tip(26.95, "good") == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func tip(amount float64, rating string) int {
	rates := map[string]float64{
		"terrible":  .0,
		"poor":      .05,
		"good":      .1,
		"great":     .15,
		"excellent": .2,
	}
	rate, found := rates[strings.ToLower(rating)]
	if !found {
		return -1
	}
	return int(math.Ceil(amount * rate))
}
