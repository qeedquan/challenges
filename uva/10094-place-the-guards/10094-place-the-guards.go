package main

import "fmt"

func main() {
	fmt.Println(solve(4))
	fmt.Println(solve(8))
	fmt.Println(solve(10))
}

func solve(n int) []int {
	r := []int{}
	if n <= 3 {
		return r
	}

	if n%6 != 2 && n%6 != 3 {
		r = append(r, 2)
		r = gen1(r, 4, n)
		r = gen1(r, 1, n)
		return r
	}

	k := (n - (n % 2)) / 2
	r = append(r, k)
	switch {
	case k%2 == 0 && n%2 == 0:
		r = gen2(r, k, n, n, k-2, n-1, k+1)
	case k%2 == 0 && n%2 == 1:
		r = gen2(r, k, n, n-1, k-2, n-2, k+1)
	case k%2 == 1 && n%2 == 0:
		r = gen2(r, k, n, n-1, k-2, n, k+1)
	case k%2 == 1 && n%2 == 1:
		r = gen2(r, k, n, n-2, k-2, n-1, k+1)
	}
	return r
}

func gen1(r []int, i0, i1 int) []int {
	for i := i0; i <= i1; i += 2 {
		r = append(r, i)
	}
	return r
}

func gen2(r []int, k, n, n1, k1, n2, k2 int) []int {
	r = gen1(r, k+2, n1)
	r = gen1(r, 2, k1)
	r = gen1(r, k+3, n2)
	r = gen1(r, 1, k2)
	return r
}
