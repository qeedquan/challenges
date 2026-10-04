package main

func main() {
	assert(gen([]string{"this", "is", "a", "test", "of", "some", "words", "to", "try", "out"}) == 17247663)
	assert(gen([]string{"a", "bee", "see", "dee"}) == 4427)
	assert(gen([]string{"the", "of", "and", "to", "a", "in", "that", "is", "i", "it", "with", "for", "as"}) == 667241)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func gen(w []string) int {
	n := len(w)
	x := make([]int, n)
	for i := range n {
		x[i] = 0
		for j := 0; j < len(w[i]); j++ {
			x[i] = (x[i] << 5) + int(w[i][j]) - 'a' + 1
		}
	}

	c := 1
	for {
		f := false
		for i := range n {
			for j := range i {
				if (c/x[i])%n == (c/x[j])%n {
					f = true
					c = max(c, min(x[i]*(c/x[i]+1), x[j]*(c/x[j]+1)))
				}
			}
		}
		if !f {
			break
		}
	}
	return c
}
