package main

func main() {
	assert(solve(2, 3, []int{1, 2, 1, 1}) == 3)
	assert(solve(5, 9, []int{1, 1, 1, 1, 2, 1}) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(x, y int, v []int) int {
	n := len(v)
	A := make([][]int, n+1)
	for i := range A {
		A[i] = make([]int, n+1)
	}
	copy(A[0], v)

	for i := 1; i <= n; i++ {
		A[i][0] = 1
		A[i][n-1] = 1
		for j := 1; j < n-1; j++ {
			A[i][j] = (A[i-1][j+1]*A[i][j-1] + 1) / A[i-1][j]
		}
	}
	return A[(y-1)%(n+1)][x-1]
}
