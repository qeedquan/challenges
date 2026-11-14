package main

import "fmt"

func main() {
	fmt.Println(solve([]int{3, 1, 2, 2, 1, 3, 5, 3, 3, 2}))
}

func solve(values []int) [][2]int {
	order := [][2]int{}
	count := make(map[int]int)
	for _, value := range values {
		if count[value] == 0 {
			order = append(order, [2]int{value, 0})
		}
		count[value] += 1
	}
	for index := range order {
		order[index][1] = count[order[index][0]]
	}
	return order
}
