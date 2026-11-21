package main

import "fmt"

func main() {
	fmt.Println(solve(3, 1))
	fmt.Println(solve(4, 10))
	fmt.Println(solve(2, 2))
	fmt.Println(solve(4, 15))
}

func solve(n, m int) (int, int) {
	l := 1 << n
	t := m
	c := 0
	for ; t != 0; t >>= 1 {
		c += t & 1
	}
	if m == 0 {
		t = 1 << n
	} else {
		t = m &^ (m - 1)
	}
	return c + 1, l - t + 1
}
