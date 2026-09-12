package main

func main() {
	assert(solve(0, 0, 4, 0, 0, 1) == 2)
	assert(solve(7, 5, 1, 0, 0, 0) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(b1, b2, b3, b4, b5, b6 int) int {
	p := 0
	p += b6
	p += b5

	b1 -= b5 * 11
	p += b4

	b2 -= b4 * 5
	p += (b3 + 3) / 4

	switch b3 % 4 {
	case 1:
		b2 -= 5
		b1 -= 7
	case 2:
		b2 -= 3
		b1 -= 6
	case 3:
		b2 -= 1
		b1 -= 5
	}

	if b2 > 0 {
		p += (b2 + 8) / 9
		b2 -= 9 * ((b2 + 8) / 9)
	}

	if b2 < 0 {
		b1 += b2 * 4
	}
	if b1 > 0 {
		p += (b1 + 35) / 36
	}

	return p
}
