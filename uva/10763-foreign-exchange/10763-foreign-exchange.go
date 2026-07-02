package main

import (
	"slices"
	"sort"
)

func main() {
	assert(solve([][2]int{
		{1, 2},
		{2, 1},
		{3, 4},
		{4, 3},
		{100, 200},
		{200, 100},
		{57, 2},
		{2, 57},
		{1, 2},
		{2, 1},
	}) == true)

	assert(solve([][2]int{
		{1, 2},
		{3, 4},
		{5, 6},
		{7, 8},
		{9, 10},
		{11, 12},
		{13, 14},
		{15, 16},
		{17, 18},
		{19, 20},
	}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(array [][2]int) bool {
	var (
		original []int
		target   []int
	)
	for _, value := range array {
		original = append(original, value[0])
		target = append(target, value[1])
	}
	sort.Ints(original)
	sort.Ints(target)
	return slices.Equal(original, target)
}
