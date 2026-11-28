package main

func main() {
	assert(symmetric([][]int{
		{5, 1, 3},
		{2, 0, 2},
		{3, 1, 5},
	}) == true)

	assert(symmetric([][]int{
		{5, 1, 3},
		{2, 0, 2},
		{0, 1, 5},
	}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func symmetric(m [][]int) bool {
	n := len(m)
	for r := range (n + 1) / 2 {
		l := n
		if r == n/2 {
			l = (n + 1) / 2
		}
		for c := range l {
			if m[r][c] < 0 || m[r][c] != m[n-1-r][n-1-c] {
				return false
			}
		}
	}
	return true
}
