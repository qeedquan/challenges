package main

import (
	"fmt"
	"slices"
)

func main() {
	fmt.Println(solve([]int{26, 25, 2, 21}, []int{35, 25, 23, 24}))
	fmt.Println(solve([]int{20}, []int{30, 40}))
	fmt.Println(solve([]int{5, 5, 10, 15}, []int{20, 18}))
}

func solve(bachelors, spinsters []int) (int, int) {
	if len(bachelors) <= len(spinsters) {
		return 0, 0
	}
	return len(bachelors) - len(spinsters), slices.Min(bachelors)
}
