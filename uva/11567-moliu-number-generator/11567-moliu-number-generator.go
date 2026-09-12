package main

func main() {
	tab := []int{
		0, 1, 2, 3, 3, 4, 4, 5, 4, 5, 5, 6, 5, 6, 6, 6, 5, 6, 6, 7, 6, 7, 7, 7,
		6, 7, 7, 8, 7, 8, 7, 7, 6, 7, 7, 8, 7, 8, 8, 8, 7, 8, 8, 9, 8, 9, 8, 8,
		7, 8, 8, 9, 8, 9, 9, 9, 8, 9, 9, 9, 8, 9, 8, 8, 7, 8, 8, 9, 8, 9, 9, 9,
		8, 9, 9, 10, 9, 10, 9, 9, 8, 9, 9, 10, 9, 10, 10, 10, 9, 10, 10, 10, 9,
		10, 9, 9, 8, 9, 9,
	}

	assert(solve(7) == 5)

	for i := range tab {
		assert(solve(i) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A061339
func solve(n int) int {
	if n <= 1 {
		return n
	}
	if n%2 != 0 {
		return solve(check(n)) + 1
	}
	return solve(n/2) + 1
}

func check(n int) int {
	if n == 3 {
		return 2
	}
	if n-1 == 0 {
		return n - 1
	}

	c := 0
	for m := n + 1; m%2 == 0 && m != 0; m /= 2 {
		c += 1
	}
	for m := n - 1; m%2 == 0 && m != 0; m /= 2 {
		c -= 1
	}

	if c > 0 {
		return n + 1
	}
	return n - 1
}
