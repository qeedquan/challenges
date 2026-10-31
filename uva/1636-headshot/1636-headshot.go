package main

func main() {
	assert(solve("0011") == "EQUAL")
	assert(solve("0111") == "ROTATE")
	assert(solve("000111") == "SHOOT")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(s string) string {
	n := len(s)
	z := 0
	c := 0
	for i := range n {
		if s[i] == '1' {
			continue
		}
		z += 1
		if s[(i+1)%n] == '0' {
			c += 1
		}
	}
	if c*n == z*z {
		return "EQUAL"
	}
	if c*n > z*z {
		return "SHOOT"
	}
	return "ROTATE"
}
