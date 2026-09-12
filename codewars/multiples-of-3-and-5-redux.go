/*

The galactic games have begun!
It's the galactic games! Beings of all worlds come together to compete in several interesting sports, like nroogring, fredling and buzzing (the beefolks love the last one). However, there's also the traditional marathon run.

Unfortunately, there have been cheaters in the last years, and the committee decided to place sensors on the track. Committees being committees, they've come up with the following rule:

A sensor should be placed every 3 and 5 meters from the start, e.g. at 3m, 5m, 6m, 9m, 10m, 12m, 15m, 18m….

Since you're responsible for the track, you need to buy those sensors. Even worse, you don't know how long the track will be! And since there might be more than a single track, and you can't be bothered to do all of this by hand, you decide to write a program instead.

Task
Return the sum of the multiples of 3 and 5 below a number. Being the galactic games, the tracks can get rather large, so your solution should work for really large numbers (greater than 1,000,000).

Examples
solution (10) # => 23 = 3 + 5 + 6 + 9
solution (20) # => 78 = 3 + 5 + 6 + 9 + 10 + 12 + 15 + 18

*/

package main

func main() {
	assert(solve(10) == 23)
	assert(solve(20) == 78)
	assert(solve(100) == 2318)
	assert(solve(200) == 9168)
	assert(solve(1000) == 233168)
	assert(solve(10000) == 23331668)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int) int {
	if n--; n < 1 {
		return 0
	}

	n3 := n / 3
	n5 := n / 5
	n15 := n / 15
	return (3*n3*(n3+1) + 5*n5*(n5+1) - 15*n15*(n15+1)) / 2
}
