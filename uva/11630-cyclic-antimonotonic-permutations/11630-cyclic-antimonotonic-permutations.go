package main

import "fmt"

func main() {
	for i := range 10 {
		fmt.Println(gen(i))
	}
}

func gen(n int) []int {
	if n < 3 {
		return []int{}
	}

	A := make([]int, n+2)
	A[1] = 3
	A[2] = 1
	for i := 3; i <= n; i += 2 {
		A[i] = i + 2
	}

	if n%2 != 0 {
		A[n] = n - 1
	} else {
		A[n] = n - 2
		A[n-1] = n
	}

	for i := n - 2 + n%2; i > 2; i -= 2 {
		A[i] = i - 2
	}

	return A[1 : n+1]
}
