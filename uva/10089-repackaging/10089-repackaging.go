package main

import (
	"math"
	"sort"
)

func main() {
	assert(solve([][3]int{
		{1, 2, 3},
		{1, 11, 5},
		{9, 4, 3},
		{2, 3, 2},
	}) == "Yes")

	assert(solve([][3]int{
		{1, 3, 3},
		{1, 11, 5},
		{9, 4, 3},
		{2, 3, 2},
	}) == "No")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(S [][3]int) string {
	n := len(S)
	A := make([]float64, n)
	for i, P := range S {
		A[i] = math.Atan2(float64(P[1]-P[0]), float64(P[2]-P[0]))
	}
	sort.Float64s(A)

	r := 0.0
	for i := 1; i < n; i++ {
		r = max(r, A[i]-A[i-1])
	}
	r = max(r, 2*math.Pi-(A[n-1]-A[0]))

	if r > math.Pi {
		return "No"
	}
	return "Yes"
}
