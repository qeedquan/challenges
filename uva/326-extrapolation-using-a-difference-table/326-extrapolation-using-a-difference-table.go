package main

func main() {
	assert(term([]int{3, 6, 10, 15}, 1) == 21)
	assert(term([]int{3, 6, 10, 15}, 2) == 28)
	assert(term([]int{2, 4, 6}, 20) == 46)
	assert(term([]int{3, 9, 12, 5, 18, -4}, 10) == -319268)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func term(a []int, k int) int {
	n := len(a)
	if n == 0 {
		return 0
	}

	m := make([][]int, n)
	for i := range m {
		m[i] = make([]int, n)
	}
	for i := range a {
		m[i][0] = a[i]
	}

	for j := 1; j < n; j++ {
		for i := j; i < n; i++ {
			m[i][j] = m[i][j-1] - m[i-1][j-1]
		}
	}

	for i := 0; i < k; i++ {
		for j := n - 2; j >= 0; j-- {
			m[n-1][j] += m[n-1][j+1]
		}
	}

	return m[n-1][0]
}
