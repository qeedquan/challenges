package main

func main() {
	assert(solve(4, 2, 1, [][3]int{
		{1, 2, 1},
		{1, 3, 1},
		{2, 1, 1},
		{2, 4, 1},
		{3, 1, 1},
		{3, 4, 1},
		{4, 2, 1},
		{4, 3, 1},
	}) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, e, t int, m [][3]int) int {
	n += 1
	p := make([][]int, n)
	for i := range p {
		p[i] = make([]int, n)
		for j := range p[i] {
			p[i][j] = n
		}
	}

	for _, v := range m {
		p[v[0]][v[1]] = v[2]
	}

	for k := range n {
		for i := range n {
			for j := range n {
				p[i][j] = min(p[i][j], p[i][k]+p[k][j])
			}
		}
	}

	r := 0
	for i := range n {
		if p[i][e] <= t || i == e {
			r += 1
		}
	}
	return r
}
