package main

func main() {
	assert(solve(".#.") == 1)
	assert(solve("...##....##") == 3)
	assert(solve("##") == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(s string) int {
	m := -1
	r := 0
	for i, c := range s {
		if c == '.' && m < i {
			m = i + 2
			r += 1
		}
	}
	return r
}
