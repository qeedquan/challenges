package main

func main() {
	assert(solve([]int{0, -3, 5, 10}) == 10)
	assert(solve([]int{0, -3, 5, 7}) == 7)
	assert(solve([]int{47, 50, -3, 7}) == 57)
	assert(solve([]int{}) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a []int) int {
	n := len(a)
	p := [2][]int{}
	for i := range p {
		p[i] = make([]int, n+1)
	}

	for i := 0; i < n; i++ {
		for j := 0; j+i < n; j++ {
			if i&1 != 0 {
				p[0][j] = max(p[1][j+1]+a[j], p[1][j]+a[j+i])
			} else {
				p[1][j] = min(p[0][j+1], p[0][j])
			}
		}
	}
	return p[0][0]
}
