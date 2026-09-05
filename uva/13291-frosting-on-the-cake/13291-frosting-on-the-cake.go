package main

import "fmt"

func main() {
	fmt.Println(solve([]int{1, 1, 1}, []int{1, 1, 1}))
	fmt.Println(solve([]int{6, 2, 4, 5, 1, 1, 4}, []int{2, 5, 1, 4, 2, 3, 4}))
}

func solve(A, B []int) [3]int {
	a := [3]int{}
	b := [3]int{}
	for i := range A {
		a[i%3] += A[i]
	}
	for i := range B {
		b[i%3] += B[i]
	}

	r := [3]int{}
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			r[(i+j)%3] += a[i] * b[j]
		}
	}
	r[0], r[1], r[2] = r[1], r[2], r[0]

	return r
}
