package main

func main() {
	assert(answer(637) == 1)
	assert(answer(-120) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func answer(n int) int {
	n = (n*567/9+7492)*235/47 - 498
	return (abs(n) / 10) % 10
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
