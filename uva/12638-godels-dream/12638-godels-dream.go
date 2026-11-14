package main

func main() {
	assert(solve("0") == 1)
	assert(solve("10100") == 1)
	assert(solve("??1?") == 0)
	assert(solve("?1??") == 2)
	assert(solve("1?010100") == 2)
	assert(solve("???1????") == 6)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(s string) int {
	p := 1
	r := 0
	for _, c := range s {
		if c == '?' {
			c = '0'
		}

		if c == '0' {
			if p < 1 {
				p++
			}
		} else {
			if p > 0 {
				p = -1
			} else {
				p--
			}
		}

		if p > 0 {
			r++
		}
	}
	if p < 1 {
		r = 0
	}
	return r
}
