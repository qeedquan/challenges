package main

func main() {
	assert(solve("BAOBAB") == 22)
	assert(solve("AAAA") == 15)
	assert(solve("ABA") == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(s string) int {
	n := len(s)
	if n == 0 {
		return 0
	}

	p := make([][]int, n)
	for i := range p {
		p[i] = make([]int, n)
	}

	for i := range n {
		p[i][i] = 1
	}

	for i := n - 1; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			if s[i] == s[j] {
				p[i][j] = p[i][j-1] + p[i+1][j] + 1
			} else {
				p[i][j] = p[i][j-1] + p[i+1][j] - p[i+1][j-1]
			}
		}
	}
	return p[0][n-1]
}
