/*

Introduction
Say you have a population of people. This population is made up of 100 Alices and 25 Bobs. So, 80% of the population are Alices and 20% are Bobs. We want to change the proportional makeup of the population to be 62% Alices and 38% Bobs.

Rules
You can only add to the population. You cannot take any away from the starting population.

You can only add in multiples of the original subpopulation size. So following the above example, you can only add batches of 100 Alices to the group; likewise, you can only add batches of 25 Bobs to the group.

You have a pool of unlimited Alices and Bobs that are not in the population yet.

The algorithm must be able to handle N different name groups (e.g. N=4: Alice, Bob, Carol, David).

Pseudocode framework
# 100 Alices, 25 Bobs, 35 Carols, 60 Davids
starting_population = (100, 25, 35, 60)

# Goal percentages, must sum to 100
reproportion_goal = (10, 20, 30, 40)

# Reproportion the population to meet the goal percentages, following the rules
new_population = reproportion_population(starting_population, reproportion_goal)
Winner
Create an algorithm to re-proportion the population following the rules with an arbitrary starting_population and reproportion_goal.

The winning algorithm will solve the above-quoted problem in the fastest time on a single-core single-CPU i686 system with fixed clock speed. The algorithm must also solve other reasonable cases through the same code-path. That is, do not special-case for the example data.

I will use many thousands of iterations to test the timing of the approach. VM/runtime startup times will not be counted. The algorithm will be warmed up before timing starts. You can specify the specific version of framework you would like me to run your code under, and if I can reasonably set it up, I will.

Introduction
Say you have a population of people. This population is made up of 100 Alices and 25 Bobs. So, 80% of the population are Alices and 20% are Bobs. We want to change the proportional makeup of the population to be 62% Alices and 38% Bobs.

Rules
You can only add to the population. You cannot take any away from the starting population.

You can only add in multiples of the original subpopulation size. So following the above example, you can only add batches of 100 Alices to the group; likewise, you can only add batches of 25 Bobs to the group.

You have a pool of unlimited Alices and Bobs that are not in the population yet.

The algorithm must be able to handle N different name groups (e.g. N=4: Alice, Bob, Carol, David).

Pseudocode framework
# 100 Alices, 25 Bobs, 35 Carols, 60 Davids
starting_population = (100, 25, 35, 60)

# Goal percentages, must sum to 100
reproportion_goal = (10, 20, 30, 40)

# Reproportion the population to meet the goal percentages, following the rules
new_population = reproportion_population(starting_population, reproportion_goal)
Winner
Create an algorithm to re-proportion the population following the rules with an arbitrary starting_population and reproportion_goal.

The winning algorithm will solve the above-quoted problem in the fastest time on a single-core single-CPU i686 system with fixed clock speed. The algorithm must also solve other reasonable cases through the same code-path. That is, do not special-case for the example data.

I will use many thousands of iterations to test the timing of the approach. VM/runtime startup times will not be counted. The algorithm will be warmed up before timing starts. You can specify the specific version of framework you would like me to run your code under, and if I can reasonably set it up, I will.

*/

package main

import "fmt"

func main() {
	fmt.Println(reproportion([]int{1, 2, 31, 4}, []int{25, 25, 40, 10}))
}

// Based on @fgsfdsfgts algorithm
func reproportion(start, goal []int) []int {
	unit := 1
	for i := range start {
		unit *= start[i]
	}

	var result []int
	for i := range goal {
		result = append(result, goal[i]*unit)
	}

	return result
}
