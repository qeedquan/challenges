package main

func main() {
	tab := []int{
		0, 0, 1, 2, 4, 6, 9, 12, 16, 20, 25, 30, 36, 42, 49, 56, 64, 72, 81,
		90, 100, 110, 121, 132, 144, 156, 169, 182, 196, 210, 225, 240, 256,
		272, 289, 306, 324, 342, 361, 380, 400, 420, 441, 462, 484, 506, 529,
		552, 576, 600, 625, 650, 676, 702, 729, 756, 784, 812,
	}

	assert(count(4) == 2)
	assert(count(5) == 4)
	assert(count(6) == 6)
	for i := range tab {
		assert(count(i+1) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A002620
func count(n int) int {
	a := n / 2
	b := n - n/2
	return a*(a-1)/2 + b*(b-1)/2
}
