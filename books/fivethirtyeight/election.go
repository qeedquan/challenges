/*

https://research.swtch.com/electoral
https://godplaysdice.blogspot.com/2008/06/fuller-solution-to-tuesdays-electoral.html

fivethirtyeight.com posed the question of how many ways there were to win the electoral college with a minimal set of states,
that is, sets of states that add up to 270 or more votes, but for which removing any state from the set would drop under 270.

*/

package main

func main() {
	assert(solve() == 51_199_463_116_367)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve() int64 {
	votes := [51]int64{
		55, 34, 31, 27, 21, 21, 20, 17, 15, 15,
		15, 13, 12, 11, 11, 11, 11, 10, 10, 10,
		10, 9, 9, 9, 8, 8, 7, 7, 7, 7,
		6, 6, 6, 5, 5, 5, 5, 5, 4, 4,
		4, 4, 4, 3, 3, 3, 3, 3, 3, 3,
		3,
	}

	ways := [400]int64{0: 1}
	for n := 0; n < 51; n++ {
		for v := 270 + votes[n] - 1; v >= votes[n]; v-- {
			ways[v] += ways[v-votes[n]]
		}
	}

	total := int64(0)
	for v := 270; v < 400; v++ {
		total += ways[v]
	}
	return total
}
