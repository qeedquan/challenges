package main

import "fmt"

func main() {
	fmt.Println(solve(0))
	fmt.Println(solve(1))
	fmt.Println(solve(2))
	fmt.Println(solve(3))
	fmt.Println(solve(4))
	fmt.Println(solve(292))
	fmt.Println(solve(999999999))
}

func solve(p int) complex128 {
	b := -1 + 1i
	q := 0 + 0i
	for t := 1 + 0i; p != 0; p >>= 1 {
		if p&1 != 0 {
			q += t
		}
		t *= b
	}
	return q
}
