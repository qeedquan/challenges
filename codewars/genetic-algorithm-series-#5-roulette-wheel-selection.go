/*

The "Roulette wheel selection", also known as "Fitness proportionate selection", is a genetic operator used in genetic algorithms for selecting potentially useful solutions for recombination.

Your task is to implement it.

You throw a coin in and has a chance to fall in one of the slots, the higher the fitness the higher the chance the element has to be selected.

Given the population and fitnesses, your task is to run the roulette to return one element.

Note: Some tests are random. If you think your algorithm is correct but the result fails, trying again should work.

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	fmt.Println(roulette([]int{1, 2, 3}, []float64{0.05, 0.05, 0.90}))
}

func roulette(population []int, fitnesses []float64) (int, bool) {
	probability := rand.Float64()
	for i := range fitnesses {
		if fitnesses[i] > probability {
			return population[i], true
		}
	}
	return 0, false
}
