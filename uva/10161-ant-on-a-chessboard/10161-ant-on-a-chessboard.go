package main

import "fmt"

func main() {
	test(8, 2, 3)
	test(20, 5, 4)
	test(25, 1, 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n, rx, ry int) {
	x, y := solve(n)
	fmt.Println(x, y)
	assert(x == rx)
	assert(y == ry)
}

func solve(n int) (int, int) {
	m, i, j := 1, 2, 1
	for {
		if abs(m-n) < j {
			break
		}
		m += i
		i += 2
		j += 1
	}

	x, y := j, j
	if (j & 1) != 0 {
		if n > m {
			x -= (n - m)
		} else {
			y -= (m - n)
		}
	} else {
		if n > m {
			y -= (n - m)
		} else {
			x -= (m - n)
		}
	}
	return x, y
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
