package main

import "sort"

func main() {
	assert(solve([][2]int{
		{0, 6},
		{5, 7},
		{8, 9},
		{5, 9},
		{1, 2},
		{3, 4},
		{0, 5},
	}) == 4)

	assert(solve([][2]int{
		{6, 10},
		{5, 6},
		{0, 3},
		{0, 5},
		{3, 5},
		{4, 5},
	}) == 4)

	assert(solve([][2]int{
		{1, 5},
		{3, 9},
	}) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(M [][2]int) int {
	sort.SliceStable(M, func(i, j int) bool {
		return M[i][1] < M[j][1]
	})

	r := 0
	L := 0
	for i := range M {
		if L <= M[i][0] {
			L = M[i][1]
			r += 1
		}
	}
	return r
}
