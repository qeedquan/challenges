/*

Lately, feature requests have been piling up and you need a way to make global estimates of the time it would take to implement them all. If you estimate feature A to take 4 to 6 hours to implement, and feature B to take 2 to 5 hours, then in the best case it will only take you 6 (4 + 2) hours to implement both features, and in the worst case it will take you 11 (6 + 5). In the average case, it will take you 8.5 hours.

To help you streamline the estimation process, write a function that returns a tuple (JS: array) of the global best case, average case and worst case given a tuple of tuples (JS: array of arrays) representing best case and worst case guesses.

For example,

estimates = ((1, 2), (3, 4))
global_estimate(estimates) == (4, 5, 6)

Don't worry about rounding or invalid input.qeed@desktop:~/codewars-tasks/Global estimates$

*/

package main

import "fmt"

func main() {
	fmt.Println(globalestimate([][2]int{
		{1, 2},
		{3, 4},
	}))
}

func globalestimate(estimates [][2]int) [3]int {
	best := 0
	worst := 0
	for _, estimate := range estimates {
		best += estimate[0]
		worst += estimate[1]
	}
	return [3]int{best, (best + worst) / 2, worst}
}
