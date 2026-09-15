/*

A teacher always finds the greatest satisfaction when their students surpass them.

Around the world, there are many holidays, some of which are not well known.
Among these is Groundhog Day, although after the release of the movie with the same name, it is hard to call it unknown.
The Spring Equinox and Winter Solstice are also hard to call little known, especially after the introduction of daylight saving time and the annual challenges of adjusting to a new schedule. Here is another holiday: Random Acts of Kindness Day!
This is truly a little-known holiday (at least until the creation of this problem), and everyone celebrates it on their own day.
But since there are only 365 days in a year (ignoring leap years), sometimes this holiday might coincide for two different people,
and if they happen to be together on that day, it may bring truly happy moments to the people around them, but only for one day…

For Anton and Vitaliy, their next shared Random Acts of Kindness Day occurred during the "Winter Programming School 2011" in Kharkiv.
They decided to mark this coincidence with simple problems for the school's participants.
They saved one of these problems, as even on that day it seemed too simple to them. We decided to reveal this "hidden" problem.

So, here it is: "Find the sum of all distinct natural numbers from L to R inclusive."

Input
The only line of the input contains two integers L and R (1≤L≤R≤10^9).

Output
Output a single number: the answer to the problem.

Examples

Input #1
2 5

Answer #1
14

*/

package main

func main() {
	assert(solve(2, 5) == 14)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(l, r int) int {
	return sum(r) - sum(l-1)
}

func sum(n int) int {
	return (2 + (n - 1)) * n / 2
}
