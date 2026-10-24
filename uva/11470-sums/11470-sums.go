package main

import "fmt"

func main() {
	fmt.Println(solve([][]int{
		{5, 3, 2, 7, 9},
		{1, 7, 4, 2, 4},
		{5, 3, 2, 4, 6},
		{1, 3, 4, 5, 1},
		{1, 4, 5, 6, 3},
	}))

	fmt.Println(solve([][]int{
		{1},
	}))
}

func solve(x [][]int) []int {
	n := len(x)
	s := make([]int, n)
	for i := range n {
		for j := range n {
			if j < n-i {
				k := min(i, j)
				s[k] += x[i][j]
			} else {
				k := max(i, j)
				s[n-k-1] += x[i][j]
			}
		}
	}
	return s[:(n/2)+(n%2)]
}
