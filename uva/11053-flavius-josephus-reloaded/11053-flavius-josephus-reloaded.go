package main

type fn func(int64) int64

func main() {
	assert(solve(2, 1, 1) == 0)
	assert(solve(5, 1, 1) == 2)
	assert(solve(10, 3, 7) == 4)
	assert(solve(101, 9, 2) == 96)
	assert(solve(698253463, 1, 181945480) == 698177783)
	assert(solve(1000000000, 999999999, 999999999) == 999999994)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, a, b int64) int64 {
	_, lambda := cycle(mkfn(a, b, n), 0)
	return n - lambda
}

func cycle(f fn, x int64) (int64, int64) {
	tortoise, hare := f(x), f(f(x))
	for tortoise != hare {
		tortoise, hare = f(tortoise), f(f(hare))
	}

	mu, lambda := int64(0), int64(1)
	for hare = x; tortoise != hare; mu++ {
		tortoise, hare = f(tortoise), f(hare)
	}
	for hare = f(tortoise); tortoise != hare; lambda++ {
		hare = f(hare)
	}
	return mu, lambda
}

func mkfn(a, b, n int64) fn {
	return func(x int64) int64 {
		return (a*(x*x%n) + b) % n
	}
}
